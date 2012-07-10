#include "../FlashRuntimeExtensions.h"
#include "../functions.h"

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

FREObject Cast_32u32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	CastFunc(uint32_t, float);
}

FREObject Cast_32u32i( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	CastFunc(uint32_t, int32_t);
}
