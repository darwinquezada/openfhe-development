#include <cstdint>
#include <vector>

#include "dot_product_8.h"
#include "openfhe.h"

// header files needed for serialization
#include "ciphertext-ser.h"
#include "cryptocontext-ser.h"
#include "key/key-ser.h"
#include "scheme/bfvrns/bfvrns-ser.h"

using namespace lbcrypto;

int main(int argc, char* argv[]) {
    CryptoContext<DCRTPoly> cryptoContext = dot_product__generate_crypto_context();

    KeyPair<DCRTPoly> keyPair;
    keyPair = cryptoContext->KeyGen();

    cryptoContext = dot_product__configure_crypto_context(cryptoContext, keyPair.secretKey);

    std::vector<int16_t> arg0 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int16_t> arg1 = {2, 3, 4, 5, 6, 7, 8, 9};
    int64_t expected          = 240;

    auto encryptionStart = std::chrono::high_resolution_clock::now();
    auto arg0Encrypted   = dot_product__encrypt__arg0(cryptoContext, arg0, keyPair.publicKey);
    auto arg1Encrypted   = dot_product__encrypt__arg1(cryptoContext, arg1, keyPair.publicKey);
    auto encryptionEnd   = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTimeEncryption = encryptionEnd - encryptionStart;

    std::cout << "Total time encryption: " << totalTimeEncryption.count() << " seconds" << std::endl;

    //===========================================================================
    encryptionStart      = std::chrono::high_resolution_clock::now();
    auto outputEncrypted = dot_product(cryptoContext, arg0Encrypted, arg1Encrypted);
    encryptionEnd        = std::chrono::high_resolution_clock::now();
    totalTimeEncryption  = encryptionEnd - encryptionStart;
    std::cout << "Total time dot product: " << totalTimeEncryption.count() << " seconds" << std::endl;

    auto actual = dot_product__decrypt__result0(cryptoContext, outputEncrypted, keyPair.secretKey);

    std::cout << "Expected: " << expected << "\n";
    std::cout << "Actual: " << actual << "\n";

    return 0;
}