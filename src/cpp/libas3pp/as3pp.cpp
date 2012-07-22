#include "as3pp.h"

extern "C" {

    void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions) {
        *numFunctions = 40;
        FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

        EXPORT_FUNC(func[0],    "GetMemoryAddress", GetMemoryAddress);

        EXPORT_FUNC(func[1],   "Timer_Refresh",   Timer_Refresh);
        EXPORT_FUNC(func[2],   "Timer_Start",     Timer_Start);
        EXPORT_FUNC(func[3],   "Timer_Tick",      Timer_Tick);

        EXPORT_FUNC(func[4],   "GetNumThreads",   GetNumThreads);
        
        EXPORT_FUNC(func[5],   "Set_32f",         Set_32f);
        EXPORT_FUNC(func[6],   "Copy_32f",        Copy_32f);

        EXPORT_FUNC(func[7],   "Add_32f",         Add_32f);
        EXPORT_FUNC(func[8],   "Sub_32f",         Sub_32f);
        EXPORT_FUNC(func[9],   "Mul_32f",         Mul_32f);
        EXPORT_FUNC(func[10],  "Div_32f",         Div_32f);

        EXPORT_FUNC(func[11],  "AddC_32f",        AddC_32f);
        EXPORT_FUNC(func[12],  "SubC_32f",        SubC_32f);
        EXPORT_FUNC(func[13],  "MulC_32f",        MulC_32f);
        EXPORT_FUNC(func[14],  "DivC_32f",        DivC_32f);

        EXPORT_FUNC(func[15],   "SubCRev_32f",    SubCRev_32f);
        EXPORT_FUNC(func[16],   "DivCRev_32f",    DivCRev_32f);

        EXPORT_FUNC(func[17],   "AddI_32f",       AddI_32f);
        EXPORT_FUNC(func[18],   "SubI_32f",       SubI_32f);
        EXPORT_FUNC(func[19],   "MulI_32f",       MulI_32f);
        EXPORT_FUNC(func[20],   "DivI_32f",       DivI_32f);

        EXPORT_FUNC(func[21],   "MulAdd_32f",     MulAdd_32f);

        EXPORT_FUNC(func[22],   "Sin_32f",        Sin_32f);
        EXPORT_FUNC(func[23],   "Cos_32f",        Cos_32f);
        EXPORT_FUNC(func[24],   "Tan_32f",        Tan_32f);
        EXPORT_FUNC(func[25],   "Asin_32f",       Asin_32f);
        EXPORT_FUNC(func[26],   "Acos_32f",       Acos_32f);
        EXPORT_FUNC(func[27],   "Atan_32f",       Atan_32f);
        EXPORT_FUNC(func[28],   "Atan2_32f",      Atan2_32f);

        EXPORT_FUNC(func[29],   "Sqrt_32f",       Sqrt_32f);
        EXPORT_FUNC(func[30],   "Cbrt_32f",       Cbrt_32f);
        EXPORT_FUNC(func[31],   "Exp_32f",        Exp_32f);
        EXPORT_FUNC(func[32],   "Ln_32f",         Ln_32f);
        EXPORT_FUNC(func[33],   "Log10_32f",      Log10_32f);
        EXPORT_FUNC(func[34],   "Pow_32f",        Pow_32f);
        EXPORT_FUNC(func[35],   "PowC_32f",       PowC_32f);

        EXPORT_FUNC(func[36],   "Abs_32f",        Abs_32f);
        EXPORT_FUNC(func[37],   "MinV_32f",       MinV_32f);
        EXPORT_FUNC(func[38],   "MaxV_32f",       MaxV_32f);

        EXPORT_FUNC(func[39],   "ThreshLTC_32f",  ThreshLTC_32f);

        *functions = func;

        fwStaticInit();
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