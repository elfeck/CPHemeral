#ifndef OBJECT_IMPL_H_
#define OBJECT_IMPL_H_

#include <map>
#include <string>

#include "../include/Object.h"


namespace cph {

class ObjectManagerImpl;

class ObjectImpl : public Object {

private:
	ObjectManagerImpl* objectManager;

	std::map<std::string, Component*> components;

public:
	ObjectImpl();
	~ObjectImpl();

	virtual void destroy();
	virtual void addComponent(Component* component);
	virtual void removeComponent(Component* component);

	virtual bool hasComponent(const char* name) const;
	virtual Component* getComponent(const char* name) const;

	void setObjectManager(ObjectManagerImpl* objectManager);	
};

}

#endif