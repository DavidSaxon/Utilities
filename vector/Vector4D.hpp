/**********************\
| 4 dimensional vector |
|					   |
| @author David Saxon  |
\**********************/

#ifndef UTILITIES_VECTOR_VECTOR4D_H_
#	define UTILITIES_VECTOR_VECTOR4D_H_

#include <iostream>
#include <sstream>

namespace util { namespace vec {

class Vector4D {

	//FRIEND FUNCTIONS
	/*!Prints the vector to the output stream
	^INL
	@output the output stream to print to
	@return the changed output stream*/
	friend std::ostream& operator<<(std::ostream& output,
		const Vector4D& v);

public:

	//CONSTRUCTORS
	/*Creates a new empty 4d vector
	^INL*/
	Vector4D() :
		x(0),
		y(0),
		z(0),
		f(0) {
	}

	/*!Creates a new 4d vector
	^INL
	@_x the vector's first value
	@_y the vector's second value
	@_z the vector's third value
	@_f the vector's fourth value*/
	Vector4D(float _x, float _y, float _z, float _f) :
		x(_x),
		y(_y),
		z(_z),
		f(_f) {
	}

	/*!Creates a copy of the other vector
	^INL
	@other the other vector to copy from*/
	Vector4D(const Vector4D& other) :
		x(other.x),
		y(other.y),
		z(other.z),
		f(other.f) {
	}

	//DESTRUCTOR
	/*!Destroys this vector
	^INL*/
	~Vector4D() {
	}

	//OPERATORS
	/*!Copies the other vector's values into this vector
	^INL
	@other the other vector to copy from*/
	Vector4D& operator=(const Vector4D& other);

	/*!Compares if two vectors are equal
	^INL
	@other the other vector to compare this vector with
	@return whether the vectors are equal*/
	bool operator==(const Vector4D& other);

	/*!Compares if two vectors are not equal
	^INL
	@other the other vector to compare this vector with
	@return whether the vectors are equal*/
	bool operator!=(const Vector4D& other);

	/*!Creates a new vector from the addition of this and the other vector
	^INL
	@other the other vector to add with
	@return the result of the addition*/
	Vector4D operator+(const Vector4D& other);

	/*!Creates a new vector from the subtraction of this and the other vector
	^INL
	@other the other vector to subtract with
	@return the result of the subtraction*/
	Vector4D operator-(const Vector4D& other);

	/*!Creates a new vector from the multiplication of this and the other vector
	^INL
	@other the other vector to multiply with
	@return the result of the multiplication*/
	Vector4D operator*(const Vector4D& other);

	/*!Creates a new vector from the division of this and the other vector
	^INL
	@other the other vector to divide with
	@return the result of the division*/
	Vector4D operator/(const Vector4D& other);

	/*!Adds the values of the first vector to this vector
	^INL
	@other the other vector to add to this*/
	void operator+=(const Vector4D& other);

	/*!Subtracts the values of the second vector from this vector
	^INL
	@other the other vector to subtract from this*/
	void operator-=(const Vector4D& other);

	/*!multiplies the individual values of this vector by the values
	of the other vector
	^INL
	@other the other vector to multiply by*/
	void operator*=(const Vector4D& other);

	/*!Divides the individual values of this vector by the values of
	the other vector
	^INL
	@other the other vector to divide by*/
	void operator/=(const Vector4D& other);

	//PUBLIC MEMBER FUNCTIONS
	/*!Reset the vector to an zero vector
	^INL*/
	void clear();

	/*!^INL
	@return the x value of the vector*/
	float getX() const;

	/*!^INL
	@return the y value of the vector*/
	float getY() const;

	/*!^INL
	@return the z value of the vector*/
	float getZ() const;

	/*!^INL
	@return the f value of the vector*/
	float getF() const;

	/*!Sets the new values of the vector
	^INL
	@_x the new x value
	@_y the new y value
	@_z the new z value
	@_f the new f value*/
	void set(float _x, float _y, float _z, float _f);

	/*!^INL
	@_x the new x value of the vector*/
	void setX(float _x);

	/*!^INL
	@_y the new y value of the vector*/
	void setY(float _y);

	/*!^INL
	@_z the new z value of the vector*/
	void setZ(float _z);

	/*^INL
	@_f the new f value of the vector*/
	void setF(float _f);

	/*!Outputs the vector in string format
	^INL
	@return the string of the vector*/
	std::string toString() const;


private:

	//VARIABLES
	//the four values of the vector
	float x;
	float y;
	float z;
	float f;
};

//INLINE
//OPERATORS
inline std::ostream& operator<<(std::ostream& output,
	const Vector4D& v) {

	//print the vector to the output
	output << v.toString();

	return output;
}

inline Vector4D& Vector4D::operator=(const Vector4D& other) {

	x = other.x;
	y = other.y;
	z = other.z;
	f = other.f;
}

inline bool Vector4D::operator==(const Vector4D& other) {

	return x == other.x && y == other.y && z == other.z && f == other.f;
}

inline bool Vector4D::operator !=(const Vector4D& other) {

	return !((*this) == other);
}

inline Vector4D Vector4D::operator+(const Vector4D& other) {

	return Vector4D(x + other.x, y + other.y, z + other.z, f + other.f);
}

inline Vector4D Vector4D::operator-(const Vector4D& other) {

	return Vector4D(x - other.x, y - other.y, z - other.z, f - other.f);
}

inline Vector4D Vector4D::operator*(const Vector4D& other) {

	return Vector4D(x * other.x, y * other.y, z * other.z, f * other.f);
}

inline Vector4D Vector4D::operator/(const Vector4D& other) {

	return Vector4D(x / other.x, y / other.y, z / other.z, f / other.f);
}

inline void Vector4D::operator+=(const Vector4D& other) {

	x += other.x;
	y += other.y;
	z += other.z;
	f += other.f;
}

inline void Vector4D::operator-=(const Vector4D& other) {

	x -= other.x;
	y -= other.y;
	z -= other.z;
	f -= other.f;
}

inline void Vector4D::operator*=(const Vector4D& other) {

	x *= other.x;
	y *= other.y;
	z *= other.z;
	f *= other.f;
}

inline void Vector4D::operator/=(const Vector4D& other) {

	x /= other.x;
	y /= other.y;
	z /= other.z;
	f /= other.f;
}

//PUBLIC MEMBER FUNCTIONS
inline void Vector4D::clear() {

	x = 0;
	y = 0;
	z = 0;
	f = 0;
}

inline float Vector4D::getX() const {

	return x;
}

inline float Vector4D::getY() const {

	return y;
}

inline float Vector4D::getZ() const {

	return z;
}

inline float Vector4D::getF() const {

	return f;
}

inline void Vector4D::set(float _x, float _y, float _z, float _f) {

	x = _x;
	y = _y;
	z = _z;
	f = _f;
}

inline void Vector4D::setX(float _x) {

	x = _x;
}

inline void Vector4D::setY(float _y) {

	y = _y;
}

inline void Vector4D::setZ(float _z) {

	z = _z;
}

inline void Vector4D::setF(float _f) {

	f = _f;
}

inline std::string Vector4D::toString() const {

	//create the string of the vector
	std::stringstream ss;
	ss << "(" << x << ", " << y << ", " << z << ", " << f << ")";

	return ss.str();
}

} } //util //vec

#endif