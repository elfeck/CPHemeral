#ifndef VAO_MANAGER_H_
#define VAO_MAMANER_H_

#include "SingleAllocator.h"

#include "Vao.h"


namespace cph {

class VaoManager {

private:
	SingleAllocator<Vao> vaoAlloc;

public:
	VaoManager();
	~VaoManager();

	void processVaoEntryGL(VaoEntry* vaoEntry);
	void drawGL();

};

}

#endif