/*********************\
| A 4 x 4 matrix.     |
|                     |
| @author David Saxon |
\*********************/

#ifndef UTILITIES_MATRIX_MATRIX4_H_
#   define UTILITIES_MATRIX_MATRIX4_H_

#include <iostream>
#include <math.h>

#include "../ValuesUtil.hpp"
#include "../exceptions/ArrayException.hpp"
#include "../vector/Vector3.hpp"
#include "../vector/Vector4.hpp"

namespace util { namespace mat {

class Matrix4 {

    //FRIEND FUNCTIONS
    /*!Prints the matrix to the output stream
    @_output the output stream to print to
    @_m the matrix to print 
    @return the changed output stream*/
    friend std::ostream& operator<<(std::ostream& _output,
        const Matrix4& _m);

public:

    //CONSTRUCTORS
    /*!Creates a new zero 4x4 matrix*/
    Matrix4() {
    }

    /*!Creates a new 4x4 matrix from the three columns given
    @_col0 the first column
    @_col1 the second column
    @_col2 the third column
    @_col3 the fourth column*/
    Matrix4(const util::vec::Vector4& _col0, const util::vec::Vector4& _col1,
        const util::vec::Vector4& _col2, const util::vec::Vector4& _col3) :
        col0(_col0),
        col1(_col1),
        col2(_col2),
        col3(_col3) {
    }

    /*!Creates a new 4x4 matrix with the smae scale values
    @_scalar the scalar to set the matrix to*/
    explicit Matrix4(float _scalar) :
        col0(_scalar, _scalar, _scalar, _scalar),
        col1(_scalar, _scalar, _scalar, _scalar),
        col2(_scalar, _scalar, _scalar, _scalar),
        col3(_scalar, _scalar, _scalar, _scalar) {
    } 

    /*!Creates a new 4x4 matrix by copying the other matrix
    @_other the matrix to copy*/
    Matrix4(const Matrix4& _other) :
        col0(_other.col0),
        col1(_other.col1),
        col2(_other.col2),
        col3(_other.col3) {
    }  

    //OPERATORS
    /*!Copies the values from the other matrix to this matrix
    @_other the other matrix to copy from
    @return this matrix*/
    const Matrix4 operator =(const Matrix4& _other);

    //TODO: equality operators

    /*!Gets the column at the specified index
    @_index the column index
    @return the given column*/
    util::vec::Vector4& operator [](unsigned _index);

    /*!Gets the column at the specified index
    @_index the column index
    @return the given column*/
    const util::vec::Vector4& operator [](unsigned _index) const;

    /*!@return this matrix with all elements negated*/
    Matrix4 operator -() const;

    /*!Adds two 4 x 4 matrices together
    @_other the other matrix to add with
    @return the result of the addition*/
    Matrix4 operator +(const Matrix4& _other) const;

    /*!Adds the other matrix to this matrix
    @_other the other matrix to add this with*/
    void operator +=(const Matrix4& _other);

    /*!Subtracts two matrices
    @_other the matrix to subtract from this matrix
    @return the result of the subtraction*/
    Matrix4 operator -(const Matrix4& _other) const;

    /*!Subtracts the other matrix from this matrix
    @_other the matrix to subtract from this matrix*/
    void operator -=(const Matrix4& _other);

    /*!Multiplies a 4x4 matrix by a scalar
    @_scalar the scalar to multiply the matrix by
    @return the result of the multiplication*/
    Matrix4 operator *(float _scalar) const;

    /*!Multiplies a 4x4 by a scalar
    @_scalar the scalar to multiply the matrix by*/
    void operator *=(float _scalar);

    /*!Multiplies a 4x4 matrix by a 4d vector
    @_vec the vector to multiply by
    @return the result of the multiplication*/
    util::vec::Vector4 operator *(const util::vec::Vector4& _vec) const;

    /*!Multiplies a 4x4 matrix by another 4x4 matrix
    @_other the other matrix to multiply by
    @return the result of the multiplication*/
    Matrix4 operator *(const Matrix4& _other) const;

    /*!Multiplies a 4x4 matrix by another 4x4 matrix
    @_other the other matrix to multiply by*/
    void operator *=(const Matrix4& _other);

    //PUBLIC MEMBER FUNCTIONS
    /*!@return the 4x4 identity matrix*/
    static Matrix4 identity();

    /*!Creates a 4x4 matrix to rotate around the x axis
    @_degrees the amount in degrees to rotate around the x axis
    @return the rotation matrix*/
    static Matrix4 rotationX(float _degrees);

    /*!Creates a 4x4 matrix to rotate around the y axis
    @_degrees the amount in degrees to rotate around the y axis
    @return the rotation matrix*/
    static Matrix4 rotationY(float _degrees);

    /*!Creates a 4x4 matrix to rotate around the z axis
    @_degrees the amount in degrees to rotate around the z axis
    @return the rotation matrix*/
    static Matrix4 rotationZ(float _degrees);

    /*!Creates a 4x4 matrix to rotate around the x, y, and axis
    @_rot the amount to rotate around the axis
    @return the rotation matrix*/
    static Matrix4 rotationXYZ(const util::vec::Vector3& _rot);

    /*!Creates a 4x4 matrix to rotate around a unit-length vector
    @_degrees the degrees to rotate
    @_unitVec the vector to rotate around
    @return the rotation matrix*/
    static Matrix4 rotation(float _degrees, const util::vec::Vector3& _unitVec);

    //TODO: rotation around quaternion

    /*!Creates a 4x4 matrix for scaling
    @_scale the amount to scale by
    @return the scale matrix*/
    static Matrix4 scale(const util::vec::Vector3& _scale);

    /*!Creates a 4x4 for translation
    @_translation the amount to translate
    @return the translation matrix*/
    static Matrix4 translation(const util::vec::Vector3& _translation);

    /*!Create a matrix based on eye position, position looked at,
    and up direction
    @_eyePos the eye position
    @_lookAt the position looked at
    @_upDir the up direction
    @return the look at matrix*/
    static Matrix4 lookAt(const util::vec::Vector3& _eyePos,
        const util::vec::Vector3& _lookAt, const util::vec::Vector3& _upDir);

    /*!Creates a perspective projection matrix
    @_fov the field of view
    @_aspectRatio the aspect ratio
    @_zNear the near clipping distance
    @_zFar the far clipping distance*/
    static Matrix4 perspective(float _fov, float _aspectRatio,
        float _zNear, float _zFar);

    /*!Creates a perspective projection matrix based on frustum
    @_left the left dimension of the frustum
    @_right the right dimension of the frustum
    @_bottom the bottom dimension of the frustum
    @_top the top dimension of the frustum
    @_zNear the near clipping distance
    @_zFar the far clipping distance*/
    static Matrix4 frustum(float _left, float _right, float _bottom, float _top,
        float _zNear, float _zFar);

    /*!Creates an orthographic projection matrix
    @_left the left dimension 
    @_right the right dimension 
    @_bottom the bottom dimension 
    @_top the top dimension
    @_zNear the near clipping distance
    @_zFar the far clipping distance*/
    static Matrix4 orthographic(float _left, float _right, float _bottom,
        float _top, float _zNear, float _zFar);

    /*!Creates the transpose of the given matrix
    @_other the matrix to transpose
    @return the matrix transposed as a new matrix*/
    static Matrix4 transpose(const Matrix4& _other);

    /*!Creates the inverse of the given matrix
    @_other the matrix to inverse
    @return the matrix inversed as a new matrix*/
    static Matrix4 inverse(const Matrix4& _other);

    /*!Creates the determinant of the given matrix
    @_other the matrix to calculate the the determinant for
    @return the the determinant*/
    static float determinant(const Matrix4& _other);

    /*!Sets the the column at the given index
    @_index the column index to set
    @_col the new column*/
    void setCol(unsigned _index, const util::vec::Vector4& _col);

    /*!Sets the row at the given index
    @_index the row index to set
    @_row the new row*/
    void setRow(unsigned _index, const util::vec::Vector4& _row);

    /*!@_col the new first column of the matrix*/
    void setCol0(const util::vec::Vector4& _col);

    /*!@_col the new second column of the matrix*/
    void setCol1(const util::vec::Vector4& _col);

    /*!@_col the new third column of the matrix*/
    void setCol2(const util::vec::Vector4& _col);

    /*!@_col the new fourth column of the matrix*/
    void setCol3(const util::vec::Vector4& _col);

    /*!Sets the element at the given position in matrix
    @_col the column index
    @_row the row index
    @_value the value to set the element to*/
    void setElement(unsigned _col, unsigned _row, float _value);

    /*!Sets the translate component of the matrix
    @_translateVec the translation vector*/
    void setTranslation(const util::vec::Vector3& _translateVec);

    /*!Get the column at the given index
    @_index the column index
    @return the column*/
    const util::vec::Vector4& getCol(unsigned _index) const;

    /*!Get the row at the given index
    @_index the row index
    @return the row*/
    util::vec::Vector4 getRow(unsigned _index) const;

    /*!@return the first column of the matrix*/
    const util::vec::Vector4& getCol0() const;

    /*!@return the second column of the matrix*/
    const util::vec::Vector4& getCol1() const;

    /*!@return the third column of the matrix*/
    const util::vec::Vector4& getCol2() const;

    /*!@return the fourth column of the matrix*/
    const util::vec::Vector4& getCol3() const;

    /*!Gets the element at the given position
    @_col the column index
    @_row the row index
    @return the value at the position*/
    float getElement(unsigned _row, unsigned _col) const;

    /*!@return the translation component of the matrix*/
    util::vec::Vector3 getTranslation() const;

private:

    //VARIABLES
    //the columns of the matrix
    util::vec::Vector4 col0;
    util::vec::Vector4 col1;
    util::vec::Vector4 col2;
    util::vec::Vector4 col3;
};

//INLINE
//OPERATORS
inline const Matrix4 Matrix4::operator =(const Matrix4& _other) {

    col0 = _other.col0;
    col1 = _other.col1;
    col2 = _other.col2;
    col3 = _other.col3;

    return *this;
}

inline util::vec::Vector4& Matrix4::operator [](unsigned _index) {

    //check that the index is within bounds
    if (_index > 3) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 3.");
    }

    switch (_index) {

        case 0: {

            return col0;
        }
        case 1: {

            return col1;
        }
        case 2: {

            return col2;
        }
        default: {

            return col3;
        }
    }
}

inline const util::vec::Vector4& Matrix4::operator [](unsigned _index) const {

    //check that the index is within bounds
    if (_index > 3) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 3.");
    }

    switch (_index) {

        case 0: {

            return col0;
        }
        case 1: {

            return col1;
        }
        case 2: {

            return col2;
        }
        default: {

            return col3;
        }
    }
}

inline Matrix4 Matrix4::operator -() const {

    return Matrix4(
        -col0,
        -col1,
        -col2,
        -col3);
}

inline Matrix4 Matrix4::operator +(const Matrix4& _other) const {

    return Matrix4(
        col0 + _other.col0,
        col1 + _other.col1,
        col2 + _other.col2,
        col3 + _other.col3);
}

inline void Matrix4::operator +=(const Matrix4& _other) {

    *this = *this + _other;
}

inline Matrix4 Matrix4::operator -(const Matrix4& _other) const {

    return Matrix4(
        col0 - _other.col0,
        col1 - _other.col1,
        col2 - _other.col2,
        col3 - _other.col3);
}

inline void Matrix4::operator -=(const Matrix4& _other) {

    *this = *this - _other;
}

inline Matrix4 Matrix4::operator *(float _scalar) const {

    return Matrix4(
        (col0 * _scalar),
        (col1 * _scalar),
        (col2 * _scalar),
        (col3 * _scalar));
}

inline void Matrix4::operator *=(float _scalar) {

    *this = *this * _scalar;
}

inline util::vec::Vector4 Matrix4::operator *(
    const util::vec::Vector4& _vec) const {

    return util::vec::Vector4(
        ((((col0.getX() * _vec.getX()) + (col1.getX() * _vec.getY())) + 
            (col2.getX() * _vec.getZ())) + (col3.getX() * _vec.getW())),
        ((((col0.getY() * _vec.getX()) + (col1.getY() * _vec.getY())) + 
            (col2.getY() * _vec.getZ())) + (col3.getY() * _vec.getW())),
        ((((col0.getZ() * _vec.getX()) + (col1.getZ() * _vec.getY())) + 
            (col2.getZ() * _vec.getZ())) + (col3.getZ() * _vec.getW())),
        ((((col0.getW() * _vec.getX()) + (col1.getW() * _vec.getY())) + 
            (col2.getW() * _vec.getZ())) + (col3.getW() * _vec.getW())));
}

inline Matrix4 Matrix4::operator *(const Matrix4& _other) const {

    return Matrix4(
        (*this * _other.col0),
        (*this * _other.col1),
        (*this * _other.col2),
        (*this * _other.col3));
}

inline void Matrix4::operator *=(const Matrix4& _other) {

    *this = *this * _other;
}


//PUBLIC MEMBER FUNCTIONS
inline Matrix4 Matrix4::identity() {

    return Matrix4(
        util::vec::Vector4::xVector(),
        util::vec::Vector4::yVector(),
        util::vec::Vector4::zVector(),
        util::vec::Vector4::wVector());
}

inline Matrix4 Matrix4::rotationX(float _degrees) {

    float sine   = sinf(_degrees * util::val::DEGREES_TO_RADIANS);
    float cosine = cosf(_degrees * util::val::DEGREES_TO_RADIANS);

    return Matrix4(
        util::vec::Vector4(1.0f,  0.0f,   0.0f,   0.0f),
        util::vec::Vector4(0.0f,  cosine, sine,   0.0f),
        util::vec::Vector4(0.0f, -sine,   cosine, 0.0f),
        util::vec::Vector4(0.0f,  0.0f,   0.0f,   1.0f));
}

inline Matrix4 Matrix4::rotationY(float _degrees) {

    float sine   = sinf(_degrees * util::val::DEGREES_TO_RADIANS);
    float cosine = cosf(_degrees * util::val::DEGREES_TO_RADIANS);

    return Matrix4(
        util::vec::Vector4(cosine, 0.0f, -sine,   0.0f),
        util::vec::Vector4(0.0f,   1.0f,  0.0f,   0.0f),
        util::vec::Vector4(sine,   0.0f,  cosine, 0.0f),
        util::vec::Vector4(0.0f,   0.0f,  0.0f,   1.0f));
}

inline Matrix4 Matrix4::rotationZ(float _degrees) {

    float sine   = sinf(_degrees * util::val::DEGREES_TO_RADIANS);
    float cosine = cosf(_degrees * util::val::DEGREES_TO_RADIANS);

    return Matrix4(
        util::vec::Vector4( cosine, sine,   0.0f, 0.0f),
        util::vec::Vector4(-sine,   cosine, 0.0f, 0.0f),
        util::vec::Vector4( 0.0f,   0.0f,   1.0f, 0.0f),
        util::vec::Vector4( 0.0f,   0.0f,   0.0f, 1.0f));
}

inline Matrix4 Matrix4::rotationXYZ(const util::vec::Vector3& _rot) {

    float sinX = sinf(_rot.getX() * util::val::DEGREES_TO_RADIANS);
    float cosX = cosf(_rot.getX() * util::val::DEGREES_TO_RADIANS);
    float sinY = sinf(_rot.getY() * util::val::DEGREES_TO_RADIANS);
    float cosY = cosf(_rot.getY() * util::val::DEGREES_TO_RADIANS);
    float sinZ = sinf(_rot.getZ() * util::val::DEGREES_TO_RADIANS);
    float cosZ = cosf(_rot.getZ() * util::val::DEGREES_TO_RADIANS);

    float temp0 = cosZ * sinY;
    float temp1 = sinZ * sinY;

    return Matrix4(
        util::vec::Vector4(cosZ * cosY, sinZ * cosY, -sinY, 0.0f),
        util::vec::Vector4((temp0 * sinX) - (sinZ * cosX),
            (temp1 * sinX) + (cosZ * sinX), cosY * sinX, 0.0f),
        util::vec::Vector4((temp0 * cosX) + (sinZ * sinX),
            (temp1 * cosX) - (cosZ * sinX), cosY * cosX, 0.0f),
        util::vec::Vector4(0.0f,   0.0f,   0.0f, 1.0f));
}

inline Matrix4 Matrix4::rotation(float _degrees,
    const util::vec::Vector3& _unitVec) {

    float s = sinf(_degrees * util::val::DEGREES_TO_RADIANS);
    float c = cosf(_degrees * util::val::DEGREES_TO_RADIANS);

    float x = _unitVec.getX();
    float y = _unitVec.getY();
    float z = _unitVec.getZ();

    float xy = ( x * y );
    float yz = ( y * z );
    float zx = ( z * x );

    float oneMinusC = (1.0f - c);

    return Matrix4(
        util::vec::Vector4((((x * x) * oneMinusC) + c),
            ((xy * oneMinusC) + (z * s)), ((zx * oneMinusC) - (y * s)), 0.0f),
        util::vec::Vector4(((xy * oneMinusC) - (z * s)),
            (((y * y) * oneMinusC) + c ), ((yz * oneMinusC) + (x * s)), 0.0f),
        util::vec::Vector4(((zx * oneMinusC) + (y * s)),
            ((yz * oneMinusC) - (x * s)), (((z * z) * oneMinusC) + c), 0.0f),
        util::vec::Vector4(0.0f,   0.0f,   0.0f, 1.0f));
}

inline Matrix4 Matrix4::scale(const util::vec::Vector3& _scale) {

    return Matrix4(
        util::vec::Vector4(_scale.getX(), 0.0f,          0.0f,         0.0f),
        util::vec::Vector4(0.0f,          _scale.getY(), 0.0f,         0.0f),
        util::vec::Vector4(0.0f,          0.0f,         _scale.getZ(), 0.0f),
        util::vec::Vector4::wVector());
}

inline Matrix4 Matrix4::translation(const util::vec::Vector3& _translation) {

    return Matrix4(
        util::vec::Vector4::xVector(),
        util::vec::Vector4::yVector(),
        util::vec::Vector4::zVector(),
        util::vec::Vector4(_translation.getX(), _translation.getY(),
            _translation.getZ(), 1.0f));
}

inline Matrix4 Matrix4::lookAt(const util::vec::Vector3& _eyePos,
    const util::vec::Vector3& _lookAt, const util::vec::Vector3& _upDir) {

    //TODO:
}

inline Matrix4 Matrix4::perspective(float _fov, float _aspectRatio,
    float _zNear, float _zFar) {

    //TODO:
}

inline Matrix4 Matrix4::frustum(float _left, float _right, float _bottom,
    float _top, float _zNear, float _zFar) {

    //TODO:
}

inline Matrix4 Matrix4::orthographic(float _left, float _right, float _bottom,
    float _top, float _zNear, float _zFar) {

    //TODO:
}

inline Matrix4 Matrix4::transpose(const Matrix4& _other) {

    return Matrix4(
        util::vec::Vector4(_other[0][0], _other[1][0],
            _other[2][0], _other[3][0]),
        util::vec::Vector4(_other[0][1], _other[1][1],
            _other[2][1], _other[3][1]),
        util::vec::Vector4(_other[0][2], _other[1][2],
            _other[2][2], _other[3][2]),
        util::vec::Vector4(_other[0][3], _other[1][3],
            _other[2][3], _other[3][3]));
}

inline Matrix4 Matrix4::inverse(const Matrix4& _other) {

    float mA = _other[0][0];
    float mB = _other[0][1];
    float mC = _other[0][2];
    float mD = _other[0][3];
    float mE = _other[0][0];
    float mF = _other[0][1];
    float mG = _other[0][2];
    float mH = _other[0][3];
    float mI = _other[0][0];
    float mJ = _other[0][1];
    float mK = _other[0][2];
    float mL = _other[0][3];
    float mM = _other[0][0];
    float mN = _other[0][1];
    float mO = _other[0][2];
    float mP = _other[0][3];

    float temp0 = ((mK * mD) - (mC * mL));
    float temp1 = ((mO * mH) - (mG * mP));
    float temp2 = ((mB * mK) - (mJ * mC));
    float temp3 = ((mF * mO) - (mN * mG));
    float temp4 = ((mJ * mD) - (mB * mL));
    float temp5 = ((mN * mH) - (mF * mP));

    util::vec::Vector4 res0, res1, res2, res3;

    res0.setX((((mJ * temp1) - (mL * temp3)) - (mK * temp5)));
    res0.setY((((mN * temp0) - (mP * temp2)) - (mO * temp4)));
    res0.setZ((((mD * temp3) + (mC * temp5)) - (mB * temp1)));
    res0.setW((((mH * temp2) + (mG * temp4)) - (mF * temp0)));

    res1.setX((mI * temp1));
    res1.setY((mM * temp0));
    res1.setZ((mA * temp1));
    res1.setW((mE * temp0));

    res2.setX((mI * temp5));
    res2.setY((mM * temp4));
    res2.setZ((mA * temp5));
    res2.setW((mE * temp4));

    res3.setX((mI * temp3));
    res3.setY((mM * temp2));
    res3.setZ((mA * temp3));
    res3.setW((mE * temp2));

    temp0 = ((mI * mB) - (mA * mJ));
    temp1 = ((mM * mF) - (mE * mN));
    temp2 = ((mI * mD) - (mA * mL));
    temp3 = ((mM * mH) - (mE * mP));
    temp4 = ((mI * mC) - (mA * mK));
    temp5 = ((mM * mG) - (mE * mO));

    res1.setX((((mK * temp3) - (mL * temp5)) - res1.getX()));
    res1.setY((((mO * temp2) - (mP * temp4)) - res1.getY()));
    res1.setZ((((mD * temp5) - (mC * temp3)) + res1.getZ()));
    res1.setW((((mH * temp4) - (mG * temp2)) + res1.getW()));

    res2.setX((((mL * temp1) - (mJ * temp3)) + res2.getX()));
    res2.setY((((mP * temp0) - (mN * temp2)) + res2.getY()));
    res2.setZ((((mB * temp3) - (mD * temp1)) - res2.getZ()));
    res2.setW((((mF * temp2) - (mH * temp0)) - res2.getW()));

    res3.setX((((mJ * temp5) - (mK * temp1)) + res3.getX()));
    res3.setY((((mN * temp4) - (mO * temp0)) + res3.getY()));
    res3.setZ((((mC * temp1) - (mB * temp5)) - res3.getZ()));
    res3.setW((((mG * temp0) - (mF * temp4)) - res3.getW()));

    float detInv = (1.0f / ((((mA * res0.getX()) + (mE * res0.getY())) +
        (mI * res0.getZ())) + (mM * res0.getW())));

    return Matrix4(
        (res0 * detInv),
        (res1 * detInv),
        (res2 * detInv),
        (res3 * detInv));
}

inline float Matrix4::determinant(const Matrix4& _other) {

    float mA = _other[0][0];
    float mB = _other[0][1];
    float mC = _other[0][2];
    float mD = _other[0][3];
    float mE = _other[0][0];
    float mF = _other[0][1];
    float mG = _other[0][2];
    float mH = _other[0][3];
    float mI = _other[0][0];
    float mJ = _other[0][1];
    float mK = _other[0][2];
    float mL = _other[0][3];
    float mM = _other[0][0];
    float mN = _other[0][1];
    float mO = _other[0][2];
    float mP = _other[0][3];

    float temp0 = ((mK * mD) - (mC * mL));
    float temp1 = ((mO * mH) - (mG * mP));
    float temp2 = ((mB * mK) - (mJ * mC));
    float temp3 = ((mF * mO) - (mN * mG));
    float temp4 = ((mJ * mD) - (mB * mL));
    float temp5 = ((mN * mH) - (mF * mP));

    float dx = (((mJ * temp1) - (mL * temp3)) - (mK * temp5));
    float dy = (((mN * temp0) - (mP * temp2)) - (mO * temp4));
    float dz = (((mD * temp3) + (mC * temp5)) - (mB * temp1));
    float dw = (((mH * temp2) + (mG * temp4)) - (mF * temp0));

    return ((((mA * dx) + (mE * dy)) + (mI * dz)) + (mM * dw));
}

inline void Matrix4::setCol(unsigned _index, const util::vec::Vector4& _col) {

    //check that the index is within bounds
    if (_index > 3) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 3.");
    }

    switch (_index) {

        case 0: {

            col0 = _col;
            break;
        }
        case 1: {

            col1 = _col;
            break;
        }
        case 2: {

            col2 = _col;
            break;
        }
        default: {

            col3 = _col;
            break;
        }
    }
}

inline void Matrix4::setRow(unsigned _index, const util::vec::Vector4& _row) {

    //check that the index is within bounds
    if (_index > 3) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 3.");
    }

    col0[_index] = _row.getX();
    col1[_index] = _row.getY();
    col2[_index] = _row.getZ();
    col3[_index] = _row.getW();
}

inline void Matrix4::setCol0(const util::vec::Vector4& _col) {

    col0 = _col;
}

inline void Matrix4::setCol1(const util::vec::Vector4& _col) {

    col1 = _col;
}

inline void Matrix4::setCol2(const util::vec::Vector4& _col) {

    col2 = _col;
}

inline void Matrix4::setCol3(const util::vec::Vector4& _col) {

    col3 = _col;
}

inline void Matrix4::setElement(unsigned _col, unsigned _row, float _value) {

    //check that the index is within bounds
    if (_col > 3) {

        throw util::ex::IndexOutOfBoundsException(
            "column index is greater than 3.");
    }
    if (_row > 3) {

        throw util::ex::IndexOutOfBoundsException(
            "row index is greater than 3.");
    }

    switch (_col) {

        case 0: {

            col0[_row] = _value;
            break;
        }
        case 1: {

            col1[_row] = _value;
            break;
        }
        case 2: {

            col2[_row] = _value;
            break;
        }
        default: {

            col3[_row] = _value;
            break;
        }
    }
}

inline void Matrix4::setTranslation(const util::vec::Vector3& _translateVec) {

    col3.setX(_translateVec.getX());
    col3.setY(_translateVec.getY());
    col3.setZ(_translateVec.getZ());
}

inline const util::vec::Vector4& Matrix4::getCol(unsigned _index) const {

    //check that the index is within bounds
    if (_index > 3) {

        throw util::ex::IndexOutOfBoundsException("index is greater than 3.");
    }

    switch (_index) {

        case 0: {

            return col0;
        }
        case 1: {

            return col1;
        }
        case 2: {

            return col2;
        }
        default: {

            return col3;
        }
    }
}

inline util::vec::Vector4 Matrix4::getRow(unsigned _index) const {

    return util::vec::Vector4(col0[_index], col1[_index],
        col2[_index], col3[_index]);
}

inline const util::vec::Vector4& Matrix4::getCol0() const {

    return col0;
}

inline const util::vec::Vector4& Matrix4::getCol1() const {

    return col1;
}

inline const util::vec::Vector4& Matrix4::getCol2() const {

    return col2;
}

inline const util::vec::Vector4& Matrix4::getCol3() const {

    return col3;
}

inline float Matrix4::getElement(unsigned _row, unsigned _col) const {

    //check that the index is within bounds
    if (_col > 3) {

        throw util::ex::IndexOutOfBoundsException(
            "column index is greater than 3.");
    }
    if (_row > 3) {

        throw util::ex::IndexOutOfBoundsException(
            "row index is greater than 3.");
    }

    switch (_col) {

        case 0: {

            return col0[_row];
        }
        case 1: {

            return col1[_row];
        }
        case 2: {

            return col2[_row];
        }
        default: {

            return col3[_row];
        }
    }
}

inline util::vec::Vector3 Matrix4::getTranslation() const {

    return util::vec::Vector3(col3.getX(), col3.getY(), col3.getZ());
}

}} //util //mat

#endif