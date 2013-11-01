#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/GlobalUtils.h"


using namespace cph;

bool cph::stringContains(std::string source, std::string token) {
	return source.find(token) != std::string::npos;
}

std::string cph::stringReplaceAll(std::string source, std::string token, std::string replacement) {
	size_t pos;
	while((pos = source.find(token)) != std::string::npos) {
		source.replace(pos, token.length(), replacement);
	}
	return source;
}

std::vector<std::string> cph::stringSplit(std::string source, char delimiter) {
	std::vector<std::string> vec;
	std::stringstream ss(source);
	std::string token;
	while(std::getline(ss, token, delimiter)) {
		vec.push_back(token);
	}
	return vec;
}

std::string cph::stringUntil(std::string source, std::string delimiter) {
	int index = source.find(delimiter);
	if(index < 0) return source;
	return std::string(source).replace(index, source.length() - 1, "");
}

std::string cph::boolToString(bool value) {
	return value ? "true" : "false";
}

std::string cph::floatToString(float value) {
	std::ostringstream ss;
	ss << value;
	return ss.str();
}

std::string cph::doubleToString(double value) {
	std::ostringstream ss;
	ss << value;
	return ss.str();
}

std::string cph::intToString(int value) {
	std::ostringstream ss;
	ss << value;
	return ss.str();
}

std::string cph::cutFilepath(std::string string) {
	return "*" + string.substr(string.rfind("/"), string.length());
}

bool cph::fileExists(std::string file) {
	std::ifstream stream(file.c_str());
	bool exists = stream.good();
	stream.close();
	return exists;
}

std::string cph::fileToString(std::string file) {	
	std::string result = "";
	std::string line;
	std::ifstream stream(file.c_str());
	if(stream.is_open()) {
		while(stream.good()) {
			getline(stream, line); 
			result.append(line).append("\n");
		}
		stream.close();
	}
	return result;
}
