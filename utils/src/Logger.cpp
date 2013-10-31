#include "../include/Logger.h"


using namespace cph;

Logger::Logger(Log* logPtr) :
	localLog("logger_local"), logPtr(logPtr)
{

}

Logger::~Logger() {

}

void Logger::setLogPtr(Log* logPtr) {
	this->logPtr = logPtr;
}

void Logger::logMessage(std::string message) {
	if(logPtr != 0) logPtr->logMessage(message);
	else localLog.logMessage(message);
}

std::string Logger::getTarget() const {
	if(logPtr != 0) return logPtr->getTarget();
	else return localLog.getTarget();
}

std::ostringstream& Logger::getRaw() {
	if(logPtr != 0) return logPtr->getRaw();
	else return localLog.getRaw();
}

void Logger::setLocalConsolePrintOnLog(bool print) {
	localLog.setConsolePrintOnLog(print);
}

void Logger::setLocalWriteToBuffer(bool write) {
	localLog.setWriteToBuffer(write);
}

void Logger::setLocalWritebackOnLog(std::string* writebackPtr) {
	localLog.setWritebackOnLog(writebackPtr);
}

Logger& Logger::operator<<(const char* value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

Logger& Logger::operator<<(bool value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

Logger& Logger::operator<<(float value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

Logger& Logger::operator<<(double value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

Logger& Logger::operator<<(int value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

Logger& Logger::operator<< (std::ostream& (*pf)(std::ostream&)) {
	if(logPtr != 0) {
		*logPtr << pf;
	} else {
		localLog << pf;
	}
	return *this;
}