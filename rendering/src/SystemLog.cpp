#include "RenderingSystemImpl.h"
#include "SystemLog.h"


using namespace cph;

WriteonlyLogger& cph::getErrorLog() {
	return RenderingSystemImpl::getErrorLog();
}

WriteonlyLogger& cph::getDebugLog() {
	return RenderingSystemImpl::getDebugLog();
}

