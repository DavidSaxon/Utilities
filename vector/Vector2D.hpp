/**********************\
| 2 dimensional vector |
|					   |
| @author David Saxon  |
\**********************/

#ifndef UTILITIES_VECTOR_VECTOR2D_H_
#	define UTILITIES_VECTOR_VECTOR2D_H_

#include <iostream>
#include <sstream>

namespace util { namespace vec {

class Vector2D {

	//FRIEND FUNCTIONS
	/*!Prints the vector to the output stream
	^INL
	@output the output stream to print to
	@return the changed output stream*/
	friend std::ostream& operator<<(std::ostream& output,
		const Vector2D& v);

public:

	//CONSTRUCTORS
	/*Creates a new empty 2d vector
	^INL*/
	Vector2D() :
		x(0),
		y(0) {
	}

	/*!Creates a new 2d vector
	^INL
	@_x the vector's first value
	@_y the vector's second value*/
	Vector2D(float _x, float _y) :
		x(_x),
		y(_y) {
	}

	/*!Creates a copy of the other vector
	^INL
	@other the other vector to copy from*/
	Vector2D(const Vector2D& other) :
		x(other.x),
		y(other.y) {
	}

	//DESTRUCTOR
	/*!Destroys this vector
	^INL*/
	~Vector2D() {
	}

	//OPERATORS
	/*!Copies the other vector's values into this vector
	^INL
	@other the other vector to copy from*/
	Vector2D& operator=(const Vector2D& other);

	/*!Compares if two vectors are equal
	^INL
	@other the other vector to compare this vector with
	@return whether the vectors are equal*/
	bool operator==(const Vector2D& other);

	/*!Compares if two vectors are not equal
	^INL
	@other the other vector to compare this vector with
	@return whether the vectors are equal*/
	bool operator!=(const Vector2D& other);

	/*!Creates a new vector from the addition of this and the other vector
	^INL
	@other the other vector to add with
	@return the result of the addition*/
	Vector2D operator+(const Vector2D& other);

	/*!Creates a new vector from the subtraction of this and the other vector
	^INL
	@other the other vector to subtract with
	@return the result of the subtraction*/
	Vector2D operator-(const Vector2D& other);

	/*!Creates a new vector from the multiplication of this and the other vector
	^INL
	@other the other vector to multiply with
	@return the result of the multiplication*/
	Vector2D operator*(const Vector2D& other);

	/*!Creates a new vector from the division of this and the other vector
	^INL
	@other the other vector to divide with
	@return the result of the division*/
	Vector2D operator/(const Vector2D& other);

	/*!Adds the values of the first vector to this vector
	^INL
	@other the other vector to add to this*/
	void operator+=(const Vector2D& other);

	/*!Subtracts the values of the second vector from this vector
	^INL
	@other the other vector to subtract from this*/
	void operator-=(const Vector2D& other);

	/*!multiplies the individual values of this vector by the values
	of the other vector
	^INL
	@other the other vector to multiply by*/
	void operator*=(const Vector2D& other);

	/*!Divides the individual values of this vector by the values of
	the other vector
	^INL
	@other the other vector to divide by*/
	void operator/=(const Vector2D& other);

	//PUBLIC MEMBER FUNCTIONS
	/*!Reset the vector to an empty vector
	^INL*/
	void clear();

	/*!^INL
	@return the x value of the vector*/
	float getX() const;

	/*!^INL
	@return the y value of the vector*/
	float getY() const;

	/*!Sets the new values of the vector
	^INL
	@_x the new x value
	@_y the new y value*/
	void set(float _x, float _y);

	/*!^INL
	@_x the new x value of the vector*/
	void setX(float _x);

	/*!^INL
	@_y the new y value of the vector*/
	void setY(float _y);

	/*!Outputs the vector in string format
	^INL
	@return the string of the vector*/
	std::string toString() const;


private:

	//VARIABLES
	//the two values of the vector
	float x;
	float y;
};

//INLINE
//OPERATORS
inline std::ostream& operator<<(std::ostream& output,
	const Vector2D& v) {

	//print the vector to the output
	output << v.toString();

	return output;
}

inline Vector2D& Vector2D::operator=(const Vector2D& other) {

	x = other.x;
	y = other.y;
}

inline bool Vector2D::operator==(const Vector2D& other) {

	return x == other.x && y == other.y;
}

inline bool Vector2D::operator !=(const Vector2D& other) {

	return !((*this) == other);
}

inline Vector2D Vector2D::operator+(const Vector2D& other) {

	return Vector2D(x + other.x, y + other.y);
}

inline Vector2D Vector2D::operator-(const Vector2D& other) {

	return Vector2D(x - other.x, y - other.y);
}

inline Vector2D Vector2D::operator*(const Vector2D& other) {

	return Vector2D(x * other.x, y * other.y);
}

inline Vector2D Vector2D::operator/(const Vector2D& other) {

	return Vector2D(x / other.x, y / other.y);
}

inline void Vector2D::operator+=(const Vector2D& other) {

	x += other.x;
	y += other.y;
}

inline void Vector2D::operator-=(const Vector2D& other) {

	x -= other.x;
	y -= other.y;
}

inline void Vector2D::operator*=(const Vector2D& other) {

	x *= other.x;
	y *= other.y;
}

inline void Vector2D::operator/=(const Vector2D& other) {

	x /= other.x;
	y /= other.y;
}

//PUBLIC MEMBER FUNCTIONS
inline void Vector2D::clear() {

	x = 0;
	y = 0;
}

inline float Vector2D::getX() const {

	return x;
}

inline float Vector2D::getY() const {

	return y;
}

inline void Vector2D::set(float _x, float _y) {

	x = _x;
	y = _y;
}

inline void Vector2D::setX(float _x) {

	x = _x;
}

inline void Vector2D::setY(float _y) {

	y = _y;
}

inline std::string Vector2D::toString() const {

	//create the string of the vector
	std::stringstream ss;
	ss << "(" << x << ", " << y << ")";

	return ss.str();
}

} } //util //vec

#endif