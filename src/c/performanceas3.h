/*
 * performanceas3.h
 *
 * Author: Martin Källman
 */

#ifndef PERFORMANCEAS3_H_
#define PERFORMANCEAS3_H_

#include "FlashRuntimeExtensions.h"


#define TYPE_FLOAT32 0
#define TYPE_INT32   1
#define TYPE_UINT32  2

#define EXPORT_FUNC( to, fname, ffunc ) \
    to.name = (const uint8_t*) fname; \
    to.functionData = NULL; \
    to.function = &ffunc;


__declspec(dllexport) void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
__declspec(dllexport) void finalizer(void* extData);

#endif
