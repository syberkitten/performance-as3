LARGE_INTEGER Timer_frequency;
LARGE_INTEGER Timer_t1, Timer_t2;


FREObject Timer_Refresh( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	QueryPerformanceFrequency(&Timer_frequency);

	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Timer_Start( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	QueryPerformanceCounter(&Timer_t1);

	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject Timer_Tick( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	double timer_sec;

	QueryPerformanceCounter(&Timer_t2);

	timer_sec = (double)(Timer_t2.QuadPart - Timer_t1.QuadPart);
	timer_sec = timer_sec / (double)Timer_frequency.QuadPart;

	FRENewObjectFromDouble(timer_sec, &result);

	return result;
}