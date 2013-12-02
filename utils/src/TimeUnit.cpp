#include <iostream>
#include "../include/TimeUnit.h"


using namespace cph;

TimeUnit::TimeUnit() :
	ticks(0), last(), delta(0.0), total(0.0), average(0.0), maxDeviation(1000),
	errorLog()
{

}

TimeUnit::~TimeUnit() {

}


#ifdef _WIN32
#include <Windows.h>

void TimeUnit::start() {
	if(QueryPerformanceCounter(&last) == FALSE) std::cout << "Error with QueryPerformance" << std::endl;
}

void TimeUnit::end() {
	LARGE_INTEGER frequency;
	LARGE_INTEGER now;
	if(QueryPerformanceFrequency(&frequency) == FALSE) std::cout << "Error with QueryPerformance" << std::endl;
	if(QueryPerformanceCounter(&now) == FALSE) std::cout << "Error with QueryPerformance" << std::endl;
	delta = static_cast<double>((now.QuadPart - last.QuadPart) / static_cast<double>(frequency.QuadPart) * 1000);
	computeMisc();
}

#else

void TimeUnit::start() {
	defaultStart();
}

void TimeUnit::end() {
	defaultEnd();
}


#endif

void TimeUnit::defaultStart() {
	using namespace std::chrono;
	high_resolution_clock::time_point time = high_resolution_clock::now();
	defaultLast = duration_cast<microseconds>(time.time_since_epoch());
}

void TimeUnit::defaultEnd() {
	using namespace std::chrono;
	high_resolution_clock::time_point time = high_resolution_clock::now();
	microseconds now = duration_cast<microseconds>(time.time_since_epoch());
	delta = (now - defaultLast).count() * 0.001;
	computeMisc();
}

void TimeUnit::computeMisc() {
	if(delta <= 0) {
		delta = average;
		errorLog.pre() << "Delta " << delta << "ms <= 0! Internal error in TimeUnit" << std::endl;
		return;
	}
	total += delta;
	ticks++;
	average = total / ticks;
	if(delta > average + maxDeviation) {
		errorLog.pre() << "Delta " << delta << "ms > " << (average + maxDeviation) << "ms maximal deviation!" << std::endl;
		delta = average + maxDeviation;
	}
	maxDeviation = (maxDeviation + average * 1000) / 2.0;
}

long TimeUnit::getTicks() const {
	return ticks;
}

double TimeUnit::getDelta() const {
	return delta;
}

double TimeUnit::getAverage() const {
	return average;
}

void TimeUnit::setLog(Log* log, const char* target, const char* prepos) {
	if(strcmp(target, "error") == 0) {
		if(log != 0) {
			errorLog.setLogPtr(log);
			errorLog.setLogPrepos(prepos);
		} else {
			errorLog.setLogPtr(0);
		}
	}
}

