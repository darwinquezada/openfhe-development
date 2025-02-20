#define PROFILE

#include "openfhe.h"

namespace lbcrypto {

using CiphertextT    = ConstCiphertext<DCRTPoly>;
using CCParamsT      = CCParams<CryptoContextBGVRNS>;
using CryptoContextT = CryptoContext<DCRTPoly>;
using EvalKeyT       = EvalKey<DCRTPoly>;
using PlaintextT     = Plaintext;
using PrivateKeyT    = PrivateKey<DCRTPoly>;
using PublicKeyT     = PublicKey<DCRTPoly>;

CiphertextT dot_product(CryptoContextT cc, CiphertextT ct, CiphertextT ct1) {
    std::vector<int64_t> v0 = {0, 0, 0, 0, 0, 0, 0, 1};
    const auto& ct2         = cc->EvalMultNoRelin(ct, ct1);
    const auto& ct3         = cc->Relinearize(ct2);
    const auto& ct4         = cc->EvalRotate(ct3, 4);
    const auto& ct5         = cc->EvalAdd(ct3, ct4);
    const auto& ct6         = cc->EvalRotate(ct5, 2);
    const auto& ct7         = cc->EvalAdd(ct5, ct6);
    const auto& ct8         = cc->EvalRotate(ct7, 1);
    const auto& ct9         = cc->EvalAdd(ct7, ct8);
    const auto& ct10        = cc->ModReduce(ct9);
    auto v0_filled_n        = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
    auto v0_filled          = v0;
    v0_filled.clear();
    v0_filled.reserve(v0_filled_n);
    for (auto i = 0; i < v0_filled_n; ++i) {
        v0_filled.push_back(v0[i % v0.size()]);
    }
    const auto& pt   = cc->MakePackedPlaintext(v0_filled);
    const auto& ct11 = cc->EvalMult(ct10, pt);
    const auto& ct12 = cc->EvalRotate(ct11, 7);
    const auto& ct13 = ct12;
    const auto& ct14 = cc->ModReduce(ct13);
    return ct14;
}
CiphertextT dot_product__encrypt__arg0(CryptoContextT cc, std::vector<int16_t> v0, PublicKeyT pk) {
    std::vector<int64_t> v1(std::begin(v0), std::end(v0));
    auto v1_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
    auto v1_filled   = v1;
    v1_filled.clear();
    v1_filled.reserve(v1_filled_n);
    for (auto i = 0; i < v1_filled_n; ++i) {
        v1_filled.push_back(v1[i % v1.size()]);
    }
    const auto& pt = cc->MakePackedPlaintext(v1_filled);
    const auto& ct = cc->Encrypt(pk, pt);
    return ct;
}
CiphertextT dot_product__encrypt__arg1(CryptoContextT cc, std::vector<int16_t> v0, PublicKeyT pk) {
    std::vector<int64_t> v1(std::begin(v0), std::end(v0));
    auto v1_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
    auto v1_filled   = v1;
    v1_filled.clear();
    v1_filled.reserve(v1_filled_n);
    for (auto i = 0; i < v1_filled_n; ++i) {
        v1_filled.push_back(v1[i % v1.size()]);
    }
    const auto& pt = cc->MakePackedPlaintext(v1_filled);
    const auto& ct = cc->Encrypt(pk, pt);
    return ct;
}
int16_t dot_product__decrypt__result0(CryptoContextT cc, CiphertextT ct, PrivateKeyT sk) {
    PlaintextT pt;
    cc->Decrypt(sk, ct, &pt);
    int16_t v0 = pt->GetPackedValue()[0];
    return v0;
}
CryptoContextT dot_product__generate_crypto_context() {
    CCParamsT params;
    params.SetMultiplicativeDepth(2);
    params.SetPlaintextModulus(4295294977);
    CryptoContextT cc = GenCryptoContext(params);
    cc->Enable(PKE);
    cc->Enable(KEYSWITCH);
    cc->Enable(LEVELEDSHE);
    return cc;
}
CryptoContextT dot_product__configure_crypto_context(CryptoContextT cc, PrivateKeyT sk) {
    cc->EvalMultKeyGen(sk);
    cc->EvalRotateKeyGen(sk, {1, 2, 4, 7});
    return cc;
}
}  // namespace lbcrypto