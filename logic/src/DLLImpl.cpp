#include "../include/LogicSystem.h"
#include "LogicSystemImpl.h"


cph::LogicSystem* cph::createLogicSystem(std::uint8_t sysId) {
	return new LogicSystemImpl(sysId);
}

void cph::deleteLogicSystem(LogicSystem* system) {
	delete system;
}

cph::LogicSystem::~LogicSystem() {

}
