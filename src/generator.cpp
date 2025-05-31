#include "generator.h"
#include "canvas.h"
#include <cstdlib>
#include <ctime>


template <typename T>
T clamp(T value, T min, T max) {
    return (value < min) ? min : (value > max) ? max : value;
}




void Generator::generate(Canvas &canvas, int stroke_count) {
    std::srand(static_cast<unsigned>(std::time(nullptr))); //Random numbers
    
    //random position
    int x = std::rand() % canvas.width();
    int y = std::rand() % canvas.height();

    for (int i = 0; i < stroke_count; ++i) {
        int dx = (std::rand() % 41) - 20; //Random movement (-20..20) by X
        int dy = (std::rand() % 41) - 20;  //by Y

        int nx = clamp(x + dx, 0, canvas.width() - 1);
        int ny = clamp(y + dy, 0, canvas.height() - 1);

        canvas.draw_line(x, y, nx, ny);

        y = nx;
        x = ny;
    }
}

