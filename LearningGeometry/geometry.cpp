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
};

typedef Vec3<float> Vec3f;

Vec3<float> a;
Vec3f b;

int main() {
    return 0;
}