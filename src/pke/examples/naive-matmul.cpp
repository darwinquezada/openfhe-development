//
// Created by Darwin Quezada Gaibor on 7/2/25.
//
#define PROFILE

#include "naive-matmul.h"
#include "openfhe.h"

using namespace lbcrypto;

int main(int argc, char* argv[]) {
    CCParams<CryptoContextCKKSRNS> parameters;
    parameters.SetMultiplicativeDepth(1);
    // needs to be large enough to accommodate overflow in the plaintext space
    // pick a 32-bit prime for which (p-1) / 65536 is an integer.
    // parameters.SetPlaintextModulus(4295294977);
    CryptoContext<DCRTPoly> cryptoContext = GenCryptoContext(parameters);
    cryptoContext->Enable(PKE);
    cryptoContext->Enable(KEYSWITCH);
    cryptoContext->Enable(LEVELEDSHE);

    KeyPair<DCRTPoly> keyPair;
    keyPair = cryptoContext->KeyGen();
    cryptoContext->EvalMultKeyGen(keyPair.secretKey);

    auto publicKey = keyPair.publicKey;
    auto secretKey = keyPair.secretKey;

    std::vector<double> arg0Vals = {1.0, 0, 0, 0, 0, 0, 0, 0,
                                    0,   0, 0, 0, 0, 0, 0, 0};  // input
    std::vector<double> arg1Vals = {0.25, 0, 0, 0, 0, 0, 0, 0,
                                    0,    0, 0, 0, 0, 0, 0, 0};  // bias

    // This select the first element of the matrix (0x5036cb3d = 0.0992247) and
    // adds 0.25
    // double expected = 0.3492247;

    auto arg0Encrypted =
        matmul__encrypt__arg0(cryptoContext, arg0Vals, publicKey);
    auto arg1Encrypted =
        matmul__encrypt__arg1(cryptoContext, arg1Vals, publicKey);

    // Insert timing info
    std::clock_t c_start = std::clock();
    auto outputEncrypted = matmul(cryptoContext, arg0Encrypted, arg1Encrypted);
    std::clock_t c_end = std::clock();
    double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << "CPU time used: " << time_elapsed_ms << " ms\n";

    //auto actual =
    //    matmul__decrypt__result0(cryptoContext, outputEncrypted, secretKey);

    // EXPECT_NEAR(expected, actual, 1e-6);
}