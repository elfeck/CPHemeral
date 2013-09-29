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

	Vec3f* addVec3f(Vec3f* vec);
	Vec3f* subVec3f(Vec3f* vec);
	Vec3f* mulVec3f(Vec3f* vec);
	Vec3f* divVec3f(Vec3f* vec);
	Vec3f* mulMat3f(Mat3f* mat);
	
	Vec3f* addVec3f(Vec3f vec);
	Vec3f* subVec3f(Vec3f vec);
	Vec3f* mulVec3f(Vec3f vec);
	Vec3f* divVec3f(Vec3f vec);
	Vec3f* mulMat3f(Mat3f mat);
	
	Vec3f* addVec3f(float vx, float vy, float vz);
	Vec3f* subVec3f(float vx, float vy, float vz);
	Vec3f* mulVec3f(float vx, float vy, float vz);
	Vec3f* divVec3f(float vx, float vy, float vz);
	
	float dot(Vec3f* vec);
	float dot(Vec3f vec);
	Vec3f* mulScalar(float value);
	Vec3f* normalize();
	Vec3f* toLength(float value);
	Vec3f* negate();

	Vec3f* setX(float newX);
	Vec3f* setY(float newY);
	Vec3f* setZ(float newZ);
	Vec3f* setXYZ(float newX, float newY, float newZ);
	Vec3f* setVec(Vec3f* vec);
	Vec3f* setVec(Vec3f vec);
	float getX();
	float getY();
	float getZ();

	virtual Vecf* setN(int n, float value);
	virtual float getN(int n);
	virtual int getDim();
	
	Vec3f* copyInto(Vec3f* raw);

	void operator+=(Vec3f* vec);
	void operator-=(Vec3f* vec);
	void operator*=(Vec3f* vec);
	void operator/=(Vec3f* vec);
	void operator*=(Mat3f* mat);
	
	void operator+=(Vec3f vec);
	void operator-=(Vec3f vec);
	void operator*=(Vec3f vec);
	void operator/=(Vec3f vec);
	void operator*=(Mat3f mat);
};

}

#endif