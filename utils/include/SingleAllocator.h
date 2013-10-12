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

	class iterator {

	private:
		typename std::vector<std::unique_ptr<T1>>::iterator vecIterator;
		iterator(typename std::vector<std::unique_ptr<T1>>::iterator vecIterator) : vecIterator(vecIterator) { }

	public:
		T1* operator->() const;
		T1* operator*() const;
		void operator++();
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;

		friend class SingleAllocator<T1>;

	};

	SingleAllocator() : memVector() { }
	~SingleAllocator() { }

	T1* allocate();
	int size() const;
	void release(T1* mem);

	iterator begin() const;
	iterator end() const;

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

template<typename T1> inline
typename SingleAllocator<T1>::iterator SingleAllocator<T1>::begin() const {
	return SingleAllocator<T1>::iterator(memVector.begin());
}

template<typename T1> inline
typename SingleAllocator<T1>::iterator SingleAllocator<T1>::end() const {
	return SingleAllocator<T1>::iterator(memVector.end());
}


template<typename T1> inline
T1* SingleAllocator<T1>::iterator::operator->() const {
	return vecIterator->get();
}

template<typename T1> inline
T1* SingleAllocator<T1>::iterator::operator*() const {
	return vecIterator->get();
}

template<typename T1> inline
void SingleAllocator<T1>::iterator::operator++() {
	++vecIterator;
}

template<typename T1> inline
bool SingleAllocator<T1>::iterator::operator==(typename const SingleAllocator<T1>::iterator& other) const {
	return vecIterator == other.vecIterator;
}

template<typename T1> inline
bool SingleAllocator<T1>::iterator::operator!=(typename const SingleAllocator<T1>::iterator& other) const {
	return vecIterator != other.vecIterator;
}

}

#endif