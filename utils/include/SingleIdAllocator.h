#ifndef SINGLE_ID_ALLOCATOR_H_
#define SINGLE_ID_ALLOCATOR_H_

#include <map>
#include <memory>

#include "SingleMappedAllocator.h"


namespace cph {

template<typename T2>
class SingleIdAllocator {

private:
	int currentId;
	std::map<int, std::unique_ptr<T2>> memMap;

	SingleIdAllocator(const SingleIdAllocator& other);

public:
	SingleIdAllocator(int offset = 0) : currentId(offset), memMap() { }
	~SingleIdAllocator() { }

	T2* allocate();
	T2* at(int id) const;
	void release(int id);
	void release(T2* mem);
	int size() const;

};

template<typename T2> inline
T2* SingleIdAllocator<T2>::allocate() {
	T2* mem = new T2(currentId);
	memMap.insert(std::make_pair(currentId, std::unique_ptr<T2>(mem)));
	currentId++;
	return mem;
}

template<typename T2> inline
T2* SingleIdAllocator<T2>::at(int id) const {
	return memMap.at(id).get();
}

template<typename T2> inline
void SingleIdAllocator<T2>::release(int id) {
	memMap.erase(id);
}

template<typename T2> inline
void SingleIdAllocator<T2>::release(T2* mem) {
	typename std::map<int, std::unique_ptr<T2>>::iterator it;
	for(it = memMap.begin(); it != memMap.end(); ++it) {
		if(it->second.get() == mem) {
			release(it->first);
			break;
		}
	}
}

template<typename T2> inline
int SingleIdAllocator<T2>::size() const {
	return memMap.size();
}


}

#endif