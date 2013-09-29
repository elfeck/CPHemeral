#ifndef VEC2F_H_
#define VEC2F_H_

#include "Vecf.h"
#include "Mat2f.h"


namespace cph {

class Vec2f : public Vecf {

private:
	float x, y;

public:
	Vec2f(float x = 0, float y = 0);
	~Vec2f();

	Vec2f* addVec2f(Vec2f* vec);
	Vec2f* subVec2f(Vec2f* vec);
	Vec2f* mulVec2f(Vec2f* vec);
	Vec2f* divVec2f(Vec2f* vec);
	Vec2f* mulMat2f(Mat2f* mat);
	
	Vec2f* addVec2f(Vec2f vec);
	Vec2f* subVec2f(Vec2f vec);
	Vec2f* mulVec2f(Vec2f vec);
	Vec2f* divVec2f(Vec2f vec);
	Vec2f* mulMat2f(Mat2f mat);
	
	Vec2f* addVec2f(float vx, float vy);
	Vec2f* subVec2f(float vx, float vy);
	Vec2f* mulVec2f(float vx, float vy);
	Vec2f* divVec2f(float vx, float vy);
	

	float dot(Vec2f* vec);
	float dot(Vec2f vec);
	Vec2f* mulScalar(float value);
	Vec2f* normalize();
	Vec2f* toLength(float value);
	Vec2f* negate();

	Vec2f* setX(float newX);
	Vec2f* setY(float newY);
	Vec2f* setXY(float newX, float newY);
	Vec2f* setVec(Vec2f* vec);
	Vec2f* setVec(Vec2f vec);
	float getX();
	float getY();

	virtual Vecf* setN(int n, float value);
	virtual float getN(int n);
	virtual int getDim();

	Vec2f* copyInto(Vec2f* raw);

	void operator+=(Vec2f* vec);
	void operator-=(Vec2f* vec);
	void operator*=(Vec2f* vec);
	void operator/=(Vec2f* vec);
	void operator*=(Mat2f* mat);

	void operator+=(Vec2f vec);
	void operator-=(Vec2f vec);
	void operator*=(Vec2f vec);
	void operator/=(Vec2f vec);
	void operator*=(Mat2f mat);
};

}

#endif
