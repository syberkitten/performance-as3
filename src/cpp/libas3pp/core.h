FREObject GetMemoryAddress( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    FREObject result;
    FREByteArray byteArray;

    FREAcquireByteArray(argv[0], &byteArray);

    uint32_t address = (uint32_t)&byteArray.bytes[0];

    FRENewObjectFromUint32(address, &result);
    FREReleaseByteArray(argv[0]);

    return result;
}

FREObject GetNumThreads( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    FREObject result;
    FRENewObjectFromUint32(fwGetNumThreads(), &result);
    return result;
}