#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <sstream>


namespace cph {

class Log {

private:
	std::string target;
	std::stringstream logBuffer;

public:
	Log(std::string target);
	~Log();

	void log(std::string message);
	std::string getTarget() const;

	std::stringstream& operator<<(bool value);
	std::stringstream& operator<<(float value);
	std::stringstream& operator<<(int value);

};

}

#endif