// Copyright (c) 2020 Oxford-Hainan Blockchain Research Institute
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include "cloak_exception.h"
#include "string"

namespace abicoder {

class ABIException : public cloak4ccf::CloakException {
 public:
    explicit ABIException(const std::string& msg_) : msg(msg_) {}
    const char* what() const noexcept {
        return msg.c_str();
    }

 private:
    const std::string msg;
};
} // namespace abicoder
