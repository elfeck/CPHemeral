#ifndef SYSTEM_LOG_H_
#define SYSTEM_LOG_H_

#include "WriteonlyLogger.h"


namespace cph {

WriteonlyLogger& getErrorLog();
WriteonlyLogger& getDebugLog();

};

#endif