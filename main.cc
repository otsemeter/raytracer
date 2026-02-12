#include "color.h"
#include "vec3.h"

#include <iostream>
void generate_ppm_rg(int, int, int);

/*
PPM image file format:

P3
<width> <height>
<max_value>

r1 g1 b1
r2 g2 b2
.
.
.
.
r<width * height> g<width * height> b<width * height>
EOF

*/
void generate_ppm_rg(int x, int y, int z) {
    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i) / (image_width-1) * x,
            double(j) / (image_height-1) * y,
            z * (double(i) / (image_width-1) * x + double(j) / (image_height-1) * y));

            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                       \n";
}


int main() {
    generate_ppm_rg(1,0,0);
}