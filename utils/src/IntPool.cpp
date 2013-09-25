#include "../include/IntPool.h"


using namespace cph;

IntPool::IntPool(int size) :
	poolSize(size), intPool(std::vector<int>(size, 1))
{

}

IntPool::~IntPool() {

}

int IntPool::aquire() {
	for(int i = 0; i < poolSize; i++) {
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
