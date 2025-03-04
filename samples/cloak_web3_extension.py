

def sendPrivacyPolicy(self, codeHash, privacy_policy):
    return self.web3.manager.request_blocking(
        "cloak_sendPrivacyPolicy",
        [codeHash, privacy_policy],
    )

def sendRawPrivacyPolicy(self, raw_transaction: str):
    return self.web3.manager.request_blocking(
        "cloak_sendRawPrivacyTransaction",
        [raw_transaction]
    )

def sendOnchainContract(self, to, contract_abi):
    return self.web3.manager.request_blocking(
        "cloak_sendOnchainContract",
        [to, contract_abi],
    )


def sendMultiPartyTransaction(self, data):
    return self.web3.manager.request_blocking(
        "cloak_sendRawMultiPartyTransaction",
        [data],
    )

# Implementation of web3 Provider which talks framed-JSON-over-TLS to a CCF node
def cloak_middleware(make_request, w3):
    # do one-time setup operations here

    def middleware(method, params):
        if "sendRawTransaction" in method:
            print("preprocess method: {}".format(method))
            method = "cloak_sendRawTransaction"
            print("processed method: {}".format(method))

        # perform the RPC request, getting the response
        response = make_request(method, params)

        # finally return the response
        return response
    return middleware
