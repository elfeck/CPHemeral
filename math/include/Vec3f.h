#ifndef VEC3F_H_
#define VEC3F_H_

#include "Vecf.h"
#include "Mat3f.h"


namespace cph {

class Vec3f : public Vecf {
	
private:
	float x, y, z;

public:
	Vec3f(float x = 0, float y = 0, float z = 0);
	~Vec3f();

	Vec3f* addVec3f(const Vec3f* vec);
	Vec3f* subVec3f(const Vec3f* vec);
	Vec3f* mulVec3f(const Vec3f* vec);
	Vec3f* divVec3f(const Vec3f* vec);
	Vec3f* mulMat3f(const Mat3f* mat);
	
	Vec3f* addVec3f(const Vec3f& vec);
	Vec3f* subVec3f(const Vec3f& vec);
	Vec3f* mulVec3f(const Vec3f& vec);
	Vec3f* divVec3f(const Vec3f& vec);
	Vec3f* mulMat3f(const Mat3f& mat);

	Vec3f* addVec3f(float vx, float vy, float vz);
	Vec3f* subVec3f(float vx, float vy, float vz);
	Vec3f* mulVec3f(float vx, float vy, float vz);
	Vec3f* divVec3f(float vx, float vy, float vz);
	
	float dot(const Vec3f* vec) const;
	float dot(const Vec3f& vec) const;

	Vec3f* mulScalar(float value);
	Vec3f* normalize();
	Vec3f* toLength(float value);
	Vec3f* negate();

	float getX() const;
	float getY() const;
	float getZ() const;
	Vec3f* setX(float newX);
	Vec3f* setY(float newY);
	Vec3f* setZ(float newZ);
	Vec3f* setXYZ(float newX, float newY, float newZ);

	Vec3f* setVec(const Vec3f* vec);
	Vec3f* setVec(const Vec3f& vec);

	virtual float getN(int n) const;
	virtual Vecf* setN(int n, float value);
	virtual int getDim() const;
	
	Vec3f copy() const;
	Vec3f* copyInto(Vec3f* raw) const;

	void operator+=(const Vec3f* vec);
	void operator-=(const Vec3f* vec);
	void operator*=(const Vec3f* vec);
	void operator/=(const Vec3f* vec);
	void operator*=(const Mat3f* mat);

	void operator+=(const Vec3f& vec);
	void operator-=(const Vec3f& vec);
	void operator*=(const Vec3f& vec);
	void operator/=(const Vec3f& vec);
	void operator*=(const Mat3f& mat);

};

}

#endif