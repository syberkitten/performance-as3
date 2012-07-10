#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "FlashRuntimeExtensions.h"
#include "performanceas3.h"

#include "support/float32.h"
#include "support/int32.h"
#include "support/uint32.h"

#include "math/float32.h"
#include "math/int32.h"
#include "math/uint32.h"

#include "timer/timer.h"



/** Core Functions **/

FREObject GetMemoryAddress( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
    FREObject result;
    FREByteArray byteArray;

    FREAcquireByteArray(argv[0], &byteArray);

    uint32_t alignment = (uint32_t)&byteArray.bytes[0];

    FRENewObjectFromUint32(alignment, &result);
    FREReleaseByteArray(argv[0]);

    return result;
}



/** Extension Functions **/

void contextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions) {
    *numFunctions = 87;
    FRENamedFunction* func = (FRENamedFunction*) malloc(sizeof(FRENamedFunction) * (*numFunctions));

    EXPORT_FUNC(func[0],    "GetMemoryAddress", GetMemoryAddress);
    EXPORT_FUNC(func[1],    "Add_32f",          Add_32f);
    EXPORT_FUNC(func[2],    "AddC_32f",         AddC_32f);
    EXPORT_FUNC(func[3],    "Sub_32f",          Sub_32f);
    EXPORT_FUNC(func[4],    "SubC_32f",         SubC_32f);
    EXPORT_FUNC(func[5],    "SubCRev_32f",      SubCRev_32f);
    EXPORT_FUNC(func[6],    "Mul_32f",          Mul_32f);
    EXPORT_FUNC(func[7],    "MulC_32f",         MulC_32f);
    EXPORT_FUNC(func[8],    "Div_32f",          Div_32f);
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

    EXPORT_FUNC(func[33],   "Add_32i",          Add_32i);
    EXPORT_FUNC(func[34],   "AddC_32i",         AddC_32i);
    EXPORT_FUNC(func[35],   "Sub_32i",          Sub_32i);
    EXPORT_FUNC(func[36],   "SubC_32i",         SubC_32i);
    EXPORT_FUNC(func[37],   "SubCRev_32i",      SubCRev_32i);
    EXPORT_FUNC(func[38],   "Mul_32i",          Mul_32i);
    EXPORT_FUNC(func[39],   "MulC_32i",         MulC_32i);
    EXPORT_FUNC(func[40],   "Div_32i",          Div_32i);
    EXPORT_FUNC(func[41],   "DivC_32i",         DivC_32i);
    EXPORT_FUNC(func[42],   "DivCRev_32i",      DivCRev_32i);
    EXPORT_FUNC(func[43],   "Mod_32i",          Mod_32i);
    EXPORT_FUNC(func[44],   "ModC_32i",         ModC_32i);

    EXPORT_FUNC(func[45],   "Add_32u",          Add_32u);
    EXPORT_FUNC(func[46],   "AddC_32u",         AddC_32u);
    EXPORT_FUNC(func[47],   "Sub_32u",          Sub_32u);
    EXPORT_FUNC(func[48],   "SubC_32u",         SubC_32u);
    EXPORT_FUNC(func[49],   "SubCRev_32u",      SubCRev_32u);
    EXPORT_FUNC(func[50],   "Mul_32u",          Mul_32u);
    EXPORT_FUNC(func[51],   "MulC_32u",         MulC_32u);
    EXPORT_FUNC(func[52],   "Div_32u",          Div_32u);
    EXPORT_FUNC(func[53],   "DivC_32u",         DivC_32u);
    EXPORT_FUNC(func[54],   "DivCRev_32u",      DivCRev_32u);
    EXPORT_FUNC(func[55],   "Mod_32u",          Mod_32u);
    EXPORT_FUNC(func[56],   "ModC_32u",         ModC_32u);

    EXPORT_FUNC(func[57],   "And_32i",          And_32i);
    EXPORT_FUNC(func[58],   "AndC_32i",         AndC_32i);
    EXPORT_FUNC(func[59],   "Or_32i",           Or_32i);
    EXPORT_FUNC(func[60],   "OrC_32i",          OrC_32i);
    EXPORT_FUNC(func[61],   "Xor_32i",          Xor_32i);
    EXPORT_FUNC(func[62],   "XorC_32i",         XorC_32i);
    EXPORT_FUNC(func[63],   "Not_32i",          Not_32i);
    EXPORT_FUNC(func[64],   "Lsh_32i",          Lsh_32i);
    EXPORT_FUNC(func[65],   "Rsh_32i",          Rsh_32i);

    EXPORT_FUNC(func[66],   "And_32u",          And_32u);
    EXPORT_FUNC(func[67],   "AndC_32u",         AndC_32u);
    EXPORT_FUNC(func[68],   "Or_32u",           Or_32u);
    EXPORT_FUNC(func[69],   "OrC_32u",          OrC_32u);
    EXPORT_FUNC(func[70],   "Xor_32u",          Xor_32u);
    EXPORT_FUNC(func[71],   "XorC_32u",         XorC_32u);
    EXPORT_FUNC(func[72],   "Not_32u",          Not_32u);
    EXPORT_FUNC(func[73],   "Lsh_32u",          Lsh_32u);
    EXPORT_FUNC(func[74],   "Rsh_32u",          Rsh_32u);

    EXPORT_FUNC(func[75],   "Set_32f",          Set_32f);
    EXPORT_FUNC(func[76],   "Copy_32f",         Copy_32f);
    EXPORT_FUNC(func[77],   "Move_32f",         Move_32f);

    EXPORT_FUNC(func[78],   "Set_32i",          Set_32i);
    EXPORT_FUNC(func[79],   "Copy_32i",         Copy_32i);
    EXPORT_FUNC(func[80],   "Move_32i",         Move_32i);

    EXPORT_FUNC(func[81],   "Set_32u",          Set_32u);
    EXPORT_FUNC(func[82],   "Copy_32u",         Copy_32u);
    EXPORT_FUNC(func[83],   "Move_32u",         Move_32u);

    EXPORT_FUNC(func[84],   "TimerRefreshFrequency", TimerStart);
    EXPORT_FUNC(func[85],   "TimerStart",       TimerStart);
    EXPORT_FUNC(func[86],   "TimerTick",        TimerTick);

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
