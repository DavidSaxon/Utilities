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

namespace util { namespace vec {

class Vector2 {

    //FRIEND FUNCTIONS
    /*!Prints the vector to the output stream
    @output the output stream to print to
    @return the changed output stream*/
    friend std::ostream& operator<<(std::ostream& output,
        const Vector2& v);

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
    Vector2(const Vector2& other) :
        x(other.x),
        y(other.y) {
    }

    //DESTRUCTOR
    /*!Destorys this vector*/
    ~Vector2() {
    }

    //OPERATORS
    /*!Copies the other vector's values to this vector
    @other the other vector to copy from*/
    Vector2& operator=(const Vector2& other);

    /*!Checks if this vector and the other vector are equal
    @other the other vector to compare with
    @return whether the vectors are equal*/
    bool operator==(const Vector2& other) const;

    /*!Checks if this vector and the other vector are not equal
    @other the other vector to compare with
    @return whether the vectors are not equal*/
    bool operator!=(const Vector2& other) const;

    /*!Creates a new vector from the addition of this and the other vector
    @other the other vector to add with
    @return the result of the addition*/
    Vector2* operator+(const Vector2& other) const;

    /*!Creates a new vector from the subtraction of this and the other vector
    @other the other vector to subtract with
    @return the result of the subtraction*/
    Vector2* operator-(const Vector2& other) const;

    /*!Creates a new vector from the multiplication of this and the other vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @other the other vector to multiply with
    @return the result of the multiplication*/
    Vector2* operator*(const Vector2& other) const;

    /*!Creates a new vector from the division of this and the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @other the other vector to divide with
    @return the result of the division*/
    Vector2* operator/(const Vector2& other) const;

    /*!Adds the value of the other vector to this vector
    @other the other vector to add to this*/
    void operator+=(const Vector2& other);

    /*!Subtracts the value of the other vector from this vector
    #NOTE: where multiplication is evaluated as (x1 * x2), (y1 * y2), ....
    @other the other vector to subtract from this*/
    void operator-=(const Vector2& other);

    /*!Multiplies this vector by the other vector
    @other the other vector to multiply by*/
    void operator*=(const Vector2& other);

    /*!Divides this vector by the other vector
    #NOTE: where division is evaluated as (x1 / x2), (y1 / y2), ....
    @other the other vector to divide by*/
    void operator/=(const Vector2& other);

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the 2D zero vector*/
    static Vector2 zero();

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
    @other the other vector
    @return the dot product*/
    float dotProduct(const util::vec::Vector2& other) const;

    /*!Calculates the distance between this vector and the other vector
    @other the vector
    @return the distance*/
    float distance(const util::vec::Vector2& other) const;

    /*!Calculates the distance between this vector and the other vector
    @other the other vector
    @return the angle between*/
    float angleBetween(const util::vec::Vector2& other) const;

    /*!@v the value to add to the x value of this vector*/
    void addX(float v);

    /*!@v the value to add to the the y value of this vector*/
    void addY(float v);

    /*!@v the value to subtract from the x value of this vector*/
    void subX(float v);

    /*!@v the value to subtract from the y value of this vector*/
    void subY(float v);

    /*!@v the value to multiply the x value of this vector by*/
    void mulX(float v);

    /*!@v the value to multiply the y value of this vector by*/
    void mulY(float v);

    /*!@v the value to divide the x value of this vector by*/
    void divX(float v);

    /*!@v the value to divide the y value of this vector by*/
    void divY(float v);

    /*!@return the vector as an array*/
    float* toArray() const;

    /*!@return the x value*/
    float getX() const;

    /*!@return the y value*/
    float getY() const;

    /*!Sets the new values
    @_x the new x value
    @_y the new y value*/
    void set(float _x, float _y);

    /*!@_x the new x value*/
    void setX(float _x);

    /*!@_y the new y value*/
    void setY(float _y);

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
inline std::ostream& operator<<(std::ostream& output,
    const Vector2& v) {

    //print the vector to the output
    output << v.toString();

    return output;
}

inline Vector2& Vector2::operator=(const Vector2& other) {

    x = other.x;
    y = other.y;

    return *this;
}

inline bool Vector2::operator==(const Vector2& other) const {

    return x == other.x && y == other.y;
}

inline bool Vector2::operator !=(const Vector2& other) const {

    return !((*this) == other);
}

inline Vector2* Vector2::operator+(const Vector2& other) const {

    return new Vector2(x + other.x, y + other.y);
}

inline Vector2* Vector2::operator-(const Vector2& other) const {

    return new Vector2(x - other.x, y - other.y);
}

inline Vector2* Vector2::operator*(const Vector2& other) const {

    return new Vector2(x * other.x, y * other.y);
}

inline Vector2* Vector2::operator/(const Vector2& other) const {

    return new Vector2(x / other.x, y / other.y);
}

inline void Vector2::operator+=(const Vector2& other) {

    x += other.x;
    y += other.y;
}

inline void Vector2::operator-=(const Vector2& other) {

    x -= other.x;
    y -= other.y;
}

inline void Vector2::operator*=(const Vector2& other) {

    x *= other.x;
    y *= other.y;
}

inline void Vector2::operator/=(const Vector2& other) {

    x /= other.x;
    y /= other.y;
}

//PUBLIC MEMBER FUNCTIONS
inline Vector2 Vector2::zero() {

    return Vector2();
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

inline float Vector2::dotProduct(const util::vec::Vector2& other) const {

    return (x * other.x) + (y * other.y);
}

inline float Vector2::distance(const util::vec::Vector2& other) const {

    return sqrt(pow(x - other.x, 2.0f) + pow(y - other.y, 2.0f));
}

inline float Vector2::angleBetween(const util::vec::Vector2& other) const {

    return (-1.0f * atan2(y - other.y, x - other.x));
}

inline void Vector2::addX(float v) {

    x += v;
}

inline void Vector2::addY(float v) {

    y += v;
}

inline void Vector2::subX(float v) {

    x -= v;
}

inline void Vector2::subY(float v) {

    y -= v;
}

inline void Vector2::mulX(float v) {

    x *= v;
}

inline void Vector2::mulY(float v) {

    y *= v;
}

inline void Vector2::divX(float v) {

    x /= v;
}

inline void Vector2::divY(float v) {

    y /= v;
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

inline std::string Vector2::toString() const {

    //create the string of the vector
    std::stringstream ss;
    ss << "[" << x << ", " << y << "]";

    return ss.str();
}

} } //util //vec

#endif