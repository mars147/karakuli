#pragma once
#include <vector>
#include <cstdint>

class Canvas 
{
    public:
        Canvas(int width, int height); 
        void set_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b); //In pixel RGB selector
        void draw_line(int x0, int y0, int x1, int y1); //two point line
        bool save_to_png(const char* filename) const;
        int width() const { return width_; }
        int height() const { return height_; }

    private:
        int width_; //width picture in pixels
        int height_; //height pictur in pixels
        std::vector<uint8_t> data_; //picture data (RGB pixels)
};