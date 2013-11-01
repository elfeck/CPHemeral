#include <iostream>
#include "../include/Log.h"
#include "../include/GlobalUtils.h"


using namespace cph;

Log::Log(std::string target) :
	consolePrint(false), writeToBuffer(false), writebackPtr(0), target(target), logBuffer()

{

}


Log::Log(const Log& other) :
	consolePrint(other.consolePrint), writeToBuffer(other.writeToBuffer), writebackPtr(other.writebackPtr),
	target(other.target), logBuffer()
{
	logBuffer << other.logBuffer << std::endl;
}


Log::~Log() {

}

void Log::logMessage(std::string message) {
	if(writeToBuffer) logBuffer << message << std::endl;
	if(writebackPtr != 0) writebackPtr = &message;
	if(consolePrint) std::cout << message << std::endl;
}


std::string Log::getTarget() const {
	return target;
}

std::ostringstream& Log::getRaw() {
	return logBuffer;
}

void Log::setConsolePrintOnLog(bool print) {
	this->consolePrint = print;
}

void Log::setWriteToBuffer(bool write) {
	this->writeToBuffer = write;
}

void Log::setWritebackOnLog(std::string* writebackPtr) {
	this->writebackPtr = writebackPtr;
}

Log& Log::operator<<(const char* value) {
	if(writeToBuffer) logBuffer << value;
	if(writebackPtr != 0) *writebackPtr += value;
	if(consolePrint) std::cout << value;
	return *this;
}

Log& Log::operator<<(std::string value) {
	if(writeToBuffer) logBuffer << value;
	if(writebackPtr != 0) *writebackPtr += value;
	if(consolePrint) std::cout << value;
	return *this;
}

Log& Log::operator<<(bool value) {
	if(writeToBuffer) logBuffer << value;
	if(writebackPtr != 0) *writebackPtr += boolToString(value);
	if(consolePrint) std::cout << value;
	return *this;
}

Log& Log::operator<<(float value) {
	if(writeToBuffer) logBuffer << value;
	if(writebackPtr != 0) *writebackPtr += floatToString(value);
	if(consolePrint) std::cout << value;
	return *this;
}

Log& Log::operator<<(double value) {
	if(writeToBuffer) logBuffer << value;
	if(writebackPtr != 0) *writebackPtr += doubleToString(value);
	if(consolePrint) std::cout << value;
	return *this;
}

Log& Log::operator<<(int value) {
	if(writeToBuffer) logBuffer << value;
	if(writebackPtr != 0) *writebackPtr += intToString(value);
	if(consolePrint) std::cout << value;
	return *this;
}

Log& Log::operator<< (std::ostream& (*pf)(std::ostream&)) {
	if(writeToBuffer) logBuffer << pf;
	if(writebackPtr != 0) {
		std::ostringstream ss;
		ss << pf;
		*writebackPtr += ss.str();
	}
	if(consolePrint) std::cout << pf;
	return *this;
}
