/** Add, Sub, Mul, Div **/

FREObject Add_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc1, fsrc2;
	uint32_t dst_offset, src1_offset, src2_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc1);
	FREAcquireByteArray(argv[2], &fsrc2);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src1_offset);
	FREGetObjectAsUint32(argv[5], &src2_offset);
	FREGetObjectAsUint32(argv[6], &n);

	fwsAdd_32f(
        (Fw32f*)fsrc2.bytes + src2_offset,
		(Fw32f*)fsrc1.bytes + src1_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[2]);
	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Sub_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc1, fsrc2;
	uint32_t dst_offset, src1_offset, src2_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc1);
	FREAcquireByteArray(argv[2], &fsrc2);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src1_offset);
	FREGetObjectAsUint32(argv[5], &src2_offset);
	FREGetObjectAsUint32(argv[6], &n);

	fwsSub_32f(
        (Fw32f*)fsrc2.bytes + src2_offset,
		(Fw32f*)fsrc1.bytes + src1_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[2]);
	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Mul_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc1, fsrc2;
	uint32_t dst_offset, src1_offset, src2_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc1);
	FREAcquireByteArray(argv[2], &fsrc2);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src1_offset);
	FREGetObjectAsUint32(argv[5], &src2_offset);
	FREGetObjectAsUint32(argv[6], &n);

	fwsMul_32f(
        (Fw32f*)fsrc2.bytes + src2_offset,
		(Fw32f*)fsrc1.bytes + src1_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[2]);
	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Div_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc1, fsrc2;
	uint32_t dst_offset, src1_offset, src2_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc1);
	FREAcquireByteArray(argv[2], &fsrc2);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src1_offset);
	FREGetObjectAsUint32(argv[5], &src2_offset);
	FREGetObjectAsUint32(argv[6], &n);

	fwsDiv_32f(
        (Fw32f*)fsrc2.bytes + src2_offset,
		(Fw32f*)fsrc1.bytes + src1_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[2]);
	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject AddC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsAddC_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject SubC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsSubC_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject MulC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsMulC_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject DivC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsDivC_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject SubCRev_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsSubCRev_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject DivCRev_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsDivCRev_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject AddI_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdstSrc, fsrc;
	uint32_t dstSrc_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdstSrc);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dstSrc_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsAdd_32f_I(
        (Fw32f*)fsrc.bytes + src_offset,
        (Fw32f*)fdstSrc.bytes + dstSrc_offset,
        n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject SubI_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdstSrc, fsrc;
	uint32_t dstSrc_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdstSrc);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dstSrc_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsSub_32f_I(
        (Fw32f*)fsrc.bytes + src_offset,
        (Fw32f*)fdstSrc.bytes + dstSrc_offset,
        n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject MulI_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdstSrc, fsrc;
	uint32_t dstSrc_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdstSrc);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dstSrc_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsMul_32f_I(
        (Fw32f*)fsrc.bytes + src_offset,
        (Fw32f*)fdstSrc.bytes + dstSrc_offset,
        n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject DivI_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdstSrc, fsrc;
	uint32_t dstSrc_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdstSrc);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dstSrc_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsDiv_32f_I(
        (Fw32f*)fsrc.bytes + src_offset,
        (Fw32f*)fdstSrc.bytes + dstSrc_offset,
        n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject MulAdd_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc1, fsrc2;
	uint32_t dst_offset, src1_offset, src2_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc1);
	FREAcquireByteArray(argv[2], &fsrc2);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src1_offset);
	FREGetObjectAsUint32(argv[5], &src2_offset);
	FREGetObjectAsUint32(argv[6], &n);

    fwsAddProduct_32f(
        (Fw32f*)fsrc2.bytes + src2_offset,
		(Fw32f*)fsrc1.bytes + src1_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[2]);
	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

//TODO: SubIRev, DivIRev, AddIC, SubIC, SubICRev, MulIC, DivIC, DivICRev

FREObject Sin_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsSin_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Cos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsCos_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Tan_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsTan_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Acos_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsAcos_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Asin_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsAsin_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Atan_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsSin_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Atan2_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc1, fsrc2;
	uint32_t dst_offset, src1_offset, src2_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc1);
	FREAcquireByteArray(argv[2], &fsrc2);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src1_offset);
	FREGetObjectAsUint32(argv[5], &src2_offset);
	FREGetObjectAsUint32(argv[6], &n);

    fwsAtan2_32f_A11(
        (Fw32f*)fsrc2.bytes + src2_offset,
		(Fw32f*)fsrc1.bytes + src1_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[2]);
	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Sqrt_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsSqrt_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Cbrt_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsCbrt_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Exp_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsExp_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Ln_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsLn_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Log10_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsLog10_32f_A11(
        (Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Pow_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc1, fsrc2;
	uint32_t dst_offset, src1_offset, src2_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc1);
	FREAcquireByteArray(argv[2], &fsrc2);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src1_offset);
	FREGetObjectAsUint32(argv[5], &src2_offset);
	FREGetObjectAsUint32(argv[6], &n);

	fwsPow_32f_A11(
        (Fw32f*)fsrc2.bytes + src2_offset,
		(Fw32f*)fsrc1.bytes + src1_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[2]);
	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject PowC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsPowx_32f_A11(
		(Fw32f*)fsrc.bytes + src_offset,
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Abs_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsAbs_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject MinV_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsMinEvery_32f_I(
		(Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject MaxV_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsMaxEvery_32f_I(
		(Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Copy_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &src_offset);
	FREGetObjectAsUint32(argv[4], &n);

    fwsCopy_32f(
		(Fw32f*)fsrc.bytes + src_offset,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject Set_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst;
    double fval;
	uint32_t dst_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
    FREGetObjectAsDouble(argv[1], &fval);
	FREGetObjectAsUint32(argv[2], &dst_offset);
	FREGetObjectAsUint32(argv[3], &n);

    fwsSet_32f(
		(float)fval,
		(Fw32f*)fdst.bytes + dst_offset,
		n
	);

	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

FREObject ThreshLTC_32f( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	FREByteArray fdst, fsrc;
    double fval;
	uint32_t dst_offset, src_offset;
	uint32_t n;

	FREAcquireByteArray(argv[0], &fdst);
	FREAcquireByteArray(argv[1], &fsrc);
    FREGetObjectAsDouble(argv[2], &fval);
	FREGetObjectAsUint32(argv[3], &dst_offset);
	FREGetObjectAsUint32(argv[4], &src_offset);
	FREGetObjectAsUint32(argv[5], &n);

    fwsThreshold_LTVal_32f(
        (Fw32f*)fsrc.bytes + src_offset,
        (Fw32f*)fdst.bytes + dst_offset,
        n,
        (float)fval, (float)fval
    );

	FREReleaseByteArray(argv[1]);
	FREReleaseByteArray(argv[0]);

	FRENewObjectFromUint32(1, &result);
	return result;
}

//TODO: Additional threshold and compare functions