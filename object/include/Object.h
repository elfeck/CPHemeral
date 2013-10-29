#ifndef OBJECT_H_
#define OBJECT_H_

#include <cstdint>


namespace cph {

struct Component;

struct Object {

	virtual void destroy() = 0;

	virtual void addComponent(Component* component) = 0;
	virtual void removeComponent(Component* component) = 0;

	virtual bool hasComponent(std::uint8_t sysId) const = 0;
	virtual Component* getComponent(std::uint8_t sysId) const = 0;

	virtual std::uint32_t getObjId() const = 0;

};

}


#endif