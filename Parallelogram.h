#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrilateral.h"

class Parallelogram : public Quadrilateral {
	public:
		Parallelogram(int width, int height, const std::string& name);
		virtual ~Parallelogram () = default;

		double geometricArea() const override; 		// geometric area
		double geometricPerimeter() const override; 	// geometric perimeter
		int screenArea() const override; 				// Character count for drawn shape
		int screenPerimeter() const override; 		// Character count for border of drwan shape
};
#endif