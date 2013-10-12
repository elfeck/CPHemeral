#ifndef VEC1F_H_
#define VEC1F_H_

#include "Vecf.h"


namespace cph {

class Vec1f : public Vecf {

protected:
	float x;

public:
	Vec1f(float x = 0);
	~Vec1f();

	Vec1f* addVec1f(const Vec1f* vec);
	Vec1f* subVec1f(const Vec1f* vec);
	Vec1f* mulVec1f(const Vec1f* vec);
	Vec1f* divVec1f(const Vec1f* vec);
		
	Vec1f* addVec1f(const Vec1f& vec);
	Vec1f* subVec1f(const Vec1f& vec);
	Vec1f* mulVec1f(const Vec1f& vec);
	Vec1f* divVec1f(const Vec1f& vec);

	Vec1f* addVec1f(float vx);
	Vec1f* subVec1f(float vx);
	Vec1f* mulVec1f(float vx);
	Vec1f* divVec1f(float vx);

	float dot(const Vec1f* vec) const;
	float dot(const Vec1f& vec) const;

	Vec1f* mulScalar(float value);
	Vec1f* normalize();
	Vec1f* toLength(float value);
	Vec1f* negate();

	float getX() const;
	Vec1f* setX(float newX);
	
	Vec1f* setVec(const Vec1f* vec);
	Vec1f* setVec(const Vec1f& vec);

	virtual float getN(int n) const;
	virtual Vecf* setN(int n, float value);
	virtual int getDim() const;

	Vec1f copy() const;
	Vec1f* copyInto(Vec1f* raw) const;

	void operator+=(const Vec1f* vec);
	void operator-=(const Vec1f* vec);
	void operator*=(const Vec1f* vec);
	void operator/=(const Vec1f* vec);

	void operator+=(const Vec1f& vec);
	void operator-=(const Vec1f& vec);
	void operator*=(const Vec1f& vec);
	void operator/=(const Vec1f& vec);

};

}

#endif
