#ifndef OBJECT_SYSTEM_H_
#define OBJECT_SYSTEM_H_


namespace cph {

struct ObjectSystem {

	virtual void execute(long delta) = 0;

};

}

#endif