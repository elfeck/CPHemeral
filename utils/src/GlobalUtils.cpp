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

std::string cph::floatToString(float value) {
	std::ostringstream ss;
	ss << value;
	return ss.str();
}
