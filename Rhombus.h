#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Quadrilateral.h"
#include <cmath>    // for sqrt

class Rhombus : public Quadrilateral {
	public:
		Rhombus(int diagonal, const std::string& name = "Diamond");
		virtual ~Rhombus() = default;

		// Implement pure virtual functions
		virtual Canvas draw(char pen = '*', char fillChar = ' ') override;

		virtual double geometricArea() const override;
		virtual double geometricPerimeter() const override;
		virtual int screenArea() const override;
		virtual int screenPerimeter() const override;
	};

#endif