#include "../include/IntPool.h"


using namespace cph;

IntPool::IntPool(int size) :
	poolSize(size), intPool(std::vector<char>(size, 1))
{

}

IntPool::~IntPool() {

}

int IntPool::aquire() {
	for(std::vector<char>::size_type i = 0; i < static_cast<std::vector<char>::size_type>(poolSize); i++) {
		if(intPool.at(i) == 1) {
			intPool.at(i) = 0;
			return i;
		}
	}
	return -1;
}

void IntPool::release(int value) {
	intPool.at(value) = 1;
}

bool IntPool::isEmpty() const {
	return intPool.at(poolSize - 1) == 0;
}

int IntPool::last() const {
	int last = 0;
	for(std::vector<char>::size_type i = 0; i < static_cast<std::vector<char>::size_type>(poolSize); i++) {
		if(intPool.at(i) == 0) last = i;
	}
	return last;
}

int IntPool::getSize() const {
	return poolSize;
}

void IntPool::resize(int newSize) {
	int toAdd = newSize - poolSize;
	for(int i = 0; i < toAdd; i++) {
		intPool.push_back(1);
	}
}
