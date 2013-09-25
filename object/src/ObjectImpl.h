#ifndef OBJECT_IMPL_H_
#define OBJECT_IMPL_H_

#include <vector>

#include "../include/Object.h"


namespace cph {

class ObjectManagerImpl;

class ObjectImpl : public Object {

private:
	int id;
	ObjectManagerImpl* objectManager;

	std::vector<Component*> components;

public:
	ObjectImpl();
	~ObjectImpl();

	virtual void release();
	virtual void addComponent(Component* component);
	virtual void removeComponent(Component* component);
	virtual Component* getComponent(const char* name) const;

	int getId() const;

	void setId(int id);
	void setObjectManager(ObjectManagerImpl* objectManager);	
};

}

#endif