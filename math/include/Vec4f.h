#ifndef VEC4F_H_
#define VEC4F_H_

#include "Vecf.h"
#include "Mat4f.h"


namespace cph {

class Vec4f : public Vecf {
	
private:
	float x, y, z, w;

public:
	Vec4f(float x = 0, float y = 0, float z = 0, float w = 0);
	~Vec4f();

	Vec4f* addVec4f(const Vec4f* vec);
	Vec4f* subVec4f(const Vec4f* vec);
	Vec4f* mulVec4f(const Vec4f* vec);
	Vec4f* divVec4f(const Vec4f* vec);
	Vec4f* mulMat4f(const Mat4f* mat);
	
	Vec4f* addVec4f(const Vec4f& vec);
	Vec4f* subVec4f(const Vec4f& vec);
	Vec4f* mulVec4f(const Vec4f& vec);
	Vec4f* divVec4f(const Vec4f& vec);
	Vec4f* mulMat4f(const Mat4f& mat);
	
	Vec4f* addVec4f(float vx, float vy, float vz, float vw);
	Vec4f* subVec4f(float vx, float vy, float vz, float vw);
	Vec4f* mulVec4f(float vx, float vy, float vz, float vw);
	Vec4f* divVec4f(float vx, float vy, float vz, float vw);
	
	float dot(const Vec4f* vec) const;
	float dot(const Vec4f& vec) const;

	Vec4f* mulScalar(float value);
	Vec4f* normalize();
	Vec4f* toLength(float value);
	Vec4f* negate();

	float getX() const;
	float getY() const;
	float getZ() const;
	float getW() const;
	Vec4f* setX(float newX);
	Vec4f* setY(float newY);
	Vec4f* setZ(float newZ);
	Vec4f* setW(float newW);
	Vec4f* setXYZW(float newX, float newY, float newZ, float newW);
	
	Vec4f* setVec(const Vec4f* vec);
	Vec4f* setVec(const Vec4f& vec);

	virtual float getN(int n) const;
	virtual Vecf* setN(int n, float value);
	virtual int getDim() const;
	
	Vec4f copy() const;
	Vec4f* copyInto(Vec4f* raw) const;

	void operator+=(const Vec4f* vec);
	void operator-=(const Vec4f* vec);
	void operator*=(const Vec4f* vec);
	void operator/=(const Vec4f* vec);
	void operator*=(const Mat4f* mat);
	
	void operator+=(const Vec4f& vec);
	void operator-=(const Vec4f& vec);
	void operator*=(const Vec4f& vec);
	void operator/=(const Vec4f& vec);
	void operator*=(const Mat4f& mat);

};

}

#endif