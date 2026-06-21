#ifndef RECTAGLE_H
#define RECTAGLE_H

#include "Quadrilateral.h"

class Rectangle : public Quadrilateral{
		public:
		Rectangle(int width, int height, const std::string& name = "Box");
		virtual ~Rectangle() = default;

		Canvas draw(char pen = '*', char fillChar = ' ') override;

		double geometricArea() const override; 		// geometric area
		double geometricPerimeter() const override; 	// geometric perimeter
		int screenArea() const override; 				// Character count for drawn shape
		int screenPerimeter() const override; 		// Character count for border of drwan shape
};
#endif