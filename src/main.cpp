#include "canvas.h"
#include "generator.h"

int main() {
    const int WIDHT = 200;
    const int HEIGHT = 200;
    const int STROKE_COUNT = 800;

    Canvas canvas(WIDHT, HEIGHT);

    Generator::generate(canvas, STROKE_COUNT);
    canvas.save_to_png("res.png");

    return 0;
}