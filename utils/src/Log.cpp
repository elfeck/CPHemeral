#include "../include/Log.h"


using namespace cph;

Log::Log(std::string target) :
	target(target), logBuffer()

{

}

Log::~Log() {

}

void Log::log(std::string message) {
	logBuffer << message << std::endl;
}


std::string Log::getTarget() const {
	return target;
}

std::stringstream& Log::operator<<(bool value) {
	logBuffer << value;
	return logBuffer;
}

std::stringstream& Log::operator<<(float value) {
	logBuffer << value;
	return logBuffer;
}

std::stringstream& Log::operator<<(int value) {
	logBuffer << value;
	return logBuffer;
}


