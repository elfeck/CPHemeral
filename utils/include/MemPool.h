#ifndef MEM_POOL_H_
#define MEM_POOL_H_

#include "IntPool.h"
#include <iostream>


namespace cph {


template<typename T1>
class MemPool {

	template<typename T2>
	struct MemSet {
		T2* memSet;

		MemSet() : 
			memSet(0) 
		{ 
		
		}

		~MemSet() { 
			std::cout << "Releasing division array: " << memSet << std::endl;
			if(memSet != 0) delete[] memSet; 
		}

		void allocate(int divisions) {
			memSet = new T2[divisions];
			std::cout << "Allocating division array: " << memSet << std::endl;
		}

		bool isAllocated() {
			return memSet != 0;
		}

	};

private:
	const int divisions, divisionSize;
	MemSet<T1>* memPool;
	IntPool intPool;

public:
	MemPool(int divisions, int divisionSize);
	~MemPool();

	T1* allocate();
	void release(T1* mem);
	void preAllocate(int divisionCount);
};



template<typename T1>
inline
MemPool<T1>::MemPool(int divisions, int divisionSize) :
	divisions(divisions), divisionSize(divisionSize), 
	memPool(new MemSet<T1>[divisions]), intPool(divisions * divisionSize)
{
	std::cout << "Allocating MemPool: " << memPool << std::endl;
}

template<typename T1>
inline
MemPool<T1>::~MemPool() {
	std::cout << "Releasing MemPool: " << memPool << std::endl;
	delete[] memPool;
}

template<typename T1>
inline
T1* MemPool<T1>::allocate() {
	int index = intPool.aquire();
	if(index == -1) return 0;
	int poolIndex = index / divisionSize;
	int setIndex = index % divisionSize;
	if(setIndex == 0) {
		if(!memPool[poolIndex].isAllocated()) memPool[poolIndex].allocate(divisionSize);
	}
	return &(memPool[poolIndex].memSet[setIndex]);
}

template<typename T1>
inline
void MemPool<T1>::release(T1* mem) {
	for(int i = 0; i < divisions; i++) {
		for(int j = 0; j < divisionSize; j++) {
			if(&(memPool[i].memSet[j]) == mem) {
				int index = i * divisionSize + j;
				memPool[i].memSet[j] = T1();
				intPool.release(index);
			}
		}
	}
}

template<typename T1>
inline
void MemPool<T1>::preAllocate(int divisionCount) {
	divisionCount = divisionCount < divisions ? divisionCount : divisions;
	for(int i = 0; i < divisionCount; i++) {
		if(!memPool[i].isAllocated()) memPool[i].allocate(divisionSize);
	}
}

}

#endif