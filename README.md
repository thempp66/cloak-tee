<img  width="280" src="https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/_static/logo.png" alt="cloak-logo" align="left">

<h1 align="center">
    <a>
    Cloak TEE
  </a>
</h1>

<p align="center">
  <a href="https://en.wikipedia.org/wiki/C%2B%2B#Standardization">
    <img src="https://img.shields.io/badge/c%2B%2B-11/14/17/20-blue.svg" alt="Standard" />
  </a>
  <a href="https://github.com/OxHainan/cloak-tee/blob/cloak/LICENSE">
    <img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="Cloak TEE is released under the MIT license." />
  </a>
  <a href="https://circleci.com/gh/OxHainan/cloak-tee">
    <img src="https://circleci.com/gh/OxHainan/cloak-tee/tree/cloak.svg?style=shield" alt="Current CircleCI build status." />
  </a>
  <a href="https://www.codefactor.io/repository/github/oxhainan/cloak-tee">
    <img src="https://www.codefactor.io/repository/github/oxhainan/cloak-tee/badge" alt="CodeFactor." />
  </a>
  <a href="https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/started/contribute.html">
    <img src="https://img.shields.io/badge/PRs-welcome-brightgreen.svg" alt="PRs welcome!" />
  </a>
</p>

Cloak TEE is based on [EVM-for-CCF][evm-for-ccf]. It contains a sample application for the Confidential Consortium Framework([CCF][ccf]), running at Ethereum Virtual Machine([EVM][evm]).

[evm-for-ccf]: https://github.com/microsoft/EVM-for-CCF
[ccf]: https://github.com/Microsoft/CCF
[evm]: https://github.com/Microsoft/eEVM/

Cloak TEE is the core component in the [**Cloak Networks**][cloak-networks], and it runs the CCF framework to provide high-performance, fully-confidential distributed services, hosting a user-defined application and it also deals with Ethereum and Cloak transaction from users and synchronizes the results to Block chain. 
In this case the user-defined application is an interpreter for Ethereum bytecode, executing smart contracts entirely inside a [TEE][tee].

This service looks in many ways like a traditional Ethereum node, but has some fundamental differences:
- Consensus is deterministic rather than probabilistic. Since we trust the executing node, we do not need to re-execute on every node or wait for multiple block commits. There is a single transaction history, with no forks.
- There are no local nodes. Users do not run their own node, trusting it with key access and potentially private state. Instead all nodes run inside enclaves, maintaining privacy and guaranteeing execution integrity, regardless of where those enclaves are actually hosted.
- State is confidential, and that confidentiality is entirely controlled by smart contract logic. The app does not produce a public log of all transactions, and it does not reveal the resulting state to all users. The only access to state is by calling methods on smart contracts, where arbitrarily complex and dynamic restrictions can be applied.

[cloak-networks]: https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/tee-blockchain-architecture/cloak-network.html#cloak-network
[tee]: https://en.wikipedia.org/wiki/Trusted_execution_environment

## Contents

- [Prerequisites](#-rerequisites)
- [Building your first Cloak TEE app](#-building-your-first-Cloak-TEE-app)
- [Documentation](#-documentation)
- [How to Contribute](#-How-to-Contribute)
- [License](#-license)

## 📋 Requirements

This sample requires an developing environment of CCF's application. Installation of these requirements is described in [CCF's documentation](https://microsoft.github.io/CCF/ccf-0.15.2/quickstart/build_setup.html).

In order to quickly enter the CLoak-TEE compilation environment, we provide a docker images:

```
docker pull plytools/circleci-cloak-tee:v0.2.0
```

## 🎉 Building your first Cloak TEE app

### Building the source code

```
git clone --recurse-submodules https://github.com/OxHainan/cloak-tee.git
cd cloak-tee
mkdir build
cd build
# if you want to use CLOAK_DEBUG_FMT macro, you need add -DCLOAK_DEBUG_LOGGING=ON option
cmake .. -GNinja -DTARGET=virtual -DCMAKE_BUILD_TYPE=Debug -L
ninja
```

### Running the sample

To run the sample:

```
cd build
/opt/ccf-0.15.2/bin/sandbox.sh -v -p libevm4ccf.virtual.so

export EVM4CCF_HOME=<the path to evm4ccf>
export CONTRACTS_DIR=${EVM4CCF_HOME}//tests/contracts
python3 "${EVM4CCF_HOME}/samples/evmtest_deploy_and_transfer.py"
```

To launch a local instance for manual testing:

```
cd build
/opt/ccf-0.15.2/bin/sandbox.sh -v -p libevm4ccf.virtual.so -d 0
```

### Testing the Case

To run the test case

```
cd build
ctest
```

User initialize a Cloak Service as described in the [initialize Cloak Network on Blockchain][initialize-cloak-network-on-blockchain], and deploy confidential smart contract to Block chain as described in the [deploy cloak smart contract][deploy-cloak-smart-contract]

[deploy-cloak-smart-contract]: https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/deploy-cloak-smart-contract/deploy.html
[initialize-cloak-network-on-blockchain]: https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/tee-blockchain-architecture/initialize-cloak-network-on-blockchain.html

## 📖 Documentation

The full documentation for Cloak can found on our [Cloak documentation][cloak-docs]

[cloak-docs]: https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/#

## 👏 How to Contribute

The main purpose of this repository is to continue evolving Cloak TEE core. We want to make contributing to this project as easy and transparent as possible, and we are grateful to the community for contributing bug fixes and improvements. 
Read below to learn how you can take part in improving Cloak TEE.

### [Code of Conduct][code]

Cloak TEE has adopted a Code of Conduct that we expect project participants to adhere to.
Please read the [full text][code] so that you can understand what actions will and will not be tolerated.

[code]: https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/started/contribute.html#documentation-style-guide

### [Contributing Guide][contribute]

Read our [**Call for Contributions**][contribute] to learn about our development process, how to propose bugfixed and improvements, and how to build and test your changes to Cloak.

[contribute]: https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/started/contribute.html#all-contributions-counts

### [Open Source Roadmap][roadmap]

You can learn more about our vision for Cloak Networks in the [**Roadmap**][roadmap].

[roadmap]: https://oxhainan-cloak-docs.readthedocs-hosted.com/en/latest/roadmap/index.html#roadmap

### Submit Issues

If you find a bug or have some new idea, please submit it to [**issues**][issues]. This is a great place to get started, gain experience,
and get familiar with our contribution process.

[issues]: https://github.com/OxHainan/cloak-tee/issues

## 📄 License

cloak-tee is made under the [Apache 2.0][al], as found in the [LICENSE][l] file.

[al]: http://www.apache.org/licenses/LICENSE-2.0
[l]: https://github.com/OxHainan/cloak-tee/blob/cloak/LICENSE