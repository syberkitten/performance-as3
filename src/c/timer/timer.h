#include "../FlashRuntimeExtensions.h"
#include <windows.h>


LARGE_INTEGER timer_frequency;
LARGE_INTEGER timer_t1, timer_t2;


FREObject TimerRefreshFrequency( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	QueryPerformanceFrequency(&timer_frequency);

	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject TimerStart( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;

	QueryPerformanceCounter(&timer_t1);

	FRENewObjectFromBool(1, &result);

	return result;
}

FREObject TimerTick( FREContext ctx, void* funcData, uint32_t argc, FREObject argv[] ) {
	FREObject result;
	double timer_sec;

	QueryPerformanceCounter(&timer_t2);

	timer_sec = (double)(timer_t2.QuadPart - timer_t1.QuadPart);
	timer_sec = timer_sec / (double)timer_frequency.QuadPart;

	FRENewObjectFromDouble(timer_sec, &result);

	return result;
}
