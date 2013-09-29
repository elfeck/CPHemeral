#ifndef GLOBAL_UTILS_H_
#define GLOBAL_UTILS_H_

#include <string>


namespace cph {

bool stringContains(std::string source, std::string token);
std::string stringReplaceAll(std::string source, std::string token, std::string replacement);
std::string fileToString(std::string file);
std::string floatToString(float value);

}

#endif