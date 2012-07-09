/*
 * performanceas3.c
 *
 * Author: Martin Källman
 */

#include "stdlib.h"
#include "stdint.h"
#include "math.h"
#include "sleef.h"
#include "FlashRuntimeExtensions.h"
#include "performanceas3.h"

//DST = X
#define SETDST( expression ) \
    uint32_t i; \
    for( i = 0; i < dst_length; i++ ) { \
        dst[i] = (expression); \
    }

//DST1, DST2 = X, Y
#define SETDST1DST2( expression1, expression2 ) \
    uint32_t i; \
    for( i = 0; i < src_length; i++ ) { \
        dst1[i] = (expression1); \
        dst2[i] = (expression2); \
    }

//DST = OP(SRC)
#define DSTSRC_HEAD( type ) \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsUint32(argv[2], &dst_offset); \
    FREGetObjectAsUint32(argv[3], &src_offset); \
    FREGetObjectAsUint32(argv[4], &dst_length); \
    FREGetObjectAsUint32(argv[5], &src_length); \
    type* dst = (type*)(dst_array.bytes+dst_offset); \
    type* src = (type*)(src_array.bytes+src_offset);


//DST = OP(SRC1, SRC2)
#define DSTSRC1SRC2_HEAD( type ) \
    FREByteArray dst_array; \
    FREByteArray src1_array; \
    FREByteArray src2_array; \
    uint32_t dst_offset; \
    uint32_t src1_offset; \
    uint32_t src2_offset; \
    uint32_t dst_length; \
    uint32_t src1_length; \
    uint32_t src2_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src1_array); \
    FREAcquireByteArray(argv[2], &src2_array); \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src1_offset); \
    FREGetObjectAsUint32(argv[5], &src2_offset); \
    FREGetObjectAsUint32(argv[6], &dst_length); \
    FREGetObjectAsUint32(argv[7], &src1_length); \
    FREGetObjectAsUint32(argv[8], &src2_length); \
    type* dst = (type*)(dst_array.bytes+dst_offset); \
    type* src1 = (type*)(src1_array.bytes+src1_offset); \
    type* src2 = (type*)(src2_array.bytes+src2_offset);

//DST = OP(SRC, VAL)
#define DSTSRCVAL_HEAD( uptype, downtype ) \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    uptype val; \
    downtype fval; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsDouble(argv[2], &val); \
    fval = (downtype)val; \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src_offset); \
    FREGetObjectAsUint32(argv[5], &dst_length); \
    FREGetObjectAsUint32(argv[6], &src_length); \
    downtype* dst = (downtype*)(dst_array.bytes+dst_offset); \
    downtype* src = (downtype*)(src_array.bytes+src_offset);


//DST = OP(SRC, VAL) [32i]
#define DSTSRCVAL32I_HEAD \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    int32_t fval; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsInt32(argv[2], &fval); \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src_offset); \
    FREGetObjectAsUint32(argv[5], &dst_length); \
    FREGetObjectAsUint32(argv[6], &src_length); \
    int32_t* dst = (int32_t*)(dst_array.bytes+dst_offset); \
    int32_t* src = (int32_t*)(src_array.bytes+src_offset);

//DST = OP(SRC, VAL) [32u]
#define DSTSRCVAL32U_HEAD \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    uint32_t fval; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsUint32(argv[2], &fval); \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src_offset); \
    FREGetObjectAsUint32(argv[5], &dst_length); \
    FREGetObjectAsUint32(argv[6], &src_length); \
    uint32_t* dst = (uint32_t*)(dst_array.bytes+dst_offset); \
    uint32_t* src = (uint32_t*)(src_array.bytes+src_offset);


//DST = OP(SRC1, SRC2, SRC)
#define DSTSRC1SRC2SRC3_HEAD( type ) \
    FREByteArray dst_array; \
    FREByteArray src1_array; \
    FREByteArray src2_array; \
    FREByteArray src3_array; \
    uint32_t dst_offset; \
    uint32_t src1_offset; \
    uint32_t src2_offset; \
    uint32_t src3_offset; \
    uint32_t dst_length; \
    uint32_t src1_length; \
    uint32_t src2_length; \
    uint32_t src3_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src1_array); \
    FREAcquireByteArray(argv[2], &src2_array); \
    FREAcquireByteArray(argv[3], &src3_array); \
    FREGetObjectAsUint32(argv[4], &dst_offset); \
    FREGetObjectAsUint32(argv[5], &src1_offset); \
    FREGetObjectAsUint32(argv[6], &src2_offset); \
    FREGetObjectAsUint32(argv[7], &src3_offset); \
    FREGetObjectAsUint32(argv[8], &dst_length); \
    FREGetObjectAsUint32(argv[9], &src1_length); \
    FREGetObjectAsUint32(argv[10], &src2_length); \
    FREGetObjectAsUint32(argv[11], &src3_length); \
    type* dst = (type*)(dst_array.bytes+dst_offset); \
    type* src1 = (type*)(src1_array.bytes+src1_offset); \
    type* src2 = (type*)(src2_array.bytes+src2_offset); \
    type* src3 = (type*)(src3_array.bytes+src3_offset);

//DST1, DST2 = OP(SRC)
#define DST1DST2SRC_HEAD( type ) \
    FREByteArray dst1_array; \
    FREByteArray dst2_array; \
    FREByteArray src_array; \
    uint32_t dst1_offset; \
    uint32_t dst2_offset; \
    uint32_t src_offset; \
    uint32_t dst1_length; \
    uint32_t dst2_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst1_array); \
    FREAcquireByteArray(argv[1], &dst2_array); \
    FREAcquireByteArray(argv[2], &src_array); \
    FREGetObjectAsUint32(argv[3], &dst1_offset); \
    FREGetObjectAsUint32(argv[4], &dst2_offset); \
    FREGetObjectAsUint32(argv[5], &src_offset); \
    FREGetObjectAsUint32(argv[6], &dst1_length); \
    FREGetObjectAsUint32(argv[7], &dst2_length); \
    FREGetObjectAsUint32(argv[8], &src_length); \
    type* dst1 = (type*)(dst1_array.bytes+dst1_offset); \
    type* dst2 = (type*)(dst2_array.bytes+dst2_offset); \
    type* src = (type*)(src_array.bytes+src_offset);

#define DSTSRC_TAIL \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DSTSRC1SRC2_TAIL \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DSTSRCVAL_TAIL \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DST1DST2SRC_TAIL \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DSTSRC1SRC2SRC3_TAIL \
    FREReleaseByteArray(argv[3]); \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

//DST = OP(SRC)
#define DstSrcFunc( type, expression ) \
    FREObject result; \
    DSTSRC_HEAD(type); \
    SETDST(expression); \
    DSTSRC_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC1, SRC2)
#define DstSrc1Src2Func( type, expression ) \
    FREObject result; \
    DSTSRC1SRC2_HEAD(type); \
    SETDST(expression); \
    DSTSRC1SRC2_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC1, SRC2, SRC3)
#define DstSrc1Src2Src3Func( type, expression ) \
    FREObject result; \
    DSTSRC1SRC2SRC3_HEAD(type); \
    SETDST(expression); \
    DSTSRC1SRC2SRC3_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC, VAL)
#define DstSrcValFunc( uptype, downtype, expression ) \
    FREObject result; \
    DSTSRCVAL_HEAD(uptype, downtype); \
    SETDST(expression); \
    DSTSRCVAL_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC, VAL) [32i]
#define DstSrcVal32iFunc( expression ) \
    FREObject result; \
    DSTSRCVAL32I_HEAD; \
    SETDST(expression); \
    DSTSRCVAL_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC, VAL) [32u]
#define DstSrcVal32uFunc( expression ) \
    FREObject result; \
    DSTSRCVAL32U_HEAD; \
    SETDST(expression); \
    DSTSRCVAL_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST1, DST2 = OP(SRC)
#define Dst1Dst2SrcFunc( type, expression1, expression2 ) \
    FREObject result; \
    DST1DST2SRC_HEAD(type); \
    SETDST1DST2(expression1, expression2); \
    DST1DST2SRC_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

#define EXPORT_FUNC( to, fname, ffunc ) \
    to.name = (const uint8_t*) fname; \
    to.functionData = NULL; \
    to.function = &ffunc;



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


FREObject Set_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	double val;
	float fval;
	uint32_t dst_offset;
	uint32_t dst_length;

	FREAcquireByteArray(argv[0], &dst_array);
	FREGetObjectAsDouble(argv[1], &val);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &dst_length);

	fval = (float)val;
	float* dst = (float*)(dst_array.bytes+dst_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = fval;
	}

	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Copy_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	FREByteArray src_array;
	uint32_t dst_offset;
	uint32_t src_offset;
	uint32_t dst_length;


	FREAcquireByteArray(argv[0], &dst_array);
	FREAcquireByteArray(argv[1], &src_array);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &dst_length);

	float* dst = (float*)(dst_array.bytes+dst_offset);
	float* src = (float*)(src_array.bytes+src_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = src[i];
	}

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Move_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	FREByteArray src_array;
	uint32_t dst_offset;
	uint32_t src_offset;
	uint32_t dst_length;


	FREAcquireByteArray(argv[0], &dst_array);
	FREAcquireByteArray(argv[1], &src_array);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &dst_length);

	float* dst = (float*)(dst_array.bytes+dst_offset);
	float* src = (float*)(src_array.bytes+src_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = src[i];
		src[i] = 0.0f;
	}

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}


FREObject Set_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	int32_t val;
	uint32_t dst_offset;
	uint32_t dst_length;

	FREAcquireByteArray(argv[0], &dst_array);
	FREGetObjectAsInt32(argv[1], &val);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &dst_length);

	int32_t* dst = (int32_t*)(dst_array.bytes+dst_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = val;
	}

	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Copy_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	FREByteArray src_array;
	uint32_t dst_offset;
	uint32_t src_offset;
	uint32_t dst_length;

	FREAcquireByteArray(argv[0], &dst_array);
	FREAcquireByteArray(argv[1], &src_array);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &dst_length);

	int32_t* dst = (int32_t*)(dst_array.bytes+dst_offset);
	int32_t* src = (int32_t*)(src_array.bytes+src_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = src[i];
	}

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Move_32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	FREByteArray src_array;
	uint32_t dst_offset;
	uint32_t src_offset;
	uint32_t dst_length;

	FREAcquireByteArray(argv[0], &dst_array);
	FREAcquireByteArray(argv[1], &src_array);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &dst_length);

	int32_t* dst = (int32_t*)(dst_array.bytes+dst_offset);
	int32_t* src = (int32_t*)(src_array.bytes+src_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = src[i];
		src[i] = 0;
	}

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}


FREObject Set_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	uint32_t val;
	uint32_t dst_offset;
	uint32_t dst_length;

	FREAcquireByteArray(argv[0], &dst_array);
	FREGetObjectAsUint32(argv[1], &val);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &dst_length);

	uint32_t* dst = (uint32_t*)(dst_array.bytes+dst_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = val;
	}

	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Copy_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	FREByteArray src_array;
	uint32_t dst_offset;
	uint32_t src_offset;
	uint32_t dst_length;

	FREAcquireByteArray(argv[0], &dst_array);
	FREAcquireByteArray(argv[1], &src_array);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &dst_length);

	uint32_t* dst = (uint32_t*)(dst_array.bytes+dst_offset);
	uint32_t* src = (uint32_t*)(src_array.bytes+src_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = src[i];
	}

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Move_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	FREByteArray dst_array;
	FREByteArray src_array;
	uint32_t dst_offset;
	uint32_t src_offset;
	uint32_t dst_length;

	FREAcquireByteArray(argv[0], &dst_array);
	FREAcquireByteArray(argv[1], &src_array);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &dst_length);

	uint32_t* dst = (uint32_t*)(dst_array.bytes+dst_offset);
	uint32_t* src = (uint32_t*)(src_array.bytes+src_offset);

	uint32_t i;

	for( i = 0; i < dst_length; i++ ) {
		dst[i] = src[i];
		src[i] = 0;
	}

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);
	FRENewObjectFromBool(1, &result);

	return result;
}


FREObject GetMemoryAddress( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    FREObject result;
    FREByteArray byteArray;

    FREAcquireByteArray(argv[0], &byteArray);

    uint32_t alignment = (uint32_t)&byteArray.bytes[0];

    FRENewObjectFromUint32(alignment, &result);

    FREReleaseByteArray(argv[0]);

    return result;
}


void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions) {
    *numFunctions = 84;
    FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

    EXPORT_FUNC(func[0],    "GetMemoryAddress",    GetMemoryAddress);
    EXPORT_FUNC(func[1],    "Add_32f",          Add_32f);
    EXPORT_FUNC(func[2],    "AddC_32f",         AddC_32f);
    EXPORT_FUNC(func[3],    "Sub_32f",          Sub_32f);
    EXPORT_FUNC(func[4],    "SubC_32f",         SubC_32f);
    EXPORT_FUNC(func[5],    "SubCRev_32f",      SubCRev_32f);
    EXPORT_FUNC(func[6],    "Mul_32f",          Mul_32f);
    EXPORT_FUNC(func[7],    "MulC_32f",         MulC_32f);
    EXPORT_FUNC(func[8],    "Div_32f",          Div_32f);
    EXPORT_FUNC(func[9],    "DivC_32f",         DivC_32f);
    EXPORT_FUNC(func[10],   "DivCRev_32f",      DivCRev_32f);
    EXPORT_FUNC(func[11],   "Sin_32f",          Sin_32f);
    EXPORT_FUNC(func[12],   "Cos_32f",          Cos_32f);
    EXPORT_FUNC(func[13],   "Tan_32f",          Tan_32f);
    EXPORT_FUNC(func[14],   "Asin_32f",         Asin_32f);
    EXPORT_FUNC(func[15],   "Acos_32f",         Acos_32f);
    EXPORT_FUNC(func[16],   "Atan_32f",         Atan_32f);
    EXPORT_FUNC(func[17],   "SinCos_32f",       SinCos_32f);
    EXPORT_FUNC(func[19],   "Atan2_32f",        Atan2_32f);
    EXPORT_FUNC(func[20],   "Exp_32f",          Exp_32f);
    EXPORT_FUNC(func[21],   "Log_32f",          Log_32f);
    EXPORT_FUNC(func[22],   "Log10_32f",        Log10_32f);
    EXPORT_FUNC(func[23],   "Pow_32f",          Pow_32f);
    EXPORT_FUNC(func[24],   "PowC_32f",         PowC_32f);
    EXPORT_FUNC(func[25],   "Sqrt_32f",         Sqrt_32f);
    EXPORT_FUNC(func[26],   "Cbrt_32f",         Cbrt_32f);
    EXPORT_FUNC(func[27],   "Ceil_32f",         Ceil_32f);
    EXPORT_FUNC(func[28],   "Floor_32f",        Floor_32f);
    EXPORT_FUNC(func[29],   "Abs_32f",          Abs_32f);
    EXPORT_FUNC(func[30],   "Mod_32f",          Mod_32f);
    EXPORT_FUNC(func[31],   "ModC_32f",         ModC_32f);
    EXPORT_FUNC(func[32],   "FMA_32f",          FMA_32f);

    EXPORT_FUNC(func[33],   "Add_32i",          Add_32i);
    EXPORT_FUNC(func[34],   "AddC_32i",         AddC_32i);
    EXPORT_FUNC(func[35],   "Sub_32i",          Sub_32i);
    EXPORT_FUNC(func[36],   "SubC_32i",         SubC_32i);
    EXPORT_FUNC(func[37],   "SubCRev_32i",      SubCRev_32i);
    EXPORT_FUNC(func[38],   "Mul_32i",          Mul_32i);
    EXPORT_FUNC(func[39],   "MulC_32i",         MulC_32i);
    EXPORT_FUNC(func[40],   "Div_32i",          Div_32i);
    EXPORT_FUNC(func[41],   "DivC_32i",         DivC_32i);
    EXPORT_FUNC(func[42],   "DivCRev_32i",      DivCRev_32i);
    EXPORT_FUNC(func[43],   "Mod_32i",          Mod_32i);
    EXPORT_FUNC(func[44],   "ModC_32i",         ModC_32i);

    EXPORT_FUNC(func[45],   "Add_32u",          Add_32u);
    EXPORT_FUNC(func[46],   "AddC_32u",         AddC_32u);
    EXPORT_FUNC(func[47],   "Sub_32u",          Sub_32u);
    EXPORT_FUNC(func[48],   "SubC_32u",         SubC_32u);
    EXPORT_FUNC(func[49],   "SubCRev_32u",      SubCRev_32u);
    EXPORT_FUNC(func[50],   "Mul_32u",          Mul_32u);
    EXPORT_FUNC(func[51],   "MulC_32u",         MulC_32u);
    EXPORT_FUNC(func[52],   "Div_32u",          Div_32u);
    EXPORT_FUNC(func[53],   "DivC_32u",         DivC_32u);
    EXPORT_FUNC(func[54],   "DivCRev_32u",      DivCRev_32u);
    EXPORT_FUNC(func[55],   "Mod_32u",          Mod_32u);
    EXPORT_FUNC(func[56],   "ModC_32u",         ModC_32u);

    EXPORT_FUNC(func[57],   "And_32i",          And_32i);
    EXPORT_FUNC(func[58],   "AndC_32i",         AndC_32i);
    EXPORT_FUNC(func[59],   "Or_32i",           Or_32i);
    EXPORT_FUNC(func[60],   "OrC_32i",          OrC_32i);
    EXPORT_FUNC(func[61],   "Xor_32i",          Xor_32i);
    EXPORT_FUNC(func[62],   "XorC_32i",         XorC_32i);
    EXPORT_FUNC(func[63],   "Not_32i",          Not_32i);
    EXPORT_FUNC(func[64],   "Lsh_32i",          Lsh_32i);
    EXPORT_FUNC(func[65],   "Rsh_32i",          Rsh_32i);

    EXPORT_FUNC(func[66],   "And_32u",          And_32u);
    EXPORT_FUNC(func[67],   "AndC_32u",         AndC_32u);
    EXPORT_FUNC(func[68],   "Or_32u",           Or_32u);
    EXPORT_FUNC(func[69],   "OrC_32u",          OrC_32u);
    EXPORT_FUNC(func[70],   "Xor_32u",          Xor_32u);
    EXPORT_FUNC(func[71],   "XorC_32u",         XorC_32u);
    EXPORT_FUNC(func[72],   "Not_32u",          Not_32u);
    EXPORT_FUNC(func[73],   "Lsh_32u",          Lsh_32u);
    EXPORT_FUNC(func[74],   "Rsh_32u",          Rsh_32u);

    EXPORT_FUNC(func[75],   "Set_32f",          Set_32f);
	EXPORT_FUNC(func[76],   "Copy_32f",         Copy_32f);
	EXPORT_FUNC(func[77],   "Move_32f",         Move_32f);

    EXPORT_FUNC(func[78],   "Set_32i",          Set_32i);
	EXPORT_FUNC(func[79],   "Copy_32i",         Copy_32i);
	EXPORT_FUNC(func[80],   "Move_32i",         Move_32i);

    EXPORT_FUNC(func[81],   "Set_32u",          Set_32u);
	EXPORT_FUNC(func[82],   "Copy_32u",         Copy_32u);
	EXPORT_FUNC(func[83],   "Move_32u",         Move_32u);



    *functions = func;
}

void contextFinalizer(FREContext ctx) {
    return;
}

void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer) {
    *ctxInitializer = &contextInitializer;
    *ctxFinalizer = &contextFinalizer;
}

void finalizer(void* extData) {
    return;
}
