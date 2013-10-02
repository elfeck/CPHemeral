#ifndef UNIQUE_ALLOCATOR_H_
#define UNIQUE_ALLOCATOR_H_

#include <vector>
#include <memory>


namespace cph {

template<typename T1>
class UniqueAllocator {

private:
	std::vector<std::unique_ptr<T1>> memVector;

	UniqueAllocator(const UniqueAllocator& old) { }

public:
	UniqueAllocator() : memVector() { }
	~UniqueAllocator() { }

	T1* allocate();
	void release(T1* mem);

};

template<typename T1> inline
T1* UniqueAllocator<T1>::allocate() {
	T1* mem = new T1();
	memVector.emplace_back(std::unique_ptr<T1>(mem));
	return mem;
}

template<typename T1> inline
void UniqueAllocator<T1>::release(T1* mem) {
	typename std::vector<std::unique_ptr<T1>>::iterator it;
	for(it = memVector.begin(); it != memVector.end(); ++it) {
		if(it->get() == mem) {
			memVector.erase(it);
			break;
		}
	}
}

}

#endif