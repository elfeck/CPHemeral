#ifndef LOGGER_H_
#define LOGGER_H_

#include <sstream>
#include "Log.h"
#include "WriteonlyLogger.h"


namespace cph  {

class Logger : public WriteonlyLogger {

private:
	Log localLog;
	Log* logPtr;

public:
	Logger(Log* logPtr = 0);
	~Logger();

	void setLogPtr(Log* logPtr);

	virtual void logMessage(std::string message);
	
	std::string getTarget() const;	
	std::ostringstream& getRaw();

	void setLocalConsolePrintOnLog(bool print);
	void setLocalWriteToBuffer(bool write);
	void setLocalWritebackOnLog(std::string* writebackPtr);
	
	virtual WriteonlyLogger& operator<<(const char* value);
	virtual WriteonlyLogger& operator<<(std::string value);
	virtual WriteonlyLogger& operator<<(bool value);
	virtual WriteonlyLogger& operator<<(float value);
	virtual WriteonlyLogger& operator<<(double value);
	virtual WriteonlyLogger& operator<<(int value);
	virtual WriteonlyLogger& operator<<(std::uint32_t value);
	virtual WriteonlyLogger& operator<<(std::ostream& (*pf)(std::ostream&));

};

}


#endif