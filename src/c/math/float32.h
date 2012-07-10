#include "../FlashRuntimeExtensions.h"
#include "../functions.h"
#include "sleef.h"


const float LOG_10 = 2.30258509299404f;


FREObject Add_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(float, src1[i] + src2[i]);
}

FREObject AddC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, src[i] + fval);
}

FREObject Sub_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(float, src1[i] - src2[i]);
}

FREObject SubC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, src[i] - fval);
}

FREObject SubCRev_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, fval - src[i]);
}

FREObject Mul_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(float, src1[i] * src2[i]);
}

FREObject MulC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, src[i] * fval);
}

FREObject Div_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(float, src1[i] / src2[i]);
}

FREObject DivC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, src[i] / fval);
}

FREObject DivCRev_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, fval / src[i]);
}

FREObject Sin_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xsinf(src[i]));
}

FREObject Cos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xcosf(src[i]));
}

FREObject Tan_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xtanf(src[i]));
}

FREObject Asin_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xasinf(src[i]));
}

FREObject Acos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xacosf(src[i]));
}

FREObject Atan_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xatanf(src[i]));
}

FREObject SinCos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    Dst1Dst2SrcFunc(float, xsinf(src[i]), xcosf(src[i]));
}

FREObject Atan2_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(float, xatan2f(src1[i], src2[i]));
}

FREObject Exp_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xexpf(src[i]));
}

FREObject Log_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xlogf(src[i]));
}

FREObject Log10_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xlogf(src[i]) / LOG_10);
}

FREObject Pow_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(float, (float)xpow(src1[i], src2[i]));
}

FREObject PowC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, (float)xpow(src[i], fval));
}

FREObject Sqrt_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, (float)xsqrt(src[i]));
}

FREObject Cbrt_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, xcbrtf(src[i]));
}

FREObject Ceil_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, ceilf(src[i]));
}

FREObject Floor_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, floorf(src[i]));
}

FREObject Abs_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcFunc(float, fabsf(src[i]));
}

FREObject Mod_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Func(float, fmod(src1[i], src2[i]));
}

FREObject ModC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrcValFunc(double, float, fmod(src[i], fval));
}

FREObject FMA_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    DstSrc1Src2Src3Func(float, (float)xfma(src1[i], src2[i], src3[i]));
}
