#include "Parallelogram.h"

// Constructor
Parallelogram::Parallelogram(int width, int height, const std::string& name)
    : Quadrilateral( width, height, name) {}

// Geometric area: w * h
double Parallelogram::geometricArea() const {
    return static_cast<double>(width) * height;
}

// Geometric perimeter: 2 * (w + h)
double Parallelogram::geometricPerimeter() const {
    return 2.0 * (width + height);
}

// Screen area: w * h
int Parallelogram::screenArea() const{
    return width * height;
}

// Screen perimeter:
// If w > 1 and h > 1: 2*(w + h) - 4
// If w == 1 or h == 1: w * h
int Parallelogram::screenPerimeter() const {
    int w = width;
    int h = height;
    if (w > 1 && h > 1) {
        return 2 * (w + h) - 4;
    }
    return w * h;
}