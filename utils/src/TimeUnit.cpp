#include <iostream>

#include "../include/TimeUnit.h"


using namespace cph;

TimeUnit::TimeUnit() :
	last(0), delta(0), total(0), ticks(0),
	average(0.0)
{

}

TimeUnit::~TimeUnit() {

}

void TimeUnit::enterStart(long time) {
	last = time;
}

void TimeUnit::enterEnd(long time) {
	ticks++;
	delta = time - last;
	total += delta;
	average = (double) total / ticks;
}

void TimeUnit::printRate() const {
	std::cout << delta << "ms  current rate" << std::endl;
}

void TimeUnit::printAverageRate() const {
	std::cout << average << "ms  average rate" << std::endl;
}

void TimeUnit::printAll() const {
	std::cout << delta << "ms    [" << average << "ms]    [@ " << ticks << " ticks]" << std::endl;
}

long TimeUnit::getDelta() const {
	return delta;
}

long TimeUnit::getTicks() const {
	return ticks;
}

double TimeUnit::getAverage() const {
	return average;
}
