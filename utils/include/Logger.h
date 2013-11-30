#ifndef LOGGER_H_
#define LOGGER_H_

#include <sstream>
#include "Log.h"
#include "WriteonlyLogger.h"


namespace cph  {

class Logger : public WriteonlyLogger {

private:
	std::string logPrepos;
	Log localLog;
	Log* logPtr;

public:
	Logger( const char* logPrepos = "", Log* logPtr = 0);
	~Logger();

	void setLogPtr(Log* logPtr);
	void setLogPrepos(const char* logPrepos);

	virtual void logMessage(std::string message);
	
	std::string getTarget() const;	
	std::ostringstream& getRaw();

	void setLocalConsolePrintOnLog(bool print);
	void setLocalWriteToBuffer(bool write);
	void setLocalWritebackOnLog(std::string* writebackPtr);
	
	virtual WriteonlyLogger& pre();

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