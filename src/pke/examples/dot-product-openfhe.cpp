//==================================================================================
// BSD 2-Clause License
//
// Copyright (c) 2014-2022, NJIT, Duality Technologies Inc. and other contributors
//
// All rights reserved.
//
// Author TPOC: contact@openfhe.org
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//==================================================================================

/*
  Simple example for BFVrns (integer arithmetic)
 */

#include "openfhe.h"

using namespace lbcrypto;

int main() {

    CCParams<CryptoContextBGVRNS> parameters;
    parameters.SetMultiplicativeDepth(2);
    parameters.SetPlaintextModulus(4295294977);

    CryptoContext<DCRTPoly> cryptoContext = GenCryptoContext(parameters);

    cryptoContext->Enable(PKE);
    cryptoContext->Enable(KEYSWITCH);
    cryptoContext->Enable(LEVELEDSHE);

    // Initialize Public Key Containers
    KeyPair<DCRTPoly> keyPair;

    // Generate a public/private key pair
    keyPair = cryptoContext->KeyGen();

    cryptoContext->EvalMultKeyGen(keyPair.secretKey);
    cryptoContext->Enable(ADVANCEDSHE);
    cryptoContext->EvalSumKeyGen(keyPair.secretKey);
    cryptoContext->EvalRotateKeyGen(keyPair.secretKey, {1, 2, -1, -2});


    std::vector<int64_t> arg0 = {1, 2, 3, 4, 5, 6, 7, 8};
    Plaintext plaintext1      = cryptoContext->MakePackedPlaintext(arg0);

    std::vector<int64_t> arg1 = {2, 3, 4, 5, 6, 7, 8, 9};
    Plaintext plaintext2      = cryptoContext->MakePackedPlaintext(arg1);

    int64_t expected = 240;


    // ==================================================================
    auto encryptionStart = std::chrono::high_resolution_clock::now();

    auto ciphertext1 = cryptoContext->Encrypt(keyPair.publicKey, plaintext1);
    auto ciphertext2 = cryptoContext->Encrypt(keyPair.publicKey, plaintext2);

    auto encryptionEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTimeEncryption = encryptionEnd - encryptionStart;

    std::cout << "Total time encryption: " << totalTimeEncryption.count() << " seconds" << std::endl;
    // ==================================================================
    encryptionStart = std::chrono::high_resolution_clock::now();
    auto result      = cryptoContext->EvalMult(ciphertext1, ciphertext2);
    auto dot_product_result = cryptoContext->EvalSum(result, arg1.size());

    encryptionEnd = std::chrono::high_resolution_clock::now();
    totalTimeEncryption = encryptionEnd - encryptionStart;
    std::cout << "Total time dot product: " << totalTimeEncryption.count() << " seconds" << std::endl;

    Plaintext plaintextMultResult;
    cryptoContext->Decrypt(keyPair.secretKey, result, &plaintextMultResult);

    // plaintextMultResult->SetLength(1);

    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << plaintextMultResult << std::endl;

    return 0;
}
