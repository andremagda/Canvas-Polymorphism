#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Shape.h"

class Quadrilateral : public Shape{
	public: 
		Quadrilateral (int width, int height, const std::string& name );
		virtual ~Quadrilateral () = default;
};
#endif