#ifndef OBJECT_IMPL_H_
#define OBJECT_IMPL_H_

#include <map>
#include <string>
#include <cstdint>

#include "../include/Object.h"
#include "../include/Component.h"


namespace cph {

class ObjectManagerImpl;

class ObjectImpl : public Object {

private:
	const std::uint32_t objId;
	ObjectManagerImpl* objectManager;

	std::map<std::uint8_t, Component*> components;

public:
	ObjectImpl(std::uint32_t id);
	~ObjectImpl();

	virtual void destroy();
	virtual void addComponent(Component* component);
	virtual void removeComponent(Component* component);

	virtual bool hasComponent(std::uint8_t sysId) const;
	virtual Component* getComponent(std::uint8_t sysId) const;

	virtual std::uint32_t getObjId() const;

	void setObjectManager(ObjectManagerImpl* objectManager);	
};

}

#endif