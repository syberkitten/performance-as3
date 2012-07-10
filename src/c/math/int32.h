#include "../FlashRuntimeExtensions.h"
#include "../functions.h"

FREObject Add_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] + src2[i]);
}

FREObject AddC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] + fval);
}

FREObject Sub_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] - src2[i]);
}

FREObject SubC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] - fval);
}

FREObject SubCRev_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(fval - src[i]);
}

FREObject Mul_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] * src2[i]);
}

FREObject MulC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] * fval);
}

FREObject Div_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] / src2[i]);
}

FREObject DivC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] / fval);
}

FREObject DivCRev_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(fval / src[i]);
}

FREObject Mod_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] % src2[i]);
}

FREObject ModC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] % fval);
}

FREObject And_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] & src2[i]);
}

FREObject AndC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] & fval);
}

FREObject Or_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] | src2[i]);
}

FREObject OrC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] | fval);
}

FREObject Xor_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(int32_t, src1[i] ^ src2[i]);
}

FREObject XorC_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] ^ fval);
}

FREObject Not_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(int32_t, ~src[i]);
}

FREObject Lsh_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] << fval);
}

FREObject Rsh_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32iFunc(src[i] >> fval);
}

