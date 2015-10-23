#ifndef __VECTOR3__
#define __VECTOR3__

class Vector3 {
	double _x = 0;
	double _y = 0;
	double _z = 0;
public:
	inline Vector3() { _x = 0; _y = 0; _z = 0; }
	inline Vector3(double x, double y, double z) { set(x, y, z); }
	inline virtual ~Vector3() {}
	double getX() { return _x; }
	double getY() { return _y; }
	double getZ() { return _z; }
	void set(double x, double y, double z) { _x = x; _y = y; _z = z; }
	void set(Vector3 v) { _x = v.getX(); _y = v.getY(); _z = v.getZ(); }
	void invert() { _x = (-_x); _y = (- _y); _z = (- _z); }
	//void set(Vector3 *a);
	Vector3 operator=(Vector3 *vec) {
		_x = vec->getX();  _y = vec->getY(); _z = vec->getZ(); return *this;
	}
	Vector3 operator*(double num) { 
		_x *= num; _y *= num; _z *= num; 
		return *this;
	}
	Vector3 operator*(Vector3 vec) {
		_x *= vec.getX(); _y *= vec.getY(); _z *= vec.getZ();
		return *this;
	}

	Vector3 operator+(Vector3 vec) {
		_x -= vec.getX(); _y -= vec.getY(); _z -= vec.getZ();
		return *this;
	}
	Vector3 operator+(double num) {
		_x += num; _y += num; _z += num;
		return *this;
	}

	Vector3 operator-(Vector3 vec) {
		_x -= vec.getX(); _y -= vec.getY(); _z -= vec.getZ();
		return *this; 
	}
	Vector3 operator-(double num) {
		_x -= num; _y -= num; _z -= num;
		return *this;
	}
};

#endif