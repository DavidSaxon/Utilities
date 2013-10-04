/***********************\
| 3 dimensional vector. |
|                       |
| @author David Saxon   |
\***********************/

#ifndef UTILTIES_VECTOR_VECTOR3_H_
#   define UTILTIES_VECTOR_VECTOR3_H_

#include <iostream>
#include <cmath>
#include <sstream>

#include "../exceptions/ArrayException.hpp"

namespace util { namespace vec {

namespace v3 {

//ENUMERATORS
//!Access enumerators for the dimension values
enum {

    X = 0,
    Y,
    Z
};

//!Access enumerators for the colour values
enum {

    R = 0,
    G,
    B
};

//!Access enumerators for the measurement values
enum {

    WIDTH = 0,
    HEIGHT,
    DEPTH
};

} //v3

class Vector3 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @_output the output stream to print to
    @_v the vector to print
    @return the changed output stream*/
    friend std::ostream& operator <<(std::ostream& _output,
        const Vector3& _v);

public:

    //CONSTRUCTORS
    /*!Creates a new zero 3D vector*/
    Vector3() :
        x(0),
        y(0),
        z(0) {
    }

    /*!Creates a new 3D vector
    @_x the vector's first value
    @_y the vector's second value
    @_z the vector's third value*/
    Vector3(float _x, float _y, float _z) :
        x(_x),
        y(_y),
        z(_z) {
    }

    /*!Creates a vector by copying the other vector
    @_other the other vector to copy from*/
    Vector3(const Vector3& _other) :
        x(_other.x),
        y(_other.y),
        z(_other.z) {
    }

    //DESTRUCTOR
    /*!Destorys this vector*/
    ~Vector3() {
    }

    //OPERATORS
    /*!Copies the other vector's values to this vector
    @_other the other vector to copy from*/
    Vector3& operator =(const Vector3& _other);

    /*!Checks if this vector and the other vector are equal
    @_other the other vector to compare with
    @return whether the vectors are equal*/
    bool operator ==(const Vector3& _other) const;

    /*!Checks if this vector and the other vector are not equal
    @_other the other vector to compare with
    @return whether the vectors are not equal*/
    bool operator !=(const Vector3& _other) const;

    /*!Gets the value at the specified index
    @_index the index
    @return the value*/
    float& operator [](unsigned _index);

    /*!Gets the value at the specified index
    @_index the index
    @return the value*/
    const float& operator [](unsigned _index) const;

    /*!@return the vector with all elements negated*/
    Vector3 operator -() const;

    /*!Creates a new vector from the addition of this and the scalar
    @_scalar the scale to add with
    @return the result of the addition*/
    Vector3 operator +(float _scalar) const;

    /*!Adds the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator +=(float _scalar);

    /*!Creates a new vector from the addition of this and the other vector
    @_other the other vector to add with
    @return the result of the addition*/
    Vector3 operator +(const Vector3& _other) const;

    /*!Adds the value of the other vector to this vector
    @other the other vector to add to this*/
    void operator +=(const Vector3& other);

    /*!Creates a new vector from the subtraction of this and the scalar
    @_scalar the scale to add with
    @return the result of the subtraction*/
    Vector3 operator -(float _scalar) const;

    /*!Subtracts the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator -=(float _scalar);

    /*!Creates a new vector from the subtraction of this and the other vector
    @_other the other vector to subtract with
    @return the result of the subtraction*/
    Vector3 operator -(const Vector3& _other) const;

    /*!Subtracts the value of the other vector from this vector
    @_other the other vector to subtract from this*/
    void operator -=(const Vector3& _other);

    /*!Creates a new vector from the multiplication of this and the scalar
    @_scalar the scale to add with
    @return the result of the multiplication*/
    Vector3 operator *(float _scalar) const;

    /*!Multiplies the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator *=(float _scalar);

    /*!Creates a new vector from the multiplication of this and the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @_other the other vector to multiply with
    @return the result of the multiplication*/
    Vector3 operator *(const Vector3& _other) const;


    /*!Multiplies this vector by the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @_other the other vector to multiply by*/
    void operator *=(const Vector3& _other);

    /*!Creates a new vector from the division of this and the scalar
    @_scalar the scale to add with
    @return the result of the division*/
    Vector3 operator /(float _scalar) const;

    /*!Divides the value of the scalar to this vector
    @_scalar the scalar to add*/
    void operator /=(float _scalar);

    /*!Creates a new vector from the division of this and the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @_other the other vector to divide with
    @return the result of the division*/
    Vector3 operator /(const Vector3& _other) const;

    /*!Divides this vector by the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @_other the other vector to divide by*/
    void operator /=(const Vector3& _other);

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the 3D zero vector*/
    static Vector3 zero();

    /*!@return the x 3d vector*/
    static Vector3 xVector();

    /*!@return the y 3d vector*/
    static Vector3 yVector();

    /*!@return the z 3d vector*/
    static Vector3 zVector();

    /*!@return the white rgb vector*/
    static Vector3 white();

    /*!@return the black rgb vector*/
    static Vector3 black();

    /*!@return the grey rgb vector*/
    static Vector3 grey();

    /*!@return the red rgb vector*/
    static Vector3 red();

    /*!@return the green rgb vector*/
    static Vector3 green();

    /*!@return the blue rgb vector*/
    static Vector3 blue();

    /*!@return the yellow rgb vector*/
    static Vector3 yellow();

    /*!@return the orange rgb vector*/
    static Vector3 orange();

    /*!@return the brown rgb vector*/
    static Vector3 brown();

    /*!@return the cyan rgb vector*/
    static Vector3 cyan();

    /*!@return the pink rgb vector*/
    static Vector3 pink();

    /*!@return the purple rgb vector*/
    static Vector3 purple();

    /*!Resets the vector to the zero vector*/
    void clear();

    /*!Inverses the vector*/
    void inverse();

    /*!@return the vector inversed*/
    Vector3* getInverse() const;

    /*!normalises the vector*/
    void normalise();
    
    /*!@return the magnitude of the vector*/
    float magnitude() const;

    /*!Computes the dot product of this vector and the other vector
    @_other the other vector
    @return the dot product*/
    float dotProduct(const Vector3& _other) const;

    /*!Computes the cross product of this vector and the other vector
    @_other the other vector
    @return the vector that is the result of the cross product*/
    Vector3 crossProduct(const Vector3& _other) const;

    /*!Calculates the distance between this vector and the other vector
    @_other the vector
    @return the distance*/
    float distance(const Vector3& _other) const;

    /*Calculates the angle between this vector and the other vector
    @_other the other vector
    @return the angle between the two vectors*/
    float angleBetween(const Vector3& _other) const;

    /*!@return the vector as an array*/
    float* toArray() const;

    /*!@return the x value*/
    float getX() const;

    /*!@return the y value*/
    float getY() const;

    /*!@return the z value*/
    float getZ() const;

    /*!@return the x value*/
    float getR() const;

    /*!@return the y value*/
    float getG() const;

    /*!@return the z value*/
    float getB() const;

    /*!@return the x value*/
    float getWidth() const;

    /*!@return the y value*/
    float getHeight() const;

    /*!@return the z value*/
    float getDepth() const;

    /*!Sets the new values
    @_x the new x value
    @_y the new y value
    @_z the new z value*/
    void set(float _x, float _y, float _z);

    /*!@_x the new x value*/
    void setX(float _x);

    /*!@_y the new y value*/
    void setY(float _y);

    /*!@_z the new z value*/
    void setZ(float _z);

    /*!@_r the new x value*/
    void setR(float _r);

    /*!@_g the new y value*/
    void setG(float _g);

    /*!@_b the new z value*/
    void setB(float _b);

    /*!@_width the new x value*/
    void setWidth(float _width);

    /*!@_height the new y value*/
    void setHeight(float _height);

    /*!@_depth the new z value*/
    void setDepth(float _depth);

    /*!Outputs the vector in string format
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
inline std::ostream& operator <<(std::ostream& _output,
    const Vector3& _v) {

    //print the vector to the output
    _output << _v.toString();

    return _output;
}

inline Vector3& Vector3::operator =(const Vector3& _other) {

    x = _other.x;
    y = _other.y;
    z = _other.z;

    return *this;
}

inline bool Vector3::operator ==(const Vector3& _other) const {

    return x == _other.x && y == _other.y && z == _other.z;
}

inline bool Vector3::operator  !=(const Vector3& _other) const {

    return !((*this) == _other);
}

inline float& Vector3::operator [](unsigned _index) {

    //check that the index is within bounds
    if (_index > 2) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 2.");
    }

    switch (_index) {

        case 0: {

            return x;
        }
        case 1: {

            return y;
        }
        default: {

            return z;
        }
    }
}

inline const float& Vector3::operator [](unsigned _index) const {

    //check that the index is within bounds
    if (_index > 2) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 2.");
    }

    switch (_index) {

        case 0: {

            return x;
        }
        case 1: {

            return y;
        }
        default: {

            return z;
        }
    }
}

inline Vector3 Vector3::operator -() const {

    return Vector3(-x, -y, -z);
}

inline Vector3 Vector3::operator +(float _scalar) const {

    return Vector3(x + _scalar, y + _scalar, z + _scalar);
}

inline void Vector3::operator +=(float _scalar) {

    x += _scalar;
    y += _scalar;
    z += _scalar;
}

inline Vector3 Vector3::operator +(const Vector3& _other) const {

    return Vector3(x + _other.x, y + _other.y, z + _other.z);
}

inline void Vector3::operator +=(const Vector3& _other) {

    x += _other.x;
    y += _other.y;
    z += _other.z;
}

inline Vector3 Vector3::operator -(float _scalar) const {

    return Vector3(x - _scalar, y - _scalar, z - _scalar);
}

inline void Vector3::operator -=(float _scalar) {

    x -= _scalar;
    y -= _scalar;
    z -= _scalar;
}

inline Vector3 Vector3::operator -(const Vector3& _other) const {

    return Vector3(x - _other.x, y - _other.y, z - _other.z);
}

inline void Vector3::operator -=(const Vector3& _other) {

    x -= _other.x;
    y -= _other.y;
    z -= _other.z;
}

inline Vector3 Vector3::operator *(float _scalar) const {

    return Vector3(x * _scalar, y * _scalar, z * _scalar);
}

inline void Vector3::operator *=(float _scalar) {

    x *= _scalar;
    y *= _scalar;
    z *= _scalar;
}

inline Vector3 Vector3::operator *(const Vector3& _other) const {

    return Vector3(x * _other.x, y * _other.y, z * _other.z);
}

inline void Vector3::operator *=(const Vector3& _other) {

    x *= _other.x;
    y *= _other.y;
    z *= _other.z;
}

inline Vector3 Vector3::operator /(float _scalar) const {

    return Vector3(x / _scalar, y / _scalar, z / _scalar);
}

inline void Vector3::operator /=(float _scalar) {

    x /= _scalar;
    y /= _scalar;
    z /= _scalar;
}

inline Vector3 Vector3::operator /(const Vector3& _other) const {

    return Vector3(x / _other.x, y / _other.y, z / _other.z);
}

inline void Vector3::operator /=(const Vector3& _other) {

    x /= _other.x;
    y /= _other.y;
    z /= _other.z;
}

//PUBLIC MEMBER FUNCTIONS
inline Vector3 Vector3::zero() {

    return Vector3();
}

inline Vector3 Vector3::xVector() {

    return Vector3(1.0f, 0.0f, 0.0f);
}

inline Vector3 Vector3::yVector() {

    return Vector3(0.0f, 1.0f, 0.0f);
}

inline Vector3 Vector3::zVector() {

    return Vector3(0.0f, 0.0f, 1.0f);
}

inline Vector3 Vector3::white() {

    return Vector3(1.0f, 1.0f, 1.0f);
}

inline Vector3 Vector3::black() {

    return Vector3(0.0f, 0.0f, 0.0f);
}

inline Vector3 Vector3::grey() {

    return Vector3(0.5f, 0.5f, 0.5f);
}

inline Vector3 Vector3::red() {

    return Vector3(1.0f, 0.0f, 0.0f);
}

inline Vector3 Vector3::green() {

    return Vector3(0.0f, 1.0f, 0.0f);
}

inline Vector3 Vector3::blue() {

    return Vector3(0.0f, 0.0f, 1.0f);
}

inline Vector3 Vector3::yellow() {

    return Vector3(1.0f, 1.0f, 0.0f);
}

inline Vector3 Vector3::orange() {

    return Vector3(1.0f, 0.5f, 0.0f);
}

inline Vector3 Vector3::brown() {

    return Vector3(0.32f, 0.18f, 0.0f);
}

inline Vector3 Vector3::cyan() {

    return Vector3(0.0f, 1.0f, 1.0f);
}

inline Vector3 Vector3::pink() {

    return Vector3(1.0f, 0.0f, 1.0f);
}

inline Vector3 Vector3::purple() {

    return Vector3(0.5f, 0.0f, 1.0f);
}

inline void Vector3::clear() {

    x = 0;
    y = 0;
    z = 0;
}

inline void Vector3::inverse() {

    x = -x;
    y = -y;
    z = -z;
}

inline Vector3* Vector3::getInverse() const {

    return new Vector3(-x, -y, -z);
}

inline void Vector3::normalise() {

    //get the magnitude
    float mag = magnitude();

    //normalise the components
    x /= mag;
    y /= mag;
    z /= mag;
}

inline float Vector3::magnitude() const {

    return distance(Vector3::zero());
}

inline float Vector3::dotProduct(const Vector3& _other) const {

    return (x * _other.x) + (y * _other.y) + (z * _other.z);
}

inline Vector3 Vector3::crossProduct(const Vector3& _other) const {

    //the cross product values
    float cx = 0.0f;
    float cy = 0.0f;
    float cz = 0.0f;

    cx = (y * _other.z) - (z * _other.y);
    cy = (x * _other.z) - (z * _other.x);
    cz = (x * _other.y) - (y * _other.x);

    return Vector3(cx, cy, cz);
}

inline float Vector3::distance(const Vector3& _other) const {

    return sqrt(pow(x - _other.x, 2.0f) + pow(y - _other.y, 2.0f) +
        pow(z - _other.z, 2.0f));
}

inline float Vector3::angleBetween(const Vector3& _other) const {

    return acos(dotProduct(_other) / (magnitude() * _other.magnitude()));
}

inline float* Vector3::toArray() const {

    float* array = new float[3];
    array[0] = x;
    array[1] = y;
    array[2] = z;

    return array;
}

inline float Vector3::getX() const {

    return x;
}

inline float Vector3::getY() const {

    return y;
}

inline float Vector3::getZ() const {

    return z;
}

inline float Vector3::getR() const {

    return x;
}

inline float Vector3::getG() const {

    return y;
}

inline float Vector3::getB() const {

    return z;
}

inline float Vector3::getWidth() const {

    return x;
}

inline float Vector3::getHeight() const {

    return y;
}

inline float Vector3::getDepth() const {

    return z;
}

inline void Vector3::set(float _x, float _y, float _z) {

    x = _x;
    y = _y;
    z = _z;
}

inline void Vector3::setX(float _x) {

    x = _x;
}

inline void Vector3::setY(float _y) {

    y = _y;
}

inline void Vector3::setZ(float _z) {

    z = _z;
}

inline void Vector3::setR(float _r) {

    x = _r;
}

inline void Vector3::setG(float _g) {

    y = _g;
}

inline void Vector3::setB(float _b) {

    z = _b;
}

inline void Vector3::setWidth(float _width) {

    x = _width;
}

inline void Vector3::setHeight(float _height) {

    y = _height;
}

inline void Vector3::setDepth(float _depth) {

    z = _depth;
}

inline std::string Vector3::toString() const {

    //create the string of the vector
    std::stringstream ss;
    ss << "[" << x << ", " << y << ", " << z << "]";

    return ss.str();
}

} } //util //vec

#endif