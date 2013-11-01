#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <sstream>


namespace cph {

class Log {

private:
	bool consolePrint, writeToBuffer;
	std::string target;
	std::string* writebackPtr;
	std::ostringstream logBuffer;


public:
	Log(std::string target);
	Log(const Log& other);
	~Log();

	void logMessage(std::string message);

	std::string getTarget() const;
	std::ostringstream& getRaw();

	void setConsolePrintOnLog(bool print);
	void setWriteToBuffer(bool write);
	void setWritebackOnLog(std::string* writebackPtr);

	Log& operator<<(const char* value);
	Log& operator<<(std::string value);
	Log& operator<<(bool value);
	Log& operator<<(float value);
	Log& operator<<(double value);
	Log& operator<<(int value);
	Log& operator<<(std::ostream& (*pf)(std::ostream&));

};

}

#endif