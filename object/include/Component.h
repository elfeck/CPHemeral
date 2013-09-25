#ifndef COMPONENT_H_
#define COMPONENT_H_


namespace cph {

struct Component {

	virtual const char* getName() const = 0;

	virtual void release() = 0;

};

}


#endif