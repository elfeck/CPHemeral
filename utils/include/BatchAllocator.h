#ifndef BATCH_ALLOCATOR
#define BATCH_ALLOCATOR

#include <vector>
#include <memory>


namespace cph {

template<typename T1>
class BatchAllocator {

private:
	std::vector<std::unique_ptr<T1[]>> memVector;

	BatchAllocator(const BatchAllocator& old) { }

public:
	BatchAllocator() : memVector() { }
	~BatchAllocator() { }

	T1* allocate(int n);
	void release(T1* mem);

};

template<typename T1> inline
T1* BatchAllocator<T1>::allocate(int n) {
	T1* mem = new T1[n];
	memVector.emplace_back(std::unique_ptr<T1[]>(object));
	return mem;
}

template<typename T1> inline
void BatchAllocator<T1>::release(T1* mem) {
	typename std::vector<std::unique_ptr<T1[]>>::iterator it;
	for(it = memVector.begin(); it != memVector.end(); ++it) {
		if(it->get() == mem) {
			memVector.erase(it);
			break;
		}
	}
}

}

#endif