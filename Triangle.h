#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>

class Triangle : public Shape {
	protected:
		int base;
	public:
		Triangle (int b, const std::string& name);
		virtual ~Triangle () = default;
};
#endif