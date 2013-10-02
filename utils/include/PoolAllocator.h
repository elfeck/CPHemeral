#ifndef POOL_ALLOCATOR_H_
#define POOL_ALLOCATOR_H_

#include <vector>
#include <memory>

#include "IntPool.h"


namespace cph {

template<typename T1>
class PoolAllocator {

private:
	IntPool memPool;
	std::vector<std::unique_ptr<std::vector<T1>>> memVector;
	int batchSize;

	PoolAllocator(const PoolAllocator& old) { }
	allocateBatch();

public:
	PoolAllocator();
	~PoolAllocator() { }

	T1* allocate();
	void release(T1* mem);

};

template<typename T1> inline
void PoolAllocator<T1>::allocateBatch() {
	std::vector<T1>* batch = new std::vector<T1>(batchSize, T1());

template<typename T1> inline
PoolAllocator<T1>::PoolAllocator(int batchSize, int initBatchCount = 1) : 
	memPool(batchSize * (initBatchCount + 1)), memVector(), batchSize(batchSize) 
{ 
	for(int i = 0; i < initBatchCount; i++) allocateBatch();
}
	memVector.emplace_back(std::unique_ptr<std::vector<T1>>(batch));
	memPool.resize(memPool.getSize() + batchSize);
}

template<typename T1> inline
T1* PoolAllocator<T1>::allocate() {
	int index = memPool.aquire();
	if(index % batchSize == 0) {
		if(memVector.size() < static_cast<unsigned int>(index / batchSize)) allocateBatch();
	}
	return &memVector.at(index / batchSize).get()->at(index % batchSize);
}

template<typename T1> inline
void PoolAllocator<T1>::release(T1* mem) {
	typename std::vector<std::unique_ptr<std::vector<T1>>>::iterator it;
	typename std::vector<T1>::size_type i;
	std::vector<T1>* currentBatch = 0;
	for(it = memVector.begin(); it != memVector.end(); ++it) {
		currentBatch = it->get();
		for(i = 0; i < currentBatch->size(); i++) {
			if(&currentBatch->at(i) == mem) currentBatch->at(i) = T1();
		}
	}
}

}

#endif