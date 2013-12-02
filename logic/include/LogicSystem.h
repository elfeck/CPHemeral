#ifndef LOGIC_SYSTEM_H_
#define LOGIC_SYSTEM_H_

#ifdef LOGIC_EXPORTS
#define CPH_LOGIC_DLL _declspec(dllexport)
#else
#define CPH_LOGIC_DLL _declspec(dllimport)
#endif

#include "ObjectSystem.h"
#include "LogicAllocator.h"


namespace cph {

struct LogicComponent;
struct ObjectManager;
class Log;

struct LogicSystem : public ObjectSystem, public LogicAllocator {
	
	virtual LogicComponent* createComponent() = 0;
	
	virtual void execute(ObjectManager* objectManager, double delta) = 0;
	virtual std::uint8_t getSysId() const = 0;	
	
	virtual void setLog(Log* log, const char* target = 0) = 0;

	virtual ~LogicSystem() = 0;

};

extern "C" {
	CPH_LOGIC_DLL LogicSystem* createLogicSystem(std::uint8_t sysId);
	CPH_LOGIC_DLL void deleteLogicSystem(LogicSystem* renderingSystem);
}

}


#endif