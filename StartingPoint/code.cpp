#include <cstdio>

/*
following along:
https://www.scratchapixel.com/lessons/3d-basic-rendering/get-started/gentle-introduction-to-computer-graphics-programming.html
*/

// define concept of point
typedef float Point[3];

int main() {
    Point corners[8] = {
         { 1, -1, -5},
         { 1, -1, -3},
         { 1,  1, -5},
         { 1,  1, -3},
         {-1, -1, -5},
         {-1, -1, -3},
         {-1,  1, -5},
         {-1,  1, -3}
    };

    // perspective divide -> ycoordinate on cannvas is ycoord/-zcoord
    // x coordinate is p.x/-p.z

    const unsigned int image_width = 512, image_height = 512;
    float aspect_ratio = image_width / static_cast<float>(image_height);

    for (int i = 0; i < 8; i++) {
        // screen space
        float x_proj = -corners[i][0] / corners[i][2]; // op1: divide by aspectratio
        float y_proj = -corners[i][1] / corners[i][2] * aspect_ratio; //op2
        // normalized device coordinates
        x_proj = (1 + x_proj) / 2;
        y_proj = (1 + y_proj) / 2;
        // raster space
        x_proj *= image_width;
        y_proj *= image_height;
        printf("Projected corner %d: x: %f, y: %f\n", i, x_proj, y_proj);
    }

    return 0;
}