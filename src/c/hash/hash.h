#include "../FlashRuntimeExtensions.h"
#include "jenkins32/jenkins32.h"
#include "xxhash/xxhash.h"


FREObject Hash_Wang_32u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    FREObject result;
    FREByteArray dst_array;
    FREByteArray src_array;
    uint32_t dst_length;

    FREAcquireByteArray(argv[0], &dst_array);
    FREAcquireByteArray(argv[1], &src_array);
    FREGetObjectAsUint32(argv[2], &dst_length);

    uint32_t* dst = (uint32_t*)dst_array.bytes;
    uint32_t* src = (uint32_t*)src_array.bytes;

    uint32_t i;
    uint32_t key;

    for( i = 0; i < dst_length; i++ ) {
    	key = src[i];
    	JENKINS32(key);
    	dst[i] = key;
    }

    FREReleaseByteArray(argv[1]);
    FREReleaseByteArray(argv[0]);
    FRENewObjectFromBool(1, &result);

    return result;
}

FREObject Hash_XXHFast_8u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    FREObject result;
    FREByteArray src_array;
    uint32_t src_length;
    uint32_t seed;

    FREAcquireByteArray(argv[0], &src_array);
    FREGetObjectAsUint32(argv[1], &src_length);
    FREGetObjectAsUint32(argv[2], &seed);

    uint32_t hash = XXH_fast32((uint8_t*)src_array.bytes, src_length, seed);

    FREReleaseByteArray(argv[0]);
    FRENewObjectFromUint32(hash, &result);

    return result;
}

FREObject Hash_XXHStrong_8u( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    FREObject result;
    FREByteArray src_array;
    uint32_t src_length;
    uint32_t seed;

    FREAcquireByteArray(argv[0], &src_array);
    FREGetObjectAsUint32(argv[1], &src_length);
    FREGetObjectAsUint32(argv[2], &seed);

    uint32_t hash = XXH_strong32((uint8_t*)src_array.bytes, src_length, seed);

    FREReleaseByteArray(argv[0]);
    FRENewObjectFromUint32(hash, &result);

    return result;
}
