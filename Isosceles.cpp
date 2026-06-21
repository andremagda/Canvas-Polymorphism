#include "Isosceles.h"
#include <cmath>
#include "Canvas.h"

// Isosceles::Isosceles(int base, const std::string& name)
//     : Triangle(base, name)  // passes base twice to Shape, name "Ladder"
// 	{};

Isosceles::Isosceles(int b, const std::string& name)
    : Triangle( (b % 2 == 0) ? b + 1 : b, name )
{
    // Adjust the dimensions in the Shape base class:
    // We need to update width and height in Shape to fit the isosceles dimension rules

    // Assuming Shape stores width and height as protected members,
    // and you have setters or can access them, do this:
    
    // width = base (already set correctly from Triangle constructor)
    // height = (base + 1) / 2

    // But the Triangle constructor passes base twice to Shape,
    // so you may want to set height explicitly now:
    
	// Ensure the base is odd
    int correctedBase = (base % 2 == 0) ? base + 1 : base;
    int correctedHeight = (correctedBase + 1) / 2;

    this->width = correctedBase;
    this->height = correctedHeight;

    // Otherwise, if Shape has setters, use those.
}

double Isosceles::geometricArea() const {
    return (width * height) / 2.0;
}

double Isosceles::geometricPerimeter() const {
    // Perimeter = base + 2 * side
    // side = sqrt((w/2)^2 + h^2)
    double side = std::sqrt((width / 2.0) * (width / 2.0) + height * height);
    return width + 2 * side;
}

int Isosceles::screenArea() const {
    // Screen area = h^2
    return height * height;
}

int Isosceles::screenPerimeter() const {
    if (width == 1 || height == 1) return 1;
    return 4 * (height - 1);
}

Canvas Isosceles::draw(char pen, char fillChar) {
    Canvas canvas(width, height, fillChar);

    // The isosceles triangle grows in width each row by 2, centered horizontally:
    // The widest row (bottom) has 'width' characters, height rows total
    // Calculate middle index (center column)
    int mid = width / 2;

    for (int y = 0; y < height; ++y) {
        // Number of pen chars in this row: 1 + 2*y
        int charsInRow = 1 + 2 * y;
        int startX = mid - y;
        int endX = mid + y;
        for (int x = startX; x <= endX; ++x) {
            canvas.put(pen, x, y);
        }
    }
    return canvas;
}