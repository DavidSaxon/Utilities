/**********************\
| 3 dimensional vector |
|					   |
| @author David Saxon  |
\**********************/

#ifndef UTILITIES_VECTOR_VECTOR3D_H_
#	define UTILITIES_VECTOR_VECTOR3D_H_

#include <iostream>
#include <sstream>

namespace util { namespace vec {

class Vector3D {

	//FRIEND FUNCTIONS
	/*!Prints the vector to the output stream
	^INL
	@output the output stream to print to
	@return the changed output stream*/
	friend std::ostream& operator<<(std::ostream& output,
		const Vector3D& v);

public:

	//CONSTRUCTORS
	/*Creates a new empty 3d vector
	^INL*/
	Vector3D() :
		x(0),
		y(0),
		z(0){
	}

	/*!Creates a new 3d vector
	^INL
	@_x the vector's first value
	@_y the vector's second value
	@_z the vector's third value*/
	Vector3D(float _x, float _y, float _z) :
		x(_x),
		y(_y),
		z(_z) {
	}

	/*!Creates a copy of the other vector
	^INL
	@other the other vector to copy from*/
	Vector3D(const Vector3D& other) :
		x(other.x),
		y(other.y),
		z(other.z) {
	}

	//DESTRUCTOR
	/*!Destroys this vector
	^INL*/
	~Vector3D() {
	}

	//OPERATORS
	/*!Copies the other vector's values into this vector
	^INL
	@other the other vector to copy from*/
	Vector3D& operator=(const Vector3D& other);

	/*!Compares if two vectors are equal
	^INL
	@other the other vector to compare this vector with
	@return whether the vectors are equal*/
	bool operator==(const Vector3D& other);

	/*!Compares if two vectors are not equal
	^INL
	@other the other vector to compare this vector with
	@return whether the vectors are equal*/
	bool operator!=(const Vector3D& other);

	/*!Creates a new vector from the addition of this and the other vector
	^INL
	@other the other vector to add with
	@return the result of the addition*/
	Vector3D operator+(const Vector3D& other);

	/*!Creates a new vector from the subtraction of this and the other vector
	^INL
	@other the other vector to subtract with
	@return the result of the subtraction*/
	Vector3D operator-(const Vector3D& other);

	/*!Creates a new vector from the multiplication of this and the other vector
	^INL
	@other the other vector to multiply with
	@return the result of the multiplication*/
	Vector3D operator*(const Vector3D& other);

	/*!Creates a new vector from the division of this and the other vector
	^INL
	@other the other vector to divide with
	@return the result of the division*/
	Vector3D operator/(const Vector3D& other);

	/*!Adds the values of the first vector to this vector
	^INL
	@other the other vector to add to this*/
	void operator+=(const Vector3D& other);

	/*!Subtracts the values of the second vector from this vector
	^INL
	@other the other vector to subtract from this*/
	void operator-=(const Vector3D& other);

	/*!multiplies the individual values of this vector by the values
	of the other vector
	^INL
	@other the other vector to multiply by*/
	void operator*=(const Vector3D& other);

	/*!Divides the individual values of this vector by the values of
	the other vector
	^INL
	@other the other vector to divide by*/
	void operator/=(const Vector3D& other);

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

	/*!Sets the new values of the vector
	^INL
	@_x the new x value
	@_y the new y value
	@_z the new z value*/
	void set(float _x, float _y, float _z);

	/*!^INL
	@_x the new x value of the vector*/
	void setX(float _x);

	/*!^INL
	@_y the new y value of the vector*/
	void setY(float _y);

	/*!^INL
	@_z the new z value of the vector*/
	void setZ(float _z);

	/*!Outputs the vector in string format
	^INL
	@return the string of the vector*/
	std::string toString() const;


private:

	//VARIABLES
	//the three values of the vector
	float x;
	float y;
	float z;
};

//INLINE
//OPERATORS
inline std::ostream& operator<<(std::ostream& output,
	const Vector3D& v) {

	//print the vector to the output
	output << v.toString();

	return output;
}

inline Vector3D& Vector3D::operator=(const Vector3D& other) {

	x = other.x;
	y = other.y;
	z = other.z;
}

inline bool Vector3D::operator==(const Vector3D& other) {

	return x == other.x && y == other.y && z == other.z;
}

inline bool Vector3D::operator !=(const Vector3D& other) {

	return !((*this) == other);
}

inline Vector3D Vector3D::operator+(const Vector3D& other) {

	return Vector3D(x + other.x, y + other.y, z + other.z);
}

inline Vector3D Vector3D::operator-(const Vector3D& other) {

	return Vector3D(x - other.x, y - other.y, z - other.z);
}

inline Vector3D Vector3D::operator*(const Vector3D& other) {

	return Vector3D(x * other.x, y * other.y, z * other.z);
}

inline Vector3D Vector3D::operator/(const Vector3D& other) {

	return Vector3D(x / other.x, y / other.y, z / other.z);
}

inline void Vector3D::operator+=(const Vector3D& other) {

	x += other.x;
	y += other.y;
	z += other.z;
}

inline void Vector3D::operator-=(const Vector3D& other) {

	x -= other.x;
	y -= other.y;
	z -= other.z;
}

inline void Vector3D::operator*=(const Vector3D& other) {

	x *= other.x;
	y *= other.y;
	z *= other.z;
}

inline void Vector3D::operator/=(const Vector3D& other) {

	x /= other.x;
	y /= other.y;
	z /= other.z;
}

//PUBLIC MEMBER FUNCTIONS
inline void Vector3D::clear() {

	x = 0;
	y = 0;
	z = 0;
}

inline float Vector3D::getX() const {

	return x;
}

inline float Vector3D::getY() const {

	return y;
}

inline float Vector3D::getZ() const {

	return z;
}

inline void Vector3D::set(float _x, float _y, float _z) {

	x = _x;
	y = _y;
	z = _z;
}

inline void Vector3D::setX(float _x) {

	x = _x;
}

inline void Vector3D::setY(float _y) {

	y = _y;
}

inline void Vector3D::setZ(float _z) {

	z = _z;
}

inline std::string Vector3D::toString() const {

	//create the string of the vector
	std::stringstream ss;
	ss << "(" << x << ", " << y << ", " << z << ")";

	return ss.str();
}

} } //util //vec

#endif