/**
 * 
 * Learning from
 * 
 * https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/points-vectors-and-normals.html
 * 
 */

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
};

// Vector utility functions /////////////////////////////////

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

typedef Vec3<float> Vec3f;

Vec3<float> a;
Vec3f b;

int main() {

    return 0;
}