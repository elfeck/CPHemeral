#ifndef OBJECT_SYSTEM_H_
#define OBJECT_SYSTEM_H_

#include <cstdint>


namespace cph {

struct ObjectManager;

struct ObjectSystem {

	virtual void execute(ObjectManager* objectManager, long delta) = 0;
	virtual std::uint8_t getSysId() const = 0;

};

}

#endif