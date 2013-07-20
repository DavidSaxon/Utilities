/***********************\
| 3 dimensional vector. |
|                       |
| @author David Saxon   |
\***********************/

#ifndef UTILTIES_VECTOR_VECTOR3_H_
#   define UTILTIES_VECTOR_VECTOR3_H_

#include <iostream>
#include <sstream>

namespace util { namespace vec {

class Vector3 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @output the output stream to print to
    @return the changed output stream*/
    friend std::ostream& operator<<(std::ostream& output,
        const Vector3& v);

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
    @other the other vector to copy from*/
    Vector3(const Vector3& other) :
        x(other.x),
        y(other.y),
        z(other.z) {
    }

    //DESTRUCTOR
    /*!Destorys this vector*/
    ~Vector3() {
    }

    //OPERATORS
    /*!Copies the other vector's values to this vector
    @other the other vector to copy from*/
    Vector3& operator=(const Vector3& other);

    /*!Checks if this vector and the other vector are equal
    @other the other vector to compare with
    @return whether the vectors are equal*/
    bool operator==(const Vector3& other);

    /*!Checks if this vector and the other vector are not equal
    @other the other vector to compare with
    @return whether the vectors are not equal*/
    bool operator!=(const Vector3& other);

    /*!Creates a new vector from the addition of this and the other vector
    @other the other vector to add with
    @return the result of the addition*/
    Vector3* operator+(const Vector3& other);

    /*!Creates a new vector from the subtraction of this and the other vector
    @other the other vector to subtract with
    @return the result of the subtraction*/
    Vector3* operator-(const Vector3& other);

    /*!Creates a new vector from the multiplication of this and the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @other the other vector to multiply with
    @return the result of the multiplication*/
    Vector3* operator*(const Vector3& other);

    /*!Creates a new vector from the division of this and the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @other the other vector to divide with
    @return the result of the division*/
    Vector3* operator/(const Vector3& other);

    /*!Adds the value of the other vector to this vector
    @other the other vector to add to this*/
    void operator+=(const Vector3& other);

    /*!Subtracts the value of the other vector from this vector
    @other the other vector to subtract from this*/
    void operator-=(const Vector3& other);

    /*!Multiplies this vector by the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @other the other vector to multiply by*/
    void operator*=(const Vector3& other);

    /*!Divides this vector by the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @other the other vector to divide by*/
    void operator/=(const Vector3& other);

    //PUBLIC MEMBER FUNCTIONS
    /*!Resets the vector to the zero vector*/
    void clear();

    /*!Computes the dot product of this vector and the other vector
    @other the other vector
    @return the dot product*/
    float dotProduct(const util::vec::Vector3& other);

    /*!Computes the cross product of this vector and the other vector
    @other the other vector
    @return the vector that is the result of the cross product*/
    util::vec::Vector3* crossProduct(const util::vec::Vector3& other);

    /*!@v the value to add to the x value of this vector*/
    void addX(float v);

    /*!@v the value to add to the the y value of this vector*/
    void addY(float v);

    /*!@v the value to add to the the z value of this vector*/
    void addZ(float v);

    /*!@v the value to subtract from the x value of this vector*/
    void subX(float v);

    /*!@v the value to subtract from the y value of this vector*/
    void subY(float v);

    /*!@v the value to subtract from the z value of this vector*/
    void subZ(float v);

    /*!@v the value to multiply the x value of this vector by*/
    void mulX(float v);

    /*!@v the value to multiply the y value of this vector by*/
    void mulY(float v);

    /*!@v the value to multiply the z value of this vector by*/
    void mulZ(float v);

    /*!@v the value to divide the x value of this vector by*/
    void divX(float v);

    /*!@v the value to divide the y value of this vector by*/
    void divY(float v);

    /*!@v the value to divide the z value of this vector by*/
    void divZ(float v);

    /*!@return the x value*/
    float getX() const;

    /*!@return the y value*/
    float getY() const;

    /*!@return the z value*/
    float getZ() const;

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
inline std::ostream& operator<<(std::ostream& output,
    const Vector3& v) {

    //print the vector to the output
    output << v.toString();

    return output;
}

inline Vector3& Vector3::operator=(const Vector3& other) {

    x = other.x;
    y = other.y;
    z = other.z;
}

inline bool Vector3::operator==(const Vector3& other) {

    return x == other.x && y == other.y && z == other.z;
}

inline bool Vector3::operator !=(const Vector3& other) {

    return !((*this) == other);
}

inline Vector3* Vector3::operator+(const Vector3& other) {

    return new Vector3(x + other.x, y + other.y, z + other.z);
}

inline Vector3* Vector3::operator-(const Vector3& other) {

    return new Vector3(x - other.x, y - other.y, z - other.z);
}

inline Vector3* Vector3::operator*(const Vector3& other) {

    return new Vector3(x * other.x, y * other.y, z * other.z);
}

inline Vector3* Vector3::operator/(const Vector3& other) {

    return new Vector3(x / other.x, y / other.y, z / other.z);
}

inline void Vector3::operator+=(const Vector3& other) {

    x += other.x;
    y += other.y;
    z += other.z;
}

inline void Vector3::operator-=(const Vector3& other) {

    x -= other.x;
    y -= other.y;
    z -= other.z;
}

inline void Vector3::operator*=(const Vector3& other) {

    x *= other.x;
    y *= other.y;
    z *= other.z;
}

inline void Vector3::operator/=(const Vector3& other) {

    x /= other.x;
    y /= other.y;
    z /= other.z;
}

//PUBLIC MEMBER FUNCTIONS
inline void Vector3::clear() {

    x = 0;
    y = 0;
    z = 0;
}

inline float Vector3::dotProduct(const util::vec::Vector3& other) {

    return (x * other.x) + (y * other.y) + (z * other.z);
}

inline util::vec::Vector3* Vector3::crossProduct(
    const util::vec::Vector3& other) {

    //the cross product values
    float cx = 0.0f;
    float cy = 0.0f;
    float cz = 0.0f;

    cx = (y * other.z) - (z * other.y);
    cy = (x * other.z) - (z * other.x);
    cz = (x * other.y) - (y * other.x);

    return new Vector3(cx, cy, cz);
}

inline void Vector3::addX(float v) {

    x += v;
}

inline void Vector3::addY(float v) {

    y += v;
}

inline void Vector3::addZ(float v) {

    z += v;
}

inline void Vector3::subX(float v) {

    x -= v;
}

inline void Vector3::subY(float v) {

    y -= v;
}

inline void Vector3::subZ(float v) {

    z -= v;
}

inline void Vector3::mulX(float v) {

    x *= v;
}

inline void Vector3::mulY(float v) {

    y *= v;
}

inline void Vector3::mulZ(float v) {

    z *= v;
}

inline void Vector3::divX(float v) {

    x /= v;
}

inline void Vector3::divY(float v) {

    y /= v;
}

inline void Vector3::divZ(float v) {

    z /= v;
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

inline std::string Vector3::toString() const {

    //create the string of the vector
    std::stringstream ss;
    ss << "[" << x << ", " << y << ", " << z << "]";

    return ss.str();
}

} } //util //vec

#endif