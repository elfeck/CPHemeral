#ifndef INTPOOL_H_
#define INTPOOL_H_

#include <vector>


namespace cph {

class IntPool {

private:
	int poolSize;
	std::vector<int> intPool;

public:
	IntPool(int size);
	~IntPool();

	int aquire();
	void release(int value);
	bool isEmpty() const;
};

}

#endif
