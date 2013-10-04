#ifndef SINGLE_ALLOCATOR_H_
#define SINGLE_ALLOCATOR_H_

#include <vector>
#include <memory>


namespace cph {

template<typename T1>
class SingleAllocator {

private:
	std::vector<std::unique_ptr<T1>> memVector;

	SingleAllocator(const SingleAllocator& old) { }

public:
	SingleAllocator() : memVector() { }
	~SingleAllocator() { }

	T1* allocate();
	int size() const;
	void release(T1* mem);

};

template<typename T1> inline
T1* SingleAllocator<T1>::allocate() {
	T1* mem = new T1();
	memVector.emplace_back(std::unique_ptr<T1>(mem));
	return mem;
}

template<typename T1> inline
int SingleAllocator<T1>::size() const {
	return memVector.size();
}

template<typename T1> inline
void SingleAllocator<T1>::release(T1* mem) {
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