#include "as3pp.h"

extern "C" {

    FREObject GetMemoryAddress( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
        FREObject result;
        FREByteArray byteArray;

        FREAcquireByteArray(argv[0], &byteArray);

        uint32_t address = (uint32_t)&byteArray.bytes[0];

        FRENewObjectFromUint32(address, &result);
        FREReleaseByteArray(argv[0]);

        return result;
    }


    void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions) {
        *numFunctions = 5;
        FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

        EXPORT_FUNC(func[0],    "GetMemoryAddress", GetMemoryAddress);

        EXPORT_FUNC(func[1],    "Add_32f",          Add_32f);
        EXPORT_FUNC(func[2],    "Sub_32f",          Sub_32f);
        EXPORT_FUNC(func[3],    "Mul_32f",          Mul_32f);
        EXPORT_FUNC(func[4],    "Div_32f",          Div_32f);

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

}