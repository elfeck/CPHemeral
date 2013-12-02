#ifndef TIME_UNIT_H_
#define TIME_UNIT_H_

#include <chrono>
#include "Logger.h"

#ifdef _WIN32

#include <Windows.h>
typedef LARGE_INTEGER cph_time;

#else

typedef std::chrono::microseconds cph_time;

#endif

namespace cph {

class TimeUnit {

private:
	long ticks;
	cph_time last;
	std::chrono::microseconds defaultLast;
	double average, total, delta, maxDeviation;
	Logger errorLog;

	void computeMisc();
	void defaultStart();
	void defaultEnd();

public:
	TimeUnit();
	~TimeUnit();

	void start();
	void end();

	long getTicks() const;
	double getDelta() const;
	double getAverage() const;

	void setLog(Log* log, const char* target, const char* prepos = "");
};

}

#endif
