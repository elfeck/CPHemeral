#ifndef GLOBAL_UTILS_H_
#define GLOBAL_UTILS_H_

#include <string>
#include <vector>


namespace cph {

bool stringContains(std::string source, std::string token);
std::string stringReplaceAll(std::string source, std::string token, std::string replacement);
std::vector<std::string> stringSplit(std::string source, char delimiter);
std::string floatToString(float value);

bool fileExists(std::string file);
std::string fileToString(std::string file);

}

#endif