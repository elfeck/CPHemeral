#include "../include/Logger.h"


using namespace cph;

Logger::Logger(const char* logPrepos, Log* logPtr) :
	logPrepos(logPrepos), localLog("logger_local"), logPtr(logPtr)
{

}

Logger::~Logger() {

}

void Logger::setLogPtr(Log* logPtr) {
	this->logPtr = logPtr;
}

void Logger::setLogPrepos(const char* logPrepos) {
	this->logPrepos = logPrepos;
}

void Logger::logMessage(std::string message) {
	if(logPtr != 0) logPtr->logMessage(logPrepos + " " + message);
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

WriteonlyLogger& Logger::pre() {
	if(logPtr != 0) {
		*logPtr << logPrepos << "   ";
	} else {
		localLog << logPrepos << "   ";
	}
	return *this;
}

WriteonlyLogger& Logger::operator<<(const char* value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

WriteonlyLogger& Logger::operator<<(std::string value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

WriteonlyLogger& Logger::operator<<(bool value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

WriteonlyLogger& Logger::operator<<(float value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

WriteonlyLogger& Logger::operator<<(double value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

WriteonlyLogger& Logger::operator<<(int value) {
	if(logPtr != 0) {
		*logPtr << value;
	} else {
		localLog << value;
	}
	return *this;
}

WriteonlyLogger& Logger::operator<<(std::uint32_t value) {
	if(logPtr != 0) {
		*logPtr << static_cast<int>(value);
	} else {
		localLog << static_cast<int>(value);
	}
	return *this;
}

WriteonlyLogger& Logger::operator<< (std::ostream& (*pf)(std::ostream&)) {
	if(logPtr != 0) {
		*logPtr << pf;
	} else {
		localLog << pf;
	}
	return *this;
}