#ifndef __VECTOR3__
#define __VECTOR3__

class Vector3 {
	double _x;
	double _y;
	double _z;
public:
	inline Vector3() {}
	inline Vector3(double x, double y, double z) {}
	inline virtual ~Vector3() {}
	double getX();
	double getY();
	double getZ();
	void set(double x, double y, double z);
	//void set(Vector3 *a);
	Vector3 operator=(const Vector3 & vec); /*PORQUE NÃO UM *VECTOR? */
	Vector3 operator*(double num);
	Vector3 operator+(const Vector3 & vec);
	Vector3 operator-(const Vector3 & vec);
};

#endif