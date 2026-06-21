#include "Rectangle.h"
#include <algorithm> // For std::max

// Constructor
Rectangle::Rectangle(int width, int height, const std::string& name)
    : Quadrilateral( width, height, name) {}

// Geometric area: w * h
double Rectangle::geometricArea() const {
    return static_cast<double>(getWidth()) * getHeight();
}

// Geometric perimeter: 2 * (w + h)
double Rectangle::geometricPerimeter() const {
    return 2.0 * (getWidth() + getHeight());
}

// Screen area: w * h
int Rectangle::screenArea() const{
    return getWidth() * getHeight();
}

// Screen perimeter:
// If w > 1 and h > 1: 2*(w + h) - 4
// If w == 1 or h == 1: w * h
int Rectangle::screenPerimeter() const {
    int w = getWidth();
    int h = getHeight();
    if (w > 1 && h > 1) {
        return 2 * (w + h) - 4;
    }
    return w * h;
}

// Draws a rectangle using the pen and fill characters
Canvas Rectangle::draw(char pen, char fillChar) {
   Canvas canvas(width, height, fillChar);
	
    for (int y = 0 ; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
                canvas.put(pen, x, y); // Inside the frame
        }
    }
    return canvas;
}

// Canvas Rectangle::draw(char pen, char fillChar) {
//     Canvas canvas(getWidth(), getHeight(), fillChar); // fill everything inside with fillChar

//     // Draw top and bottom borders with pen
//     for (int x = 0; x < getWidth(); ++x) {
//         canvas.put(pen, 0, x);                  // top border (row 0)
//         canvas.put(pen, getHeight() - 1, x);   // bottom border (last row)
//     }

//     // Draw left and right borders with pen
//     for (int y = 1; y < getHeight() - 1; ++y) {
//         canvas.put(pen, y, 0);                  // left border (col 0)
//         canvas.put(pen, y, getWidth() - 1);    // right border (last col)
//     }

//     // The inside is already filled with fillChar, no need to overwrite

//     return canvas;
// }
