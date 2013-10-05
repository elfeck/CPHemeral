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
	std::unordered_set<std::uint32_t> prevComponents;

public:
	VaoManager();
	~VaoManager();

	void processVaoEntryGL(std::uint32_t compId, VaoEntry* vaoEntry);
	void drawGL();

};

}

#endif