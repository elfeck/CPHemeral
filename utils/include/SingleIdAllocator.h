#ifndef SINGLE_ID_ALLOCATOR_H_
#define SINGLE_ID_ALLOCATOR_H_

#include <map>
#include <memory>
#include <cstdint>


namespace cph {

template<typename T2>
class SingleIdAllocator {

private:
	std::uint32_t currentId;
	std::map<std::uint32_t, std::unique_ptr<T2>> memMap;

	SingleIdAllocator(const SingleIdAllocator& other);

public:

	class iterator {

	private:
		typename std::map<std::uint32_t, std::unique_ptr<T2>>::iterator mapIterator;
		iterator(typename std::map<std::uint32_t, std::unique_ptr<T2>>::iterator mapIterator) : mapIterator(mapIterator) { }

	public:
		T2* operator->() const;
		T2* operator*() const;
		void operator++();
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;

		friend class SingleIdAllocator<T2>;

	};

	SingleIdAllocator(std::uint32_t offset = 0) : currentId(offset), memMap() { }
	~SingleIdAllocator() { }

	T2* allocate();
	T2* at(std::uint32_t id) const;
	void release(std::uint32_t id);
	void release(T2* mem);
	int size() const;

	iterator begin();
	iterator end();
};

template<typename T2> inline
T2* SingleIdAllocator<T2>::allocate() {
	T2* mem = new T2(currentId);
	memMap.insert(std::make_pair(currentId, std::unique_ptr<T2>(mem)));
	currentId++;
	return mem;
}

template<typename T2> inline
T2* SingleIdAllocator<T2>::at(std::uint32_t id) const {
	return memMap.at(id).get();
}

template<typename T2> inline
void SingleIdAllocator<T2>::release(std::uint32_t id) {
	memMap.erase(id);
}

template<typename T2> inline
void SingleIdAllocator<T2>::release(T2* mem) {
	typename std::map<std::uint32_t, std::unique_ptr<T2>>::iterator it;
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

template<typename T2> inline
typename SingleIdAllocator<T2>::iterator SingleIdAllocator<T2>::begin() {
	return SingleIdAllocator<T2>::iterator(memMap.begin());
}

template<typename T2> inline
typename SingleIdAllocator<T2>::iterator SingleIdAllocator<T2>::end() {
	return SingleIdAllocator<T2>::iterator(memMap.end());
}

template<typename T2> inline
T2* SingleIdAllocator<T2>::iterator::operator->() const {
	return mapIterator->second.get();
}

template<typename T2> inline
T2* SingleIdAllocator<T2>::iterator::operator*() const {
	return mapIterator->second.get();
}

template<typename T2> inline
void SingleIdAllocator<T2>::iterator::operator++() {
	++mapIterator;
}

template<typename T2> inline
bool SingleIdAllocator<T2>::iterator::operator==(typename const SingleIdAllocator<T2>::iterator& other) const {
	return mapIterator == other.mapIterator;
}

template<typename T2> inline
bool SingleIdAllocator<T2>::iterator::operator!=(typename const SingleIdAllocator<T2>::iterator& other) const {
	return mapIterator != other.mapIterator;
}

}

#endif