#include "RightTriangle.h"
#include <cmath>   // for sqrt
#include "Canvas.h"


	RightTriangle::RightTriangle(int base, const std::string& name)
    : Triangle(base, name)  // passes base twice to Shape, name "Ladder"
	{};

		
	double RightTriangle::geometricArea() const {
		return (width * height) / 2.0;
	}

	double RightTriangle::geometricPerimeter() const {
		// Perimeter = w + h + hypotenuse = w * (2 + sqrt(2)) since w = h = base
		// This is given formula: w * (2 + sqrt(2))
		return width * (2 + std::sqrt(2));
	}

	int RightTriangle::screenArea() const {
		// Screen area = h * (h + 1) / 2
		return height * (height + 1) / 2;
	}

	int RightTriangle::screenPerimeter() const {
		if (width == 1 || height == 1) return 1;
		return 3 * (height - 1);
	}

	// Draw RightTriangle (assuming right angle at bottom-left)
	Canvas RightTriangle::draw(char pen, char fillChar) {
		Canvas canvas(width, height, fillChar);		
		for (int y = 0; y < height; ++y) {
			for (int x = 0; x <= y && x < width; ++x) {
				canvas.put(pen, x, y); 
			}
		}
		return canvas;
	}