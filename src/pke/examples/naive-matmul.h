#ifndef NAIVE_MATMUL_H
#define NAIVE_MATMUL_H

#include "openfhe.h"

namespace lbcrypto {

using CiphertextT = ConstCiphertext<DCRTPoly>;
using CCParamsT = CCParams<CryptoContextCKKSRNS>;
using CryptoContextT = CryptoContext<DCRTPoly>;
using EvalKeyT = EvalKey<DCRTPoly>;
using PlaintextT = Plaintext;
using PrivateKeyT = PrivateKey<DCRTPoly>;
using PublicKeyT = PublicKey<DCRTPoly>;

std::vector<CiphertextT> matmul__encrypt__arg0(CryptoContextT v16, std::vector<double> v17, PublicKeyT v18);
std::vector<CiphertextT> matmul__encrypt__arg1(CryptoContextT v16, std::vector<double> v17, PublicKeyT v18);
double matmul__decrypt__result0(CryptoContextT v26, std::vector<CiphertextT> v27, PrivateKeyT v28);
std::vector<CiphertextT> matmul(CryptoContextT cc, std::vector<CiphertextT> v0, std::vector<CiphertextT> v1);
}

#endif //NAIVE_MATMUL_H
