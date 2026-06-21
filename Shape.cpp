#include "Shape.h"

#include <typeinfo>
#include <sstream>
#include <iomanip>

	int Shape::idCounter = 1;

	//Constructor. Initializes dimensions/name, auto-sets ID
		Shape::Shape(int w, int h, std::string n) 
				: width (w), height (h), name (n) {
						ID = idCounter++;
				};
	// Getters (getWidth(), etc.) Accessor Retrieve attributes
		int Shape::getWidth() const{ 
			return width; };

		int Shape::getHeight() const { 
			return height; };

		long Shape::getID() const { 
			return ID; };

		std::string Shape::getname() const { 
			return name; };

		int Shape::getIdCounter() { 
			return idCounter; };

		// Setters (setWidth(), etc.) Mutator Modify attributes (except ID)	
		// Sets the width, optionally you can add validation if needed
		void Shape::setWidth(int w){
			if (w >= 0) {
				width = w;
			} else {
				// Handle invalid input, e.g., ignore or set to 0
				width = 0;
			}
		}
	
		// Sets the height with optional validation
		void Shape::setHeight(int h) {
			if (h >= 0) {
				height = h;
			} else {
				height = 0;
			}
		}		
		
		// Sets the name of the shape
		void Shape::setname(const std::string& n) {
			name = n;
		}

		// Virtual Functions
		//Returns descriptive string (implemented on page ")
		std::string Shape::toString() const {
			std::ostringstream oss;

			oss << std::fixed << std::setprecision(2);
			oss << "SHAPE INFORMATION\n";
			oss << "-----------------\n";
			oss << "ID: " << this -> getID() << "\n";
			oss << "Shape name: " << this -> getname() << "\n";
			oss << "Width (columns): " << this -> getWidth() << "\n";
			oss << "Height (rows): " << this -> getHeight() << "\n";

			oss << "Screen Area: " << this -> screenArea() << "\n";
			oss << "Geometric Area: " << this -> geometricArea() << "\n";
			oss << "Screen Perimeter: " << this ->  screenPerimeter() << "\n";
			oss << "Geometric Perimeter: " << this -> geometricPerimeter() << "\n";

			oss << "Static type: " << typeid(this).name() << '\n';
			oss << "Dynamic type: " << typeid(*this).name() << '\n';

			return oss.str();
		}

		std::ostream& operator<<(std::ostream& os, const Shape& s) {
			os << s.toString();
			return os;
		}