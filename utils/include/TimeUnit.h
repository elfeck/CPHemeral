#ifndef TIME_UNIT_H_
#define TIME_UNIT_H_


namespace cph {

class TimeUnit {

private:
	long last, delta, total, ticks;
	double average;

public:
	TimeUnit();
	~TimeUnit();

	void enterStart(long time);
	void enterEnd(long time);

	void printRate() const;
	void printAverageRate() const;
	void printAll() const;

	long getDelta() const;
	long getTicks() const;
	double getAverage() const;
};

}

#endif
