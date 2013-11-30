#ifndef VAO_MANAGER_H_
#define VAO_MAMANER_H_

#include <cstdint>
#include <unordered_set>
#include "SingleAllocator.h"

#include "Vao.h"


namespace cph {

class VaoManager {

private:
	SingleAllocator<Vao> vaoAlloc;

	VaoManager(const VaoManager& other);

public:
	VaoManager();
	~VaoManager();

	void cleanVaoEntry(VaoEntry* entry);
	void processVaoEntry(VaoEntry* entry);
	
	void updateGL();
	void drawGL();
};

}

#endif