/*
 * performanceas3.h
 *
 * Author: Martin Källman
 */

#ifndef PERFORMANCEAS3_H_
#define PERFORMANCEAS3_H_

#include "FlashRuntimeExtensions.h"

__declspec(dllexport) void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
__declspec(dllexport) void finalizer(void* extData);

#endif
