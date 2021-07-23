#pragma once
#include "tls/key_pair.h"
#include <eEVM/rlp.h>


namespace evm4ccf
{
    using PointCoord = uint256_t;
    struct SignatureAbstract
    {
    protected:
        SignatureAbstract() {}

    public:
        static constexpr size_t r_fixed_length = 32u;
        uint8_t v;
        PointCoord r;
        PointCoord s;

        SignatureAbstract(
            uint8_t v_,
            const PointCoord& r_,
            const PointCoord& s_) :
            v(v_),
            r(r_),
            s(s_)
        {}

        SignatureAbstract(
            const tls::RecoverableSignature& sig)
        {
            v = to_ethereum_recovery_id(sig.recovery_id);
            const auto s_data = sig.raw.begin() + r_fixed_length;
            r = eevm::from_big_endian(sig.raw.data(), r_fixed_length);
            s = eevm::from_big_endian(s_data, r_fixed_length);
        }

        eevm::Address signatureAndVerify(const eevm::KeccakHash& tbs) const
        {
            tls::RecoverableSignature rs;
            to_recoverable_signature(rs);
            auto pubk = 
                tls::PublicKey_k1Bitcoin::recover_key(rs, {tbs.data(), tbs.size()});
            return get_address_from_public_key_asn1(public_key_asn1(pubk.get_raw_context()));
        }

    private:
        void to_recoverable_signature(tls::RecoverableSignature& sig) const
        {
            sig.recovery_id = from_ethereum_recovery_id(v);
            const auto s_begin = sig.raw.data() + r_fixed_length;
            eevm::to_big_endian(r, sig.raw.data());
            eevm::to_big_endian(s, s_begin);
        }
    };
    
} // namespace evm4ccf