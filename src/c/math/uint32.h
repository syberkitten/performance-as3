#include "../FlashRuntimeExtensions.h"
#include "../functions.h"

FREObject Add_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] + src2[i]);
}

FREObject AddC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] + fval);
}

FREObject Sub_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] - src2[i]);
}

FREObject SubC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] - fval);
}

FREObject SubCRev_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(fval - src[i]);
}

FREObject Mul_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] * src2[i]);
}

FREObject MulC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] * fval);
}

FREObject Div_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] / src2[i]);
}

FREObject DivC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] / fval);
}

FREObject DivCRev_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(fval / src[i]);
}

FREObject Mod_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] % src2[i]);
}

FREObject ModC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] % fval);
}

FREObject And_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] & src2[i]);
}

FREObject AndC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] & fval);
}

FREObject Or_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] | src2[i]);
}

FREObject OrC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] | fval);
}

FREObject Xor_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(uint32_t, src1[i] ^ src2[i]);
}

FREObject XorC_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] ^ fval);
}

FREObject Not_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(uint32_t, ~src[i]);
}

FREObject Lsh_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] << fval);
}

FREObject Rsh_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcVal32uFunc(src[i] >> fval);
}
