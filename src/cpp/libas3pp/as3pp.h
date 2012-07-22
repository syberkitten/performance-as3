#include <memory>
#include <windows.h>

#include "FlashRuntimeExtensions.h"
#include "fwBase.h"
#include "fwSignal.h"

#include "core.h"
#include "vectormath.h"
#include "timer.h"

#define EXPORT_FUNC( to, fname, ffunc ) \
    to.name = (const uint8_t*) fname; \
    to.functionData = NULL; \
    to.function = &ffunc;

extern "C" {

    __declspec(dllexport) void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
    __declspec(dllexport) void finalizer(void* extData);

}