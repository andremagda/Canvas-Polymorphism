#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Triangle.h"

class RightTriangle : public Triangle {
	public:
		RightTriangle(int base, const std::string& name = "Ladder"); 
		Canvas draw(char pen = '*', char fillChar=' ') override;

		double geometricArea() const override; 		// geometric area
		double geometricPerimeter() const override; 	// geometric perimeter
		int screenArea() const override; 				// Character count for drawn shape
		int screenPerimeter() const override; 		// Character count for border of drwan shape
};
#endif