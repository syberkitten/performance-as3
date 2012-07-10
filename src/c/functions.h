#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//DST = X
#define SETDST( expression ) \
    uint32_t i; \
    for( i = 0; i < dst_length; i++ ) { \
        dst[i] = (expression); \
    }

//DST1, DST2 = X, Y
#define SETDST1DST2( expression1, expression2 ) \
    uint32_t i; \
    for( i = 0; i < src_length; i++ ) { \
        dst1[i] = (expression1); \
        dst2[i] = (expression2); \
    }

//DST = OP(SRC)
#define DSTSRC_HEAD( type ) \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsUint32(argv[2], &dst_offset); \
    FREGetObjectAsUint32(argv[3], &src_offset); \
    FREGetObjectAsUint32(argv[4], &dst_length); \
    FREGetObjectAsUint32(argv[5], &src_length); \
    type* dst = (type*)(dst_array.bytes+dst_offset); \
    type* src = (type*)(src_array.bytes+src_offset);


//DST = OP(SRC1, SRC2)
#define DSTSRC1SRC2_HEAD( type ) \
    FREByteArray dst_array; \
    FREByteArray src1_array; \
    FREByteArray src2_array; \
    uint32_t dst_offset; \
    uint32_t src1_offset; \
    uint32_t src2_offset; \
    uint32_t dst_length; \
    uint32_t src1_length; \
    uint32_t src2_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src1_array); \
    FREAcquireByteArray(argv[2], &src2_array); \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src1_offset); \
    FREGetObjectAsUint32(argv[5], &src2_offset); \
    FREGetObjectAsUint32(argv[6], &dst_length); \
    FREGetObjectAsUint32(argv[7], &src1_length); \
    FREGetObjectAsUint32(argv[8], &src2_length); \
    type* dst = (type*)(dst_array.bytes+dst_offset); \
    type* src1 = (type*)(src1_array.bytes+src1_offset); \
    type* src2 = (type*)(src2_array.bytes+src2_offset);

//DST = OP(SRC, VAL)
#define DSTSRCVAL_HEAD( uptype, downtype ) \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    uptype val; \
    downtype fval; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsDouble(argv[2], &val); \
    fval = (downtype)val; \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src_offset); \
    FREGetObjectAsUint32(argv[5], &dst_length); \
    FREGetObjectAsUint32(argv[6], &src_length); \
    downtype* dst = (downtype*)(dst_array.bytes+dst_offset); \
    downtype* src = (downtype*)(src_array.bytes+src_offset);


//DST = OP(SRC, VAL) [32i]
#define DSTSRCVAL32I_HEAD \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    int32_t fval; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsInt32(argv[2], &fval); \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src_offset); \
    FREGetObjectAsUint32(argv[5], &dst_length); \
    FREGetObjectAsUint32(argv[6], &src_length); \
    int32_t* dst = (int32_t*)(dst_array.bytes+dst_offset); \
    int32_t* src = (int32_t*)(src_array.bytes+src_offset);

//DST = OP(SRC, VAL) [32u]
#define DSTSRCVAL32U_HEAD \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    uint32_t fval; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsUint32(argv[2], &fval); \
    FREGetObjectAsUint32(argv[3], &dst_offset); \
    FREGetObjectAsUint32(argv[4], &src_offset); \
    FREGetObjectAsUint32(argv[5], &dst_length); \
    FREGetObjectAsUint32(argv[6], &src_length); \
    uint32_t* dst = (uint32_t*)(dst_array.bytes+dst_offset); \
    uint32_t* src = (uint32_t*)(src_array.bytes+src_offset);


//DST = OP(SRC1, SRC2, SRC)
#define DSTSRC1SRC2SRC3_HEAD( type ) \
    FREByteArray dst_array; \
    FREByteArray src1_array; \
    FREByteArray src2_array; \
    FREByteArray src3_array; \
    uint32_t dst_offset; \
    uint32_t src1_offset; \
    uint32_t src2_offset; \
    uint32_t src3_offset; \
    uint32_t dst_length; \
    uint32_t src1_length; \
    uint32_t src2_length; \
    uint32_t src3_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src1_array); \
    FREAcquireByteArray(argv[2], &src2_array); \
    FREAcquireByteArray(argv[3], &src3_array); \
    FREGetObjectAsUint32(argv[4], &dst_offset); \
    FREGetObjectAsUint32(argv[5], &src1_offset); \
    FREGetObjectAsUint32(argv[6], &src2_offset); \
    FREGetObjectAsUint32(argv[7], &src3_offset); \
    FREGetObjectAsUint32(argv[8], &dst_length); \
    FREGetObjectAsUint32(argv[9], &src1_length); \
    FREGetObjectAsUint32(argv[10], &src2_length); \
    FREGetObjectAsUint32(argv[11], &src3_length); \
    type* dst = (type*)(dst_array.bytes+dst_offset); \
    type* src1 = (type*)(src1_array.bytes+src1_offset); \
    type* src2 = (type*)(src2_array.bytes+src2_offset); \
    type* src3 = (type*)(src3_array.bytes+src3_offset);

//DST1, DST2 = OP(SRC)
#define DST1DST2SRC_HEAD( type ) \
    FREByteArray dst1_array; \
    FREByteArray dst2_array; \
    FREByteArray src_array; \
    uint32_t dst1_offset; \
    uint32_t dst2_offset; \
    uint32_t src_offset; \
    uint32_t dst1_length; \
    uint32_t dst2_length; \
    uint32_t src_length; \
    FREAcquireByteArray(argv[0], &dst1_array); \
    FREAcquireByteArray(argv[1], &dst2_array); \
    FREAcquireByteArray(argv[2], &src_array); \
    FREGetObjectAsUint32(argv[3], &dst1_offset); \
    FREGetObjectAsUint32(argv[4], &dst2_offset); \
    FREGetObjectAsUint32(argv[5], &src_offset); \
    FREGetObjectAsUint32(argv[6], &dst1_length); \
    FREGetObjectAsUint32(argv[7], &dst2_length); \
    FREGetObjectAsUint32(argv[8], &src_length); \
    type* dst1 = (type*)(dst1_array.bytes+dst1_offset); \
    type* dst2 = (type*)(dst2_array.bytes+dst2_offset); \
    type* src = (type*)(src_array.bytes+src_offset);

#define CAST_HEAD( src_type, dst_type ) \
    FREByteArray dst_array; \
    FREByteArray src_array; \
    uint32_t dst_offset; \
    uint32_t src_offset; \
    uint32_t dst_length; \
    FREAcquireByteArray(argv[0], &dst_array); \
    FREAcquireByteArray(argv[1], &src_array); \
    FREGetObjectAsUint32(argv[2], &dst_offset); \
    FREGetObjectAsUint32(argv[3], &src_offset); \
    FREGetObjectAsUint32(argv[4], &dst_length); \
    dst_type* dst = (dst_type*)(dst_array.bytes+dst_offset); \
    src_type* src = (src_type*)(src_array.bytes+src_offset);

#define DSTSRC_TAIL \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DSTSRC1SRC2_TAIL \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DSTSRCVAL_TAIL \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DST1DST2SRC_TAIL \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define DSTSRC1SRC2SRC3_TAIL \
    FREReleaseByteArray(argv[3]); \
    FREReleaseByteArray(argv[2]); \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

#define CAST_TAIL \
    FREReleaseByteArray(argv[1]); \
    FREReleaseByteArray(argv[0]);

//DST = OP(SRC)
#define DstSrcFunc( type, expression ) \
    FREObject result; \
    DSTSRC_HEAD(type); \
    SETDST(expression); \
    DSTSRC_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC1, SRC2)
#define DstSrc1Src2Func( type, expression ) \
    FREObject result; \
    DSTSRC1SRC2_HEAD(type); \
    SETDST(expression); \
    DSTSRC1SRC2_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC1, SRC2, SRC3)
#define DstSrc1Src2Src3Func( type, expression ) \
    FREObject result; \
    DSTSRC1SRC2SRC3_HEAD(type); \
    SETDST(expression); \
    DSTSRC1SRC2SRC3_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC, VAL)
#define DstSrcValFunc( uptype, downtype, expression ) \
    FREObject result; \
    DSTSRCVAL_HEAD(uptype, downtype); \
    SETDST(expression); \
    DSTSRCVAL_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC, VAL) [32i]
#define DstSrcVal32iFunc( expression ) \
    FREObject result; \
    DSTSRCVAL32I_HEAD; \
    SETDST(expression); \
    DSTSRCVAL_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC, VAL) [32u]
#define DstSrcVal32uFunc( expression ) \
    FREObject result; \
    DSTSRCVAL32U_HEAD; \
    SETDST(expression); \
    DSTSRCVAL_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST1, DST2 = OP(SRC)
#define Dst1Dst2SrcFunc( type, expression1, expression2 ) \
    FREObject result; \
    DST1DST2SRC_HEAD(type); \
    SETDST1DST2(expression1, expression2); \
    DST1DST2SRC_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;

//DST = OP(SRC)
#define CastFunc( src_type, dst_type ) \
    FREObject result; \
    CAST_HEAD(src_type, dst_type); \
    SETDST((dst_type)src[i]); \
    CAST_TAIL; \
    FRENewObjectFromBool(1, &result); \
    return result;


#endif /* FUNCTIONS_H_ */
