#ifndef WRITEONLY_LOGGER_H_
#define WRITEONLY_LOGGER_H_

#include <sstream>
#include <cstdint>


struct WriteonlyLogger {

	virtual void logMessage(std::string message) = 0;

	virtual WriteonlyLogger& operator<<(const char* value) = 0;
	virtual WriteonlyLogger& operator<<(std::string value) = 0;
	virtual WriteonlyLogger& operator<<(bool value) = 0;
	virtual WriteonlyLogger& operator<<(float value) = 0;
	virtual WriteonlyLogger& operator<<(double value) = 0;
	virtual WriteonlyLogger& operator<<(int value) = 0;
	virtual WriteonlyLogger& operator<<(std::uint32_t value) = 0;
	virtual WriteonlyLogger& operator<<(std::ostream& (*pf)(std::ostream&)) = 0;

};


#endif