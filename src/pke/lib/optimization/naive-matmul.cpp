#define PROFILE

#include "openfhe.h"

namespace lbcrypto {

using namespace lbcrypto;
using CiphertextT = ConstCiphertext<DCRTPoly>;
using CCParamsT = CCParams<CryptoContextCKKSRNS>;
using CryptoContextT = CryptoContext<DCRTPoly>;
using EvalKeyT = EvalKey<DCRTPoly>;
using PlaintextT = Plaintext;
using PrivateKeyT = PrivateKey<DCRTPoly>;
using PublicKeyT = PublicKey<DCRTPoly>;

std::vector<CiphertextT> matmul__encrypt__arg0(CryptoContextT v16,
                                               std::vector<double> v17,
                                               PublicKeyT v18) {
    std::vector<float> v17_cast(std::begin(v17), std::end(v17));
    int32_t n =
        v16->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
    // create a 1x16 vector of ciphertexts encrypting each value
    std::vector<CiphertextT> outputs;
    outputs.reserve(16);
    for (auto v17_val : v17_cast) {
        std::vector<double> single(n, v17_val);
        const auto& v19 = v16->MakeCKKSPackedPlaintext(single);
        const auto& v20 = v16->Encrypt(v18, v19);
        outputs.push_back(v20);
    }
    return outputs;
}

std::vector<CiphertextT> matmul__encrypt__arg1(CryptoContextT v16,
                                               std::vector<double> v17,
                                               PublicKeyT v18) {
    std::vector<float> v17_cast(std::begin(v17), std::end(v17));
    int32_t n =
        v16->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
    // create a 1x16 vector of ciphertexts encrypting each value
    std::vector<CiphertextT> outputs;
    outputs.reserve(16);
    for (auto v17_val : v17_cast) {
        std::vector<double> single(n, v17_val);
        const auto& v19 = v16->MakeCKKSPackedPlaintext(single);
        const auto& v20 = v16->Encrypt(v18, v19);
        outputs.push_back(v20);
    }
    return outputs;
}

double matmul__decrypt__result0(CryptoContextT v26,
                                std::vector<CiphertextT> v27, PrivateKeyT v28) {
    PlaintextT v29;
    v26->Decrypt(v28, v27[0], &v29);  // just decrypt first element
    double v30 = v29->GetCKKSPackedValue()[0].real();
    return v30;
}

std::vector<CiphertextT> matmul(CryptoContextT cc, std::vector<CiphertextT> v0, std::vector<CiphertextT> v1) {
  std::vector<double> v2(1024, -0.79403835535049438);
  std::vector<double> v3(1024, -1.053525447845459);
  std::vector<double> v4(1024, 0.55316483974456787);
  std::vector<double> v5(1024, -0.1626245379447937);
  std::vector<double> v6(1024, 0.14210513234138489);
  std::vector<double> v7(1024, -0.96425813436508179);
  std::vector<double> v8(1024, 0.84862178564071655);
  std::vector<double> v9(1024, 1.1056674718856812);
  std::vector<double> v10(1024, 0.58436465263366699);
  std::vector<double> v11(1024, 0.15611384809017181);
  std::vector<double> v12(1024, 0.12404315918684006);
  std::vector<double> v13(1024, -1.2648825645446777);
  std::vector<double> v14(1024, -0.050678789615631104);
  std::vector<double> v15(1024, -0.55540144443511963);
  std::vector<double> v16(1024, 0.64370489120483398);
  std::vector<double> v17(1024, 0.23090896010398865);
  std::vector<double> v18(1024, -0.15463680028915405);
  std::vector<double> v19(1024, -0.13727159798145294);
  std::vector<double> v20(1024, 0.53945612907409668);
  std::vector<double> v21(1024, -1.128947377204895);
  std::vector<double> v22(1024, 0.54557633399963379);
  std::vector<double> v23(1024, 1.5118139982223511);
  std::vector<double> v24(1024, -0.11440037935972214);
  std::vector<double> v25(1024, -2.7087633609771729);
  std::vector<double> v26(1024, 0.5092734694480896);
  std::vector<double> v27(1024, 0.2554873526096344);
  std::vector<double> v28(1024, 0.34788578748703003);
  std::vector<double> v29(1024, 1.8628616333007813);
  std::vector<double> v30(1024, 0.63514477014541626);
  std::vector<double> v31(1024, 0.1859058290719986);
  std::vector<double> v32(1024, -0.097009263932704925);
  std::vector<double> v33(1024, -0.59649866819381714);
  std::vector<double> v34(1024, -0.17439877986907959);
  std::vector<double> v35(1024, -0.44132152199745178);
  std::vector<double> v36(1024, 0.26087236404418945);
  std::vector<double> v37(1024, 0.56313872337341309);
  std::vector<double> v38(1024, 0.55591857433319092);
  std::vector<double> v39(1024, -0.81891751289367676);
  std::vector<double> v40(1024, 0.42754733562469482);
  std::vector<double> v41(1024, 1.7444931268692017);
  std::vector<double> v42(1024, -0.084191672503948211);
  std::vector<double> v43(1024, 0.60702967643737793);
  std::vector<double> v44(1024, -0.77257430553436279);
  std::vector<double> v45(1024, -0.83179187774658203);
  std::vector<double> v46(1024, -0.362113356590271);
  std::vector<double> v47(1024, -0.50011521577835083);
  std::vector<double> v48(1024, 0.055427834391593933);
  std::vector<double> v49(1024, -0.035896223038434982);
  std::vector<double> v50(1024, 0.042754113674163818);
  std::vector<double> v51(1024, -0.71374839544296265);
  std::vector<double> v52(1024, -0.045355863869190216);
  std::vector<double> v53(1024, 0.60777837038040161);
  std::vector<double> v54(1024, 0.45448914170265198);
  std::vector<double> v55(1024, -0.36936965584754944);
  std::vector<double> v56(1024, 0.13158641755580902);
  std::vector<double> v57(1024, 0.92284315824508667);
  std::vector<double> v58(1024, 0.33086207509040833);
  std::vector<double> v59(1024, 0.31551116704940796);
  std::vector<double> v60(1024, 0.14185333251953125);
  std::vector<double> v61(1024, -0.71573382616043091);
  std::vector<double> v62(1024, -0.18900975584983826);
  std::vector<double> v63(1024, 0.1399475634098053);
  std::vector<double> v64(1024, 0.53351414203643799);
  std::vector<double> v65(1024, -0.15196458995342255);
  std::vector<double> v66(1024, 0.72189658880233765);
  std::vector<double> v67(1024, 0.42072516679763794);
  std::vector<double> v68(1024, -0.63889205455780029);
  std::vector<double> v69(1024, -0.55219501256942749);
  std::vector<double> v70(1024, -0.66741663217544556);
  std::vector<double> v71(1024, 0.57427167892456055);
  std::vector<double> v72(1024, -0.12304101884365082);
  std::vector<double> v73(1024, -2.4899179935455322);
  std::vector<double> v74(1024, -0.38562390208244324);
  std::vector<double> v75(1024, -0.94897919893264771);
  std::vector<double> v76(1024, 1.0719634294509888);
  std::vector<double> v77(1024, 1.4242702722549438);
  std::vector<double> v78(1024, 1.5876189470291138);
  std::vector<double> v79(1024, 0.39650118350982666);
  std::vector<double> v80(1024, -0.62660735845565796);
  std::vector<double> v81(1024, 0.28227093815803528);
  std::vector<double> v82(1024, 0.93498927354812622);
  std::vector<double> v83(1024, 1.5652397871017456);
  std::vector<double> v84(1024, -0.36077478528022766);
  std::vector<double> v85(1024, -0.022781724110245705);
  std::vector<double> v86(1024, -0.42488935589790344);
  std::vector<double> v87(1024, 0.58892345428466797);
  std::vector<double> v88(1024, -0.98682498931884765);
  std::vector<double> v89(1024, -0.54379379749298096);
  std::vector<double> v90(1024, -0.73252391815185547);
  std::vector<double> v91(1024, -0.1667218804359436);
  std::vector<double> v92(1024, -0.056285310536623001);
  std::vector<double> v93(1024, 0.48631376028060913);
  std::vector<double> v94(1024, 0.032491646707057953);
  std::vector<double> v95(1024, 0.28629797697067261);
  std::vector<double> v96(1024, -0.28719732165336609);
  std::vector<double> v97(1024, -0.0055417143739759922);
  std::vector<double> v98(1024, -0.32021120190620422);
  std::vector<double> v99(1024, -0.60051995515823364);
  std::vector<double> v100(1024, 0.51121169328689575);
  std::vector<double> v101(1024, -0.0021613829303532839);
  std::vector<double> v102(1024, 0.042693194001913071);
  std::vector<double> v103(1024, -0.59854382276535034);
  std::vector<double> v104(1024, 0.25620663166046143);
  std::vector<double> v105(1024, 1.1326062679290771);
  std::vector<double> v106(1024, -0.072063654661178589);
  std::vector<double> v107(1024, -0.077801972627639771);
  std::vector<double> v108(1024, -0.51371169090270996);
  std::vector<double> v109(1024, -1.2477518320083618);
  std::vector<double> v110(1024, -0.24975378811359406);
  std::vector<double> v111(1024, -0.50972318649291992);
  std::vector<double> v112(1024, 0.33080604672431946);
  std::vector<double> v113(1024, -0.19504448771476746);
  std::vector<double> v114(1024, -0.14820653200149536);
  std::vector<double> v115(1024, 0.12368624657392502);
  std::vector<double> v116(1024, -0.24653038382530212);
  std::vector<double> v117(1024, -0.45864945650100708);
  std::vector<double> v118(1024, 0.29292252659797668);
  std::vector<double> v119(1024, 1.5237555503845215);
  std::vector<double> v120(1024, 0.68420100212097168);
  std::vector<double> v121(1024, -2.8995475769042969);
  std::vector<double> v122(1024, 0.19195529818534851);
  std::vector<double> v123(1024, -0.1414572149515152);
  std::vector<double> v124(1024, 0.86872678995132446);
  std::vector<double> v125(1024, 1.9643477201461792);
  std::vector<double> v126(1024, 1.2988345623016357);
  std::vector<double> v127(1024, -0.07382628321647644);
  std::vector<double> v128(1024, -0.28475037217140198);
  std::vector<double> v129(1024, -0.73823446035385132);
  std::vector<double> v130(1024, 0.22049681842327118);
  std::vector<double> v131(1024, -0.4583095908164978);
  std::vector<double> v132(1024, -0.25832182168960571);
  std::vector<double> v133(1024, 0.045063536614179611);
  std::vector<double> v134(1024, -0.32149222493171692);
  std::vector<double> v135(1024, 0.092302776873111724);
  std::vector<double> v136(1024, -0.18154707551002502);
  std::vector<double> v137(1024, 0.15252558887004852);
  std::vector<double> v138(1024, 0.022696418687701225);
  std::vector<double> v139(1024, -0.43141689896583557);
  std::vector<double> v140(1024, 0.52734839916229248);
  std::vector<double> v141(1024, -0.71634590625762939);
  std::vector<double> v142(1024, 0.064757443964481354);
  std::vector<double> v143(1024, -0.32779023051261902);
  std::vector<double> v144(1024, -0.33316606283187866);
  std::vector<double> v145(1024, 0.19714674353599548);
  std::vector<double> v146(1024, 0.42838233709335327);
  std::vector<double> v147(1024, -0.22657079994678497);
  std::vector<double> v148(1024, -0.54749703407287598);
  std::vector<double> v149(1024, 0.03665456548333168);
  std::vector<double> v150(1024, -0.18768051266670227);
  std::vector<double> v151(1024, 0.21442615985870361);
  std::vector<double> v152(1024, -0.84238362312316895);
  std::vector<double> v153(1024, -1.4815764427185059);
  std::vector<double> v154(1024, -0.83481806516647339);
  std::vector<double> v155(1024, -1.2645710706710815);
  std::vector<double> v156(1024, 0.93882423639297485);
  std::vector<double> v157(1024, 0.60106617212295532);
  std::vector<double> v158(1024, 1.5899275541305542);
  std::vector<double> v159(1024, 0.31331375241279602);
  std::vector<double> v160(1024, -0.72272264957427979);
  std::vector<double> v161(1024, 0.1149054542183876);
  std::vector<double> v162(1024, -0.20700185000896454);
  std::vector<double> v163(1024, -0.30057206749916077);
  std::vector<double> v164(1024, 0.23362289369106293);
  std::vector<double> v165(1024, 0.48057058453559875);
  std::vector<double> v166(1024, -0.20961792767047882);
  std::vector<double> v167(1024, -0.81989318132400513);
  std::vector<double> v168(1024, 0.3548349142074585);
  std::vector<double> v169(1024, 1.1731358766555786);
  std::vector<double> v170(1024, 0.24027314782142639);
  std::vector<double> v171(1024, 0.27162325382232666);
  std::vector<double> v172(1024, -0.21186260879039764);
  std::vector<double> v173(1024, -1.2426817417144775);
  std::vector<double> v174(1024, -0.47020760178565979);
  std::vector<double> v175(1024, 0.39420214295387268);
  std::vector<double> v176(1024, -0.3701728880405426);
  std::vector<double> v177(1024, 0.27544882893562317);
  std::vector<double> v178(1024, -0.38478666543960571);
  std::vector<double> v179(1024, -1.1268185335211456E-4);
  std::vector<double> v180(1024, 0.32624354958534241);
  std::vector<double> v181(1024, -0.31723788380622864);
  std::vector<double> v182(1024, 0.51305907964706421);
  std::vector<double> v183(1024, 1.2669166326522827);
  std::vector<double> v184(1024, -0.18538130819797516);
  std::vector<double> v185(1024, -2.4022583961486816);
  std::vector<double> v186(1024, -0.2432744950056076);
  std::vector<double> v187(1024, -0.20576582849025726);
  std::vector<double> v188(1024, 0.56241577863693237);
  std::vector<double> v189(1024, 1.1475141048431396);
  std::vector<double> v190(1024, 0.71883642673492432);
  std::vector<double> v191(1024, 0.12207169830799103);
  std::vector<double> v192(1024, 0.27550306916236877);
  std::vector<double> v193(1024, -0.96464920043945313);
  std::vector<double> v194(1024, -0.3929552435874939);
  std::vector<double> v195(1024, -0.33431562781333923);
  std::vector<double> v196(1024, -0.071691848337650299);
  std::vector<double> v197(1024, 0.5469127893447876);
  std::vector<double> v198(1024, 0.26154384016990662);
  std::vector<double> v199(1024, -0.49483364820480347);
  std::vector<double> v200(1024, 0.16159024834632874);
  std::vector<double> v201(1024, 0.60860002040863037);
  std::vector<double> v202(1024, 0.59895026683807373);
  std::vector<double> v203(1024, 0.085726074874401092);
  std::vector<double> v204(1024, -0.48890489339828491);
  std::vector<double> v205(1024, -0.66605234146118164);
  std::vector<double> v206(1024, -0.66186690330505371);
  std::vector<double> v207(1024, 0.057877685874700546);
  std::vector<double> v208(1024, 0.45453822612762451);
  std::vector<double> v209(1024, -0.15796004235744476);
  std::vector<double> v210(1024, 0.53068709373474121);
  std::vector<double> v211(1024, 0.49015524983406067);
  std::vector<double> v212(1024, -0.89652681350708008);
  std::vector<double> v213(1024, -0.23064124584197998);
  std::vector<double> v214(1024, -0.16090504825115204);
  std::vector<double> v215(1024, 0.04734518751502037);
  std::vector<double> v216(1024, -0.10481414198875427);
  std::vector<double> v217(1024, -1.2402379512786865);
  std::vector<double> v218(1024, -0.61209958791732788);
  std::vector<double> v219(1024, -0.71234738826751709);
  std::vector<double> v220(1024, 0.80671006441116333);
  std::vector<double> v221(1024, 0.97291922569274902);
  std::vector<double> v222(1024, 1.0075423717498779);
  std::vector<double> v223(1024, 1.1132321357727051);
  std::vector<double> v224(1024, -0.94652318954467773);
  std::vector<double> v225(1024, 0.18131214380264282);
  std::vector<double> v226(1024, -0.20818331837654114);
  std::vector<double> v227(1024, 0.48062974214553833);
  std::vector<double> v228(1024, 0.027477791532874107);
  std::vector<double> v229(1024, -0.56367188692092896);
  std::vector<double> v230(1024, -0.10177969187498093);
  std::vector<double> v231(1024, 1.3368092775344849);
  std::vector<double> v232(1024, 0.10944274812936783);
  std::vector<double> v233(1024, -2.338003396987915);
  std::vector<double> v234(1024, -0.033918734639883041);
  std::vector<double> v235(1024, 0.095811963081359863);
  std::vector<double> v236(1024, 0.9463585615158081);
  std::vector<double> v237(1024, 1.5206575393676758);
  std::vector<double> v238(1024, 1.0443764925003052);
  std::vector<double> v239(1024, 0.26170644164085388);
  std::vector<double> v240(1024, 0.18692751228809357);
  std::vector<double> v241(1024, -0.38140776753425598);
  std::vector<double> v242(1024, 0.06509147584438324);
  [[maybe_unused]] size_t v243 = 15;
  std::vector<double> v244(1024, -0.95574027299880981);
  [[maybe_unused]] size_t v245 = 14;
  std::vector<double> v246(1024, -0.18913891911506653);
  [[maybe_unused]] size_t v247 = 13;
  std::vector<double> v248(1024, 0.59854048490524292);
  [[maybe_unused]] size_t v249 = 12;
  std::vector<double> v250(1024, 0.24027144908905029);
  [[maybe_unused]] size_t v251 = 11;
  std::vector<double> v252(1024, -0.64523142576217651);
  [[maybe_unused]] size_t v253 = 10;
  std::vector<double> v254(1024, -0.036247525364160538);
  [[maybe_unused]] size_t v255 = 9;
  std::vector<double> v256(1024, 1.2252428531646729);
  [[maybe_unused]] size_t v257 = 8;
  std::vector<double> v258(1024, -0.078801549971103668);
  [[maybe_unused]] size_t v259 = 7;
  std::vector<double> v260(1024, 0.2462066113948822);
  [[maybe_unused]] size_t v261 = 6;
  std::vector<double> v262(1024, 0.013903730548918247);
  [[maybe_unused]] size_t v263 = 5;
  std::vector<double> v264(1024, -1.2275182008743286);
  [[maybe_unused]] size_t v265 = 4;
  std::vector<double> v266(1024, -0.019158914685249329);
  [[maybe_unused]] size_t v267 = 3;
  std::vector<double> v268(1024, -0.14811104536056519);
  [[maybe_unused]] size_t v269 = 2;
  std::vector<double> v270(1024, -0.18939845263957977);
  [[maybe_unused]] size_t v271 = 1;
  std::vector<double> v272(1024, 0.099224686622619628);
  [[maybe_unused]] size_t v273 = 0;
  const auto& ct = v0[0 + 16 * (0)];
  const auto& ct1 = v1[0 + 16 * (0)];
  auto v272_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v272_filled = v272;
  v272_filled.clear();
  v272_filled.reserve(v272_filled_n);
  for (auto i = 0; i < v272_filled_n; ++i) {
    v272_filled.push_back(v272[i % v272.size()]);
  }
  const auto& pt = cc->MakeCKKSPackedPlaintext(v272_filled);
  const auto& ct2 = cc->EvalMult(ct, pt);
  const auto& ct3 = cc->EvalAdd(ct1, ct2);
  v1[0 + 16 * (0)] = ct3;
  std::vector<CiphertextT> v274 = std::move(v1);
  const auto& ct4 = v0[1 + 16 * (0)];
  const auto& ct5 = v274[0 + 16 * (0)];
  auto v270_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v270_filled = v270;
  v270_filled.clear();
  v270_filled.reserve(v270_filled_n);
  for (auto i = 0; i < v270_filled_n; ++i) {
    v270_filled.push_back(v270[i % v270.size()]);
  }
  const auto& pt1 = cc->MakeCKKSPackedPlaintext(v270_filled);
  const auto& ct6 = cc->EvalMult(ct4, pt1);
  const auto& ct7 = cc->EvalAdd(ct5, ct6);
  v274[0 + 16 * (0)] = ct7;
  std::vector<CiphertextT> v275 = std::move(v274);
  const auto& ct8 = v0[2 + 16 * (0)];
  const auto& ct9 = v275[0 + 16 * (0)];
  auto v268_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v268_filled = v268;
  v268_filled.clear();
  v268_filled.reserve(v268_filled_n);
  for (auto i = 0; i < v268_filled_n; ++i) {
    v268_filled.push_back(v268[i % v268.size()]);
  }
  const auto& pt2 = cc->MakeCKKSPackedPlaintext(v268_filled);
  const auto& ct10 = cc->EvalMult(ct8, pt2);
  const auto& ct11 = cc->EvalAdd(ct9, ct10);
  v275[0 + 16 * (0)] = ct11;
  std::vector<CiphertextT> v276 = std::move(v275);
  const auto& ct12 = v0[3 + 16 * (0)];
  const auto& ct13 = v276[0 + 16 * (0)];
  auto v266_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v266_filled = v266;
  v266_filled.clear();
  v266_filled.reserve(v266_filled_n);
  for (auto i = 0; i < v266_filled_n; ++i) {
    v266_filled.push_back(v266[i % v266.size()]);
  }
  const auto& pt3 = cc->MakeCKKSPackedPlaintext(v266_filled);
  const auto& ct14 = cc->EvalMult(ct12, pt3);
  const auto& ct15 = cc->EvalAdd(ct13, ct14);
  v276[0 + 16 * (0)] = ct15;
  std::vector<CiphertextT> v277 = std::move(v276);
  const auto& ct16 = v0[4 + 16 * (0)];
  const auto& ct17 = v277[0 + 16 * (0)];
  auto v264_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v264_filled = v264;
  v264_filled.clear();
  v264_filled.reserve(v264_filled_n);
  for (auto i = 0; i < v264_filled_n; ++i) {
    v264_filled.push_back(v264[i % v264.size()]);
  }
  const auto& pt4 = cc->MakeCKKSPackedPlaintext(v264_filled);
  const auto& ct18 = cc->EvalMult(ct16, pt4);
  const auto& ct19 = cc->EvalAdd(ct17, ct18);
  v277[0 + 16 * (0)] = ct19;
  std::vector<CiphertextT> v278 = std::move(v277);
  const auto& ct20 = v0[5 + 16 * (0)];
  const auto& ct21 = v278[0 + 16 * (0)];
  auto v262_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v262_filled = v262;
  v262_filled.clear();
  v262_filled.reserve(v262_filled_n);
  for (auto i = 0; i < v262_filled_n; ++i) {
    v262_filled.push_back(v262[i % v262.size()]);
  }
  const auto& pt5 = cc->MakeCKKSPackedPlaintext(v262_filled);
  const auto& ct22 = cc->EvalMult(ct20, pt5);
  const auto& ct23 = cc->EvalAdd(ct21, ct22);
  v278[0 + 16 * (0)] = ct23;
  std::vector<CiphertextT> v279 = std::move(v278);
  const auto& ct24 = v0[6 + 16 * (0)];
  const auto& ct25 = v279[0 + 16 * (0)];
  auto v260_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v260_filled = v260;
  v260_filled.clear();
  v260_filled.reserve(v260_filled_n);
  for (auto i = 0; i < v260_filled_n; ++i) {
    v260_filled.push_back(v260[i % v260.size()]);
  }
  const auto& pt6 = cc->MakeCKKSPackedPlaintext(v260_filled);
  const auto& ct26 = cc->EvalMult(ct24, pt6);
  const auto& ct27 = cc->EvalAdd(ct25, ct26);
  v279[0 + 16 * (0)] = ct27;
  std::vector<CiphertextT> v280 = std::move(v279);
  const auto& ct28 = v0[7 + 16 * (0)];
  const auto& ct29 = v280[0 + 16 * (0)];
  auto v258_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v258_filled = v258;
  v258_filled.clear();
  v258_filled.reserve(v258_filled_n);
  for (auto i = 0; i < v258_filled_n; ++i) {
    v258_filled.push_back(v258[i % v258.size()]);
  }
  const auto& pt7 = cc->MakeCKKSPackedPlaintext(v258_filled);
  const auto& ct30 = cc->EvalMult(ct28, pt7);
  const auto& ct31 = cc->EvalAdd(ct29, ct30);
  v280[0 + 16 * (0)] = ct31;
  std::vector<CiphertextT> v281 = std::move(v280);
  const auto& ct32 = v0[8 + 16 * (0)];
  const auto& ct33 = v281[0 + 16 * (0)];
  auto v256_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v256_filled = v256;
  v256_filled.clear();
  v256_filled.reserve(v256_filled_n);
  for (auto i = 0; i < v256_filled_n; ++i) {
    v256_filled.push_back(v256[i % v256.size()]);
  }
  const auto& pt8 = cc->MakeCKKSPackedPlaintext(v256_filled);
  const auto& ct34 = cc->EvalMult(ct32, pt8);
  const auto& ct35 = cc->EvalAdd(ct33, ct34);
  v281[0 + 16 * (0)] = ct35;
  std::vector<CiphertextT> v282 = std::move(v281);
  const auto& ct36 = v0[9 + 16 * (0)];
  const auto& ct37 = v282[0 + 16 * (0)];
  auto v254_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v254_filled = v254;
  v254_filled.clear();
  v254_filled.reserve(v254_filled_n);
  for (auto i = 0; i < v254_filled_n; ++i) {
    v254_filled.push_back(v254[i % v254.size()]);
  }
  const auto& pt9 = cc->MakeCKKSPackedPlaintext(v254_filled);
  const auto& ct38 = cc->EvalMult(ct36, pt9);
  const auto& ct39 = cc->EvalAdd(ct37, ct38);
  v282[0 + 16 * (0)] = ct39;
  std::vector<CiphertextT> v283 = std::move(v282);
  const auto& ct40 = v0[10 + 16 * (0)];
  const auto& ct41 = v283[0 + 16 * (0)];
  auto v252_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v252_filled = v252;
  v252_filled.clear();
  v252_filled.reserve(v252_filled_n);
  for (auto i = 0; i < v252_filled_n; ++i) {
    v252_filled.push_back(v252[i % v252.size()]);
  }
  const auto& pt10 = cc->MakeCKKSPackedPlaintext(v252_filled);
  const auto& ct42 = cc->EvalMult(ct40, pt10);
  const auto& ct43 = cc->EvalAdd(ct41, ct42);
  v283[0 + 16 * (0)] = ct43;
  std::vector<CiphertextT> v284 = std::move(v283);
  const auto& ct44 = v0[11 + 16 * (0)];
  const auto& ct45 = v284[0 + 16 * (0)];
  auto v250_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v250_filled = v250;
  v250_filled.clear();
  v250_filled.reserve(v250_filled_n);
  for (auto i = 0; i < v250_filled_n; ++i) {
    v250_filled.push_back(v250[i % v250.size()]);
  }
  const auto& pt11 = cc->MakeCKKSPackedPlaintext(v250_filled);
  const auto& ct46 = cc->EvalMult(ct44, pt11);
  const auto& ct47 = cc->EvalAdd(ct45, ct46);
  v284[0 + 16 * (0)] = ct47;
  std::vector<CiphertextT> v285 = std::move(v284);
  const auto& ct48 = v0[12 + 16 * (0)];
  const auto& ct49 = v285[0 + 16 * (0)];
  auto v248_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v248_filled = v248;
  v248_filled.clear();
  v248_filled.reserve(v248_filled_n);
  for (auto i = 0; i < v248_filled_n; ++i) {
    v248_filled.push_back(v248[i % v248.size()]);
  }
  const auto& pt12 = cc->MakeCKKSPackedPlaintext(v248_filled);
  const auto& ct50 = cc->EvalMult(ct48, pt12);
  const auto& ct51 = cc->EvalAdd(ct49, ct50);
  v285[0 + 16 * (0)] = ct51;
  std::vector<CiphertextT> v286 = std::move(v285);
  const auto& ct52 = v0[13 + 16 * (0)];
  const auto& ct53 = v286[0 + 16 * (0)];
  auto v246_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v246_filled = v246;
  v246_filled.clear();
  v246_filled.reserve(v246_filled_n);
  for (auto i = 0; i < v246_filled_n; ++i) {
    v246_filled.push_back(v246[i % v246.size()]);
  }
  const auto& pt13 = cc->MakeCKKSPackedPlaintext(v246_filled);
  const auto& ct54 = cc->EvalMult(ct52, pt13);
  const auto& ct55 = cc->EvalAdd(ct53, ct54);
  v286[0 + 16 * (0)] = ct55;
  std::vector<CiphertextT> v287 = std::move(v286);
  const auto& ct56 = v0[14 + 16 * (0)];
  const auto& ct57 = v287[0 + 16 * (0)];
  auto v244_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v244_filled = v244;
  v244_filled.clear();
  v244_filled.reserve(v244_filled_n);
  for (auto i = 0; i < v244_filled_n; ++i) {
    v244_filled.push_back(v244[i % v244.size()]);
  }
  const auto& pt14 = cc->MakeCKKSPackedPlaintext(v244_filled);
  const auto& ct58 = cc->EvalMult(ct56, pt14);
  const auto& ct59 = cc->EvalAdd(ct57, ct58);
  v287[0 + 16 * (0)] = ct59;
  std::vector<CiphertextT> v288 = std::move(v287);
  const auto& ct60 = v0[15 + 16 * (0)];
  const auto& ct61 = v288[0 + 16 * (0)];
  auto v242_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v242_filled = v242;
  v242_filled.clear();
  v242_filled.reserve(v242_filled_n);
  for (auto i = 0; i < v242_filled_n; ++i) {
    v242_filled.push_back(v242[i % v242.size()]);
  }
  const auto& pt15 = cc->MakeCKKSPackedPlaintext(v242_filled);
  const auto& ct62 = cc->EvalMult(ct60, pt15);
  const auto& ct63 = cc->EvalAdd(ct61, ct62);
  v288[0 + 16 * (0)] = ct63;
  std::vector<CiphertextT> v289 = std::move(v288);
  const auto& ct64 = v289[1 + 16 * (0)];
  auto v241_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v241_filled = v241;
  v241_filled.clear();
  v241_filled.reserve(v241_filled_n);
  for (auto i = 0; i < v241_filled_n; ++i) {
    v241_filled.push_back(v241[i % v241.size()]);
  }
  const auto& pt16 = cc->MakeCKKSPackedPlaintext(v241_filled);
  const auto& ct65 = cc->EvalMult(ct, pt16);
  const auto& ct66 = cc->EvalAdd(ct64, ct65);
  v289[1 + 16 * (0)] = ct66;
  std::vector<CiphertextT> v290 = std::move(v289);
  const auto& ct67 = v290[1 + 16 * (0)];
  auto v240_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v240_filled = v240;
  v240_filled.clear();
  v240_filled.reserve(v240_filled_n);
  for (auto i = 0; i < v240_filled_n; ++i) {
    v240_filled.push_back(v240[i % v240.size()]);
  }
  const auto& pt17 = cc->MakeCKKSPackedPlaintext(v240_filled);
  const auto& ct68 = cc->EvalMult(ct4, pt17);
  const auto& ct69 = cc->EvalAdd(ct67, ct68);
  v290[1 + 16 * (0)] = ct69;
  std::vector<CiphertextT> v291 = std::move(v290);
  const auto& ct70 = v291[1 + 16 * (0)];
  auto v239_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v239_filled = v239;
  v239_filled.clear();
  v239_filled.reserve(v239_filled_n);
  for (auto i = 0; i < v239_filled_n; ++i) {
    v239_filled.push_back(v239[i % v239.size()]);
  }
  const auto& pt18 = cc->MakeCKKSPackedPlaintext(v239_filled);
  const auto& ct71 = cc->EvalMult(ct8, pt18);
  const auto& ct72 = cc->EvalAdd(ct70, ct71);
  v291[1 + 16 * (0)] = ct72;
  std::vector<CiphertextT> v292 = std::move(v291);
  const auto& ct73 = v292[1 + 16 * (0)];
  auto v238_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v238_filled = v238;
  v238_filled.clear();
  v238_filled.reserve(v238_filled_n);
  for (auto i = 0; i < v238_filled_n; ++i) {
    v238_filled.push_back(v238[i % v238.size()]);
  }
  const auto& pt19 = cc->MakeCKKSPackedPlaintext(v238_filled);
  const auto& ct74 = cc->EvalMult(ct12, pt19);
  const auto& ct75 = cc->EvalAdd(ct73, ct74);
  v292[1 + 16 * (0)] = ct75;
  std::vector<CiphertextT> v293 = std::move(v292);
  const auto& ct76 = v293[1 + 16 * (0)];
  auto v237_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v237_filled = v237;
  v237_filled.clear();
  v237_filled.reserve(v237_filled_n);
  for (auto i = 0; i < v237_filled_n; ++i) {
    v237_filled.push_back(v237[i % v237.size()]);
  }
  const auto& pt20 = cc->MakeCKKSPackedPlaintext(v237_filled);
  const auto& ct77 = cc->EvalMult(ct16, pt20);
  const auto& ct78 = cc->EvalAdd(ct76, ct77);
  v293[1 + 16 * (0)] = ct78;
  std::vector<CiphertextT> v294 = std::move(v293);
  const auto& ct79 = v294[1 + 16 * (0)];
  auto v236_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v236_filled = v236;
  v236_filled.clear();
  v236_filled.reserve(v236_filled_n);
  for (auto i = 0; i < v236_filled_n; ++i) {
    v236_filled.push_back(v236[i % v236.size()]);
  }
  const auto& pt21 = cc->MakeCKKSPackedPlaintext(v236_filled);
  const auto& ct80 = cc->EvalMult(ct20, pt21);
  const auto& ct81 = cc->EvalAdd(ct79, ct80);
  v294[1 + 16 * (0)] = ct81;
  std::vector<CiphertextT> v295 = std::move(v294);
  const auto& ct82 = v295[1 + 16 * (0)];
  auto v235_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v235_filled = v235;
  v235_filled.clear();
  v235_filled.reserve(v235_filled_n);
  for (auto i = 0; i < v235_filled_n; ++i) {
    v235_filled.push_back(v235[i % v235.size()]);
  }
  const auto& pt22 = cc->MakeCKKSPackedPlaintext(v235_filled);
  const auto& ct83 = cc->EvalMult(ct24, pt22);
  const auto& ct84 = cc->EvalAdd(ct82, ct83);
  v295[1 + 16 * (0)] = ct84;
  std::vector<CiphertextT> v296 = std::move(v295);
  const auto& ct85 = v296[1 + 16 * (0)];
  auto v234_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v234_filled = v234;
  v234_filled.clear();
  v234_filled.reserve(v234_filled_n);
  for (auto i = 0; i < v234_filled_n; ++i) {
    v234_filled.push_back(v234[i % v234.size()]);
  }
  const auto& pt23 = cc->MakeCKKSPackedPlaintext(v234_filled);
  const auto& ct86 = cc->EvalMult(ct28, pt23);
  const auto& ct87 = cc->EvalAdd(ct85, ct86);
  v296[1 + 16 * (0)] = ct87;
  std::vector<CiphertextT> v297 = std::move(v296);
  const auto& ct88 = v297[1 + 16 * (0)];
  auto v233_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v233_filled = v233;
  v233_filled.clear();
  v233_filled.reserve(v233_filled_n);
  for (auto i = 0; i < v233_filled_n; ++i) {
    v233_filled.push_back(v233[i % v233.size()]);
  }
  const auto& pt24 = cc->MakeCKKSPackedPlaintext(v233_filled);
  const auto& ct89 = cc->EvalMult(ct32, pt24);
  const auto& ct90 = cc->EvalAdd(ct88, ct89);
  v297[1 + 16 * (0)] = ct90;
  std::vector<CiphertextT> v298 = std::move(v297);
  const auto& ct91 = v298[1 + 16 * (0)];
  auto v232_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v232_filled = v232;
  v232_filled.clear();
  v232_filled.reserve(v232_filled_n);
  for (auto i = 0; i < v232_filled_n; ++i) {
    v232_filled.push_back(v232[i % v232.size()]);
  }
  const auto& pt25 = cc->MakeCKKSPackedPlaintext(v232_filled);
  const auto& ct92 = cc->EvalMult(ct36, pt25);
  const auto& ct93 = cc->EvalAdd(ct91, ct92);
  v298[1 + 16 * (0)] = ct93;
  std::vector<CiphertextT> v299 = std::move(v298);
  const auto& ct94 = v299[1 + 16 * (0)];
  auto v231_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v231_filled = v231;
  v231_filled.clear();
  v231_filled.reserve(v231_filled_n);
  for (auto i = 0; i < v231_filled_n; ++i) {
    v231_filled.push_back(v231[i % v231.size()]);
  }
  const auto& pt26 = cc->MakeCKKSPackedPlaintext(v231_filled);
  const auto& ct95 = cc->EvalMult(ct40, pt26);
  const auto& ct96 = cc->EvalAdd(ct94, ct95);
  v299[1 + 16 * (0)] = ct96;
  std::vector<CiphertextT> v300 = std::move(v299);
  const auto& ct97 = v300[1 + 16 * (0)];
  auto v230_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v230_filled = v230;
  v230_filled.clear();
  v230_filled.reserve(v230_filled_n);
  for (auto i = 0; i < v230_filled_n; ++i) {
    v230_filled.push_back(v230[i % v230.size()]);
  }
  const auto& pt27 = cc->MakeCKKSPackedPlaintext(v230_filled);
  const auto& ct98 = cc->EvalMult(ct44, pt27);
  const auto& ct99 = cc->EvalAdd(ct97, ct98);
  v300[1 + 16 * (0)] = ct99;
  std::vector<CiphertextT> v301 = std::move(v300);
  const auto& ct100 = v301[1 + 16 * (0)];
  auto v229_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v229_filled = v229;
  v229_filled.clear();
  v229_filled.reserve(v229_filled_n);
  for (auto i = 0; i < v229_filled_n; ++i) {
    v229_filled.push_back(v229[i % v229.size()]);
  }
  const auto& pt28 = cc->MakeCKKSPackedPlaintext(v229_filled);
  const auto& ct101 = cc->EvalMult(ct48, pt28);
  const auto& ct102 = cc->EvalAdd(ct100, ct101);
  v301[1 + 16 * (0)] = ct102;
  std::vector<CiphertextT> v302 = std::move(v301);
  const auto& ct103 = v302[1 + 16 * (0)];
  auto v228_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v228_filled = v228;
  v228_filled.clear();
  v228_filled.reserve(v228_filled_n);
  for (auto i = 0; i < v228_filled_n; ++i) {
    v228_filled.push_back(v228[i % v228.size()]);
  }
  const auto& pt29 = cc->MakeCKKSPackedPlaintext(v228_filled);
  const auto& ct104 = cc->EvalMult(ct52, pt29);
  const auto& ct105 = cc->EvalAdd(ct103, ct104);
  v302[1 + 16 * (0)] = ct105;
  std::vector<CiphertextT> v303 = std::move(v302);
  const auto& ct106 = v303[1 + 16 * (0)];
  auto v227_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v227_filled = v227;
  v227_filled.clear();
  v227_filled.reserve(v227_filled_n);
  for (auto i = 0; i < v227_filled_n; ++i) {
    v227_filled.push_back(v227[i % v227.size()]);
  }
  const auto& pt30 = cc->MakeCKKSPackedPlaintext(v227_filled);
  const auto& ct107 = cc->EvalMult(ct56, pt30);
  const auto& ct108 = cc->EvalAdd(ct106, ct107);
  v303[1 + 16 * (0)] = ct108;
  std::vector<CiphertextT> v304 = std::move(v303);
  const auto& ct109 = v304[1 + 16 * (0)];
  auto v226_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v226_filled = v226;
  v226_filled.clear();
  v226_filled.reserve(v226_filled_n);
  for (auto i = 0; i < v226_filled_n; ++i) {
    v226_filled.push_back(v226[i % v226.size()]);
  }
  const auto& pt31 = cc->MakeCKKSPackedPlaintext(v226_filled);
  const auto& ct110 = cc->EvalMult(ct60, pt31);
  const auto& ct111 = cc->EvalAdd(ct109, ct110);
  v304[1 + 16 * (0)] = ct111;
  std::vector<CiphertextT> v305 = std::move(v304);
  const auto& ct112 = v305[2 + 16 * (0)];
  auto v225_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v225_filled = v225;
  v225_filled.clear();
  v225_filled.reserve(v225_filled_n);
  for (auto i = 0; i < v225_filled_n; ++i) {
    v225_filled.push_back(v225[i % v225.size()]);
  }
  const auto& pt32 = cc->MakeCKKSPackedPlaintext(v225_filled);
  const auto& ct113 = cc->EvalMult(ct, pt32);
  const auto& ct114 = cc->EvalAdd(ct112, ct113);
  v305[2 + 16 * (0)] = ct114;
  std::vector<CiphertextT> v306 = std::move(v305);
  const auto& ct115 = v306[2 + 16 * (0)];
  auto v224_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v224_filled = v224;
  v224_filled.clear();
  v224_filled.reserve(v224_filled_n);
  for (auto i = 0; i < v224_filled_n; ++i) {
    v224_filled.push_back(v224[i % v224.size()]);
  }
  const auto& pt33 = cc->MakeCKKSPackedPlaintext(v224_filled);
  const auto& ct116 = cc->EvalMult(ct4, pt33);
  const auto& ct117 = cc->EvalAdd(ct115, ct116);
  v306[2 + 16 * (0)] = ct117;
  std::vector<CiphertextT> v307 = std::move(v306);
  const auto& ct118 = v307[2 + 16 * (0)];
  auto v223_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v223_filled = v223;
  v223_filled.clear();
  v223_filled.reserve(v223_filled_n);
  for (auto i = 0; i < v223_filled_n; ++i) {
    v223_filled.push_back(v223[i % v223.size()]);
  }
  const auto& pt34 = cc->MakeCKKSPackedPlaintext(v223_filled);
  const auto& ct119 = cc->EvalMult(ct8, pt34);
  const auto& ct120 = cc->EvalAdd(ct118, ct119);
  v307[2 + 16 * (0)] = ct120;
  std::vector<CiphertextT> v308 = std::move(v307);
  const auto& ct121 = v308[2 + 16 * (0)];
  auto v222_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v222_filled = v222;
  v222_filled.clear();
  v222_filled.reserve(v222_filled_n);
  for (auto i = 0; i < v222_filled_n; ++i) {
    v222_filled.push_back(v222[i % v222.size()]);
  }
  const auto& pt35 = cc->MakeCKKSPackedPlaintext(v222_filled);
  const auto& ct122 = cc->EvalMult(ct12, pt35);
  const auto& ct123 = cc->EvalAdd(ct121, ct122);
  v308[2 + 16 * (0)] = ct123;
  std::vector<CiphertextT> v309 = std::move(v308);
  const auto& ct124 = v309[2 + 16 * (0)];
  auto v221_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v221_filled = v221;
  v221_filled.clear();
  v221_filled.reserve(v221_filled_n);
  for (auto i = 0; i < v221_filled_n; ++i) {
    v221_filled.push_back(v221[i % v221.size()]);
  }
  const auto& pt36 = cc->MakeCKKSPackedPlaintext(v221_filled);
  const auto& ct125 = cc->EvalMult(ct16, pt36);
  const auto& ct126 = cc->EvalAdd(ct124, ct125);
  v309[2 + 16 * (0)] = ct126;
  std::vector<CiphertextT> v310 = std::move(v309);
  const auto& ct127 = v310[2 + 16 * (0)];
  auto v220_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v220_filled = v220;
  v220_filled.clear();
  v220_filled.reserve(v220_filled_n);
  for (auto i = 0; i < v220_filled_n; ++i) {
    v220_filled.push_back(v220[i % v220.size()]);
  }
  const auto& pt37 = cc->MakeCKKSPackedPlaintext(v220_filled);
  const auto& ct128 = cc->EvalMult(ct20, pt37);
  const auto& ct129 = cc->EvalAdd(ct127, ct128);
  v310[2 + 16 * (0)] = ct129;
  std::vector<CiphertextT> v311 = std::move(v310);
  const auto& ct130 = v311[2 + 16 * (0)];
  auto v219_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v219_filled = v219;
  v219_filled.clear();
  v219_filled.reserve(v219_filled_n);
  for (auto i = 0; i < v219_filled_n; ++i) {
    v219_filled.push_back(v219[i % v219.size()]);
  }
  const auto& pt38 = cc->MakeCKKSPackedPlaintext(v219_filled);
  const auto& ct131 = cc->EvalMult(ct24, pt38);
  const auto& ct132 = cc->EvalAdd(ct130, ct131);
  v311[2 + 16 * (0)] = ct132;
  std::vector<CiphertextT> v312 = std::move(v311);
  const auto& ct133 = v312[2 + 16 * (0)];
  auto v218_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v218_filled = v218;
  v218_filled.clear();
  v218_filled.reserve(v218_filled_n);
  for (auto i = 0; i < v218_filled_n; ++i) {
    v218_filled.push_back(v218[i % v218.size()]);
  }
  const auto& pt39 = cc->MakeCKKSPackedPlaintext(v218_filled);
  const auto& ct134 = cc->EvalMult(ct28, pt39);
  const auto& ct135 = cc->EvalAdd(ct133, ct134);
  v312[2 + 16 * (0)] = ct135;
  std::vector<CiphertextT> v313 = std::move(v312);
  const auto& ct136 = v313[2 + 16 * (0)];
  auto v217_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v217_filled = v217;
  v217_filled.clear();
  v217_filled.reserve(v217_filled_n);
  for (auto i = 0; i < v217_filled_n; ++i) {
    v217_filled.push_back(v217[i % v217.size()]);
  }
  const auto& pt40 = cc->MakeCKKSPackedPlaintext(v217_filled);
  const auto& ct137 = cc->EvalMult(ct32, pt40);
  const auto& ct138 = cc->EvalAdd(ct136, ct137);
  v313[2 + 16 * (0)] = ct138;
  std::vector<CiphertextT> v314 = std::move(v313);
  const auto& ct139 = v314[2 + 16 * (0)];
  auto v216_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v216_filled = v216;
  v216_filled.clear();
  v216_filled.reserve(v216_filled_n);
  for (auto i = 0; i < v216_filled_n; ++i) {
    v216_filled.push_back(v216[i % v216.size()]);
  }
  const auto& pt41 = cc->MakeCKKSPackedPlaintext(v216_filled);
  const auto& ct140 = cc->EvalMult(ct36, pt41);
  const auto& ct141 = cc->EvalAdd(ct139, ct140);
  v314[2 + 16 * (0)] = ct141;
  std::vector<CiphertextT> v315 = std::move(v314);
  const auto& ct142 = v315[2 + 16 * (0)];
  auto v215_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v215_filled = v215;
  v215_filled.clear();
  v215_filled.reserve(v215_filled_n);
  for (auto i = 0; i < v215_filled_n; ++i) {
    v215_filled.push_back(v215[i % v215.size()]);
  }
  const auto& pt42 = cc->MakeCKKSPackedPlaintext(v215_filled);
  const auto& ct143 = cc->EvalMult(ct40, pt42);
  const auto& ct144 = cc->EvalAdd(ct142, ct143);
  v315[2 + 16 * (0)] = ct144;
  std::vector<CiphertextT> v316 = std::move(v315);
  const auto& ct145 = v316[2 + 16 * (0)];
  auto v214_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v214_filled = v214;
  v214_filled.clear();
  v214_filled.reserve(v214_filled_n);
  for (auto i = 0; i < v214_filled_n; ++i) {
    v214_filled.push_back(v214[i % v214.size()]);
  }
  const auto& pt43 = cc->MakeCKKSPackedPlaintext(v214_filled);
  const auto& ct146 = cc->EvalMult(ct44, pt43);
  const auto& ct147 = cc->EvalAdd(ct145, ct146);
  v316[2 + 16 * (0)] = ct147;
  std::vector<CiphertextT> v317 = std::move(v316);
  const auto& ct148 = v317[2 + 16 * (0)];
  auto v213_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v213_filled = v213;
  v213_filled.clear();
  v213_filled.reserve(v213_filled_n);
  for (auto i = 0; i < v213_filled_n; ++i) {
    v213_filled.push_back(v213[i % v213.size()]);
  }
  const auto& pt44 = cc->MakeCKKSPackedPlaintext(v213_filled);
  const auto& ct149 = cc->EvalMult(ct48, pt44);
  const auto& ct150 = cc->EvalAdd(ct148, ct149);
  v317[2 + 16 * (0)] = ct150;
  std::vector<CiphertextT> v318 = std::move(v317);
  const auto& ct151 = v318[2 + 16 * (0)];
  auto v212_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v212_filled = v212;
  v212_filled.clear();
  v212_filled.reserve(v212_filled_n);
  for (auto i = 0; i < v212_filled_n; ++i) {
    v212_filled.push_back(v212[i % v212.size()]);
  }
  const auto& pt45 = cc->MakeCKKSPackedPlaintext(v212_filled);
  const auto& ct152 = cc->EvalMult(ct52, pt45);
  const auto& ct153 = cc->EvalAdd(ct151, ct152);
  v318[2 + 16 * (0)] = ct153;
  std::vector<CiphertextT> v319 = std::move(v318);
  const auto& ct154 = v319[2 + 16 * (0)];
  auto v211_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v211_filled = v211;
  v211_filled.clear();
  v211_filled.reserve(v211_filled_n);
  for (auto i = 0; i < v211_filled_n; ++i) {
    v211_filled.push_back(v211[i % v211.size()]);
  }
  const auto& pt46 = cc->MakeCKKSPackedPlaintext(v211_filled);
  const auto& ct155 = cc->EvalMult(ct56, pt46);
  const auto& ct156 = cc->EvalAdd(ct154, ct155);
  v319[2 + 16 * (0)] = ct156;
  std::vector<CiphertextT> v320 = std::move(v319);
  const auto& ct157 = v320[2 + 16 * (0)];
  auto v210_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v210_filled = v210;
  v210_filled.clear();
  v210_filled.reserve(v210_filled_n);
  for (auto i = 0; i < v210_filled_n; ++i) {
    v210_filled.push_back(v210[i % v210.size()]);
  }
  const auto& pt47 = cc->MakeCKKSPackedPlaintext(v210_filled);
  const auto& ct158 = cc->EvalMult(ct60, pt47);
  const auto& ct159 = cc->EvalAdd(ct157, ct158);
  v320[2 + 16 * (0)] = ct159;
  std::vector<CiphertextT> v321 = std::move(v320);
  const auto& ct160 = v321[3 + 16 * (0)];
  auto v209_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v209_filled = v209;
  v209_filled.clear();
  v209_filled.reserve(v209_filled_n);
  for (auto i = 0; i < v209_filled_n; ++i) {
    v209_filled.push_back(v209[i % v209.size()]);
  }
  const auto& pt48 = cc->MakeCKKSPackedPlaintext(v209_filled);
  const auto& ct161 = cc->EvalMult(ct, pt48);
  const auto& ct162 = cc->EvalAdd(ct160, ct161);
  v321[3 + 16 * (0)] = ct162;
  std::vector<CiphertextT> v322 = std::move(v321);
  const auto& ct163 = v322[3 + 16 * (0)];
  auto v208_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v208_filled = v208;
  v208_filled.clear();
  v208_filled.reserve(v208_filled_n);
  for (auto i = 0; i < v208_filled_n; ++i) {
    v208_filled.push_back(v208[i % v208.size()]);
  }
  const auto& pt49 = cc->MakeCKKSPackedPlaintext(v208_filled);
  const auto& ct164 = cc->EvalMult(ct4, pt49);
  const auto& ct165 = cc->EvalAdd(ct163, ct164);
  v322[3 + 16 * (0)] = ct165;
  std::vector<CiphertextT> v323 = std::move(v322);
  const auto& ct166 = v323[3 + 16 * (0)];
  auto v207_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v207_filled = v207;
  v207_filled.clear();
  v207_filled.reserve(v207_filled_n);
  for (auto i = 0; i < v207_filled_n; ++i) {
    v207_filled.push_back(v207[i % v207.size()]);
  }
  const auto& pt50 = cc->MakeCKKSPackedPlaintext(v207_filled);
  const auto& ct167 = cc->EvalMult(ct8, pt50);
  const auto& ct168 = cc->EvalAdd(ct166, ct167);
  v323[3 + 16 * (0)] = ct168;
  std::vector<CiphertextT> v324 = std::move(v323);
  const auto& ct169 = v324[3 + 16 * (0)];
  auto v206_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v206_filled = v206;
  v206_filled.clear();
  v206_filled.reserve(v206_filled_n);
  for (auto i = 0; i < v206_filled_n; ++i) {
    v206_filled.push_back(v206[i % v206.size()]);
  }
  const auto& pt51 = cc->MakeCKKSPackedPlaintext(v206_filled);
  const auto& ct170 = cc->EvalMult(ct12, pt51);
  const auto& ct171 = cc->EvalAdd(ct169, ct170);
  v324[3 + 16 * (0)] = ct171;
  std::vector<CiphertextT> v325 = std::move(v324);
  const auto& ct172 = v325[3 + 16 * (0)];
  auto v205_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v205_filled = v205;
  v205_filled.clear();
  v205_filled.reserve(v205_filled_n);
  for (auto i = 0; i < v205_filled_n; ++i) {
    v205_filled.push_back(v205[i % v205.size()]);
  }
  const auto& pt52 = cc->MakeCKKSPackedPlaintext(v205_filled);
  const auto& ct173 = cc->EvalMult(ct16, pt52);
  const auto& ct174 = cc->EvalAdd(ct172, ct173);
  v325[3 + 16 * (0)] = ct174;
  std::vector<CiphertextT> v326 = std::move(v325);
  const auto& ct175 = v326[3 + 16 * (0)];
  auto v204_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v204_filled = v204;
  v204_filled.clear();
  v204_filled.reserve(v204_filled_n);
  for (auto i = 0; i < v204_filled_n; ++i) {
    v204_filled.push_back(v204[i % v204.size()]);
  }
  const auto& pt53 = cc->MakeCKKSPackedPlaintext(v204_filled);
  const auto& ct176 = cc->EvalMult(ct20, pt53);
  const auto& ct177 = cc->EvalAdd(ct175, ct176);
  v326[3 + 16 * (0)] = ct177;
  std::vector<CiphertextT> v327 = std::move(v326);
  const auto& ct178 = v327[3 + 16 * (0)];
  auto v203_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v203_filled = v203;
  v203_filled.clear();
  v203_filled.reserve(v203_filled_n);
  for (auto i = 0; i < v203_filled_n; ++i) {
    v203_filled.push_back(v203[i % v203.size()]);
  }
  const auto& pt54 = cc->MakeCKKSPackedPlaintext(v203_filled);
  const auto& ct179 = cc->EvalMult(ct24, pt54);
  const auto& ct180 = cc->EvalAdd(ct178, ct179);
  v327[3 + 16 * (0)] = ct180;
  std::vector<CiphertextT> v328 = std::move(v327);
  const auto& ct181 = v328[3 + 16 * (0)];
  auto v202_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v202_filled = v202;
  v202_filled.clear();
  v202_filled.reserve(v202_filled_n);
  for (auto i = 0; i < v202_filled_n; ++i) {
    v202_filled.push_back(v202[i % v202.size()]);
  }
  const auto& pt55 = cc->MakeCKKSPackedPlaintext(v202_filled);
  const auto& ct182 = cc->EvalMult(ct28, pt55);
  const auto& ct183 = cc->EvalAdd(ct181, ct182);
  v328[3 + 16 * (0)] = ct183;
  std::vector<CiphertextT> v329 = std::move(v328);
  const auto& ct184 = v329[3 + 16 * (0)];
  auto v201_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v201_filled = v201;
  v201_filled.clear();
  v201_filled.reserve(v201_filled_n);
  for (auto i = 0; i < v201_filled_n; ++i) {
    v201_filled.push_back(v201[i % v201.size()]);
  }
  const auto& pt56 = cc->MakeCKKSPackedPlaintext(v201_filled);
  const auto& ct185 = cc->EvalMult(ct32, pt56);
  const auto& ct186 = cc->EvalAdd(ct184, ct185);
  v329[3 + 16 * (0)] = ct186;
  std::vector<CiphertextT> v330 = std::move(v329);
  const auto& ct187 = v330[3 + 16 * (0)];
  auto v200_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v200_filled = v200;
  v200_filled.clear();
  v200_filled.reserve(v200_filled_n);
  for (auto i = 0; i < v200_filled_n; ++i) {
    v200_filled.push_back(v200[i % v200.size()]);
  }
  const auto& pt57 = cc->MakeCKKSPackedPlaintext(v200_filled);
  const auto& ct188 = cc->EvalMult(ct36, pt57);
  const auto& ct189 = cc->EvalAdd(ct187, ct188);
  v330[3 + 16 * (0)] = ct189;
  std::vector<CiphertextT> v331 = std::move(v330);
  const auto& ct190 = v331[3 + 16 * (0)];
  auto v199_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v199_filled = v199;
  v199_filled.clear();
  v199_filled.reserve(v199_filled_n);
  for (auto i = 0; i < v199_filled_n; ++i) {
    v199_filled.push_back(v199[i % v199.size()]);
  }
  const auto& pt58 = cc->MakeCKKSPackedPlaintext(v199_filled);
  const auto& ct191 = cc->EvalMult(ct40, pt58);
  const auto& ct192 = cc->EvalAdd(ct190, ct191);
  v331[3 + 16 * (0)] = ct192;
  std::vector<CiphertextT> v332 = std::move(v331);
  const auto& ct193 = v332[3 + 16 * (0)];
  auto v198_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v198_filled = v198;
  v198_filled.clear();
  v198_filled.reserve(v198_filled_n);
  for (auto i = 0; i < v198_filled_n; ++i) {
    v198_filled.push_back(v198[i % v198.size()]);
  }
  const auto& pt59 = cc->MakeCKKSPackedPlaintext(v198_filled);
  const auto& ct194 = cc->EvalMult(ct44, pt59);
  const auto& ct195 = cc->EvalAdd(ct193, ct194);
  v332[3 + 16 * (0)] = ct195;
  std::vector<CiphertextT> v333 = std::move(v332);
  const auto& ct196 = v333[3 + 16 * (0)];
  auto v197_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v197_filled = v197;
  v197_filled.clear();
  v197_filled.reserve(v197_filled_n);
  for (auto i = 0; i < v197_filled_n; ++i) {
    v197_filled.push_back(v197[i % v197.size()]);
  }
  const auto& pt60 = cc->MakeCKKSPackedPlaintext(v197_filled);
  const auto& ct197 = cc->EvalMult(ct48, pt60);
  const auto& ct198 = cc->EvalAdd(ct196, ct197);
  v333[3 + 16 * (0)] = ct198;
  std::vector<CiphertextT> v334 = std::move(v333);
  const auto& ct199 = v334[3 + 16 * (0)];
  auto v196_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v196_filled = v196;
  v196_filled.clear();
  v196_filled.reserve(v196_filled_n);
  for (auto i = 0; i < v196_filled_n; ++i) {
    v196_filled.push_back(v196[i % v196.size()]);
  }
  const auto& pt61 = cc->MakeCKKSPackedPlaintext(v196_filled);
  const auto& ct200 = cc->EvalMult(ct52, pt61);
  const auto& ct201 = cc->EvalAdd(ct199, ct200);
  v334[3 + 16 * (0)] = ct201;
  std::vector<CiphertextT> v335 = std::move(v334);
  const auto& ct202 = v335[3 + 16 * (0)];
  auto v195_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v195_filled = v195;
  v195_filled.clear();
  v195_filled.reserve(v195_filled_n);
  for (auto i = 0; i < v195_filled_n; ++i) {
    v195_filled.push_back(v195[i % v195.size()]);
  }
  const auto& pt62 = cc->MakeCKKSPackedPlaintext(v195_filled);
  const auto& ct203 = cc->EvalMult(ct56, pt62);
  const auto& ct204 = cc->EvalAdd(ct202, ct203);
  v335[3 + 16 * (0)] = ct204;
  std::vector<CiphertextT> v336 = std::move(v335);
  const auto& ct205 = v336[3 + 16 * (0)];
  auto v194_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v194_filled = v194;
  v194_filled.clear();
  v194_filled.reserve(v194_filled_n);
  for (auto i = 0; i < v194_filled_n; ++i) {
    v194_filled.push_back(v194[i % v194.size()]);
  }
  const auto& pt63 = cc->MakeCKKSPackedPlaintext(v194_filled);
  const auto& ct206 = cc->EvalMult(ct60, pt63);
  const auto& ct207 = cc->EvalAdd(ct205, ct206);
  v336[3 + 16 * (0)] = ct207;
  std::vector<CiphertextT> v337 = std::move(v336);
  const auto& ct208 = v337[4 + 16 * (0)];
  auto v193_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v193_filled = v193;
  v193_filled.clear();
  v193_filled.reserve(v193_filled_n);
  for (auto i = 0; i < v193_filled_n; ++i) {
    v193_filled.push_back(v193[i % v193.size()]);
  }
  const auto& pt64 = cc->MakeCKKSPackedPlaintext(v193_filled);
  const auto& ct209 = cc->EvalMult(ct, pt64);
  const auto& ct210 = cc->EvalAdd(ct208, ct209);
  v337[4 + 16 * (0)] = ct210;
  std::vector<CiphertextT> v338 = std::move(v337);
  const auto& ct211 = v338[4 + 16 * (0)];
  auto v192_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v192_filled = v192;
  v192_filled.clear();
  v192_filled.reserve(v192_filled_n);
  for (auto i = 0; i < v192_filled_n; ++i) {
    v192_filled.push_back(v192[i % v192.size()]);
  }
  const auto& pt65 = cc->MakeCKKSPackedPlaintext(v192_filled);
  const auto& ct212 = cc->EvalMult(ct4, pt65);
  const auto& ct213 = cc->EvalAdd(ct211, ct212);
  v338[4 + 16 * (0)] = ct213;
  std::vector<CiphertextT> v339 = std::move(v338);
  const auto& ct214 = v339[4 + 16 * (0)];
  auto v191_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v191_filled = v191;
  v191_filled.clear();
  v191_filled.reserve(v191_filled_n);
  for (auto i = 0; i < v191_filled_n; ++i) {
    v191_filled.push_back(v191[i % v191.size()]);
  }
  const auto& pt66 = cc->MakeCKKSPackedPlaintext(v191_filled);
  const auto& ct215 = cc->EvalMult(ct8, pt66);
  const auto& ct216 = cc->EvalAdd(ct214, ct215);
  v339[4 + 16 * (0)] = ct216;
  std::vector<CiphertextT> v340 = std::move(v339);
  const auto& ct217 = v340[4 + 16 * (0)];
  auto v190_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v190_filled = v190;
  v190_filled.clear();
  v190_filled.reserve(v190_filled_n);
  for (auto i = 0; i < v190_filled_n; ++i) {
    v190_filled.push_back(v190[i % v190.size()]);
  }
  const auto& pt67 = cc->MakeCKKSPackedPlaintext(v190_filled);
  const auto& ct218 = cc->EvalMult(ct12, pt67);
  const auto& ct219 = cc->EvalAdd(ct217, ct218);
  v340[4 + 16 * (0)] = ct219;
  std::vector<CiphertextT> v341 = std::move(v340);
  const auto& ct220 = v341[4 + 16 * (0)];
  auto v189_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v189_filled = v189;
  v189_filled.clear();
  v189_filled.reserve(v189_filled_n);
  for (auto i = 0; i < v189_filled_n; ++i) {
    v189_filled.push_back(v189[i % v189.size()]);
  }
  const auto& pt68 = cc->MakeCKKSPackedPlaintext(v189_filled);
  const auto& ct221 = cc->EvalMult(ct16, pt68);
  const auto& ct222 = cc->EvalAdd(ct220, ct221);
  v341[4 + 16 * (0)] = ct222;
  std::vector<CiphertextT> v342 = std::move(v341);
  const auto& ct223 = v342[4 + 16 * (0)];
  auto v188_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v188_filled = v188;
  v188_filled.clear();
  v188_filled.reserve(v188_filled_n);
  for (auto i = 0; i < v188_filled_n; ++i) {
    v188_filled.push_back(v188[i % v188.size()]);
  }
  const auto& pt69 = cc->MakeCKKSPackedPlaintext(v188_filled);
  const auto& ct224 = cc->EvalMult(ct20, pt69);
  const auto& ct225 = cc->EvalAdd(ct223, ct224);
  v342[4 + 16 * (0)] = ct225;
  std::vector<CiphertextT> v343 = std::move(v342);
  const auto& ct226 = v343[4 + 16 * (0)];
  auto v187_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v187_filled = v187;
  v187_filled.clear();
  v187_filled.reserve(v187_filled_n);
  for (auto i = 0; i < v187_filled_n; ++i) {
    v187_filled.push_back(v187[i % v187.size()]);
  }
  const auto& pt70 = cc->MakeCKKSPackedPlaintext(v187_filled);
  const auto& ct227 = cc->EvalMult(ct24, pt70);
  const auto& ct228 = cc->EvalAdd(ct226, ct227);
  v343[4 + 16 * (0)] = ct228;
  std::vector<CiphertextT> v344 = std::move(v343);
  const auto& ct229 = v344[4 + 16 * (0)];
  auto v186_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v186_filled = v186;
  v186_filled.clear();
  v186_filled.reserve(v186_filled_n);
  for (auto i = 0; i < v186_filled_n; ++i) {
    v186_filled.push_back(v186[i % v186.size()]);
  }
  const auto& pt71 = cc->MakeCKKSPackedPlaintext(v186_filled);
  const auto& ct230 = cc->EvalMult(ct28, pt71);
  const auto& ct231 = cc->EvalAdd(ct229, ct230);
  v344[4 + 16 * (0)] = ct231;
  std::vector<CiphertextT> v345 = std::move(v344);
  const auto& ct232 = v345[4 + 16 * (0)];
  auto v185_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v185_filled = v185;
  v185_filled.clear();
  v185_filled.reserve(v185_filled_n);
  for (auto i = 0; i < v185_filled_n; ++i) {
    v185_filled.push_back(v185[i % v185.size()]);
  }
  const auto& pt72 = cc->MakeCKKSPackedPlaintext(v185_filled);
  const auto& ct233 = cc->EvalMult(ct32, pt72);
  const auto& ct234 = cc->EvalAdd(ct232, ct233);
  v345[4 + 16 * (0)] = ct234;
  std::vector<CiphertextT> v346 = std::move(v345);
  const auto& ct235 = v346[4 + 16 * (0)];
  auto v184_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v184_filled = v184;
  v184_filled.clear();
  v184_filled.reserve(v184_filled_n);
  for (auto i = 0; i < v184_filled_n; ++i) {
    v184_filled.push_back(v184[i % v184.size()]);
  }
  const auto& pt73 = cc->MakeCKKSPackedPlaintext(v184_filled);
  const auto& ct236 = cc->EvalMult(ct36, pt73);
  const auto& ct237 = cc->EvalAdd(ct235, ct236);
  v346[4 + 16 * (0)] = ct237;
  std::vector<CiphertextT> v347 = std::move(v346);
  const auto& ct238 = v347[4 + 16 * (0)];
  auto v183_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v183_filled = v183;
  v183_filled.clear();
  v183_filled.reserve(v183_filled_n);
  for (auto i = 0; i < v183_filled_n; ++i) {
    v183_filled.push_back(v183[i % v183.size()]);
  }
  const auto& pt74 = cc->MakeCKKSPackedPlaintext(v183_filled);
  const auto& ct239 = cc->EvalMult(ct40, pt74);
  const auto& ct240 = cc->EvalAdd(ct238, ct239);
  v347[4 + 16 * (0)] = ct240;
  std::vector<CiphertextT> v348 = std::move(v347);
  const auto& ct241 = v348[4 + 16 * (0)];
  auto v182_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v182_filled = v182;
  v182_filled.clear();
  v182_filled.reserve(v182_filled_n);
  for (auto i = 0; i < v182_filled_n; ++i) {
    v182_filled.push_back(v182[i % v182.size()]);
  }
  const auto& pt75 = cc->MakeCKKSPackedPlaintext(v182_filled);
  const auto& ct242 = cc->EvalMult(ct44, pt75);
  const auto& ct243 = cc->EvalAdd(ct241, ct242);
  v348[4 + 16 * (0)] = ct243;
  std::vector<CiphertextT> v349 = std::move(v348);
  const auto& ct244 = v349[4 + 16 * (0)];
  auto v181_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v181_filled = v181;
  v181_filled.clear();
  v181_filled.reserve(v181_filled_n);
  for (auto i = 0; i < v181_filled_n; ++i) {
    v181_filled.push_back(v181[i % v181.size()]);
  }
  const auto& pt76 = cc->MakeCKKSPackedPlaintext(v181_filled);
  const auto& ct245 = cc->EvalMult(ct48, pt76);
  const auto& ct246 = cc->EvalAdd(ct244, ct245);
  v349[4 + 16 * (0)] = ct246;
  std::vector<CiphertextT> v350 = std::move(v349);
  const auto& ct247 = v350[4 + 16 * (0)];
  auto v180_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v180_filled = v180;
  v180_filled.clear();
  v180_filled.reserve(v180_filled_n);
  for (auto i = 0; i < v180_filled_n; ++i) {
    v180_filled.push_back(v180[i % v180.size()]);
  }
  const auto& pt77 = cc->MakeCKKSPackedPlaintext(v180_filled);
  const auto& ct248 = cc->EvalMult(ct52, pt77);
  const auto& ct249 = cc->EvalAdd(ct247, ct248);
  v350[4 + 16 * (0)] = ct249;
  std::vector<CiphertextT> v351 = std::move(v350);
  const auto& ct250 = v351[4 + 16 * (0)];
  auto v179_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v179_filled = v179;
  v179_filled.clear();
  v179_filled.reserve(v179_filled_n);
  for (auto i = 0; i < v179_filled_n; ++i) {
    v179_filled.push_back(v179[i % v179.size()]);
  }
  const auto& pt78 = cc->MakeCKKSPackedPlaintext(v179_filled);
  const auto& ct251 = cc->EvalMult(ct56, pt78);
  const auto& ct252 = cc->EvalAdd(ct250, ct251);
  v351[4 + 16 * (0)] = ct252;
  std::vector<CiphertextT> v352 = std::move(v351);
  const auto& ct253 = v352[4 + 16 * (0)];
  auto v178_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v178_filled = v178;
  v178_filled.clear();
  v178_filled.reserve(v178_filled_n);
  for (auto i = 0; i < v178_filled_n; ++i) {
    v178_filled.push_back(v178[i % v178.size()]);
  }
  const auto& pt79 = cc->MakeCKKSPackedPlaintext(v178_filled);
  const auto& ct254 = cc->EvalMult(ct60, pt79);
  const auto& ct255 = cc->EvalAdd(ct253, ct254);
  v352[4 + 16 * (0)] = ct255;
  std::vector<CiphertextT> v353 = std::move(v352);
  const auto& ct256 = v353[5 + 16 * (0)];
  auto v177_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v177_filled = v177;
  v177_filled.clear();
  v177_filled.reserve(v177_filled_n);
  for (auto i = 0; i < v177_filled_n; ++i) {
    v177_filled.push_back(v177[i % v177.size()]);
  }
  const auto& pt80 = cc->MakeCKKSPackedPlaintext(v177_filled);
  const auto& ct257 = cc->EvalMult(ct, pt80);
  const auto& ct258 = cc->EvalAdd(ct256, ct257);
  v353[5 + 16 * (0)] = ct258;
  std::vector<CiphertextT> v354 = std::move(v353);
  const auto& ct259 = v354[5 + 16 * (0)];
  auto v176_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v176_filled = v176;
  v176_filled.clear();
  v176_filled.reserve(v176_filled_n);
  for (auto i = 0; i < v176_filled_n; ++i) {
    v176_filled.push_back(v176[i % v176.size()]);
  }
  const auto& pt81 = cc->MakeCKKSPackedPlaintext(v176_filled);
  const auto& ct260 = cc->EvalMult(ct4, pt81);
  const auto& ct261 = cc->EvalAdd(ct259, ct260);
  v354[5 + 16 * (0)] = ct261;
  std::vector<CiphertextT> v355 = std::move(v354);
  const auto& ct262 = v355[5 + 16 * (0)];
  auto v175_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v175_filled = v175;
  v175_filled.clear();
  v175_filled.reserve(v175_filled_n);
  for (auto i = 0; i < v175_filled_n; ++i) {
    v175_filled.push_back(v175[i % v175.size()]);
  }
  const auto& pt82 = cc->MakeCKKSPackedPlaintext(v175_filled);
  const auto& ct263 = cc->EvalMult(ct8, pt82);
  const auto& ct264 = cc->EvalAdd(ct262, ct263);
  v355[5 + 16 * (0)] = ct264;
  std::vector<CiphertextT> v356 = std::move(v355);
  const auto& ct265 = v356[5 + 16 * (0)];
  auto v174_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v174_filled = v174;
  v174_filled.clear();
  v174_filled.reserve(v174_filled_n);
  for (auto i = 0; i < v174_filled_n; ++i) {
    v174_filled.push_back(v174[i % v174.size()]);
  }
  const auto& pt83 = cc->MakeCKKSPackedPlaintext(v174_filled);
  const auto& ct266 = cc->EvalMult(ct12, pt83);
  const auto& ct267 = cc->EvalAdd(ct265, ct266);
  v356[5 + 16 * (0)] = ct267;
  std::vector<CiphertextT> v357 = std::move(v356);
  const auto& ct268 = v357[5 + 16 * (0)];
  auto v173_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v173_filled = v173;
  v173_filled.clear();
  v173_filled.reserve(v173_filled_n);
  for (auto i = 0; i < v173_filled_n; ++i) {
    v173_filled.push_back(v173[i % v173.size()]);
  }
  const auto& pt84 = cc->MakeCKKSPackedPlaintext(v173_filled);
  const auto& ct269 = cc->EvalMult(ct16, pt84);
  const auto& ct270 = cc->EvalAdd(ct268, ct269);
  v357[5 + 16 * (0)] = ct270;
  std::vector<CiphertextT> v358 = std::move(v357);
  const auto& ct271 = v358[5 + 16 * (0)];
  auto v172_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v172_filled = v172;
  v172_filled.clear();
  v172_filled.reserve(v172_filled_n);
  for (auto i = 0; i < v172_filled_n; ++i) {
    v172_filled.push_back(v172[i % v172.size()]);
  }
  const auto& pt85 = cc->MakeCKKSPackedPlaintext(v172_filled);
  const auto& ct272 = cc->EvalMult(ct20, pt85);
  const auto& ct273 = cc->EvalAdd(ct271, ct272);
  v358[5 + 16 * (0)] = ct273;
  std::vector<CiphertextT> v359 = std::move(v358);
  const auto& ct274 = v359[5 + 16 * (0)];
  auto v171_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v171_filled = v171;
  v171_filled.clear();
  v171_filled.reserve(v171_filled_n);
  for (auto i = 0; i < v171_filled_n; ++i) {
    v171_filled.push_back(v171[i % v171.size()]);
  }
  const auto& pt86 = cc->MakeCKKSPackedPlaintext(v171_filled);
  const auto& ct275 = cc->EvalMult(ct24, pt86);
  const auto& ct276 = cc->EvalAdd(ct274, ct275);
  v359[5 + 16 * (0)] = ct276;
  std::vector<CiphertextT> v360 = std::move(v359);
  const auto& ct277 = v360[5 + 16 * (0)];
  auto v170_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v170_filled = v170;
  v170_filled.clear();
  v170_filled.reserve(v170_filled_n);
  for (auto i = 0; i < v170_filled_n; ++i) {
    v170_filled.push_back(v170[i % v170.size()]);
  }
  const auto& pt87 = cc->MakeCKKSPackedPlaintext(v170_filled);
  const auto& ct278 = cc->EvalMult(ct28, pt87);
  const auto& ct279 = cc->EvalAdd(ct277, ct278);
  v360[5 + 16 * (0)] = ct279;
  std::vector<CiphertextT> v361 = std::move(v360);
  const auto& ct280 = v361[5 + 16 * (0)];
  auto v169_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v169_filled = v169;
  v169_filled.clear();
  v169_filled.reserve(v169_filled_n);
  for (auto i = 0; i < v169_filled_n; ++i) {
    v169_filled.push_back(v169[i % v169.size()]);
  }
  const auto& pt88 = cc->MakeCKKSPackedPlaintext(v169_filled);
  const auto& ct281 = cc->EvalMult(ct32, pt88);
  const auto& ct282 = cc->EvalAdd(ct280, ct281);
  v361[5 + 16 * (0)] = ct282;
  std::vector<CiphertextT> v362 = std::move(v361);
  const auto& ct283 = v362[5 + 16 * (0)];
  auto v168_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v168_filled = v168;
  v168_filled.clear();
  v168_filled.reserve(v168_filled_n);
  for (auto i = 0; i < v168_filled_n; ++i) {
    v168_filled.push_back(v168[i % v168.size()]);
  }
  const auto& pt89 = cc->MakeCKKSPackedPlaintext(v168_filled);
  const auto& ct284 = cc->EvalMult(ct36, pt89);
  const auto& ct285 = cc->EvalAdd(ct283, ct284);
  v362[5 + 16 * (0)] = ct285;
  std::vector<CiphertextT> v363 = std::move(v362);
  const auto& ct286 = v363[5 + 16 * (0)];
  auto v167_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v167_filled = v167;
  v167_filled.clear();
  v167_filled.reserve(v167_filled_n);
  for (auto i = 0; i < v167_filled_n; ++i) {
    v167_filled.push_back(v167[i % v167.size()]);
  }
  const auto& pt90 = cc->MakeCKKSPackedPlaintext(v167_filled);
  const auto& ct287 = cc->EvalMult(ct40, pt90);
  const auto& ct288 = cc->EvalAdd(ct286, ct287);
  v363[5 + 16 * (0)] = ct288;
  std::vector<CiphertextT> v364 = std::move(v363);
  const auto& ct289 = v364[5 + 16 * (0)];
  auto v166_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v166_filled = v166;
  v166_filled.clear();
  v166_filled.reserve(v166_filled_n);
  for (auto i = 0; i < v166_filled_n; ++i) {
    v166_filled.push_back(v166[i % v166.size()]);
  }
  const auto& pt91 = cc->MakeCKKSPackedPlaintext(v166_filled);
  const auto& ct290 = cc->EvalMult(ct44, pt91);
  const auto& ct291 = cc->EvalAdd(ct289, ct290);
  v364[5 + 16 * (0)] = ct291;
  std::vector<CiphertextT> v365 = std::move(v364);
  const auto& ct292 = v365[5 + 16 * (0)];
  auto v165_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v165_filled = v165;
  v165_filled.clear();
  v165_filled.reserve(v165_filled_n);
  for (auto i = 0; i < v165_filled_n; ++i) {
    v165_filled.push_back(v165[i % v165.size()]);
  }
  const auto& pt92 = cc->MakeCKKSPackedPlaintext(v165_filled);
  const auto& ct293 = cc->EvalMult(ct48, pt92);
  const auto& ct294 = cc->EvalAdd(ct292, ct293);
  v365[5 + 16 * (0)] = ct294;
  std::vector<CiphertextT> v366 = std::move(v365);
  const auto& ct295 = v366[5 + 16 * (0)];
  auto v164_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v164_filled = v164;
  v164_filled.clear();
  v164_filled.reserve(v164_filled_n);
  for (auto i = 0; i < v164_filled_n; ++i) {
    v164_filled.push_back(v164[i % v164.size()]);
  }
  const auto& pt93 = cc->MakeCKKSPackedPlaintext(v164_filled);
  const auto& ct296 = cc->EvalMult(ct52, pt93);
  const auto& ct297 = cc->EvalAdd(ct295, ct296);
  v366[5 + 16 * (0)] = ct297;
  std::vector<CiphertextT> v367 = std::move(v366);
  const auto& ct298 = v367[5 + 16 * (0)];
  auto v163_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v163_filled = v163;
  v163_filled.clear();
  v163_filled.reserve(v163_filled_n);
  for (auto i = 0; i < v163_filled_n; ++i) {
    v163_filled.push_back(v163[i % v163.size()]);
  }
  const auto& pt94 = cc->MakeCKKSPackedPlaintext(v163_filled);
  const auto& ct299 = cc->EvalMult(ct56, pt94);
  const auto& ct300 = cc->EvalAdd(ct298, ct299);
  v367[5 + 16 * (0)] = ct300;
  std::vector<CiphertextT> v368 = std::move(v367);
  const auto& ct301 = v368[5 + 16 * (0)];
  auto v162_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v162_filled = v162;
  v162_filled.clear();
  v162_filled.reserve(v162_filled_n);
  for (auto i = 0; i < v162_filled_n; ++i) {
    v162_filled.push_back(v162[i % v162.size()]);
  }
  const auto& pt95 = cc->MakeCKKSPackedPlaintext(v162_filled);
  const auto& ct302 = cc->EvalMult(ct60, pt95);
  const auto& ct303 = cc->EvalAdd(ct301, ct302);
  v368[5 + 16 * (0)] = ct303;
  std::vector<CiphertextT> v369 = std::move(v368);
  const auto& ct304 = v369[6 + 16 * (0)];
  auto v161_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v161_filled = v161;
  v161_filled.clear();
  v161_filled.reserve(v161_filled_n);
  for (auto i = 0; i < v161_filled_n; ++i) {
    v161_filled.push_back(v161[i % v161.size()]);
  }
  const auto& pt96 = cc->MakeCKKSPackedPlaintext(v161_filled);
  const auto& ct305 = cc->EvalMult(ct, pt96);
  const auto& ct306 = cc->EvalAdd(ct304, ct305);
  v369[6 + 16 * (0)] = ct306;
  std::vector<CiphertextT> v370 = std::move(v369);
  const auto& ct307 = v370[6 + 16 * (0)];
  auto v160_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v160_filled = v160;
  v160_filled.clear();
  v160_filled.reserve(v160_filled_n);
  for (auto i = 0; i < v160_filled_n; ++i) {
    v160_filled.push_back(v160[i % v160.size()]);
  }
  const auto& pt97 = cc->MakeCKKSPackedPlaintext(v160_filled);
  const auto& ct308 = cc->EvalMult(ct4, pt97);
  const auto& ct309 = cc->EvalAdd(ct307, ct308);
  v370[6 + 16 * (0)] = ct309;
  std::vector<CiphertextT> v371 = std::move(v370);
  const auto& ct310 = v371[6 + 16 * (0)];
  auto v159_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v159_filled = v159;
  v159_filled.clear();
  v159_filled.reserve(v159_filled_n);
  for (auto i = 0; i < v159_filled_n; ++i) {
    v159_filled.push_back(v159[i % v159.size()]);
  }
  const auto& pt98 = cc->MakeCKKSPackedPlaintext(v159_filled);
  const auto& ct311 = cc->EvalMult(ct8, pt98);
  const auto& ct312 = cc->EvalAdd(ct310, ct311);
  v371[6 + 16 * (0)] = ct312;
  std::vector<CiphertextT> v372 = std::move(v371);
  const auto& ct313 = v372[6 + 16 * (0)];
  auto v158_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v158_filled = v158;
  v158_filled.clear();
  v158_filled.reserve(v158_filled_n);
  for (auto i = 0; i < v158_filled_n; ++i) {
    v158_filled.push_back(v158[i % v158.size()]);
  }
  const auto& pt99 = cc->MakeCKKSPackedPlaintext(v158_filled);
  const auto& ct314 = cc->EvalMult(ct12, pt99);
  const auto& ct315 = cc->EvalAdd(ct313, ct314);
  v372[6 + 16 * (0)] = ct315;
  std::vector<CiphertextT> v373 = std::move(v372);
  const auto& ct316 = v373[6 + 16 * (0)];
  auto v157_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v157_filled = v157;
  v157_filled.clear();
  v157_filled.reserve(v157_filled_n);
  for (auto i = 0; i < v157_filled_n; ++i) {
    v157_filled.push_back(v157[i % v157.size()]);
  }
  const auto& pt100 = cc->MakeCKKSPackedPlaintext(v157_filled);
  const auto& ct317 = cc->EvalMult(ct16, pt100);
  const auto& ct318 = cc->EvalAdd(ct316, ct317);
  v373[6 + 16 * (0)] = ct318;
  std::vector<CiphertextT> v374 = std::move(v373);
  const auto& ct319 = v374[6 + 16 * (0)];
  auto v156_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v156_filled = v156;
  v156_filled.clear();
  v156_filled.reserve(v156_filled_n);
  for (auto i = 0; i < v156_filled_n; ++i) {
    v156_filled.push_back(v156[i % v156.size()]);
  }
  const auto& pt101 = cc->MakeCKKSPackedPlaintext(v156_filled);
  const auto& ct320 = cc->EvalMult(ct20, pt101);
  const auto& ct321 = cc->EvalAdd(ct319, ct320);
  v374[6 + 16 * (0)] = ct321;
  std::vector<CiphertextT> v375 = std::move(v374);
  const auto& ct322 = v375[6 + 16 * (0)];
  auto v155_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v155_filled = v155;
  v155_filled.clear();
  v155_filled.reserve(v155_filled_n);
  for (auto i = 0; i < v155_filled_n; ++i) {
    v155_filled.push_back(v155[i % v155.size()]);
  }
  const auto& pt102 = cc->MakeCKKSPackedPlaintext(v155_filled);
  const auto& ct323 = cc->EvalMult(ct24, pt102);
  const auto& ct324 = cc->EvalAdd(ct322, ct323);
  v375[6 + 16 * (0)] = ct324;
  std::vector<CiphertextT> v376 = std::move(v375);
  const auto& ct325 = v376[6 + 16 * (0)];
  auto v154_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v154_filled = v154;
  v154_filled.clear();
  v154_filled.reserve(v154_filled_n);
  for (auto i = 0; i < v154_filled_n; ++i) {
    v154_filled.push_back(v154[i % v154.size()]);
  }
  const auto& pt103 = cc->MakeCKKSPackedPlaintext(v154_filled);
  const auto& ct326 = cc->EvalMult(ct28, pt103);
  const auto& ct327 = cc->EvalAdd(ct325, ct326);
  v376[6 + 16 * (0)] = ct327;
  std::vector<CiphertextT> v377 = std::move(v376);
  const auto& ct328 = v377[6 + 16 * (0)];
  auto v153_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v153_filled = v153;
  v153_filled.clear();
  v153_filled.reserve(v153_filled_n);
  for (auto i = 0; i < v153_filled_n; ++i) {
    v153_filled.push_back(v153[i % v153.size()]);
  }
  const auto& pt104 = cc->MakeCKKSPackedPlaintext(v153_filled);
  const auto& ct329 = cc->EvalMult(ct32, pt104);
  const auto& ct330 = cc->EvalAdd(ct328, ct329);
  v377[6 + 16 * (0)] = ct330;
  std::vector<CiphertextT> v378 = std::move(v377);
  const auto& ct331 = v378[6 + 16 * (0)];
  auto v152_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v152_filled = v152;
  v152_filled.clear();
  v152_filled.reserve(v152_filled_n);
  for (auto i = 0; i < v152_filled_n; ++i) {
    v152_filled.push_back(v152[i % v152.size()]);
  }
  const auto& pt105 = cc->MakeCKKSPackedPlaintext(v152_filled);
  const auto& ct332 = cc->EvalMult(ct36, pt105);
  const auto& ct333 = cc->EvalAdd(ct331, ct332);
  v378[6 + 16 * (0)] = ct333;
  std::vector<CiphertextT> v379 = std::move(v378);
  const auto& ct334 = v379[6 + 16 * (0)];
  auto v151_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v151_filled = v151;
  v151_filled.clear();
  v151_filled.reserve(v151_filled_n);
  for (auto i = 0; i < v151_filled_n; ++i) {
    v151_filled.push_back(v151[i % v151.size()]);
  }
  const auto& pt106 = cc->MakeCKKSPackedPlaintext(v151_filled);
  const auto& ct335 = cc->EvalMult(ct40, pt106);
  const auto& ct336 = cc->EvalAdd(ct334, ct335);
  v379[6 + 16 * (0)] = ct336;
  std::vector<CiphertextT> v380 = std::move(v379);
  const auto& ct337 = v380[6 + 16 * (0)];
  auto v150_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v150_filled = v150;
  v150_filled.clear();
  v150_filled.reserve(v150_filled_n);
  for (auto i = 0; i < v150_filled_n; ++i) {
    v150_filled.push_back(v150[i % v150.size()]);
  }
  const auto& pt107 = cc->MakeCKKSPackedPlaintext(v150_filled);
  const auto& ct338 = cc->EvalMult(ct44, pt107);
  const auto& ct339 = cc->EvalAdd(ct337, ct338);
  v380[6 + 16 * (0)] = ct339;
  std::vector<CiphertextT> v381 = std::move(v380);
  const auto& ct340 = v381[6 + 16 * (0)];
  auto v149_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v149_filled = v149;
  v149_filled.clear();
  v149_filled.reserve(v149_filled_n);
  for (auto i = 0; i < v149_filled_n; ++i) {
    v149_filled.push_back(v149[i % v149.size()]);
  }
  const auto& pt108 = cc->MakeCKKSPackedPlaintext(v149_filled);
  const auto& ct341 = cc->EvalMult(ct48, pt108);
  const auto& ct342 = cc->EvalAdd(ct340, ct341);
  v381[6 + 16 * (0)] = ct342;
  std::vector<CiphertextT> v382 = std::move(v381);
  const auto& ct343 = v382[6 + 16 * (0)];
  auto v148_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v148_filled = v148;
  v148_filled.clear();
  v148_filled.reserve(v148_filled_n);
  for (auto i = 0; i < v148_filled_n; ++i) {
    v148_filled.push_back(v148[i % v148.size()]);
  }
  const auto& pt109 = cc->MakeCKKSPackedPlaintext(v148_filled);
  const auto& ct344 = cc->EvalMult(ct52, pt109);
  const auto& ct345 = cc->EvalAdd(ct343, ct344);
  v382[6 + 16 * (0)] = ct345;
  std::vector<CiphertextT> v383 = std::move(v382);
  const auto& ct346 = v383[6 + 16 * (0)];
  auto v147_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v147_filled = v147;
  v147_filled.clear();
  v147_filled.reserve(v147_filled_n);
  for (auto i = 0; i < v147_filled_n; ++i) {
    v147_filled.push_back(v147[i % v147.size()]);
  }
  const auto& pt110 = cc->MakeCKKSPackedPlaintext(v147_filled);
  const auto& ct347 = cc->EvalMult(ct56, pt110);
  const auto& ct348 = cc->EvalAdd(ct346, ct347);
  v383[6 + 16 * (0)] = ct348;
  std::vector<CiphertextT> v384 = std::move(v383);
  const auto& ct349 = v384[6 + 16 * (0)];
  auto v146_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v146_filled = v146;
  v146_filled.clear();
  v146_filled.reserve(v146_filled_n);
  for (auto i = 0; i < v146_filled_n; ++i) {
    v146_filled.push_back(v146[i % v146.size()]);
  }
  const auto& pt111 = cc->MakeCKKSPackedPlaintext(v146_filled);
  const auto& ct350 = cc->EvalMult(ct60, pt111);
  const auto& ct351 = cc->EvalAdd(ct349, ct350);
  v384[6 + 16 * (0)] = ct351;
  std::vector<CiphertextT> v385 = std::move(v384);
  const auto& ct352 = v385[7 + 16 * (0)];
  auto v145_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v145_filled = v145;
  v145_filled.clear();
  v145_filled.reserve(v145_filled_n);
  for (auto i = 0; i < v145_filled_n; ++i) {
    v145_filled.push_back(v145[i % v145.size()]);
  }
  const auto& pt112 = cc->MakeCKKSPackedPlaintext(v145_filled);
  const auto& ct353 = cc->EvalMult(ct, pt112);
  const auto& ct354 = cc->EvalAdd(ct352, ct353);
  v385[7 + 16 * (0)] = ct354;
  std::vector<CiphertextT> v386 = std::move(v385);
  const auto& ct355 = v386[7 + 16 * (0)];
  auto v144_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v144_filled = v144;
  v144_filled.clear();
  v144_filled.reserve(v144_filled_n);
  for (auto i = 0; i < v144_filled_n; ++i) {
    v144_filled.push_back(v144[i % v144.size()]);
  }
  const auto& pt113 = cc->MakeCKKSPackedPlaintext(v144_filled);
  const auto& ct356 = cc->EvalMult(ct4, pt113);
  const auto& ct357 = cc->EvalAdd(ct355, ct356);
  v386[7 + 16 * (0)] = ct357;
  std::vector<CiphertextT> v387 = std::move(v386);
  const auto& ct358 = v387[7 + 16 * (0)];
  auto v143_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v143_filled = v143;
  v143_filled.clear();
  v143_filled.reserve(v143_filled_n);
  for (auto i = 0; i < v143_filled_n; ++i) {
    v143_filled.push_back(v143[i % v143.size()]);
  }
  const auto& pt114 = cc->MakeCKKSPackedPlaintext(v143_filled);
  const auto& ct359 = cc->EvalMult(ct8, pt114);
  const auto& ct360 = cc->EvalAdd(ct358, ct359);
  v387[7 + 16 * (0)] = ct360;
  std::vector<CiphertextT> v388 = std::move(v387);
  const auto& ct361 = v388[7 + 16 * (0)];
  auto v142_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v142_filled = v142;
  v142_filled.clear();
  v142_filled.reserve(v142_filled_n);
  for (auto i = 0; i < v142_filled_n; ++i) {
    v142_filled.push_back(v142[i % v142.size()]);
  }
  const auto& pt115 = cc->MakeCKKSPackedPlaintext(v142_filled);
  const auto& ct362 = cc->EvalMult(ct12, pt115);
  const auto& ct363 = cc->EvalAdd(ct361, ct362);
  v388[7 + 16 * (0)] = ct363;
  std::vector<CiphertextT> v389 = std::move(v388);
  const auto& ct364 = v389[7 + 16 * (0)];
  auto v141_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v141_filled = v141;
  v141_filled.clear();
  v141_filled.reserve(v141_filled_n);
  for (auto i = 0; i < v141_filled_n; ++i) {
    v141_filled.push_back(v141[i % v141.size()]);
  }
  const auto& pt116 = cc->MakeCKKSPackedPlaintext(v141_filled);
  const auto& ct365 = cc->EvalMult(ct16, pt116);
  const auto& ct366 = cc->EvalAdd(ct364, ct365);
  v389[7 + 16 * (0)] = ct366;
  std::vector<CiphertextT> v390 = std::move(v389);
  const auto& ct367 = v390[7 + 16 * (0)];
  auto v140_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v140_filled = v140;
  v140_filled.clear();
  v140_filled.reserve(v140_filled_n);
  for (auto i = 0; i < v140_filled_n; ++i) {
    v140_filled.push_back(v140[i % v140.size()]);
  }
  const auto& pt117 = cc->MakeCKKSPackedPlaintext(v140_filled);
  const auto& ct368 = cc->EvalMult(ct20, pt117);
  const auto& ct369 = cc->EvalAdd(ct367, ct368);
  v390[7 + 16 * (0)] = ct369;
  std::vector<CiphertextT> v391 = std::move(v390);
  const auto& ct370 = v391[7 + 16 * (0)];
  auto v139_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v139_filled = v139;
  v139_filled.clear();
  v139_filled.reserve(v139_filled_n);
  for (auto i = 0; i < v139_filled_n; ++i) {
    v139_filled.push_back(v139[i % v139.size()]);
  }
  const auto& pt118 = cc->MakeCKKSPackedPlaintext(v139_filled);
  const auto& ct371 = cc->EvalMult(ct24, pt118);
  const auto& ct372 = cc->EvalAdd(ct370, ct371);
  v391[7 + 16 * (0)] = ct372;
  std::vector<CiphertextT> v392 = std::move(v391);
  const auto& ct373 = v392[7 + 16 * (0)];
  auto v138_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v138_filled = v138;
  v138_filled.clear();
  v138_filled.reserve(v138_filled_n);
  for (auto i = 0; i < v138_filled_n; ++i) {
    v138_filled.push_back(v138[i % v138.size()]);
  }
  const auto& pt119 = cc->MakeCKKSPackedPlaintext(v138_filled);
  const auto& ct374 = cc->EvalMult(ct28, pt119);
  const auto& ct375 = cc->EvalAdd(ct373, ct374);
  v392[7 + 16 * (0)] = ct375;
  std::vector<CiphertextT> v393 = std::move(v392);
  const auto& ct376 = v393[7 + 16 * (0)];
  auto v137_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v137_filled = v137;
  v137_filled.clear();
  v137_filled.reserve(v137_filled_n);
  for (auto i = 0; i < v137_filled_n; ++i) {
    v137_filled.push_back(v137[i % v137.size()]);
  }
  const auto& pt120 = cc->MakeCKKSPackedPlaintext(v137_filled);
  const auto& ct377 = cc->EvalMult(ct32, pt120);
  const auto& ct378 = cc->EvalAdd(ct376, ct377);
  v393[7 + 16 * (0)] = ct378;
  std::vector<CiphertextT> v394 = std::move(v393);
  const auto& ct379 = v394[7 + 16 * (0)];
  auto v136_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v136_filled = v136;
  v136_filled.clear();
  v136_filled.reserve(v136_filled_n);
  for (auto i = 0; i < v136_filled_n; ++i) {
    v136_filled.push_back(v136[i % v136.size()]);
  }
  const auto& pt121 = cc->MakeCKKSPackedPlaintext(v136_filled);
  const auto& ct380 = cc->EvalMult(ct36, pt121);
  const auto& ct381 = cc->EvalAdd(ct379, ct380);
  v394[7 + 16 * (0)] = ct381;
  std::vector<CiphertextT> v395 = std::move(v394);
  const auto& ct382 = v395[7 + 16 * (0)];
  auto v135_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v135_filled = v135;
  v135_filled.clear();
  v135_filled.reserve(v135_filled_n);
  for (auto i = 0; i < v135_filled_n; ++i) {
    v135_filled.push_back(v135[i % v135.size()]);
  }
  const auto& pt122 = cc->MakeCKKSPackedPlaintext(v135_filled);
  const auto& ct383 = cc->EvalMult(ct40, pt122);
  const auto& ct384 = cc->EvalAdd(ct382, ct383);
  v395[7 + 16 * (0)] = ct384;
  std::vector<CiphertextT> v396 = std::move(v395);
  const auto& ct385 = v396[7 + 16 * (0)];
  auto v134_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v134_filled = v134;
  v134_filled.clear();
  v134_filled.reserve(v134_filled_n);
  for (auto i = 0; i < v134_filled_n; ++i) {
    v134_filled.push_back(v134[i % v134.size()]);
  }
  const auto& pt123 = cc->MakeCKKSPackedPlaintext(v134_filled);
  const auto& ct386 = cc->EvalMult(ct44, pt123);
  const auto& ct387 = cc->EvalAdd(ct385, ct386);
  v396[7 + 16 * (0)] = ct387;
  std::vector<CiphertextT> v397 = std::move(v396);
  const auto& ct388 = v397[7 + 16 * (0)];
  auto v133_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v133_filled = v133;
  v133_filled.clear();
  v133_filled.reserve(v133_filled_n);
  for (auto i = 0; i < v133_filled_n; ++i) {
    v133_filled.push_back(v133[i % v133.size()]);
  }
  const auto& pt124 = cc->MakeCKKSPackedPlaintext(v133_filled);
  const auto& ct389 = cc->EvalMult(ct48, pt124);
  const auto& ct390 = cc->EvalAdd(ct388, ct389);
  v397[7 + 16 * (0)] = ct390;
  std::vector<CiphertextT> v398 = std::move(v397);
  const auto& ct391 = v398[7 + 16 * (0)];
  auto v132_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v132_filled = v132;
  v132_filled.clear();
  v132_filled.reserve(v132_filled_n);
  for (auto i = 0; i < v132_filled_n; ++i) {
    v132_filled.push_back(v132[i % v132.size()]);
  }
  const auto& pt125 = cc->MakeCKKSPackedPlaintext(v132_filled);
  const auto& ct392 = cc->EvalMult(ct52, pt125);
  const auto& ct393 = cc->EvalAdd(ct391, ct392);
  v398[7 + 16 * (0)] = ct393;
  std::vector<CiphertextT> v399 = std::move(v398);
  const auto& ct394 = v399[7 + 16 * (0)];
  auto v131_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v131_filled = v131;
  v131_filled.clear();
  v131_filled.reserve(v131_filled_n);
  for (auto i = 0; i < v131_filled_n; ++i) {
    v131_filled.push_back(v131[i % v131.size()]);
  }
  const auto& pt126 = cc->MakeCKKSPackedPlaintext(v131_filled);
  const auto& ct395 = cc->EvalMult(ct56, pt126);
  const auto& ct396 = cc->EvalAdd(ct394, ct395);
  v399[7 + 16 * (0)] = ct396;
  std::vector<CiphertextT> v400 = std::move(v399);
  const auto& ct397 = v400[7 + 16 * (0)];
  auto v130_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v130_filled = v130;
  v130_filled.clear();
  v130_filled.reserve(v130_filled_n);
  for (auto i = 0; i < v130_filled_n; ++i) {
    v130_filled.push_back(v130[i % v130.size()]);
  }
  const auto& pt127 = cc->MakeCKKSPackedPlaintext(v130_filled);
  const auto& ct398 = cc->EvalMult(ct60, pt127);
  const auto& ct399 = cc->EvalAdd(ct397, ct398);
  v400[7 + 16 * (0)] = ct399;
  std::vector<CiphertextT> v401 = std::move(v400);
  const auto& ct400 = v401[8 + 16 * (0)];
  auto v129_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v129_filled = v129;
  v129_filled.clear();
  v129_filled.reserve(v129_filled_n);
  for (auto i = 0; i < v129_filled_n; ++i) {
    v129_filled.push_back(v129[i % v129.size()]);
  }
  const auto& pt128 = cc->MakeCKKSPackedPlaintext(v129_filled);
  const auto& ct401 = cc->EvalMult(ct, pt128);
  const auto& ct402 = cc->EvalAdd(ct400, ct401);
  v401[8 + 16 * (0)] = ct402;
  std::vector<CiphertextT> v402 = std::move(v401);
  const auto& ct403 = v402[8 + 16 * (0)];
  auto v128_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v128_filled = v128;
  v128_filled.clear();
  v128_filled.reserve(v128_filled_n);
  for (auto i = 0; i < v128_filled_n; ++i) {
    v128_filled.push_back(v128[i % v128.size()]);
  }
  const auto& pt129 = cc->MakeCKKSPackedPlaintext(v128_filled);
  const auto& ct404 = cc->EvalMult(ct4, pt129);
  const auto& ct405 = cc->EvalAdd(ct403, ct404);
  v402[8 + 16 * (0)] = ct405;
  std::vector<CiphertextT> v403 = std::move(v402);
  const auto& ct406 = v403[8 + 16 * (0)];
  auto v127_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v127_filled = v127;
  v127_filled.clear();
  v127_filled.reserve(v127_filled_n);
  for (auto i = 0; i < v127_filled_n; ++i) {
    v127_filled.push_back(v127[i % v127.size()]);
  }
  const auto& pt130 = cc->MakeCKKSPackedPlaintext(v127_filled);
  const auto& ct407 = cc->EvalMult(ct8, pt130);
  const auto& ct408 = cc->EvalAdd(ct406, ct407);
  v403[8 + 16 * (0)] = ct408;
  std::vector<CiphertextT> v404 = std::move(v403);
  const auto& ct409 = v404[8 + 16 * (0)];
  auto v126_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v126_filled = v126;
  v126_filled.clear();
  v126_filled.reserve(v126_filled_n);
  for (auto i = 0; i < v126_filled_n; ++i) {
    v126_filled.push_back(v126[i % v126.size()]);
  }
  const auto& pt131 = cc->MakeCKKSPackedPlaintext(v126_filled);
  const auto& ct410 = cc->EvalMult(ct12, pt131);
  const auto& ct411 = cc->EvalAdd(ct409, ct410);
  v404[8 + 16 * (0)] = ct411;
  std::vector<CiphertextT> v405 = std::move(v404);
  const auto& ct412 = v405[8 + 16 * (0)];
  auto v125_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v125_filled = v125;
  v125_filled.clear();
  v125_filled.reserve(v125_filled_n);
  for (auto i = 0; i < v125_filled_n; ++i) {
    v125_filled.push_back(v125[i % v125.size()]);
  }
  const auto& pt132 = cc->MakeCKKSPackedPlaintext(v125_filled);
  const auto& ct413 = cc->EvalMult(ct16, pt132);
  const auto& ct414 = cc->EvalAdd(ct412, ct413);
  v405[8 + 16 * (0)] = ct414;
  std::vector<CiphertextT> v406 = std::move(v405);
  const auto& ct415 = v406[8 + 16 * (0)];
  auto v124_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v124_filled = v124;
  v124_filled.clear();
  v124_filled.reserve(v124_filled_n);
  for (auto i = 0; i < v124_filled_n; ++i) {
    v124_filled.push_back(v124[i % v124.size()]);
  }
  const auto& pt133 = cc->MakeCKKSPackedPlaintext(v124_filled);
  const auto& ct416 = cc->EvalMult(ct20, pt133);
  const auto& ct417 = cc->EvalAdd(ct415, ct416);
  v406[8 + 16 * (0)] = ct417;
  std::vector<CiphertextT> v407 = std::move(v406);
  const auto& ct418 = v407[8 + 16 * (0)];
  auto v123_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v123_filled = v123;
  v123_filled.clear();
  v123_filled.reserve(v123_filled_n);
  for (auto i = 0; i < v123_filled_n; ++i) {
    v123_filled.push_back(v123[i % v123.size()]);
  }
  const auto& pt134 = cc->MakeCKKSPackedPlaintext(v123_filled);
  const auto& ct419 = cc->EvalMult(ct24, pt134);
  const auto& ct420 = cc->EvalAdd(ct418, ct419);
  v407[8 + 16 * (0)] = ct420;
  std::vector<CiphertextT> v408 = std::move(v407);
  const auto& ct421 = v408[8 + 16 * (0)];
  auto v122_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v122_filled = v122;
  v122_filled.clear();
  v122_filled.reserve(v122_filled_n);
  for (auto i = 0; i < v122_filled_n; ++i) {
    v122_filled.push_back(v122[i % v122.size()]);
  }
  const auto& pt135 = cc->MakeCKKSPackedPlaintext(v122_filled);
  const auto& ct422 = cc->EvalMult(ct28, pt135);
  const auto& ct423 = cc->EvalAdd(ct421, ct422);
  v408[8 + 16 * (0)] = ct423;
  std::vector<CiphertextT> v409 = std::move(v408);
  const auto& ct424 = v409[8 + 16 * (0)];
  auto v121_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v121_filled = v121;
  v121_filled.clear();
  v121_filled.reserve(v121_filled_n);
  for (auto i = 0; i < v121_filled_n; ++i) {
    v121_filled.push_back(v121[i % v121.size()]);
  }
  const auto& pt136 = cc->MakeCKKSPackedPlaintext(v121_filled);
  const auto& ct425 = cc->EvalMult(ct32, pt136);
  const auto& ct426 = cc->EvalAdd(ct424, ct425);
  v409[8 + 16 * (0)] = ct426;
  std::vector<CiphertextT> v410 = std::move(v409);
  const auto& ct427 = v410[8 + 16 * (0)];
  auto v120_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v120_filled = v120;
  v120_filled.clear();
  v120_filled.reserve(v120_filled_n);
  for (auto i = 0; i < v120_filled_n; ++i) {
    v120_filled.push_back(v120[i % v120.size()]);
  }
  const auto& pt137 = cc->MakeCKKSPackedPlaintext(v120_filled);
  const auto& ct428 = cc->EvalMult(ct36, pt137);
  const auto& ct429 = cc->EvalAdd(ct427, ct428);
  v410[8 + 16 * (0)] = ct429;
  std::vector<CiphertextT> v411 = std::move(v410);
  const auto& ct430 = v411[8 + 16 * (0)];
  auto v119_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v119_filled = v119;
  v119_filled.clear();
  v119_filled.reserve(v119_filled_n);
  for (auto i = 0; i < v119_filled_n; ++i) {
    v119_filled.push_back(v119[i % v119.size()]);
  }
  const auto& pt138 = cc->MakeCKKSPackedPlaintext(v119_filled);
  const auto& ct431 = cc->EvalMult(ct40, pt138);
  const auto& ct432 = cc->EvalAdd(ct430, ct431);
  v411[8 + 16 * (0)] = ct432;
  std::vector<CiphertextT> v412 = std::move(v411);
  const auto& ct433 = v412[8 + 16 * (0)];
  auto v118_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v118_filled = v118;
  v118_filled.clear();
  v118_filled.reserve(v118_filled_n);
  for (auto i = 0; i < v118_filled_n; ++i) {
    v118_filled.push_back(v118[i % v118.size()]);
  }
  const auto& pt139 = cc->MakeCKKSPackedPlaintext(v118_filled);
  const auto& ct434 = cc->EvalMult(ct44, pt139);
  const auto& ct435 = cc->EvalAdd(ct433, ct434);
  v412[8 + 16 * (0)] = ct435;
  std::vector<CiphertextT> v413 = std::move(v412);
  const auto& ct436 = v413[8 + 16 * (0)];
  auto v117_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v117_filled = v117;
  v117_filled.clear();
  v117_filled.reserve(v117_filled_n);
  for (auto i = 0; i < v117_filled_n; ++i) {
    v117_filled.push_back(v117[i % v117.size()]);
  }
  const auto& pt140 = cc->MakeCKKSPackedPlaintext(v117_filled);
  const auto& ct437 = cc->EvalMult(ct48, pt140);
  const auto& ct438 = cc->EvalAdd(ct436, ct437);
  v413[8 + 16 * (0)] = ct438;
  std::vector<CiphertextT> v414 = std::move(v413);
  const auto& ct439 = v414[8 + 16 * (0)];
  auto v116_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v116_filled = v116;
  v116_filled.clear();
  v116_filled.reserve(v116_filled_n);
  for (auto i = 0; i < v116_filled_n; ++i) {
    v116_filled.push_back(v116[i % v116.size()]);
  }
  const auto& pt141 = cc->MakeCKKSPackedPlaintext(v116_filled);
  const auto& ct440 = cc->EvalMult(ct52, pt141);
  const auto& ct441 = cc->EvalAdd(ct439, ct440);
  v414[8 + 16 * (0)] = ct441;
  std::vector<CiphertextT> v415 = std::move(v414);
  const auto& ct442 = v415[8 + 16 * (0)];
  auto v115_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v115_filled = v115;
  v115_filled.clear();
  v115_filled.reserve(v115_filled_n);
  for (auto i = 0; i < v115_filled_n; ++i) {
    v115_filled.push_back(v115[i % v115.size()]);
  }
  const auto& pt142 = cc->MakeCKKSPackedPlaintext(v115_filled);
  const auto& ct443 = cc->EvalMult(ct56, pt142);
  const auto& ct444 = cc->EvalAdd(ct442, ct443);
  v415[8 + 16 * (0)] = ct444;
  std::vector<CiphertextT> v416 = std::move(v415);
  const auto& ct445 = v416[8 + 16 * (0)];
  auto v114_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v114_filled = v114;
  v114_filled.clear();
  v114_filled.reserve(v114_filled_n);
  for (auto i = 0; i < v114_filled_n; ++i) {
    v114_filled.push_back(v114[i % v114.size()]);
  }
  const auto& pt143 = cc->MakeCKKSPackedPlaintext(v114_filled);
  const auto& ct446 = cc->EvalMult(ct60, pt143);
  const auto& ct447 = cc->EvalAdd(ct445, ct446);
  v416[8 + 16 * (0)] = ct447;
  std::vector<CiphertextT> v417 = std::move(v416);
  const auto& ct448 = v417[9 + 16 * (0)];
  auto v113_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v113_filled = v113;
  v113_filled.clear();
  v113_filled.reserve(v113_filled_n);
  for (auto i = 0; i < v113_filled_n; ++i) {
    v113_filled.push_back(v113[i % v113.size()]);
  }
  const auto& pt144 = cc->MakeCKKSPackedPlaintext(v113_filled);
  const auto& ct449 = cc->EvalMult(ct, pt144);
  const auto& ct450 = cc->EvalAdd(ct448, ct449);
  v417[9 + 16 * (0)] = ct450;
  std::vector<CiphertextT> v418 = std::move(v417);
  const auto& ct451 = v418[9 + 16 * (0)];
  auto v112_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v112_filled = v112;
  v112_filled.clear();
  v112_filled.reserve(v112_filled_n);
  for (auto i = 0; i < v112_filled_n; ++i) {
    v112_filled.push_back(v112[i % v112.size()]);
  }
  const auto& pt145 = cc->MakeCKKSPackedPlaintext(v112_filled);
  const auto& ct452 = cc->EvalMult(ct4, pt145);
  const auto& ct453 = cc->EvalAdd(ct451, ct452);
  v418[9 + 16 * (0)] = ct453;
  std::vector<CiphertextT> v419 = std::move(v418);
  const auto& ct454 = v419[9 + 16 * (0)];
  auto v111_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v111_filled = v111;
  v111_filled.clear();
  v111_filled.reserve(v111_filled_n);
  for (auto i = 0; i < v111_filled_n; ++i) {
    v111_filled.push_back(v111[i % v111.size()]);
  }
  const auto& pt146 = cc->MakeCKKSPackedPlaintext(v111_filled);
  const auto& ct455 = cc->EvalMult(ct8, pt146);
  const auto& ct456 = cc->EvalAdd(ct454, ct455);
  v419[9 + 16 * (0)] = ct456;
  std::vector<CiphertextT> v420 = std::move(v419);
  const auto& ct457 = v420[9 + 16 * (0)];
  auto v110_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v110_filled = v110;
  v110_filled.clear();
  v110_filled.reserve(v110_filled_n);
  for (auto i = 0; i < v110_filled_n; ++i) {
    v110_filled.push_back(v110[i % v110.size()]);
  }
  const auto& pt147 = cc->MakeCKKSPackedPlaintext(v110_filled);
  const auto& ct458 = cc->EvalMult(ct12, pt147);
  const auto& ct459 = cc->EvalAdd(ct457, ct458);
  v420[9 + 16 * (0)] = ct459;
  std::vector<CiphertextT> v421 = std::move(v420);
  const auto& ct460 = v421[9 + 16 * (0)];
  auto v109_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v109_filled = v109;
  v109_filled.clear();
  v109_filled.reserve(v109_filled_n);
  for (auto i = 0; i < v109_filled_n; ++i) {
    v109_filled.push_back(v109[i % v109.size()]);
  }
  const auto& pt148 = cc->MakeCKKSPackedPlaintext(v109_filled);
  const auto& ct461 = cc->EvalMult(ct16, pt148);
  const auto& ct462 = cc->EvalAdd(ct460, ct461);
  v421[9 + 16 * (0)] = ct462;
  std::vector<CiphertextT> v422 = std::move(v421);
  const auto& ct463 = v422[9 + 16 * (0)];
  auto v108_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v108_filled = v108;
  v108_filled.clear();
  v108_filled.reserve(v108_filled_n);
  for (auto i = 0; i < v108_filled_n; ++i) {
    v108_filled.push_back(v108[i % v108.size()]);
  }
  const auto& pt149 = cc->MakeCKKSPackedPlaintext(v108_filled);
  const auto& ct464 = cc->EvalMult(ct20, pt149);
  const auto& ct465 = cc->EvalAdd(ct463, ct464);
  v422[9 + 16 * (0)] = ct465;
  std::vector<CiphertextT> v423 = std::move(v422);
  const auto& ct466 = v423[9 + 16 * (0)];
  auto v107_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v107_filled = v107;
  v107_filled.clear();
  v107_filled.reserve(v107_filled_n);
  for (auto i = 0; i < v107_filled_n; ++i) {
    v107_filled.push_back(v107[i % v107.size()]);
  }
  const auto& pt150 = cc->MakeCKKSPackedPlaintext(v107_filled);
  const auto& ct467 = cc->EvalMult(ct24, pt150);
  const auto& ct468 = cc->EvalAdd(ct466, ct467);
  v423[9 + 16 * (0)] = ct468;
  std::vector<CiphertextT> v424 = std::move(v423);
  const auto& ct469 = v424[9 + 16 * (0)];
  auto v106_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v106_filled = v106;
  v106_filled.clear();
  v106_filled.reserve(v106_filled_n);
  for (auto i = 0; i < v106_filled_n; ++i) {
    v106_filled.push_back(v106[i % v106.size()]);
  }
  const auto& pt151 = cc->MakeCKKSPackedPlaintext(v106_filled);
  const auto& ct470 = cc->EvalMult(ct28, pt151);
  const auto& ct471 = cc->EvalAdd(ct469, ct470);
  v424[9 + 16 * (0)] = ct471;
  std::vector<CiphertextT> v425 = std::move(v424);
  const auto& ct472 = v425[9 + 16 * (0)];
  auto v105_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v105_filled = v105;
  v105_filled.clear();
  v105_filled.reserve(v105_filled_n);
  for (auto i = 0; i < v105_filled_n; ++i) {
    v105_filled.push_back(v105[i % v105.size()]);
  }
  const auto& pt152 = cc->MakeCKKSPackedPlaintext(v105_filled);
  const auto& ct473 = cc->EvalMult(ct32, pt152);
  const auto& ct474 = cc->EvalAdd(ct472, ct473);
  v425[9 + 16 * (0)] = ct474;
  std::vector<CiphertextT> v426 = std::move(v425);
  const auto& ct475 = v426[9 + 16 * (0)];
  auto v104_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v104_filled = v104;
  v104_filled.clear();
  v104_filled.reserve(v104_filled_n);
  for (auto i = 0; i < v104_filled_n; ++i) {
    v104_filled.push_back(v104[i % v104.size()]);
  }
  const auto& pt153 = cc->MakeCKKSPackedPlaintext(v104_filled);
  const auto& ct476 = cc->EvalMult(ct36, pt153);
  const auto& ct477 = cc->EvalAdd(ct475, ct476);
  v426[9 + 16 * (0)] = ct477;
  std::vector<CiphertextT> v427 = std::move(v426);
  const auto& ct478 = v427[9 + 16 * (0)];
  auto v103_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v103_filled = v103;
  v103_filled.clear();
  v103_filled.reserve(v103_filled_n);
  for (auto i = 0; i < v103_filled_n; ++i) {
    v103_filled.push_back(v103[i % v103.size()]);
  }
  const auto& pt154 = cc->MakeCKKSPackedPlaintext(v103_filled);
  const auto& ct479 = cc->EvalMult(ct40, pt154);
  const auto& ct480 = cc->EvalAdd(ct478, ct479);
  v427[9 + 16 * (0)] = ct480;
  std::vector<CiphertextT> v428 = std::move(v427);
  const auto& ct481 = v428[9 + 16 * (0)];
  auto v102_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v102_filled = v102;
  v102_filled.clear();
  v102_filled.reserve(v102_filled_n);
  for (auto i = 0; i < v102_filled_n; ++i) {
    v102_filled.push_back(v102[i % v102.size()]);
  }
  const auto& pt155 = cc->MakeCKKSPackedPlaintext(v102_filled);
  const auto& ct482 = cc->EvalMult(ct44, pt155);
  const auto& ct483 = cc->EvalAdd(ct481, ct482);
  v428[9 + 16 * (0)] = ct483;
  std::vector<CiphertextT> v429 = std::move(v428);
  const auto& ct484 = v429[9 + 16 * (0)];
  auto v101_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v101_filled = v101;
  v101_filled.clear();
  v101_filled.reserve(v101_filled_n);
  for (auto i = 0; i < v101_filled_n; ++i) {
    v101_filled.push_back(v101[i % v101.size()]);
  }
  const auto& pt156 = cc->MakeCKKSPackedPlaintext(v101_filled);
  const auto& ct485 = cc->EvalMult(ct48, pt156);
  const auto& ct486 = cc->EvalAdd(ct484, ct485);
  v429[9 + 16 * (0)] = ct486;
  std::vector<CiphertextT> v430 = std::move(v429);
  const auto& ct487 = v430[9 + 16 * (0)];
  auto v100_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v100_filled = v100;
  v100_filled.clear();
  v100_filled.reserve(v100_filled_n);
  for (auto i = 0; i < v100_filled_n; ++i) {
    v100_filled.push_back(v100[i % v100.size()]);
  }
  const auto& pt157 = cc->MakeCKKSPackedPlaintext(v100_filled);
  const auto& ct488 = cc->EvalMult(ct52, pt157);
  const auto& ct489 = cc->EvalAdd(ct487, ct488);
  v430[9 + 16 * (0)] = ct489;
  std::vector<CiphertextT> v431 = std::move(v430);
  const auto& ct490 = v431[9 + 16 * (0)];
  auto v99_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v99_filled = v99;
  v99_filled.clear();
  v99_filled.reserve(v99_filled_n);
  for (auto i = 0; i < v99_filled_n; ++i) {
    v99_filled.push_back(v99[i % v99.size()]);
  }
  const auto& pt158 = cc->MakeCKKSPackedPlaintext(v99_filled);
  const auto& ct491 = cc->EvalMult(ct56, pt158);
  const auto& ct492 = cc->EvalAdd(ct490, ct491);
  v431[9 + 16 * (0)] = ct492;
  std::vector<CiphertextT> v432 = std::move(v431);
  const auto& ct493 = v432[9 + 16 * (0)];
  auto v98_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v98_filled = v98;
  v98_filled.clear();
  v98_filled.reserve(v98_filled_n);
  for (auto i = 0; i < v98_filled_n; ++i) {
    v98_filled.push_back(v98[i % v98.size()]);
  }
  const auto& pt159 = cc->MakeCKKSPackedPlaintext(v98_filled);
  const auto& ct494 = cc->EvalMult(ct60, pt159);
  const auto& ct495 = cc->EvalAdd(ct493, ct494);
  v432[9 + 16 * (0)] = ct495;
  std::vector<CiphertextT> v433 = std::move(v432);
  const auto& ct496 = v433[10 + 16 * (0)];
  auto v97_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v97_filled = v97;
  v97_filled.clear();
  v97_filled.reserve(v97_filled_n);
  for (auto i = 0; i < v97_filled_n; ++i) {
    v97_filled.push_back(v97[i % v97.size()]);
  }
  const auto& pt160 = cc->MakeCKKSPackedPlaintext(v97_filled);
  const auto& ct497 = cc->EvalMult(ct, pt160);
  const auto& ct498 = cc->EvalAdd(ct496, ct497);
  v433[10 + 16 * (0)] = ct498;
  std::vector<CiphertextT> v434 = std::move(v433);
  const auto& ct499 = v434[10 + 16 * (0)];
  auto v96_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v96_filled = v96;
  v96_filled.clear();
  v96_filled.reserve(v96_filled_n);
  for (auto i = 0; i < v96_filled_n; ++i) {
    v96_filled.push_back(v96[i % v96.size()]);
  }
  const auto& pt161 = cc->MakeCKKSPackedPlaintext(v96_filled);
  const auto& ct500 = cc->EvalMult(ct4, pt161);
  const auto& ct501 = cc->EvalAdd(ct499, ct500);
  v434[10 + 16 * (0)] = ct501;
  std::vector<CiphertextT> v435 = std::move(v434);
  const auto& ct502 = v435[10 + 16 * (0)];
  auto v95_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v95_filled = v95;
  v95_filled.clear();
  v95_filled.reserve(v95_filled_n);
  for (auto i = 0; i < v95_filled_n; ++i) {
    v95_filled.push_back(v95[i % v95.size()]);
  }
  const auto& pt162 = cc->MakeCKKSPackedPlaintext(v95_filled);
  const auto& ct503 = cc->EvalMult(ct8, pt162);
  const auto& ct504 = cc->EvalAdd(ct502, ct503);
  v435[10 + 16 * (0)] = ct504;
  std::vector<CiphertextT> v436 = std::move(v435);
  const auto& ct505 = v436[10 + 16 * (0)];
  auto v94_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v94_filled = v94;
  v94_filled.clear();
  v94_filled.reserve(v94_filled_n);
  for (auto i = 0; i < v94_filled_n; ++i) {
    v94_filled.push_back(v94[i % v94.size()]);
  }
  const auto& pt163 = cc->MakeCKKSPackedPlaintext(v94_filled);
  const auto& ct506 = cc->EvalMult(ct12, pt163);
  const auto& ct507 = cc->EvalAdd(ct505, ct506);
  v436[10 + 16 * (0)] = ct507;
  std::vector<CiphertextT> v437 = std::move(v436);
  const auto& ct508 = v437[10 + 16 * (0)];
  auto v93_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v93_filled = v93;
  v93_filled.clear();
  v93_filled.reserve(v93_filled_n);
  for (auto i = 0; i < v93_filled_n; ++i) {
    v93_filled.push_back(v93[i % v93.size()]);
  }
  const auto& pt164 = cc->MakeCKKSPackedPlaintext(v93_filled);
  const auto& ct509 = cc->EvalMult(ct16, pt164);
  const auto& ct510 = cc->EvalAdd(ct508, ct509);
  v437[10 + 16 * (0)] = ct510;
  std::vector<CiphertextT> v438 = std::move(v437);
  const auto& ct511 = v438[10 + 16 * (0)];
  auto v92_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v92_filled = v92;
  v92_filled.clear();
  v92_filled.reserve(v92_filled_n);
  for (auto i = 0; i < v92_filled_n; ++i) {
    v92_filled.push_back(v92[i % v92.size()]);
  }
  const auto& pt165 = cc->MakeCKKSPackedPlaintext(v92_filled);
  const auto& ct512 = cc->EvalMult(ct20, pt165);
  const auto& ct513 = cc->EvalAdd(ct511, ct512);
  v438[10 + 16 * (0)] = ct513;
  std::vector<CiphertextT> v439 = std::move(v438);
  const auto& ct514 = v439[10 + 16 * (0)];
  auto v91_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v91_filled = v91;
  v91_filled.clear();
  v91_filled.reserve(v91_filled_n);
  for (auto i = 0; i < v91_filled_n; ++i) {
    v91_filled.push_back(v91[i % v91.size()]);
  }
  const auto& pt166 = cc->MakeCKKSPackedPlaintext(v91_filled);
  const auto& ct515 = cc->EvalMult(ct24, pt166);
  const auto& ct516 = cc->EvalAdd(ct514, ct515);
  v439[10 + 16 * (0)] = ct516;
  std::vector<CiphertextT> v440 = std::move(v439);
  const auto& ct517 = v440[10 + 16 * (0)];
  auto v90_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v90_filled = v90;
  v90_filled.clear();
  v90_filled.reserve(v90_filled_n);
  for (auto i = 0; i < v90_filled_n; ++i) {
    v90_filled.push_back(v90[i % v90.size()]);
  }
  const auto& pt167 = cc->MakeCKKSPackedPlaintext(v90_filled);
  const auto& ct518 = cc->EvalMult(ct28, pt167);
  const auto& ct519 = cc->EvalAdd(ct517, ct518);
  v440[10 + 16 * (0)] = ct519;
  std::vector<CiphertextT> v441 = std::move(v440);
  const auto& ct520 = v441[10 + 16 * (0)];
  auto v89_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v89_filled = v89;
  v89_filled.clear();
  v89_filled.reserve(v89_filled_n);
  for (auto i = 0; i < v89_filled_n; ++i) {
    v89_filled.push_back(v89[i % v89.size()]);
  }
  const auto& pt168 = cc->MakeCKKSPackedPlaintext(v89_filled);
  const auto& ct521 = cc->EvalMult(ct32, pt168);
  const auto& ct522 = cc->EvalAdd(ct520, ct521);
  v441[10 + 16 * (0)] = ct522;
  std::vector<CiphertextT> v442 = std::move(v441);
  const auto& ct523 = v442[10 + 16 * (0)];
  auto v88_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v88_filled = v88;
  v88_filled.clear();
  v88_filled.reserve(v88_filled_n);
  for (auto i = 0; i < v88_filled_n; ++i) {
    v88_filled.push_back(v88[i % v88.size()]);
  }
  const auto& pt169 = cc->MakeCKKSPackedPlaintext(v88_filled);
  const auto& ct524 = cc->EvalMult(ct36, pt169);
  const auto& ct525 = cc->EvalAdd(ct523, ct524);
  v442[10 + 16 * (0)] = ct525;
  std::vector<CiphertextT> v443 = std::move(v442);
  const auto& ct526 = v443[10 + 16 * (0)];
  auto v87_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v87_filled = v87;
  v87_filled.clear();
  v87_filled.reserve(v87_filled_n);
  for (auto i = 0; i < v87_filled_n; ++i) {
    v87_filled.push_back(v87[i % v87.size()]);
  }
  const auto& pt170 = cc->MakeCKKSPackedPlaintext(v87_filled);
  const auto& ct527 = cc->EvalMult(ct40, pt170);
  const auto& ct528 = cc->EvalAdd(ct526, ct527);
  v443[10 + 16 * (0)] = ct528;
  std::vector<CiphertextT> v444 = std::move(v443);
  const auto& ct529 = v444[10 + 16 * (0)];
  auto v86_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v86_filled = v86;
  v86_filled.clear();
  v86_filled.reserve(v86_filled_n);
  for (auto i = 0; i < v86_filled_n; ++i) {
    v86_filled.push_back(v86[i % v86.size()]);
  }
  const auto& pt171 = cc->MakeCKKSPackedPlaintext(v86_filled);
  const auto& ct530 = cc->EvalMult(ct44, pt171);
  const auto& ct531 = cc->EvalAdd(ct529, ct530);
  v444[10 + 16 * (0)] = ct531;
  std::vector<CiphertextT> v445 = std::move(v444);
  const auto& ct532 = v445[10 + 16 * (0)];
  auto v85_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v85_filled = v85;
  v85_filled.clear();
  v85_filled.reserve(v85_filled_n);
  for (auto i = 0; i < v85_filled_n; ++i) {
    v85_filled.push_back(v85[i % v85.size()]);
  }
  const auto& pt172 = cc->MakeCKKSPackedPlaintext(v85_filled);
  const auto& ct533 = cc->EvalMult(ct48, pt172);
  const auto& ct534 = cc->EvalAdd(ct532, ct533);
  v445[10 + 16 * (0)] = ct534;
  std::vector<CiphertextT> v446 = std::move(v445);
  const auto& ct535 = v446[10 + 16 * (0)];
  auto v84_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v84_filled = v84;
  v84_filled.clear();
  v84_filled.reserve(v84_filled_n);
  for (auto i = 0; i < v84_filled_n; ++i) {
    v84_filled.push_back(v84[i % v84.size()]);
  }
  const auto& pt173 = cc->MakeCKKSPackedPlaintext(v84_filled);
  const auto& ct536 = cc->EvalMult(ct52, pt173);
  const auto& ct537 = cc->EvalAdd(ct535, ct536);
  v446[10 + 16 * (0)] = ct537;
  std::vector<CiphertextT> v447 = std::move(v446);
  const auto& ct538 = v447[10 + 16 * (0)];
  auto v83_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v83_filled = v83;
  v83_filled.clear();
  v83_filled.reserve(v83_filled_n);
  for (auto i = 0; i < v83_filled_n; ++i) {
    v83_filled.push_back(v83[i % v83.size()]);
  }
  const auto& pt174 = cc->MakeCKKSPackedPlaintext(v83_filled);
  const auto& ct539 = cc->EvalMult(ct56, pt174);
  const auto& ct540 = cc->EvalAdd(ct538, ct539);
  v447[10 + 16 * (0)] = ct540;
  std::vector<CiphertextT> v448 = std::move(v447);
  const auto& ct541 = v448[10 + 16 * (0)];
  auto v82_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v82_filled = v82;
  v82_filled.clear();
  v82_filled.reserve(v82_filled_n);
  for (auto i = 0; i < v82_filled_n; ++i) {
    v82_filled.push_back(v82[i % v82.size()]);
  }
  const auto& pt175 = cc->MakeCKKSPackedPlaintext(v82_filled);
  const auto& ct542 = cc->EvalMult(ct60, pt175);
  const auto& ct543 = cc->EvalAdd(ct541, ct542);
  v448[10 + 16 * (0)] = ct543;
  std::vector<CiphertextT> v449 = std::move(v448);
  const auto& ct544 = v449[11 + 16 * (0)];
  auto v81_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v81_filled = v81;
  v81_filled.clear();
  v81_filled.reserve(v81_filled_n);
  for (auto i = 0; i < v81_filled_n; ++i) {
    v81_filled.push_back(v81[i % v81.size()]);
  }
  const auto& pt176 = cc->MakeCKKSPackedPlaintext(v81_filled);
  const auto& ct545 = cc->EvalMult(ct, pt176);
  const auto& ct546 = cc->EvalAdd(ct544, ct545);
  v449[11 + 16 * (0)] = ct546;
  std::vector<CiphertextT> v450 = std::move(v449);
  const auto& ct547 = v450[11 + 16 * (0)];
  auto v80_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v80_filled = v80;
  v80_filled.clear();
  v80_filled.reserve(v80_filled_n);
  for (auto i = 0; i < v80_filled_n; ++i) {
    v80_filled.push_back(v80[i % v80.size()]);
  }
  const auto& pt177 = cc->MakeCKKSPackedPlaintext(v80_filled);
  const auto& ct548 = cc->EvalMult(ct4, pt177);
  const auto& ct549 = cc->EvalAdd(ct547, ct548);
  v450[11 + 16 * (0)] = ct549;
  std::vector<CiphertextT> v451 = std::move(v450);
  const auto& ct550 = v451[11 + 16 * (0)];
  auto v79_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v79_filled = v79;
  v79_filled.clear();
  v79_filled.reserve(v79_filled_n);
  for (auto i = 0; i < v79_filled_n; ++i) {
    v79_filled.push_back(v79[i % v79.size()]);
  }
  const auto& pt178 = cc->MakeCKKSPackedPlaintext(v79_filled);
  const auto& ct551 = cc->EvalMult(ct8, pt178);
  const auto& ct552 = cc->EvalAdd(ct550, ct551);
  v451[11 + 16 * (0)] = ct552;
  std::vector<CiphertextT> v452 = std::move(v451);
  const auto& ct553 = v452[11 + 16 * (0)];
  auto v78_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v78_filled = v78;
  v78_filled.clear();
  v78_filled.reserve(v78_filled_n);
  for (auto i = 0; i < v78_filled_n; ++i) {
    v78_filled.push_back(v78[i % v78.size()]);
  }
  const auto& pt179 = cc->MakeCKKSPackedPlaintext(v78_filled);
  const auto& ct554 = cc->EvalMult(ct12, pt179);
  const auto& ct555 = cc->EvalAdd(ct553, ct554);
  v452[11 + 16 * (0)] = ct555;
  std::vector<CiphertextT> v453 = std::move(v452);
  const auto& ct556 = v453[11 + 16 * (0)];
  auto v77_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v77_filled = v77;
  v77_filled.clear();
  v77_filled.reserve(v77_filled_n);
  for (auto i = 0; i < v77_filled_n; ++i) {
    v77_filled.push_back(v77[i % v77.size()]);
  }
  const auto& pt180 = cc->MakeCKKSPackedPlaintext(v77_filled);
  const auto& ct557 = cc->EvalMult(ct16, pt180);
  const auto& ct558 = cc->EvalAdd(ct556, ct557);
  v453[11 + 16 * (0)] = ct558;
  std::vector<CiphertextT> v454 = std::move(v453);
  const auto& ct559 = v454[11 + 16 * (0)];
  auto v76_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v76_filled = v76;
  v76_filled.clear();
  v76_filled.reserve(v76_filled_n);
  for (auto i = 0; i < v76_filled_n; ++i) {
    v76_filled.push_back(v76[i % v76.size()]);
  }
  const auto& pt181 = cc->MakeCKKSPackedPlaintext(v76_filled);
  const auto& ct560 = cc->EvalMult(ct20, pt181);
  const auto& ct561 = cc->EvalAdd(ct559, ct560);
  v454[11 + 16 * (0)] = ct561;
  std::vector<CiphertextT> v455 = std::move(v454);
  const auto& ct562 = v455[11 + 16 * (0)];
  auto v75_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v75_filled = v75;
  v75_filled.clear();
  v75_filled.reserve(v75_filled_n);
  for (auto i = 0; i < v75_filled_n; ++i) {
    v75_filled.push_back(v75[i % v75.size()]);
  }
  const auto& pt182 = cc->MakeCKKSPackedPlaintext(v75_filled);
  const auto& ct563 = cc->EvalMult(ct24, pt182);
  const auto& ct564 = cc->EvalAdd(ct562, ct563);
  v455[11 + 16 * (0)] = ct564;
  std::vector<CiphertextT> v456 = std::move(v455);
  const auto& ct565 = v456[11 + 16 * (0)];
  auto v74_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v74_filled = v74;
  v74_filled.clear();
  v74_filled.reserve(v74_filled_n);
  for (auto i = 0; i < v74_filled_n; ++i) {
    v74_filled.push_back(v74[i % v74.size()]);
  }
  const auto& pt183 = cc->MakeCKKSPackedPlaintext(v74_filled);
  const auto& ct566 = cc->EvalMult(ct28, pt183);
  const auto& ct567 = cc->EvalAdd(ct565, ct566);
  v456[11 + 16 * (0)] = ct567;
  std::vector<CiphertextT> v457 = std::move(v456);
  const auto& ct568 = v457[11 + 16 * (0)];
  auto v73_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v73_filled = v73;
  v73_filled.clear();
  v73_filled.reserve(v73_filled_n);
  for (auto i = 0; i < v73_filled_n; ++i) {
    v73_filled.push_back(v73[i % v73.size()]);
  }
  const auto& pt184 = cc->MakeCKKSPackedPlaintext(v73_filled);
  const auto& ct569 = cc->EvalMult(ct32, pt184);
  const auto& ct570 = cc->EvalAdd(ct568, ct569);
  v457[11 + 16 * (0)] = ct570;
  std::vector<CiphertextT> v458 = std::move(v457);
  const auto& ct571 = v458[11 + 16 * (0)];
  auto v72_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v72_filled = v72;
  v72_filled.clear();
  v72_filled.reserve(v72_filled_n);
  for (auto i = 0; i < v72_filled_n; ++i) {
    v72_filled.push_back(v72[i % v72.size()]);
  }
  const auto& pt185 = cc->MakeCKKSPackedPlaintext(v72_filled);
  const auto& ct572 = cc->EvalMult(ct36, pt185);
  const auto& ct573 = cc->EvalAdd(ct571, ct572);
  v458[11 + 16 * (0)] = ct573;
  std::vector<CiphertextT> v459 = std::move(v458);
  const auto& ct574 = v459[11 + 16 * (0)];
  auto v71_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v71_filled = v71;
  v71_filled.clear();
  v71_filled.reserve(v71_filled_n);
  for (auto i = 0; i < v71_filled_n; ++i) {
    v71_filled.push_back(v71[i % v71.size()]);
  }
  const auto& pt186 = cc->MakeCKKSPackedPlaintext(v71_filled);
  const auto& ct575 = cc->EvalMult(ct40, pt186);
  const auto& ct576 = cc->EvalAdd(ct574, ct575);
  v459[11 + 16 * (0)] = ct576;
  std::vector<CiphertextT> v460 = std::move(v459);
  const auto& ct577 = v460[11 + 16 * (0)];
  auto v70_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v70_filled = v70;
  v70_filled.clear();
  v70_filled.reserve(v70_filled_n);
  for (auto i = 0; i < v70_filled_n; ++i) {
    v70_filled.push_back(v70[i % v70.size()]);
  }
  const auto& pt187 = cc->MakeCKKSPackedPlaintext(v70_filled);
  const auto& ct578 = cc->EvalMult(ct44, pt187);
  const auto& ct579 = cc->EvalAdd(ct577, ct578);
  v460[11 + 16 * (0)] = ct579;
  std::vector<CiphertextT> v461 = std::move(v460);
  const auto& ct580 = v461[11 + 16 * (0)];
  auto v69_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v69_filled = v69;
  v69_filled.clear();
  v69_filled.reserve(v69_filled_n);
  for (auto i = 0; i < v69_filled_n; ++i) {
    v69_filled.push_back(v69[i % v69.size()]);
  }
  const auto& pt188 = cc->MakeCKKSPackedPlaintext(v69_filled);
  const auto& ct581 = cc->EvalMult(ct48, pt188);
  const auto& ct582 = cc->EvalAdd(ct580, ct581);
  v461[11 + 16 * (0)] = ct582;
  std::vector<CiphertextT> v462 = std::move(v461);
  const auto& ct583 = v462[11 + 16 * (0)];
  auto v68_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v68_filled = v68;
  v68_filled.clear();
  v68_filled.reserve(v68_filled_n);
  for (auto i = 0; i < v68_filled_n; ++i) {
    v68_filled.push_back(v68[i % v68.size()]);
  }
  const auto& pt189 = cc->MakeCKKSPackedPlaintext(v68_filled);
  const auto& ct584 = cc->EvalMult(ct52, pt189);
  const auto& ct585 = cc->EvalAdd(ct583, ct584);
  v462[11 + 16 * (0)] = ct585;
  std::vector<CiphertextT> v463 = std::move(v462);
  const auto& ct586 = v463[11 + 16 * (0)];
  auto v67_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v67_filled = v67;
  v67_filled.clear();
  v67_filled.reserve(v67_filled_n);
  for (auto i = 0; i < v67_filled_n; ++i) {
    v67_filled.push_back(v67[i % v67.size()]);
  }
  const auto& pt190 = cc->MakeCKKSPackedPlaintext(v67_filled);
  const auto& ct587 = cc->EvalMult(ct56, pt190);
  const auto& ct588 = cc->EvalAdd(ct586, ct587);
  v463[11 + 16 * (0)] = ct588;
  std::vector<CiphertextT> v464 = std::move(v463);
  const auto& ct589 = v464[11 + 16 * (0)];
  auto v66_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v66_filled = v66;
  v66_filled.clear();
  v66_filled.reserve(v66_filled_n);
  for (auto i = 0; i < v66_filled_n; ++i) {
    v66_filled.push_back(v66[i % v66.size()]);
  }
  const auto& pt191 = cc->MakeCKKSPackedPlaintext(v66_filled);
  const auto& ct590 = cc->EvalMult(ct60, pt191);
  const auto& ct591 = cc->EvalAdd(ct589, ct590);
  v464[11 + 16 * (0)] = ct591;
  std::vector<CiphertextT> v465 = std::move(v464);
  const auto& ct592 = v465[12 + 16 * (0)];
  auto v65_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v65_filled = v65;
  v65_filled.clear();
  v65_filled.reserve(v65_filled_n);
  for (auto i = 0; i < v65_filled_n; ++i) {
    v65_filled.push_back(v65[i % v65.size()]);
  }
  const auto& pt192 = cc->MakeCKKSPackedPlaintext(v65_filled);
  const auto& ct593 = cc->EvalMult(ct, pt192);
  const auto& ct594 = cc->EvalAdd(ct592, ct593);
  v465[12 + 16 * (0)] = ct594;
  std::vector<CiphertextT> v466 = std::move(v465);
  const auto& ct595 = v466[12 + 16 * (0)];
  auto v64_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v64_filled = v64;
  v64_filled.clear();
  v64_filled.reserve(v64_filled_n);
  for (auto i = 0; i < v64_filled_n; ++i) {
    v64_filled.push_back(v64[i % v64.size()]);
  }
  const auto& pt193 = cc->MakeCKKSPackedPlaintext(v64_filled);
  const auto& ct596 = cc->EvalMult(ct4, pt193);
  const auto& ct597 = cc->EvalAdd(ct595, ct596);
  v466[12 + 16 * (0)] = ct597;
  std::vector<CiphertextT> v467 = std::move(v466);
  const auto& ct598 = v467[12 + 16 * (0)];
  auto v63_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v63_filled = v63;
  v63_filled.clear();
  v63_filled.reserve(v63_filled_n);
  for (auto i = 0; i < v63_filled_n; ++i) {
    v63_filled.push_back(v63[i % v63.size()]);
  }
  const auto& pt194 = cc->MakeCKKSPackedPlaintext(v63_filled);
  const auto& ct599 = cc->EvalMult(ct8, pt194);
  const auto& ct600 = cc->EvalAdd(ct598, ct599);
  v467[12 + 16 * (0)] = ct600;
  std::vector<CiphertextT> v468 = std::move(v467);
  const auto& ct601 = v468[12 + 16 * (0)];
  auto v62_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v62_filled = v62;
  v62_filled.clear();
  v62_filled.reserve(v62_filled_n);
  for (auto i = 0; i < v62_filled_n; ++i) {
    v62_filled.push_back(v62[i % v62.size()]);
  }
  const auto& pt195 = cc->MakeCKKSPackedPlaintext(v62_filled);
  const auto& ct602 = cc->EvalMult(ct12, pt195);
  const auto& ct603 = cc->EvalAdd(ct601, ct602);
  v468[12 + 16 * (0)] = ct603;
  std::vector<CiphertextT> v469 = std::move(v468);
  const auto& ct604 = v469[12 + 16 * (0)];
  auto v61_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v61_filled = v61;
  v61_filled.clear();
  v61_filled.reserve(v61_filled_n);
  for (auto i = 0; i < v61_filled_n; ++i) {
    v61_filled.push_back(v61[i % v61.size()]);
  }
  const auto& pt196 = cc->MakeCKKSPackedPlaintext(v61_filled);
  const auto& ct605 = cc->EvalMult(ct16, pt196);
  const auto& ct606 = cc->EvalAdd(ct604, ct605);
  v469[12 + 16 * (0)] = ct606;
  std::vector<CiphertextT> v470 = std::move(v469);
  const auto& ct607 = v470[12 + 16 * (0)];
  auto v60_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v60_filled = v60;
  v60_filled.clear();
  v60_filled.reserve(v60_filled_n);
  for (auto i = 0; i < v60_filled_n; ++i) {
    v60_filled.push_back(v60[i % v60.size()]);
  }
  const auto& pt197 = cc->MakeCKKSPackedPlaintext(v60_filled);
  const auto& ct608 = cc->EvalMult(ct20, pt197);
  const auto& ct609 = cc->EvalAdd(ct607, ct608);
  v470[12 + 16 * (0)] = ct609;
  std::vector<CiphertextT> v471 = std::move(v470);
  const auto& ct610 = v471[12 + 16 * (0)];
  auto v59_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v59_filled = v59;
  v59_filled.clear();
  v59_filled.reserve(v59_filled_n);
  for (auto i = 0; i < v59_filled_n; ++i) {
    v59_filled.push_back(v59[i % v59.size()]);
  }
  const auto& pt198 = cc->MakeCKKSPackedPlaintext(v59_filled);
  const auto& ct611 = cc->EvalMult(ct24, pt198);
  const auto& ct612 = cc->EvalAdd(ct610, ct611);
  v471[12 + 16 * (0)] = ct612;
  std::vector<CiphertextT> v472 = std::move(v471);
  const auto& ct613 = v472[12 + 16 * (0)];
  auto v58_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v58_filled = v58;
  v58_filled.clear();
  v58_filled.reserve(v58_filled_n);
  for (auto i = 0; i < v58_filled_n; ++i) {
    v58_filled.push_back(v58[i % v58.size()]);
  }
  const auto& pt199 = cc->MakeCKKSPackedPlaintext(v58_filled);
  const auto& ct614 = cc->EvalMult(ct28, pt199);
  const auto& ct615 = cc->EvalAdd(ct613, ct614);
  v472[12 + 16 * (0)] = ct615;
  std::vector<CiphertextT> v473 = std::move(v472);
  const auto& ct616 = v473[12 + 16 * (0)];
  auto v57_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v57_filled = v57;
  v57_filled.clear();
  v57_filled.reserve(v57_filled_n);
  for (auto i = 0; i < v57_filled_n; ++i) {
    v57_filled.push_back(v57[i % v57.size()]);
  }
  const auto& pt200 = cc->MakeCKKSPackedPlaintext(v57_filled);
  const auto& ct617 = cc->EvalMult(ct32, pt200);
  const auto& ct618 = cc->EvalAdd(ct616, ct617);
  v473[12 + 16 * (0)] = ct618;
  std::vector<CiphertextT> v474 = std::move(v473);
  const auto& ct619 = v474[12 + 16 * (0)];
  auto v56_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v56_filled = v56;
  v56_filled.clear();
  v56_filled.reserve(v56_filled_n);
  for (auto i = 0; i < v56_filled_n; ++i) {
    v56_filled.push_back(v56[i % v56.size()]);
  }
  const auto& pt201 = cc->MakeCKKSPackedPlaintext(v56_filled);
  const auto& ct620 = cc->EvalMult(ct36, pt201);
  const auto& ct621 = cc->EvalAdd(ct619, ct620);
  v474[12 + 16 * (0)] = ct621;
  std::vector<CiphertextT> v475 = std::move(v474);
  const auto& ct622 = v475[12 + 16 * (0)];
  auto v55_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v55_filled = v55;
  v55_filled.clear();
  v55_filled.reserve(v55_filled_n);
  for (auto i = 0; i < v55_filled_n; ++i) {
    v55_filled.push_back(v55[i % v55.size()]);
  }
  const auto& pt202 = cc->MakeCKKSPackedPlaintext(v55_filled);
  const auto& ct623 = cc->EvalMult(ct40, pt202);
  const auto& ct624 = cc->EvalAdd(ct622, ct623);
  v475[12 + 16 * (0)] = ct624;
  std::vector<CiphertextT> v476 = std::move(v475);
  const auto& ct625 = v476[12 + 16 * (0)];
  auto v54_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v54_filled = v54;
  v54_filled.clear();
  v54_filled.reserve(v54_filled_n);
  for (auto i = 0; i < v54_filled_n; ++i) {
    v54_filled.push_back(v54[i % v54.size()]);
  }
  const auto& pt203 = cc->MakeCKKSPackedPlaintext(v54_filled);
  const auto& ct626 = cc->EvalMult(ct44, pt203);
  const auto& ct627 = cc->EvalAdd(ct625, ct626);
  v476[12 + 16 * (0)] = ct627;
  std::vector<CiphertextT> v477 = std::move(v476);
  const auto& ct628 = v477[12 + 16 * (0)];
  auto v53_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v53_filled = v53;
  v53_filled.clear();
  v53_filled.reserve(v53_filled_n);
  for (auto i = 0; i < v53_filled_n; ++i) {
    v53_filled.push_back(v53[i % v53.size()]);
  }
  const auto& pt204 = cc->MakeCKKSPackedPlaintext(v53_filled);
  const auto& ct629 = cc->EvalMult(ct48, pt204);
  const auto& ct630 = cc->EvalAdd(ct628, ct629);
  v477[12 + 16 * (0)] = ct630;
  std::vector<CiphertextT> v478 = std::move(v477);
  const auto& ct631 = v478[12 + 16 * (0)];
  auto v52_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v52_filled = v52;
  v52_filled.clear();
  v52_filled.reserve(v52_filled_n);
  for (auto i = 0; i < v52_filled_n; ++i) {
    v52_filled.push_back(v52[i % v52.size()]);
  }
  const auto& pt205 = cc->MakeCKKSPackedPlaintext(v52_filled);
  const auto& ct632 = cc->EvalMult(ct52, pt205);
  const auto& ct633 = cc->EvalAdd(ct631, ct632);
  v478[12 + 16 * (0)] = ct633;
  std::vector<CiphertextT> v479 = std::move(v478);
  const auto& ct634 = v479[12 + 16 * (0)];
  auto v51_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v51_filled = v51;
  v51_filled.clear();
  v51_filled.reserve(v51_filled_n);
  for (auto i = 0; i < v51_filled_n; ++i) {
    v51_filled.push_back(v51[i % v51.size()]);
  }
  const auto& pt206 = cc->MakeCKKSPackedPlaintext(v51_filled);
  const auto& ct635 = cc->EvalMult(ct56, pt206);
  const auto& ct636 = cc->EvalAdd(ct634, ct635);
  v479[12 + 16 * (0)] = ct636;
  std::vector<CiphertextT> v480 = std::move(v479);
  const auto& ct637 = v480[12 + 16 * (0)];
  auto v50_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v50_filled = v50;
  v50_filled.clear();
  v50_filled.reserve(v50_filled_n);
  for (auto i = 0; i < v50_filled_n; ++i) {
    v50_filled.push_back(v50[i % v50.size()]);
  }
  const auto& pt207 = cc->MakeCKKSPackedPlaintext(v50_filled);
  const auto& ct638 = cc->EvalMult(ct60, pt207);
  const auto& ct639 = cc->EvalAdd(ct637, ct638);
  v480[12 + 16 * (0)] = ct639;
  std::vector<CiphertextT> v481 = std::move(v480);
  const auto& ct640 = v481[13 + 16 * (0)];
  auto v49_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v49_filled = v49;
  v49_filled.clear();
  v49_filled.reserve(v49_filled_n);
  for (auto i = 0; i < v49_filled_n; ++i) {
    v49_filled.push_back(v49[i % v49.size()]);
  }
  const auto& pt208 = cc->MakeCKKSPackedPlaintext(v49_filled);
  const auto& ct641 = cc->EvalMult(ct, pt208);
  const auto& ct642 = cc->EvalAdd(ct640, ct641);
  v481[13 + 16 * (0)] = ct642;
  std::vector<CiphertextT> v482 = std::move(v481);
  const auto& ct643 = v482[13 + 16 * (0)];
  auto v48_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v48_filled = v48;
  v48_filled.clear();
  v48_filled.reserve(v48_filled_n);
  for (auto i = 0; i < v48_filled_n; ++i) {
    v48_filled.push_back(v48[i % v48.size()]);
  }
  const auto& pt209 = cc->MakeCKKSPackedPlaintext(v48_filled);
  const auto& ct644 = cc->EvalMult(ct4, pt209);
  const auto& ct645 = cc->EvalAdd(ct643, ct644);
  v482[13 + 16 * (0)] = ct645;
  std::vector<CiphertextT> v483 = std::move(v482);
  const auto& ct646 = v483[13 + 16 * (0)];
  auto v47_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v47_filled = v47;
  v47_filled.clear();
  v47_filled.reserve(v47_filled_n);
  for (auto i = 0; i < v47_filled_n; ++i) {
    v47_filled.push_back(v47[i % v47.size()]);
  }
  const auto& pt210 = cc->MakeCKKSPackedPlaintext(v47_filled);
  const auto& ct647 = cc->EvalMult(ct8, pt210);
  const auto& ct648 = cc->EvalAdd(ct646, ct647);
  v483[13 + 16 * (0)] = ct648;
  std::vector<CiphertextT> v484 = std::move(v483);
  const auto& ct649 = v484[13 + 16 * (0)];
  auto v46_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v46_filled = v46;
  v46_filled.clear();
  v46_filled.reserve(v46_filled_n);
  for (auto i = 0; i < v46_filled_n; ++i) {
    v46_filled.push_back(v46[i % v46.size()]);
  }
  const auto& pt211 = cc->MakeCKKSPackedPlaintext(v46_filled);
  const auto& ct650 = cc->EvalMult(ct12, pt211);
  const auto& ct651 = cc->EvalAdd(ct649, ct650);
  v484[13 + 16 * (0)] = ct651;
  std::vector<CiphertextT> v485 = std::move(v484);
  const auto& ct652 = v485[13 + 16 * (0)];
  auto v45_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v45_filled = v45;
  v45_filled.clear();
  v45_filled.reserve(v45_filled_n);
  for (auto i = 0; i < v45_filled_n; ++i) {
    v45_filled.push_back(v45[i % v45.size()]);
  }
  const auto& pt212 = cc->MakeCKKSPackedPlaintext(v45_filled);
  const auto& ct653 = cc->EvalMult(ct16, pt212);
  const auto& ct654 = cc->EvalAdd(ct652, ct653);
  v485[13 + 16 * (0)] = ct654;
  std::vector<CiphertextT> v486 = std::move(v485);
  const auto& ct655 = v486[13 + 16 * (0)];
  auto v44_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v44_filled = v44;
  v44_filled.clear();
  v44_filled.reserve(v44_filled_n);
  for (auto i = 0; i < v44_filled_n; ++i) {
    v44_filled.push_back(v44[i % v44.size()]);
  }
  const auto& pt213 = cc->MakeCKKSPackedPlaintext(v44_filled);
  const auto& ct656 = cc->EvalMult(ct20, pt213);
  const auto& ct657 = cc->EvalAdd(ct655, ct656);
  v486[13 + 16 * (0)] = ct657;
  std::vector<CiphertextT> v487 = std::move(v486);
  const auto& ct658 = v487[13 + 16 * (0)];
  auto v43_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v43_filled = v43;
  v43_filled.clear();
  v43_filled.reserve(v43_filled_n);
  for (auto i = 0; i < v43_filled_n; ++i) {
    v43_filled.push_back(v43[i % v43.size()]);
  }
  const auto& pt214 = cc->MakeCKKSPackedPlaintext(v43_filled);
  const auto& ct659 = cc->EvalMult(ct24, pt214);
  const auto& ct660 = cc->EvalAdd(ct658, ct659);
  v487[13 + 16 * (0)] = ct660;
  std::vector<CiphertextT> v488 = std::move(v487);
  const auto& ct661 = v488[13 + 16 * (0)];
  auto v42_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v42_filled = v42;
  v42_filled.clear();
  v42_filled.reserve(v42_filled_n);
  for (auto i = 0; i < v42_filled_n; ++i) {
    v42_filled.push_back(v42[i % v42.size()]);
  }
  const auto& pt215 = cc->MakeCKKSPackedPlaintext(v42_filled);
  const auto& ct662 = cc->EvalMult(ct28, pt215);
  const auto& ct663 = cc->EvalAdd(ct661, ct662);
  v488[13 + 16 * (0)] = ct663;
  std::vector<CiphertextT> v489 = std::move(v488);
  const auto& ct664 = v489[13 + 16 * (0)];
  auto v41_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v41_filled = v41;
  v41_filled.clear();
  v41_filled.reserve(v41_filled_n);
  for (auto i = 0; i < v41_filled_n; ++i) {
    v41_filled.push_back(v41[i % v41.size()]);
  }
  const auto& pt216 = cc->MakeCKKSPackedPlaintext(v41_filled);
  const auto& ct665 = cc->EvalMult(ct32, pt216);
  const auto& ct666 = cc->EvalAdd(ct664, ct665);
  v489[13 + 16 * (0)] = ct666;
  std::vector<CiphertextT> v490 = std::move(v489);
  const auto& ct667 = v490[13 + 16 * (0)];
  auto v40_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v40_filled = v40;
  v40_filled.clear();
  v40_filled.reserve(v40_filled_n);
  for (auto i = 0; i < v40_filled_n; ++i) {
    v40_filled.push_back(v40[i % v40.size()]);
  }
  const auto& pt217 = cc->MakeCKKSPackedPlaintext(v40_filled);
  const auto& ct668 = cc->EvalMult(ct36, pt217);
  const auto& ct669 = cc->EvalAdd(ct667, ct668);
  v490[13 + 16 * (0)] = ct669;
  std::vector<CiphertextT> v491 = std::move(v490);
  const auto& ct670 = v491[13 + 16 * (0)];
  auto v39_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v39_filled = v39;
  v39_filled.clear();
  v39_filled.reserve(v39_filled_n);
  for (auto i = 0; i < v39_filled_n; ++i) {
    v39_filled.push_back(v39[i % v39.size()]);
  }
  const auto& pt218 = cc->MakeCKKSPackedPlaintext(v39_filled);
  const auto& ct671 = cc->EvalMult(ct40, pt218);
  const auto& ct672 = cc->EvalAdd(ct670, ct671);
  v491[13 + 16 * (0)] = ct672;
  std::vector<CiphertextT> v492 = std::move(v491);
  const auto& ct673 = v492[13 + 16 * (0)];
  auto v38_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v38_filled = v38;
  v38_filled.clear();
  v38_filled.reserve(v38_filled_n);
  for (auto i = 0; i < v38_filled_n; ++i) {
    v38_filled.push_back(v38[i % v38.size()]);
  }
  const auto& pt219 = cc->MakeCKKSPackedPlaintext(v38_filled);
  const auto& ct674 = cc->EvalMult(ct44, pt219);
  const auto& ct675 = cc->EvalAdd(ct673, ct674);
  v492[13 + 16 * (0)] = ct675;
  std::vector<CiphertextT> v493 = std::move(v492);
  const auto& ct676 = v493[13 + 16 * (0)];
  auto v37_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v37_filled = v37;
  v37_filled.clear();
  v37_filled.reserve(v37_filled_n);
  for (auto i = 0; i < v37_filled_n; ++i) {
    v37_filled.push_back(v37[i % v37.size()]);
  }
  const auto& pt220 = cc->MakeCKKSPackedPlaintext(v37_filled);
  const auto& ct677 = cc->EvalMult(ct48, pt220);
  const auto& ct678 = cc->EvalAdd(ct676, ct677);
  v493[13 + 16 * (0)] = ct678;
  std::vector<CiphertextT> v494 = std::move(v493);
  const auto& ct679 = v494[13 + 16 * (0)];
  auto v36_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v36_filled = v36;
  v36_filled.clear();
  v36_filled.reserve(v36_filled_n);
  for (auto i = 0; i < v36_filled_n; ++i) {
    v36_filled.push_back(v36[i % v36.size()]);
  }
  const auto& pt221 = cc->MakeCKKSPackedPlaintext(v36_filled);
  const auto& ct680 = cc->EvalMult(ct52, pt221);
  const auto& ct681 = cc->EvalAdd(ct679, ct680);
  v494[13 + 16 * (0)] = ct681;
  std::vector<CiphertextT> v495 = std::move(v494);
  const auto& ct682 = v495[13 + 16 * (0)];
  auto v35_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v35_filled = v35;
  v35_filled.clear();
  v35_filled.reserve(v35_filled_n);
  for (auto i = 0; i < v35_filled_n; ++i) {
    v35_filled.push_back(v35[i % v35.size()]);
  }
  const auto& pt222 = cc->MakeCKKSPackedPlaintext(v35_filled);
  const auto& ct683 = cc->EvalMult(ct56, pt222);
  const auto& ct684 = cc->EvalAdd(ct682, ct683);
  v495[13 + 16 * (0)] = ct684;
  std::vector<CiphertextT> v496 = std::move(v495);
  const auto& ct685 = v496[13 + 16 * (0)];
  auto v34_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v34_filled = v34;
  v34_filled.clear();
  v34_filled.reserve(v34_filled_n);
  for (auto i = 0; i < v34_filled_n; ++i) {
    v34_filled.push_back(v34[i % v34.size()]);
  }
  const auto& pt223 = cc->MakeCKKSPackedPlaintext(v34_filled);
  const auto& ct686 = cc->EvalMult(ct60, pt223);
  const auto& ct687 = cc->EvalAdd(ct685, ct686);
  v496[13 + 16 * (0)] = ct687;
  std::vector<CiphertextT> v497 = std::move(v496);
  const auto& ct688 = v497[14 + 16 * (0)];
  auto v33_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v33_filled = v33;
  v33_filled.clear();
  v33_filled.reserve(v33_filled_n);
  for (auto i = 0; i < v33_filled_n; ++i) {
    v33_filled.push_back(v33[i % v33.size()]);
  }
  const auto& pt224 = cc->MakeCKKSPackedPlaintext(v33_filled);
  const auto& ct689 = cc->EvalMult(ct, pt224);
  const auto& ct690 = cc->EvalAdd(ct688, ct689);
  v497[14 + 16 * (0)] = ct690;
  std::vector<CiphertextT> v498 = std::move(v497);
  const auto& ct691 = v498[14 + 16 * (0)];
  auto v32_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v32_filled = v32;
  v32_filled.clear();
  v32_filled.reserve(v32_filled_n);
  for (auto i = 0; i < v32_filled_n; ++i) {
    v32_filled.push_back(v32[i % v32.size()]);
  }
  const auto& pt225 = cc->MakeCKKSPackedPlaintext(v32_filled);
  const auto& ct692 = cc->EvalMult(ct4, pt225);
  const auto& ct693 = cc->EvalAdd(ct691, ct692);
  v498[14 + 16 * (0)] = ct693;
  std::vector<CiphertextT> v499 = std::move(v498);
  const auto& ct694 = v499[14 + 16 * (0)];
  auto v31_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v31_filled = v31;
  v31_filled.clear();
  v31_filled.reserve(v31_filled_n);
  for (auto i = 0; i < v31_filled_n; ++i) {
    v31_filled.push_back(v31[i % v31.size()]);
  }
  const auto& pt226 = cc->MakeCKKSPackedPlaintext(v31_filled);
  const auto& ct695 = cc->EvalMult(ct8, pt226);
  const auto& ct696 = cc->EvalAdd(ct694, ct695);
  v499[14 + 16 * (0)] = ct696;
  std::vector<CiphertextT> v500 = std::move(v499);
  const auto& ct697 = v500[14 + 16 * (0)];
  auto v30_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v30_filled = v30;
  v30_filled.clear();
  v30_filled.reserve(v30_filled_n);
  for (auto i = 0; i < v30_filled_n; ++i) {
    v30_filled.push_back(v30[i % v30.size()]);
  }
  const auto& pt227 = cc->MakeCKKSPackedPlaintext(v30_filled);
  const auto& ct698 = cc->EvalMult(ct12, pt227);
  const auto& ct699 = cc->EvalAdd(ct697, ct698);
  v500[14 + 16 * (0)] = ct699;
  std::vector<CiphertextT> v501 = std::move(v500);
  const auto& ct700 = v501[14 + 16 * (0)];
  auto v29_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v29_filled = v29;
  v29_filled.clear();
  v29_filled.reserve(v29_filled_n);
  for (auto i = 0; i < v29_filled_n; ++i) {
    v29_filled.push_back(v29[i % v29.size()]);
  }
  const auto& pt228 = cc->MakeCKKSPackedPlaintext(v29_filled);
  const auto& ct701 = cc->EvalMult(ct16, pt228);
  const auto& ct702 = cc->EvalAdd(ct700, ct701);
  v501[14 + 16 * (0)] = ct702;
  std::vector<CiphertextT> v502 = std::move(v501);
  const auto& ct703 = v502[14 + 16 * (0)];
  auto v28_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v28_filled = v28;
  v28_filled.clear();
  v28_filled.reserve(v28_filled_n);
  for (auto i = 0; i < v28_filled_n; ++i) {
    v28_filled.push_back(v28[i % v28.size()]);
  }
  const auto& pt229 = cc->MakeCKKSPackedPlaintext(v28_filled);
  const auto& ct704 = cc->EvalMult(ct20, pt229);
  const auto& ct705 = cc->EvalAdd(ct703, ct704);
  v502[14 + 16 * (0)] = ct705;
  std::vector<CiphertextT> v503 = std::move(v502);
  const auto& ct706 = v503[14 + 16 * (0)];
  auto v27_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v27_filled = v27;
  v27_filled.clear();
  v27_filled.reserve(v27_filled_n);
  for (auto i = 0; i < v27_filled_n; ++i) {
    v27_filled.push_back(v27[i % v27.size()]);
  }
  const auto& pt230 = cc->MakeCKKSPackedPlaintext(v27_filled);
  const auto& ct707 = cc->EvalMult(ct24, pt230);
  const auto& ct708 = cc->EvalAdd(ct706, ct707);
  v503[14 + 16 * (0)] = ct708;
  std::vector<CiphertextT> v504 = std::move(v503);
  const auto& ct709 = v504[14 + 16 * (0)];
  auto v26_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v26_filled = v26;
  v26_filled.clear();
  v26_filled.reserve(v26_filled_n);
  for (auto i = 0; i < v26_filled_n; ++i) {
    v26_filled.push_back(v26[i % v26.size()]);
  }
  const auto& pt231 = cc->MakeCKKSPackedPlaintext(v26_filled);
  const auto& ct710 = cc->EvalMult(ct28, pt231);
  const auto& ct711 = cc->EvalAdd(ct709, ct710);
  v504[14 + 16 * (0)] = ct711;
  std::vector<CiphertextT> v505 = std::move(v504);
  const auto& ct712 = v505[14 + 16 * (0)];
  auto v25_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v25_filled = v25;
  v25_filled.clear();
  v25_filled.reserve(v25_filled_n);
  for (auto i = 0; i < v25_filled_n; ++i) {
    v25_filled.push_back(v25[i % v25.size()]);
  }
  const auto& pt232 = cc->MakeCKKSPackedPlaintext(v25_filled);
  const auto& ct713 = cc->EvalMult(ct32, pt232);
  const auto& ct714 = cc->EvalAdd(ct712, ct713);
  v505[14 + 16 * (0)] = ct714;
  std::vector<CiphertextT> v506 = std::move(v505);
  const auto& ct715 = v506[14 + 16 * (0)];
  auto v24_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v24_filled = v24;
  v24_filled.clear();
  v24_filled.reserve(v24_filled_n);
  for (auto i = 0; i < v24_filled_n; ++i) {
    v24_filled.push_back(v24[i % v24.size()]);
  }
  const auto& pt233 = cc->MakeCKKSPackedPlaintext(v24_filled);
  const auto& ct716 = cc->EvalMult(ct36, pt233);
  const auto& ct717 = cc->EvalAdd(ct715, ct716);
  v506[14 + 16 * (0)] = ct717;
  std::vector<CiphertextT> v507 = std::move(v506);
  const auto& ct718 = v507[14 + 16 * (0)];
  auto v23_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v23_filled = v23;
  v23_filled.clear();
  v23_filled.reserve(v23_filled_n);
  for (auto i = 0; i < v23_filled_n; ++i) {
    v23_filled.push_back(v23[i % v23.size()]);
  }
  const auto& pt234 = cc->MakeCKKSPackedPlaintext(v23_filled);
  const auto& ct719 = cc->EvalMult(ct40, pt234);
  const auto& ct720 = cc->EvalAdd(ct718, ct719);
  v507[14 + 16 * (0)] = ct720;
  std::vector<CiphertextT> v508 = std::move(v507);
  const auto& ct721 = v508[14 + 16 * (0)];
  auto v22_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v22_filled = v22;
  v22_filled.clear();
  v22_filled.reserve(v22_filled_n);
  for (auto i = 0; i < v22_filled_n; ++i) {
    v22_filled.push_back(v22[i % v22.size()]);
  }
  const auto& pt235 = cc->MakeCKKSPackedPlaintext(v22_filled);
  const auto& ct722 = cc->EvalMult(ct44, pt235);
  const auto& ct723 = cc->EvalAdd(ct721, ct722);
  v508[14 + 16 * (0)] = ct723;
  std::vector<CiphertextT> v509 = std::move(v508);
  const auto& ct724 = v509[14 + 16 * (0)];
  auto v21_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v21_filled = v21;
  v21_filled.clear();
  v21_filled.reserve(v21_filled_n);
  for (auto i = 0; i < v21_filled_n; ++i) {
    v21_filled.push_back(v21[i % v21.size()]);
  }
  const auto& pt236 = cc->MakeCKKSPackedPlaintext(v21_filled);
  const auto& ct725 = cc->EvalMult(ct48, pt236);
  const auto& ct726 = cc->EvalAdd(ct724, ct725);
  v509[14 + 16 * (0)] = ct726;
  std::vector<CiphertextT> v510 = std::move(v509);
  const auto& ct727 = v510[14 + 16 * (0)];
  auto v20_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v20_filled = v20;
  v20_filled.clear();
  v20_filled.reserve(v20_filled_n);
  for (auto i = 0; i < v20_filled_n; ++i) {
    v20_filled.push_back(v20[i % v20.size()]);
  }
  const auto& pt237 = cc->MakeCKKSPackedPlaintext(v20_filled);
  const auto& ct728 = cc->EvalMult(ct52, pt237);
  const auto& ct729 = cc->EvalAdd(ct727, ct728);
  v510[14 + 16 * (0)] = ct729;
  std::vector<CiphertextT> v511 = std::move(v510);
  const auto& ct730 = v511[14 + 16 * (0)];
  auto v19_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v19_filled = v19;
  v19_filled.clear();
  v19_filled.reserve(v19_filled_n);
  for (auto i = 0; i < v19_filled_n; ++i) {
    v19_filled.push_back(v19[i % v19.size()]);
  }
  const auto& pt238 = cc->MakeCKKSPackedPlaintext(v19_filled);
  const auto& ct731 = cc->EvalMult(ct56, pt238);
  const auto& ct732 = cc->EvalAdd(ct730, ct731);
  v511[14 + 16 * (0)] = ct732;
  std::vector<CiphertextT> v512 = std::move(v511);
  const auto& ct733 = v512[14 + 16 * (0)];
  auto v18_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v18_filled = v18;
  v18_filled.clear();
  v18_filled.reserve(v18_filled_n);
  for (auto i = 0; i < v18_filled_n; ++i) {
    v18_filled.push_back(v18[i % v18.size()]);
  }
  const auto& pt239 = cc->MakeCKKSPackedPlaintext(v18_filled);
  const auto& ct734 = cc->EvalMult(ct60, pt239);
  const auto& ct735 = cc->EvalAdd(ct733, ct734);
  v512[14 + 16 * (0)] = ct735;
  std::vector<CiphertextT> v513 = std::move(v512);
  const auto& ct736 = v513[15 + 16 * (0)];
  auto v17_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v17_filled = v17;
  v17_filled.clear();
  v17_filled.reserve(v17_filled_n);
  for (auto i = 0; i < v17_filled_n; ++i) {
    v17_filled.push_back(v17[i % v17.size()]);
  }
  const auto& pt240 = cc->MakeCKKSPackedPlaintext(v17_filled);
  const auto& ct737 = cc->EvalMult(ct, pt240);
  const auto& ct738 = cc->EvalAdd(ct736, ct737);
  v513[15 + 16 * (0)] = ct738;
  std::vector<CiphertextT> v514 = std::move(v513);
  const auto& ct739 = v514[15 + 16 * (0)];
  auto v16_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v16_filled = v16;
  v16_filled.clear();
  v16_filled.reserve(v16_filled_n);
  for (auto i = 0; i < v16_filled_n; ++i) {
    v16_filled.push_back(v16[i % v16.size()]);
  }
  const auto& pt241 = cc->MakeCKKSPackedPlaintext(v16_filled);
  const auto& ct740 = cc->EvalMult(ct4, pt241);
  const auto& ct741 = cc->EvalAdd(ct739, ct740);
  v514[15 + 16 * (0)] = ct741;
  std::vector<CiphertextT> v515 = std::move(v514);
  const auto& ct742 = v515[15 + 16 * (0)];
  auto v15_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v15_filled = v15;
  v15_filled.clear();
  v15_filled.reserve(v15_filled_n);
  for (auto i = 0; i < v15_filled_n; ++i) {
    v15_filled.push_back(v15[i % v15.size()]);
  }
  const auto& pt242 = cc->MakeCKKSPackedPlaintext(v15_filled);
  const auto& ct743 = cc->EvalMult(ct8, pt242);
  const auto& ct744 = cc->EvalAdd(ct742, ct743);
  v515[15 + 16 * (0)] = ct744;
  std::vector<CiphertextT> v516 = std::move(v515);
  const auto& ct745 = v516[15 + 16 * (0)];
  auto v14_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v14_filled = v14;
  v14_filled.clear();
  v14_filled.reserve(v14_filled_n);
  for (auto i = 0; i < v14_filled_n; ++i) {
    v14_filled.push_back(v14[i % v14.size()]);
  }
  const auto& pt243 = cc->MakeCKKSPackedPlaintext(v14_filled);
  const auto& ct746 = cc->EvalMult(ct12, pt243);
  const auto& ct747 = cc->EvalAdd(ct745, ct746);
  v516[15 + 16 * (0)] = ct747;
  std::vector<CiphertextT> v517 = std::move(v516);
  const auto& ct748 = v517[15 + 16 * (0)];
  auto v13_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v13_filled = v13;
  v13_filled.clear();
  v13_filled.reserve(v13_filled_n);
  for (auto i = 0; i < v13_filled_n; ++i) {
    v13_filled.push_back(v13[i % v13.size()]);
  }
  const auto& pt244 = cc->MakeCKKSPackedPlaintext(v13_filled);
  const auto& ct749 = cc->EvalMult(ct16, pt244);
  const auto& ct750 = cc->EvalAdd(ct748, ct749);
  v517[15 + 16 * (0)] = ct750;
  std::vector<CiphertextT> v518 = std::move(v517);
  const auto& ct751 = v518[15 + 16 * (0)];
  auto v12_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v12_filled = v12;
  v12_filled.clear();
  v12_filled.reserve(v12_filled_n);
  for (auto i = 0; i < v12_filled_n; ++i) {
    v12_filled.push_back(v12[i % v12.size()]);
  }
  const auto& pt245 = cc->MakeCKKSPackedPlaintext(v12_filled);
  const auto& ct752 = cc->EvalMult(ct20, pt245);
  const auto& ct753 = cc->EvalAdd(ct751, ct752);
  v518[15 + 16 * (0)] = ct753;
  std::vector<CiphertextT> v519 = std::move(v518);
  const auto& ct754 = v519[15 + 16 * (0)];
  auto v11_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v11_filled = v11;
  v11_filled.clear();
  v11_filled.reserve(v11_filled_n);
  for (auto i = 0; i < v11_filled_n; ++i) {
    v11_filled.push_back(v11[i % v11.size()]);
  }
  const auto& pt246 = cc->MakeCKKSPackedPlaintext(v11_filled);
  const auto& ct755 = cc->EvalMult(ct24, pt246);
  const auto& ct756 = cc->EvalAdd(ct754, ct755);
  v519[15 + 16 * (0)] = ct756;
  std::vector<CiphertextT> v520 = std::move(v519);
  const auto& ct757 = v520[15 + 16 * (0)];
  auto v10_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v10_filled = v10;
  v10_filled.clear();
  v10_filled.reserve(v10_filled_n);
  for (auto i = 0; i < v10_filled_n; ++i) {
    v10_filled.push_back(v10[i % v10.size()]);
  }
  const auto& pt247 = cc->MakeCKKSPackedPlaintext(v10_filled);
  const auto& ct758 = cc->EvalMult(ct28, pt247);
  const auto& ct759 = cc->EvalAdd(ct757, ct758);
  v520[15 + 16 * (0)] = ct759;
  std::vector<CiphertextT> v521 = std::move(v520);
  const auto& ct760 = v521[15 + 16 * (0)];
  auto v9_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v9_filled = v9;
  v9_filled.clear();
  v9_filled.reserve(v9_filled_n);
  for (auto i = 0; i < v9_filled_n; ++i) {
    v9_filled.push_back(v9[i % v9.size()]);
  }
  const auto& pt248 = cc->MakeCKKSPackedPlaintext(v9_filled);
  const auto& ct761 = cc->EvalMult(ct32, pt248);
  const auto& ct762 = cc->EvalAdd(ct760, ct761);
  v521[15 + 16 * (0)] = ct762;
  std::vector<CiphertextT> v522 = std::move(v521);
  const auto& ct763 = v522[15 + 16 * (0)];
  auto v8_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v8_filled = v8;
  v8_filled.clear();
  v8_filled.reserve(v8_filled_n);
  for (auto i = 0; i < v8_filled_n; ++i) {
    v8_filled.push_back(v8[i % v8.size()]);
  }
  const auto& pt249 = cc->MakeCKKSPackedPlaintext(v8_filled);
  const auto& ct764 = cc->EvalMult(ct36, pt249);
  const auto& ct765 = cc->EvalAdd(ct763, ct764);
  v522[15 + 16 * (0)] = ct765;
  std::vector<CiphertextT> v523 = std::move(v522);
  const auto& ct766 = v523[15 + 16 * (0)];
  auto v7_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v7_filled = v7;
  v7_filled.clear();
  v7_filled.reserve(v7_filled_n);
  for (auto i = 0; i < v7_filled_n; ++i) {
    v7_filled.push_back(v7[i % v7.size()]);
  }
  const auto& pt250 = cc->MakeCKKSPackedPlaintext(v7_filled);
  const auto& ct767 = cc->EvalMult(ct40, pt250);
  const auto& ct768 = cc->EvalAdd(ct766, ct767);
  v523[15 + 16 * (0)] = ct768;
  std::vector<CiphertextT> v524 = std::move(v523);
  const auto& ct769 = v524[15 + 16 * (0)];
  auto v6_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v6_filled = v6;
  v6_filled.clear();
  v6_filled.reserve(v6_filled_n);
  for (auto i = 0; i < v6_filled_n; ++i) {
    v6_filled.push_back(v6[i % v6.size()]);
  }
  const auto& pt251 = cc->MakeCKKSPackedPlaintext(v6_filled);
  const auto& ct770 = cc->EvalMult(ct44, pt251);
  const auto& ct771 = cc->EvalAdd(ct769, ct770);
  v524[15 + 16 * (0)] = ct771;
  std::vector<CiphertextT> v525 = std::move(v524);
  const auto& ct772 = v525[15 + 16 * (0)];
  auto v5_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v5_filled = v5;
  v5_filled.clear();
  v5_filled.reserve(v5_filled_n);
  for (auto i = 0; i < v5_filled_n; ++i) {
    v5_filled.push_back(v5[i % v5.size()]);
  }
  const auto& pt252 = cc->MakeCKKSPackedPlaintext(v5_filled);
  const auto& ct773 = cc->EvalMult(ct48, pt252);
  const auto& ct774 = cc->EvalAdd(ct772, ct773);
  v525[15 + 16 * (0)] = ct774;
  std::vector<CiphertextT> v526 = std::move(v525);
  const auto& ct775 = v526[15 + 16 * (0)];
  auto v4_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v4_filled = v4;
  v4_filled.clear();
  v4_filled.reserve(v4_filled_n);
  for (auto i = 0; i < v4_filled_n; ++i) {
    v4_filled.push_back(v4[i % v4.size()]);
  }
  const auto& pt253 = cc->MakeCKKSPackedPlaintext(v4_filled);
  const auto& ct776 = cc->EvalMult(ct52, pt253);
  const auto& ct777 = cc->EvalAdd(ct775, ct776);
  v526[15 + 16 * (0)] = ct777;
  std::vector<CiphertextT> v527 = std::move(v526);
  const auto& ct778 = v527[15 + 16 * (0)];
  auto v3_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v3_filled = v3;
  v3_filled.clear();
  v3_filled.reserve(v3_filled_n);
  for (auto i = 0; i < v3_filled_n; ++i) {
    v3_filled.push_back(v3[i % v3.size()]);
  }
  const auto& pt254 = cc->MakeCKKSPackedPlaintext(v3_filled);
  const auto& ct779 = cc->EvalMult(ct56, pt254);
  const auto& ct780 = cc->EvalAdd(ct778, ct779);
  v527[15 + 16 * (0)] = ct780;
  std::vector<CiphertextT> v528 = std::move(v527);
  const auto& ct781 = v528[15 + 16 * (0)];
  auto v2_filled_n = cc->GetCryptoParameters()->GetElementParams()->GetRingDimension() / 2;
  auto v2_filled = v2;
  v2_filled.clear();
  v2_filled.reserve(v2_filled_n);
  for (auto i = 0; i < v2_filled_n; ++i) {
    v2_filled.push_back(v2[i % v2.size()]);
  }
  const auto& pt255 = cc->MakeCKKSPackedPlaintext(v2_filled);
  const auto& ct782 = cc->EvalMult(ct60, pt255);
  const auto& ct783 = cc->EvalAdd(ct781, ct782);
  v528[15 + 16 * (0)] = ct783;
  std::vector<CiphertextT> v529 = std::move(v528);
  return v529;
}
}