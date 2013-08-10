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

namespace util { namespace vec {

class Vector4 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @output the output stream to print to
    @return the changed output stream*/
    friend std::ostream& operator<<(std::ostream& output,
        const Vector4& v);

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
    @other the other vector to copy from*/
    Vector4(const Vector4& other) :
        x(other.x),
        y(other.y),
        z(other.z),
        w(other.w) {
    }

    //DESTRUCTOR
    /*!Destorys this vector*/
    ~Vector4() {
    }

    //OPERATORS
    /*!Copies the other vector's values to this vector
    @other the other vector to copy from*/
    Vector4& operator=(const Vector4& other);

    /*!Checks if this vector and the other vector are equal
    @other the other vector to compare with
    @return whether the vectors are equal*/
    bool operator==(const Vector4& other) const;

    /*!Checks if this vector and the other vector are not equal
    @other the other vector to compare with
    @return whether the vectors are not equal*/
    bool operator!=(const Vector4& other) const;

    /*!Creates a new vector from the addition of this and the other vector
    @other the other vector to add with
    @return the result of the addition*/
    Vector4* operator+(const Vector4& other) const;

    /*!Creates a new vector from the subtraction of this and the other vector
    @other the other vector to subtract with
    @return the result of the subtraction*/
    Vector4* operator-(const Vector4& other) const;

    /*!Creates a new vector from the multiplication of this and the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @other the other vector to multiply with
    @return the result of the multiplication*/
    Vector4* operator*(const Vector4& other) const;

    /*!Creates a new vector from the division of this and the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @other the other vector to divide with
    @return the result of the division*/
    Vector4* operator/(const Vector4& other) const;

    /*!Adds the value of the other vector to this vector
    @other the other vector to add to this*/
    void operator+=(const Vector4& other);

    /*!Subtracts the value of the other vector from this vector
    @other the other vector to subtract from this*/
    void operator-=(const Vector4& other);

    /*!Multiplies this vector by the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @other the other vector to multiply by*/
    void operator*=(const Vector4& other);

    /*!Divides this vector by the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @other the other vector to divide by*/
    void operator/=(const Vector4& other);

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the 4D zero vector*/
    static Vector4 zero();

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
    @other the other vector
    @return the dot product*/
    float dotProduct(const util::vec::Vector4& other) const;

    /*!Calculates the distance between this vector and the other vector
    @other the vector
    @return the distance*/
    float distance(const util::vec::Vector4& other) const;

    /*!@v the value to add to the x value of this vector*/
    void addX(float v);

    /*!@v the value to add to the the y value of this vector*/
    void addY(float v);

    /*!@v the value to add to the the z value of this vector*/
    void addZ(float v);

    /*!@v the value to add to the the w value of this vector*/
    void addW(float v);

    /*!@v the value to subtract from the x value of this vector*/
    void subX(float v);

    /*!@v the value to subtract from the y value of this vector*/
    void subY(float v);

    /*!@v the value to subtract from the z value of this vector*/
    void subZ(float v);

    /*!@v the value to subtract from the w value of this vector*/
    void subW(float v);

    /*!@v the value to multiply the x value of this vector by*/
    void mulX(float v);

    /*!@v the value to multiply the y value of this vector by*/
    void mulY(float v);

    /*!@v the value to multiply the z value of this vector by*/
    void mulZ(float v);

    /*!@v the value to multiply the w value of this vector by*/
    void mulW(float v);

    /*!@v the value to divide the x value of this vector by*/
    void divX(float v);

    /*!@v the value to divide the y value of this vector by*/
    void divY(float v);

    /*!@v the value to divide the z value of this vector by*/
    void divZ(float v);

    /*!@v the value to divide the w value of this vector by*/
    void divW(float v);

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
inline std::ostream& operator<<(std::ostream& output,
    const Vector4& v) {

    //print the vector to the output
    output << v.toString();

    return output;
}

inline Vector4& Vector4::operator=(const Vector4& other) {

    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;

    return *this;
}

inline bool Vector4::operator==(const Vector4& other) const {

    return x == other.x && y == other.y && z == other.z && w == other.w;
}

inline bool Vector4::operator !=(const Vector4& other) const {

    return !((*this) == other);
}

inline Vector4* Vector4::operator+(const Vector4& other) const {

    return new Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

inline Vector4* Vector4::operator-(const Vector4& other) const {

    return new Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

inline Vector4* Vector4::operator*(const Vector4& other) const {

    return new Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
}

inline Vector4* Vector4::operator/(const Vector4& other) const {

    return new Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
}

inline void Vector4::operator+=(const Vector4& other) {

    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
}

inline void Vector4::operator-=(const Vector4& other) {

    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
}

inline void Vector4::operator*=(const Vector4& other) {

    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
}

inline void Vector4::operator/=(const Vector4& other) {

    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
}

//PUBLIC MEMBER FUNCTIONS
inline Vector4 Vector4::zero() {

    return Vector4();
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

inline float Vector4::dotProduct(const util::vec::Vector4& other)  const {

    return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
}

inline float Vector4::distance(const util::vec::Vector4& other) const {

    return sqrt(pow(x - other.x, 2.0f) + pow(y - other.y, 2.0f) +
        pow(z - other.z, 2.0f) + pow(w - other.w, 2.0f));
}

inline void Vector4::addX(float v) {

    x += v;
}

inline void Vector4::addY(float v) {

    y += v;
}

inline void Vector4::addZ(float v) {

    z += v;
}

inline void Vector4::addW(float v) {

    w += w;
}

inline void Vector4::subX(float v) {

    x -= v;
}

inline void Vector4::subY(float v) {

    y -= v;
}

inline void Vector4::subZ(float v) {

    z -= v;
}

inline void Vector4::subW(float v) {

    w -= v;
}

inline void Vector4::mulX(float v) {

    x *= v;
}

inline void Vector4::mulY(float v) {

    y *= v;
}

inline void Vector4::mulZ(float v) {

    z *= v;
}

inline void Vector4::mulW(float v) {

    w *= v;
}

inline void Vector4::divX(float v) {

    x /= v;
}

inline void Vector4::divY(float v) {

    y /= v;
}

inline void Vector4::divZ(float v) {

    z /= v;
}

inline void Vector4::divW(float v) {

    w /= v;
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

inline std::string Vector4::toString() const {

    //create the string of the vector
    std::stringstream ss;
    ss << "[" << x << ", " << y << ", " << z << ", " << w << "]";

    return ss.str();
}

} } //util //vec

#endif