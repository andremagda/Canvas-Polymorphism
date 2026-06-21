#ifndef ISOSCELES_H
#define ISOSCELES_H

#include "Triangle.h"

class Isosceles : public Triangle {

	public:
		Isosceles (int base, const std::string& name = "Pizza");
		~Isosceles() override = default;
		Canvas draw(char pen = '*', char fillChar=' ') override;

		double geometricArea() const override; 		// geometric area
		double geometricPerimeter() const override; 	// geometric perimeter
		int screenArea() const override; 				// Character count for drawn shape
		int screenPerimeter() const override; 		// Character count for border of drwan shape
};
#endif