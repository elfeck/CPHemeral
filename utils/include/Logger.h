#ifndef LOGGER_H_
#define LOGGER_H_

#include <sstream>
#include "Log.h"


namespace cph  {

class Logger {

private:
	Log localLog;
	Log* logPtr;

public:
	Logger(Log* logPtr = 0);
	~Logger();

	void setLogPtr(Log* logPtr);

	void logMessage(std::string message);
	
	std::string getTarget() const;	
	std::ostringstream& getRaw();

	void setLocalConsolePrintOnLog(bool print);
	void setLocalWriteToBuffer(bool write);
	void setLocalWritebackOnLog(std::string* writebackPtr);
	
	Logger& operator<<(const char* value);
	Logger& operator<<(bool value);
	Logger& operator<<(float value);
	Logger& operator<<(double value);
	Logger& operator<<(int value);
	Logger& operator<<(std::ostream& (*pf)(std::ostream&));

};

}


#endif