/***********************\
| 2 dimensional vector. |
|                       |
| @author David Saxon   |
\***********************/

#ifndef UTILTIES_VECTOR_VECTOR2_H_
#   define UTILTIES_VECTOR_VECTOR2_H_

#include <iostream>
#include <cmath>
#include <sstream>

#include "../exceptions/ArrayException.hpp"

namespace util { namespace vec {

namespace v2 {

//ENUMERATORS
//!Access enumerators for the dimension values
enum {

    X = 0,
    Y
};

//!Access enumerators for the colour values
enum {

    R = 0,
    G
};

} //v2

class Vector2 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @_output the output stream to print to
    @_v the vector to print
    @return the changed output stream*/
    friend std::ostream& operator <<(std::ostream& _output,
        const Vector2& _v);

public:

    //CONSTRUCTORS
    /*!Creates a new zero 2D vector*/
    Vector2() :
        x(0),
        y(0) {
    }

    /*!Creates a new 2D vector
    @_x the vector's first value
    @_y the vector's second value*/
    Vector2(float _x, float _y) :
        x(_x),
        y(_y) {
    }

    /*!Creates a vector by copying the other vector
    @other the other vector to copy from*/
    Vector2(const Vector2& _other) :
        x(_other.x),
        y(_other.y) {
    }

    //DESTRUCTOR
    /*!Destorys this vector*/
    ~Vector2() {
    }

    //OPERATORS
    /*!Copies the other vector's values to this vector
    @_other the other vector to copy from*/
    Vector2& operator =(const Vector2& _other);

    /*!Checks if this vector and the other vector are equal
    @_other the other vector to compare with
    @return whether the vectors are equal*/
    bool operator ==(const Vector2& _other) const;

    /*!Checks if this vector and the other vector are not equal
    @_other the other vector to compare with
    @return whether the vectors are not equal*/
    bool operator !=(const Vector2& _other) const;

    /*!Gets the value at the specified index
    @_index the index
    @return the value*/
    float& operator [](unsigned _index);

    /*!Gets the value at the specified index
    @_index the index
    @return the value*/
    const float& operator [](unsigned _index) const;

    /*!@return the vector with all elements negated*/
    Vector2 operator -() const;

    /*!Creates a new vector from the addition of this and the scalar
    @_scalar the scalar to add with
    @return the result of the addition*/
    Vector2 operator +(float _scalar) const;

    /*!Adds the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator +=(float _scalar);

    /*!Creates a new vector from the addition of this and the other vector
    @_other the other vector to add with
    @return the result of the addition*/
    Vector2 operator +(const Vector2& _other) const;

    /*!Adds the value of the other vector to this vector
    @_other the other vector to add to this*/
    void operator +=(const Vector2& _other);

    /*!Creates a new vector from the subtraction of this and the scalar
    @_scalar the scalar to add with
    @return the result of the subtraction*/
    Vector2 operator -(float _scalar) const;

    /*!Subtracts the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator -=(float _scalar);

    /*!Creates a new vector from the subtraction of this and the other vector
    @_other the other vector to subtract with
    @return the result of the subtraction*/
    Vector2 operator -(const Vector2& _other) const;

    /*!Subtracts the value of the other vector from this vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @_other the other vector to subtract from this*/
    void operator -=(const Vector2& _other);

    /*!Creates a new vector from the multiplication of this and the scalar
    @_scalar the scalar to add with
    @return the result of the multiplication*/
    Vector2 operator *(float _scalar) const;

    /*!Multiplies the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator *=(float _scalar);

    /*!Creates a new vector from the multiplication of this and the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @_other the other vector to multiply with
    @return the result of the multiplication*/
    Vector2 operator *(const Vector2& _other) const;

    /*!Multiplies this vector by the other vector
    @_other the other vector to multiply by*/
    void operator *=(const Vector2& _other);

    /*!Creates a new vector from the division of this and the scalar
    @_scalar the scalar to add with
    @return the result of the division*/
    Vector2 operator /(float _scalar) const;

    /*!Divides the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator /=(float _scalar);

    /*!Creates a new vector from the division of this and the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @_other the other vector to divide with
    @return the result of the division*/
    Vector2 operator /(const Vector2& _other) const;

    /*!Divides this vector by the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @_other the other vector to divide by*/
    void operator /=(const Vector2& _other);

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the 2D zero vector*/
    static Vector2 zero();

    /*!@return the x 2d vector*/
    static Vector2 xVector();

    /*!@return the y 2d vector*/
    static Vector2 yVector();

    /*!Resets the vector to the zero vector*/
    void clear();

    /*!Inverses the vector*/
    void inverse();

    /*!@return the vector inversed*/
    Vector2* getInverse() const;

    /*!normalises the vector*/
    void normalise();

    /*!@return the magnitude of the vector*/
    float magnitude() const;

    /*!Computes the dot product of this vector and the other vector
    @_other the other vector
    @return the dot product*/
    float dotProduct(const util::vec::Vector2& _other) const;

    /*!Calculates the distance between this vector and the other vector
    @_other the vector
    @return the distance*/
    float distance(const util::vec::Vector2& _other) const;

    /*!Calculates the angle between this vector and the other vector
    @_other the other vector
    @return the angle between*/
    float angleBetween(const util::vec::Vector2& _other) const;

    /*!@return the vector as an array*/
    float* toArray() const;

    /*!@return the x value*/
    float getX() const;

    /*!@return the y value*/
    float getY() const;

    /*!@return the x value*/
    float getR() const;

    /*!@return the y value*/
    float getG() const;

    /*!Sets the new values
    @_x the new x value
    @_y the new y value*/
    void set(float _x, float _y);

    /*!@_x the new x value*/
    void setX(float _x);

    /*!@_y the new y value*/
    void setY(float _y);

    /*!@_r the new x value*/
    void setR(float _r);

    /*!@_g the new y value*/
    void setG(float _g);

    /*!Outputs the vector in string format
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
inline std::ostream& operator <<(std::ostream& _output,
    const Vector2& _v) {

    //print the vector to the output
    _output << _v.toString();

    return _output;
}

inline Vector2& Vector2::operator =(const Vector2& _other) {

    x = _other.x;
    y = _other.y;

    return *this;
}

inline bool Vector2::operator ==(const Vector2& _other) const {

    return x == _other.x && y == _other.y;
}

inline bool Vector2::operator  !=(const Vector2& _other) const {

    return !((*this) == _other);
}

inline float& Vector2::operator [](unsigned _index) {

    //check that the index is within bounds
    if (_index > 1) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 1.");
    }

    switch (_index) {

        case 0: {

            return x;
        }
        default: {

            return y;
        }
    }
}

inline const float& Vector2::operator [](unsigned _index) const {

    //check that the index is within bounds
    if (_index > 1) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 1.");
    }

    switch (_index) {

        case 0: {

            return x;
        }
        default: {

            return y;
        }
    }
}

inline Vector2 Vector2::operator -() const {

    return Vector2(-x, -y);
}

inline Vector2 Vector2::operator +(float _scalar) const {

    return Vector2(x + _scalar, y + _scalar);
}

inline void Vector2::operator +=(float _scalar) {

    x += _scalar;
    y += _scalar;
}

inline Vector2 Vector2::operator +(const Vector2& _other) const {

    return Vector2(x + _other.x, y + _other.y);
}

inline void Vector2::operator +=(const Vector2& _other) {

    x += _other.x;
    y += _other.y;
}

inline Vector2 Vector2::operator -(float _scalar) const {

    return Vector2(x - _scalar, y - _scalar);
}

inline void Vector2::operator -=(float _scalar) {

    x -= _scalar;
    y -= _scalar;
}

inline Vector2 Vector2::operator -(const Vector2& _other) const {

    return Vector2(x - _other.x, y - _other.y);
}

inline void Vector2::operator -=(const Vector2& _other) {

    x -= _other.x;
    y -= _other.y;
}

inline Vector2 Vector2::operator *(float _scalar) const {

    return Vector2(x * _scalar, y * _scalar);
}

inline void Vector2::operator *=(float _scalar) {

    x *= _scalar;
    y *= _scalar;
}

inline Vector2 Vector2::operator *(const Vector2& _other) const {

    return Vector2(x * _other.x, y * _other.y);
}

inline void Vector2::operator *=(const Vector2& _other) {

    x *= _other.x;
    y *= _other.y;
}

inline Vector2 Vector2::operator /(float _scalar) const {

    return Vector2(x / _scalar, y / _scalar);
}

inline void Vector2::operator /=(float _scalar) {

    x /= _scalar;
    y /= _scalar;
}

inline Vector2 Vector2::operator /(const Vector2& _other) const {

    return Vector2(x / _other.x, y / _other.y);
}

inline void Vector2::operator /=(const Vector2& _other) {

    x /= _other.x;
    y /= _other.y;
}

//PUBLIC MEMBER FUNCTIONS
inline Vector2 Vector2::zero() {

    return Vector2();
}

inline Vector2 Vector2::xVector() {

    return Vector2(1.0f, 0.0f);
}

inline Vector2 Vector2::yVector() {

    return Vector2(0.0f, 1.0f);
}

inline void Vector2::clear() {

    x = 0;
    y = 0;
}

inline void Vector2::inverse() {

    x = -x;
    y = -y;
}

inline Vector2* Vector2::getInverse() const {

    return new Vector2(-x, -y);
}

inline void Vector2::normalise() {

    //get the magnitude
    float mag = magnitude();

    //normalise the components
    x /= mag;
    y /= mag;
}

inline float Vector2::magnitude() const {

    return distance(Vector2::zero());
}

inline float Vector2::dotProduct(const util::vec::Vector2& _other) const {

    return (x * _other.x) + (y * _other.y);
}

inline float Vector2::distance(const util::vec::Vector2& _other) const {

    return sqrt(pow(x - _other.x, 2.0f) + pow(y - _other.y, 2.0f));
}

inline float Vector2::angleBetween(const util::vec::Vector2& _other) const {

    return (-1.0f * atan2(y - _other.y, x - _other.x));
}

inline float* Vector2::toArray() const {

    float* array = new float[2];
    array[0] = x;
    array[1] = y;

    return array;
}

inline float Vector2::getX() const {

    return x;
}

inline float Vector2::getY() const {

    return y;
}

inline float Vector2::getR() const {

    return x;
}

inline float Vector2::getG() const {

    return y;
}

inline void Vector2::set(float _x, float _y) {

    x = _x;
    y = _y;
}

inline void Vector2::setX(float _x) {

    x = _x;
}

inline void Vector2::setY(float _y) {

    y = _y;
}

inline void Vector2::setR(float _r) {

    x = _r;
}

inline void Vector2::setG(float _g) {

    y = _g;
}

inline std::string Vector2::toString() const {

    //create the string of the vector
    std::stringstream ss;
    ss << "[" << x << ", " << y << "]";

    return ss.str();
}

} } //util //vec

#endif