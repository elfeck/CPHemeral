#ifndef VEC1F_H_
#define VEC1F_H_

#include "Vecf.h"


namespace cph {

class Vec1f : public Vecf {

private:
	float x;

public:
	Vec1f(float x = 0);
	~Vec1f();

	Vec1f* addVec1f(Vec1f* vec);
	Vec1f* subVec1f(Vec1f* vec);
	Vec1f* mulVec1f(Vec1f* vec);
	Vec1f* divVec1f(Vec1f* vec);

	Vec1f* addVec1f(Vec1f vec);
	Vec1f* subVec1f(Vec1f vec);
	Vec1f* mulVec1f(Vec1f vec);
	Vec1f* divVec1f(Vec1f vec);

	Vec1f* addVec1f(float vx);
	Vec1f* subVec1f(float vx);
	Vec1f* mulVec1f(float vx);
	Vec1f* divVec1f(float vx);

	float dot(Vec1f* vec);
	float dot(Vec1f vec);
	Vec1f* mulScalar(float value);
	Vec1f* normalize();
	Vec1f* toLength(float value);
	Vec1f* negate();

	Vec1f* setX(float newX);
	Vec1f* setVec(Vec1f* vec);
	Vec1f* setVec(Vec1f vec);
	float getX();

	virtual Vecf* setN(int n, float value);
	virtual float getN(int n);
	virtual int getDim();

	Vec1f* copyInto(Vec1f* raw);

	void operator+=(Vec1f* vec);
	void operator-=(Vec1f* vec);
	void operator*=(Vec1f* vec);
	void operator/=(Vec1f* vec);

	void operator+=(Vec1f vec);
	void operator-=(Vec1f vec);
	void operator*=(Vec1f vec);
	void operator/=(Vec1f vec);
};

}

#endif
