/***********************\
| 4 dimensional vector. |
|                       |
| @author David Saxon   |
\***********************/

#ifndef UTILTIES_VECTOR_VECTOR4_H_
#   define UTILTIES_VECTOR_VECTOR4_H_

#include <iostream>
#include <cmath>
#include <sstream>

#include "../exceptions/ArrayException.hpp"

namespace util { namespace vec {

namespace v4 {

//ENUMERATORS
//!Access enumerators for the dimension values
enum {

    X = 0,
    Y,
    Z,
    W
};

//!Access enumerators for the colour values
enum {

    R = 0,
    G,
    B,
    A
};

} //v4

class Vector4 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @_output the output stream to print to
    @_v the vector to print
    @return the changed output stream*/
    friend std::ostream& operator<< (std::ostream& _output,
        const Vector4& _v);

public:

    //CONSTRUCTORS
    /*!Creates a new zero 4D vector*/
    Vector4() :
        x(0),
        y(0),
        z(0) {
    }

    /*!Creates a new 4D vector
    @_x the vector's first value
    @_y the vector's second value
    @_z the vector's third value
    @_w the vector's fourth value*/
    Vector4(float _x, float _y, float _z, float _w) :
        x(_x),
        y(_y),
        z(_z),
        w(_w) {
    }

    /*!Creates a vector by copying the other vector
    @_other the other vector to copy from*/
    Vector4(const Vector4& _other) :
        x(_other.x),
        y(_other.y),
        z(_other.z),
        w(_other.w) {
    }

    //DESTRUCTOR
    /*!Destorys this vector*/
    ~Vector4() {
    }

    //OPERATORS
    /*!Copies the other vector's values to this vector
    @_other the other vector to copy from*/
    Vector4& operator =(const Vector4& _other);

    /*!Checks if this vector and the other vector are equal
    @_other the other vector to compare with
    @return whether the vectors are equal*/
    bool operator ==(const Vector4& _other) const;

    /*!Checks if this vector and the other vector are not equal
    @_other the other vector to compare with
    @return whether the vectors are not equal*/
    bool operator !=(const Vector4& _other) const;

    /*!Gets the value at the specified index
    @_index the index
    @return the value*/
    float& operator [](unsigned _index);

    /*!Gets the value at the specified index
    @_index the index
    @return the value*/
    const float& operator [](unsigned _index) const;

    /*!@return the vector with all elements negated*/
    Vector4 operator -() const;

    /*!Creates a new vector from the addition of this and the scalar
    @_scalar the scale to add with
    @return the result of the addition*/
    Vector4 operator +(float _scalar) const;

    /*!Adds the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator +=(float _scalar);

    /*!Creates a new vector from the addition of this and the other vector
    @_other the other vector to add with
    @return the result of the addition*/
    Vector4 operator +(const Vector4& _other) const;

    /*!Adds the value of the other vector to this vector
    @_other the other vector to add to this*/
    void operator +=(const Vector4& _other);

    /*!Creates a new vector from the subtraction of this and the scalar
    @_scalar the scale to add with
    @return the result of the subtraction*/
    Vector4 operator -(float _scalar) const;

    /*!Subtracts the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator -=(float _scalar);

    /*!Creates a new vector from the subtraction of this and the other vector
    @_other the other vector to subtract with
    @return the result of the subtraction*/
    Vector4 operator -(const Vector4& _other) const;

    /*!Subtracts the value of the other vector from this vector
    @_other the other vector to subtract from this*/
    void operator -=(const Vector4& _other);

    /*!Creates a new vector from the multiplication of this and the scalar
    @_scalar the scale to add with
    @return the result of the multiplication*/
    Vector4 operator *(float _scalar) const;

    /*!Multiplies the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator *=(float _scalar);

    /*!Creates a new vector from the multiplication of this and the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @_other the other vector to multiply with
    @return the result of the multiplication*/
    Vector4 operator *(const Vector4& _other) const;

    /*!Multiplies this vector by the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @_other the other vector to multiply by*/
    void operator *=(const Vector4& _other);

    /*!Creates a new vector from the division of this and the scalar
    @_scalar the scale to add with
    @return the result of the division*/
    Vector4 operator /(float _scalar) const;

    /*!Divides the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator /=(float _scalar);

    /*!Creates a new vector from the division of this and the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @_other the other vector to divide with
    @return the result of the division*/
    Vector4 operator /(const Vector4& _other) const;

    /*!Divides this vector by the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @_other the other vector to divide by*/
    void operator /=(const Vector4& _other);

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the 4D zero vector*/
    static Vector4 zero();

    /*!@return the x 4d vector*/
    static Vector4 xVector();

    /*!@return the y 4d vector*/
    static Vector4 yVector();

    /*!@return the z 4d vector*/
    static Vector4 zVector();

    /*!@return the w 4d vector*/
    static Vector4 wVector();

    /*!@return the white rgba vector*/
    static Vector4 white();

    /*!@return the black rgba vector*/
    static Vector4 black();

    /*!@return the grey rgba vector*/
    static Vector4 grey();

    /*!@return the red rgba vector*/
    static Vector4 red();

    /*!@return the green rgba vector*/
    static Vector4 green();

    /*!@return the blue rgba vector*/
    static Vector4 blue();

    /*!@return the yellow rgba vector*/
    static Vector4 yellow();

    /*!@return the orange rgba vector*/
    static Vector4 orange();

    /*!@return the brown rgba vector*/
    static Vector4 brown();

    /*!@return the cyan rgba vector*/
    static Vector4 cyan();

    /*!@return the pink rgba vector*/
    static Vector4 pink();

    /*!@return the purple rgba vector*/
    static Vector4 purple();

    /*!Resets the vector to the zero vector*/
    void clear();

    /*!Inverses the vector*/
    void inverse();

    /*!@return the vector inversed*/
    Vector4* getInverse() const;

    /*!normalises the vector*/
    void normalise();

    /*!@return the magnitude of the vector*/
    float magnitude() const;

    /*!Computes the dot product of this vector and the other vector
    @_other the other vector
    @return the dot product*/
    float dotProduct(const Vector4& _other) const;

    /*!Calculates the distance between this vector and the other vector
    @_other the vector
    @return the distance*/
    float distance(const Vector4& _other) const;

    /*!@return the vector as an array*/
    float* toArray() const;

    /*!@return the x value*/
    float getX() const;

    /*!@return the y value*/
    float getY() const;

    /*!@return the z value*/
    float getZ() const;

    /*!@return the w value*/
    float getW() const;

    /*!@return the x value*/
    float getR() const;

    /*!@return the x value*/
    float getG() const;

    /*!@return the x value*/
    float getB() const;

    /*!@return the x value*/
    float getA() const;

    /*!Sets the new values
    @_x the new x value
    @_y the new y value
    @_z the new z value
    @_w the new w value*/
    void set(float _x, float _y, float _z, float _w);

    /*!@_x the new x value*/
    void setX(float _x);

    /*!@_y the new y value*/
    void setY(float _y);

    /*!@_z the new z value*/
    void setZ(float _z);

    /*!@_w the new w value*/
    void setW(float _w);

    /*!@_r the new x value*/
    void setR(float _r);

    /*!@_g the new y value*/
    void setG(float _g);

    /*!@_b the new z value*/
    void setB(float _b);

    /*!@_a the new w value*/
    void setA(float _a);

    /*!Outputs the vector in string format
    @return the string of the vector*/
    std::string toString() const;

private:

    //VARIABLES
    //the four values of the vector
    float x;
    float y;
    float z;
    float w;
};

//INLINE
//OPERATORS
inline std::ostream& operator <<(std::ostream& _output,
    const Vector4& _v) {

    //print the vector to the output
    _output << _v.toString();

    return _output;
}

inline Vector4& Vector4::operator =(const Vector4& _other) {

    x = _other.x;
    y = _other.y;
    z = _other.z;
    w = _other.w;

    return *this;
}

inline bool Vector4::operator ==(const Vector4& _other) const {

    return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}

inline bool Vector4::operator !=(const Vector4& _other) const {

    return !((*this) == _other);
}

inline float& Vector4::operator [](unsigned _index) {

    //check that the index is within bounds
    if (_index > 3) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 3.");
    }

    switch (_index) {

        case 0: {

            return x;
        }
        case 1: {

            return y;
        }
        case 2: {

            return z;
        }
        default: {

            return w;
        }
    }
}

inline const float& Vector4::operator [](unsigned _index) const {

    //check that the index is within bounds
    if (_index > 3) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 3.");
    }

    switch (_index) {

        case 0: {

            return x;
        }
        case 1: {

            return y;
        }
        case 2: {

            return z;
        }
        default: {

            return w;
        }
    }
}

inline Vector4 Vector4::operator -() const {

    return Vector4(-x, -y, -z, -w);
}

inline Vector4 Vector4::operator +(float _scalar) const {

    return Vector4(x + _scalar, y + _scalar, z + _scalar, w + _scalar);
}

inline void Vector4::operator +=(float _scalar) {

    x += _scalar;
    y += _scalar;
    z += _scalar;
    w += _scalar;
}

inline Vector4 Vector4::operator +(const Vector4& _other) const {

    return Vector4(x + _other.x, y + _other.y, z + _other.z, w + _other.w);
}

inline void Vector4::operator +=(const Vector4& _other) {

    x += _other.x;
    y += _other.y;
    z += _other.z;
    w += _other.w;
}

inline Vector4 Vector4::operator -(float _scalar) const {

    return Vector4(x - _scalar, y - _scalar, z - _scalar, w - _scalar);
}

inline void Vector4::operator -=(float _scalar) {

    x -= _scalar;
    y -= _scalar;
    z -= _scalar;
    w -= _scalar;
}

inline Vector4 Vector4::operator -(const Vector4& _other) const {

    return Vector4(x - _other.x, y - _other.y, z - _other.z, w - _other.w);
}

inline void Vector4::operator -=(const Vector4& _other) {

    x -= _other.x;
    y -= _other.y;
    z -= _other.z;
    w -= _other.w;
}

inline Vector4 Vector4::operator *(float _scalar) const {

    return Vector4(x * _scalar, y * _scalar, z * _scalar, w * _scalar);
}

inline void Vector4::operator *=(float _scalar) {

    x *= _scalar;
    y *= _scalar;
    z *= _scalar;
    w *= _scalar;
}

inline Vector4 Vector4::operator *(const Vector4& _other) const {

    return Vector4(x * _other.x, y * _other.y, z * _other.z, w * _other.w);
}

inline void Vector4::operator *=(const Vector4& _other) {

    x *= _other.x;
    y *= _other.y;
    z *= _other.z;
    w *= _other.w;
}

inline Vector4 Vector4::operator /(float _scalar) const {

    return Vector4(x / _scalar, y / _scalar, z / _scalar, w / _scalar);
}

inline void Vector4::operator /=(float _scalar) {

    x /= _scalar;
    y /= _scalar;
    z /= _scalar;
    w /= _scalar;
}

inline Vector4 Vector4::operator /(const Vector4& _other) const {

    return Vector4(x / _other.x, y / _other.y, z / _other.z, w / _other.w);
}

inline void Vector4::operator /=(const Vector4& _other) {

    x /= _other.x;
    y /= _other.y;
    z /= _other.z;
    w /= _other.w;
}

//PUBLIC MEMBER FUNCTIONS
inline Vector4 Vector4::zero() {

    return Vector4();
}

inline Vector4 Vector4::xVector() {

    return Vector4(1.0f, 0.0f, 0.0f, 0.0f);
}

inline Vector4 Vector4::yVector() {

    return Vector4(0.0f, 1.0f, 0.0f, 0.0f);
}

inline Vector4 Vector4::zVector() {

    return Vector4(0.0f, 0.0f, 1.0f, 0.0f);
}

inline Vector4 Vector4::wVector() {

    return Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}

inline Vector4 Vector4::white() {

    return Vector4(1.0f, 1.0f, 1.0f, 1.0f);
}

inline Vector4 Vector4::black() {

    return Vector4(0.0f, 0.0f, 0.0f, 1.0f);
}

inline Vector4 Vector4::grey() {

    return Vector4(0.5f, 0.5f, 0.5f, 1.0f);
}

inline Vector4 Vector4::red() {

    return Vector4(1.0f, 0.0f, 0.0f, 1.0f);
}

inline Vector4 Vector4::green() {

    return Vector4(0.0f, 1.0f, 0.0f, 1.0f);
}

inline Vector4 Vector4::blue() {

    return Vector4(0.0f, 0.0f, 1.0f, 1.0f);
}

inline Vector4 Vector4::yellow() {

    return Vector4(1.0f, 1.0f, 0.0f, 1.0f);
}

inline Vector4 Vector4::orange() {

    return Vector4(1.0f, 0.5f, 0.0f, 1.0f);
}

inline Vector4 Vector4::brown() {

    return Vector4(0.32f, 0.18f, 0.0f, 1.0f);
}

inline Vector4 Vector4::cyan() {

    return Vector4(0.0f, 1.0f, 1.0f, 1.0f);
}

inline Vector4 Vector4::pink() {

    return Vector4(1.0f, 0.0f, 1.0f, 1.0f);
}

inline Vector4 Vector4::purple() {

    return Vector4(0.5f, 0.0f, 1.0f, 1.0f);
}

inline void Vector4::clear() {

    x = 0;
    y = 0;
    z = 0;
    w = 0;
}

inline void Vector4::inverse() {

    x = -x;
    y = -y;
    z = -z;
    w = -w;
}

inline Vector4* Vector4::getInverse() const {

    return new Vector4(-x, -y, -z, -w);
}

inline void Vector4::normalise() {

    //get the magnitude
    float mag = magnitude();

    //normalise the components
    x /= mag;
    y /= mag;
    z /= mag;
    w /= mag;
}

inline float Vector4::magnitude() const {

    return distance(Vector4::zero());
}

inline float Vector4::dotProduct(const Vector4& _other)  const {

    return (x * _other.x) + (y * _other.y) + (z * _other.z) + (w * _other.w);
}

inline float Vector4::distance(const Vector4& _other) const {

    return sqrt(pow(x - _other.x, 2.0f) + pow(y - _other.y, 2.0f) +
        pow(z - _other.z, 2.0f) + pow(w - _other.w, 2.0f));
}

inline float* Vector4::toArray() const {

    float* array = new float[4];
    array[0] = x;
    array[1] = y;
    array[2] = z;
    array[3] = w;

    return array;
}

inline float Vector4::getX() const {

    return x;
}

inline float Vector4::getY() const {

    return y;
}

inline float Vector4::getZ() const {

    return z;
}

inline float Vector4::getW() const {

    return w;
}

inline float Vector4::getR() const {

    return x;
}

inline float Vector4::getG() const {

    return y;
}

inline float Vector4::getB() const {

    return z;
}

inline float Vector4::getA() const {

    return w;
}

inline void Vector4::set(float _x, float _y, float _z, float _w) {

    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

inline void Vector4::setX(float _x) {

    x = _x;
}

inline void Vector4::setY(float _y) {

    y = _y;
}

inline void Vector4::setZ(float _z) {

    z = _z;
}

inline void Vector4::setW(float _w) {

    w = _w;
}

inline void Vector4::setR(float _r) {

    x = _r;
}

inline void Vector4::setG(float _g) {

    y = _g;
}

inline void Vector4::setB(float _b) {

    z = _b;
}

inline void Vector4::setA(float _a) {

    w = _a;
}

inline std::string Vector4::toString() const {

    //create the string of the vector
    std::stringstream ss;
    ss << "[" << x << ", " << y << ", " << z << ", " << w << "]";

    return ss.str();
}

} } //util //vec

#endif