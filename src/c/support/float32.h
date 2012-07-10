#include "../FlashRuntimeExtensions.h"
#include "../functions.h"

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

FREObject Cast_32f32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	CastFunc(float, uint32_t);
}

FREObject Cast_32f32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	CastFunc(float, int32_t);
}
