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

	Vec2f* addVec2f(const Vec2f* vec);
	Vec2f* subVec2f(const Vec2f* vec);
	Vec2f* mulVec2f(const Vec2f* vec);
	Vec2f* divVec2f(const Vec2f* vec);
	Vec2f* mulMat2f(const Mat2f* mat);
	
	Vec2f* addVec2f(const Vec2f& vec);
	Vec2f* subVec2f(const Vec2f& vec);
	Vec2f* mulVec2f(const Vec2f& vec);
	Vec2f* divVec2f(const Vec2f& vec);
	Vec2f* mulMat2f(const Mat2f& mat);
	
	Vec2f* addVec2f(float vx, float vy);
	Vec2f* subVec2f(float vx, float vy);
	Vec2f* mulVec2f(float vx, float vy);
	Vec2f* divVec2f(float vx, float vy);

	float dot(const Vec2f* vec) const;
	float dot(const Vec2f& vec) const;

	Vec2f* mulScalar(float value);
	Vec2f* normalize();
	Vec2f* toLength(float value);
	Vec2f* negate();

	float getX() const;
	float getY() const;
	Vec2f* setX(float newX);
	Vec2f* setY(float newY);
	Vec2f* setXY(float newX, float newY);

	Vec2f* setVec(const Vec2f* vec);
	Vec2f* setVec(const Vec2f& vec);

	virtual float getN(int n) const;
	virtual Vecf* setN(int n, float value);
	virtual int getDim() const;

	Vec2f copy() const;
	Vec2f* copyInto(Vec2f* raw) const;

	void operator+=(const Vec2f* vec);
	void operator-=(const Vec2f* vec);
	void operator*=(const Vec2f* vec);
	void operator/=(const Vec2f* vec);
	void operator*=(const Mat2f* mat);

	void operator+=(const Vec2f& vec);
	void operator-=(const Vec2f& vec);
	void operator*=(const Vec2f& vec);
	void operator/=(const Vec2f& vec);
	void operator*=(const Mat2f& mat);

};

}

#endif
