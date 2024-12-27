/**
 * 
 * Learning from
 * 
 * https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/points-vectors-and-normals.html
 * 
 */

/// VECTORS ///////////////////////////////////////////////////////////////////////////////////

#include <iostream>

template<typename T>
class Vec3
{
public:
    T x, y, z;
    // constructors
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
    Vec3(const T &f) : x(f), y(f), z(f) {}
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    // copy method
    Vec3<T> copy() const { return Vec3<T>(x, y, z); }
    // overloading operators ///
    // vector addition
    Vec3<T> operator + (const Vec3<T> &v) const
    { return Vec3<T>(x + v.x, y + v.y, z + v.z); }
    // vector subtraction
    Vec3<T> operator - (const Vec3<T> &v) const
    { return Vec3<T>(x - v.x, y - v.y, z - v.z); }
    // vector multiplication
    Vec3<T> operator * (const Vec3<T> &v) const
    { return Vec3<T>(x * v.x, y * v.y, z * v.z); }
    // matrix multiplication
    Vec3<T>& operator *= (const Matrix44 &m) {
        T xx = x * m[0][0] + y * m[1][0] + z * m[2][0];
        T yy = x * m[0][1] + y * m[1][1] + z * m[2][1];
        T zz = x * m[0][2] + y * m[1][2] + z * m[2][2];
        x = xx;
        y = yy;
        z = zz;
        return *this;
    }
};

// Vector utility functions //////////////////////////////////////////////////////////////////

template<typename T>
T length(const Vec3<T> &v)
{ return sqrt(length2(v)); }

template<typename T>
T dot (const Vec3<T> &a, const Vec3<T> &b)
{ return a.x * b.x + a.y * b.y + a.z * b.z; }

template<typename T>
T dot2(const Vec3<T> &v)
{ return dot(v, v); }

template<typename T>
Vec3<T> normalize(Vec3<T> &v)
{
    T len2 = dot(v); // length squared
    Vec3<T> n = v.copy();
    if (len2 > 0) {
        T invLen = 1 / sqrt(len2);
        n.x *= invLen;
        n.y *= invLen;
        n.z *= invLen;
    }
    return n;
}

template<typename T>
Vec3<T> cross(Vec3<T> &a, const Vec3<T> &b)
{
    return Vec3<T>(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

typedef Vec3<float> vec3;

/// MATRICES ///////////////////////////////////////////////////////////////////////////////////

template<typename T>
class Matrix44
{
public:
    // init to identity matrix
    T m[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    Matrix44() {}
    // mult by Vec3
    Vec3 multVec3(const Vec3<T> &v) {
        T x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0];
        T y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1];
        T z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2];
        T w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + m[3][3];
        if (w != 1 && w != 0) {
            x /= w;
            y /= w;
            z /= w;
        }
        return Vec3(x, y, z);
    }
    // matrix operations
    Matrix44 transpose() const {
        Matrix44 res;
        for (uint8_t i = 0; i < 4; ++i) {
            for (uint8_t j = 0; j < 4; ++j) {
                res[i][j] = m[j][i];
            }
        }
        return res;
    }
    // overloading operators
    const T* operator [] (uint8_t i) const { return m[i]; }
    Matrix44 operator * (const Matrix44 &r) const
    {
        Matrix44 mult;
        for (uint8_t i = 0; i < 4; ++i) {
            for (uint8_t j = 0; j < 4; ++j) {
                mult[i][j] = m[i][0] * r[0][j] +
                             m[i][1] * r[1][j] +
                             m[i][2] * r[2][j] +
                             m[i][3] * r[3][j];
            }
        }
        return mult;
    }

};
typedef Matrix44<float> mat4;