#ifndef SINGLE_MAPPED_ALLOCATOR_H_
#define SINGLE_MAPPED_ALLOCATOR_H_

#include <map>
#include <memory>


namespace cph {

template<typename T1, typename T2>
class SingleMappedAllocator {

private:
	std::map<T1, std::unique_ptr<T2>> memMap;

	SingleMappedAllocator(const SingleMappedAllocator& old) { }

public:
	SingleMappedAllocator() : memMap() { }
	~SingleMappedAllocator() { }

	T2* allocate(T1 key);
	T2* at(T1 key) const;
	void release(T1 key);
	void release(T2* mem);
	int size() const;

};

template<typename T1, typename T2> inline
T2* SingleMappedAllocator<T1, T2>::allocate(T1 key) {
	T2* mem = new T2();
	memMap.insert(std::make_pair(key, std::unique_ptr<T2>(mem)));
	return mem;
}

template<typename T1, typename T2> inline
T2* SingleMappedAllocator<T1, T2>::at(T1 key) const {
	return memMap.at(key).get();
}

template<typename T1, typename T2> inline
void SingleMappedAllocator<T1, T2>::release(T1 key) {
	memMap.erase(key);
}

template<typename T1, typename T2> inline
void SingleMappedAllocator<T1, T2>::release(T2* mem) {
	typename std::map<T1, std::unique_ptr<T2>>::iterator it;
	for(it = memMap.begin(); it != memMap.end(); ++it) {
		if(it->second.get() == mem) {
			release(it->first);
			break;
		}
	}
}

template<typename T1, typename T2> inline
int SingleMappedAllocator<T1, T2>::size() const {
	return memMap.size();
}


}

#endif