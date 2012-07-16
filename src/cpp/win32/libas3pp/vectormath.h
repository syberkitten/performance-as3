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


/** AddC, SubC, MulC, DivC **/

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


/** SubCRev, DivCRev **/

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