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

#define F32_SETDST( expression ) \
    uint32_t i; \
    for( i = 0; i < dst_length; i++ ) { \
        dst[i] = (expression); \
    }

#define F32_SETDST1DST2( expression1, expression2 ) \
    uint32_t i; \
    for( i = 0; i < src_length; i++ ) { \
        dst1[i] = (expression1); \
        dst2[i] = (expression2); \
    }

#define F32_DSTSRC1SRC2_HEAD \
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
    float* dst = (float*)(dst_array.bytes+dst_offset); \
    float* src1 = (float*)(src1_array.bytes+src1_offset); \
    float* src2 = (float*)(src2_array.bytes+src2_offset);

#define F32_DSTSRC1SRC2_TAIL \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define F32_DSTSRC1SRC2_FUNC( expression ) \
    FREObject result; \
    F32_DSTSRC1SRC2_HEAD; \
    F32_SETDST((expression)); \
    F32_DSTSRC1SRC2_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

#define F32_DSTSRC1SRC2SRC3_HEAD \
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
    float* dst = (float*)(dst_array.bytes+dst_offset); \
    float* src1 = (float*)(src1_array.bytes+src1_offset); \
    float* src2 = (float*)(src2_array.bytes+src2_offset); \
    float* src3 = (float*)(src3_array.bytes+src3_offset);

#define F32_DSTSRC1SRC2SRC3_TAIL \
    FREReleaseByteArray(argv[3]); \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define F32_DSTSRC1SRC2SRC3_FUNC( expression ) \
    FREObject result; \
    F32_DSTSRC1SRC2SRC3_HEAD; \
    F32_SETDST((expression)); \
    F32_DSTSRC1SRC2SRC3_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

#define F32_DST1DST2SRC_HEAD \
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
    float* dst1 = (float*)(dst1_array.bytes+dst1_offset); \
    float* dst2 = (float*)(dst2_array.bytes+dst2_offset); \
    float* src = (float*)(src_array.bytes+src_offset);

#define F32_DST1DST2SRC_TAIL \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define F32_DST1DST2SRC_FUNC( expression1, expression2 ) \
    FREObject result; \
    F32_DST1DST2SRC_HEAD; \
    F32_SETDST1DST2(expression1, expression2); \
    F32_DST1DST2SRC_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

#define F32_DSTSRCVAL_HEAD \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    double val; \
    float fval; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsDouble(argv[2], &val); \
    fval = (float)val; \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src_offset); \
    FREGetObjectAsUint32(argv[5], &dst_length); \
    FREGetObjectAsUint32(argv[6], &src_length); \
    float* dst = (float*)(dst_array.bytes+dst_offset); \
    float* src = (float*)(src_array.bytes+src_offset);

#define F32_DSTSRCVAL_TAIL \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define F32_DSTSRCVAL_FUNC( expression ) \
    FREObject result; \
    F32_DSTSRCVAL_HEAD; \
    F32_SETDST((expression)); \
    F32_DSTSRCVAL_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

#define F32_DSTSRC_HEAD \
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
    float* dst = (float*)(dst_array.bytes+dst_offset); \
    float* src = (float*)(src_array.bytes+src_offset);

#define F32_DSTSRC_TAIL \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define F32_DSTSRC_FUNC( expression ) \
    FREObject result; \
    F32_DSTSRC_HEAD; \
    F32_SETDST((expression)); \
    F32_DSTSRC_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

#define EXPORT_FUNC( to, fname, ffunc ) \
	to.name = (const uint8_t*) fname; \
	to.functionData = NULL; \
	to.function = &ffunc;


const float LOG_10 = 2.30258509299404f;


FREObject Add_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2_FUNC(src1[i] + src2[i]);
}

FREObject AddC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC(src[i] + fval);
}

FREObject Sub_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2_FUNC(src1[i] - src2[i]);
}

FREObject SubC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC(src[i] - fval);
}

FREObject SubCRev_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC(fval - src[i]);
}

FREObject Mul_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2_FUNC(src1[i] * src2[i]);
}

FREObject MulC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC(src[i] * fval);
}

FREObject Div_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2_FUNC(src1[i] / src2[i]);
}

FREObject DivC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC(src[i] / fval);
}

FREObject DivCRev_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC(fval / src[i]);
}

FREObject Sin_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xsinf(src[i]));
}

FREObject Cos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xcosf(src[i]));
}

FREObject Tan_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xtanf(src[i]));
}

FREObject Asin_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xasinf(src[i]));
}

FREObject Acos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xacosf(src[i]));
}

FREObject Atan_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xatanf(src[i]));
}

FREObject SinCos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DST1DST2SRC_FUNC(xsinf(src[i]), xcosf(src[i]));
}

FREObject Atan2_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2_FUNC(xatan2f(src1[i], src2[i]));
}

FREObject Exp_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xexpf(src[i]));
}

FREObject Log_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xlogf(src[i]));
}

FREObject Log10_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xlogf(src[i]) / LOG_10);
}

FREObject Pow_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2_FUNC((float)xpow(src1[i], src2[i]));
}


FREObject PowC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC((float)xpow(src[i], fval));
}

FREObject Sqrt_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC((float)xsqrt(src[i]));
}

FREObject Cbrt_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(xcbrtf(src[i]));
}

FREObject Ceil_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(ceilf(src[i]));
}

FREObject Floor_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(floorf(src[i]));
}

FREObject Abs_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC_FUNC(fabsf(src[i]));
}

FREObject Mod_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2_FUNC(fmod(src1[i], src2[i]));
}

FREObject ModC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRCVAL_FUNC(fmod(src[i], fval));
}

FREObject FMA_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    F32_DSTSRC1SRC2SRC3_FUNC((float)xfma(src1[i], src2[i], src3[i]));
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
    *numFunctions = 33;
    FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

    EXPORT_FUNC(func[0],    "GetMemoryAddress",	GetMemoryAddress);
    EXPORT_FUNC(func[1],    "Add_32f",          Add_32f);
    EXPORT_FUNC(func[2],    "AddC_32f",         AddC_32f);
    EXPORT_FUNC(func[3],    "Sub_32f",          Sub_32f);
    EXPORT_FUNC(func[4],    "SubC_32f",         SubC_32f);
    EXPORT_FUNC(func[5],    "SubCRev_32f",      SubCRev_32f);
    EXPORT_FUNC(func[6],    "Mul_32f",          Mul_32f);
    EXPORT_FUNC(func[7],    "MulC_32f",         MulC_32f);
    EXPORT_FUNC(func[8],	"Div_32f",          Div_32f);
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
