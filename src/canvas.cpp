#include "canvas.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <algorithm>
#include <cmath>




Canvas::Canvas(int width, int height) : width_(width), height_(height), data_(width * height * 3, 255) {}

void Canvas::set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) return;

    int index = (y * width_ + x) * 3;
    data_[index] = r; //red
    data_[index + 1] = g; //green
    data_[index + 2] = b; //blue
}

//In this project I used Bresenham's line algorithm. You can read more about it here: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
void Canvas::draw_line(int x0, int y0, int x1, int y1) {
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    //get direction of line by X
    int sx = (x0 < x1) ? 1 : -1;

    //get direction of line by Y
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        set_pixel(x0, y0, 0, 0, 0);

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

bool Canvas::save_to_png(const char* filename) const {
    return stbi_write_png(
        filename, //file name
        width_, //width of picture
        height_, //height of picture
        3, // RGB
        data_.data(), //Data pointer
        width_ * 3 // Amount byte for line (width * RGB)
    );
}


    




