#ifndef SHAPE_H
#define SHAPE_H

#include "Canvas.h"
#include <string>
#include <iostream>
#include <iomanip>   // for std::fixed, std::setprecision
#include <typeinfo>  // for typeid

using std::string;

class Shape {
	protected:
		//Canvas canvas;
		int width;
		int height;
		long ID; //belong to each object
		std::string name;

	private:
		static int idCounter; //belong to the class not the object

	public:
		//Constructor. Initializes dimensions/name, auto-sets ID
		Shape(int width, int height, std::string name);

		// Getters (getWidth(), etc.) Accessor Retrieve attributes
		int getWidth() const;
		int getHeight() const;
		long getID() const;
		std::string getname() const;
		static int getIdCounter();

		// Setters (setWidth(), etc.) Mutator Modify attributes (except ID)	
		void setWidth(int w);
		void setHeight(int h) ;
		void setname(const std::string& n) ;

		// Pure Virtual functions

			// Prepares a customized Canvas using shape’s dimensions and fillChar
			// Draws shape on Canvas using pen character
			// Returns Canvas with shape drawn
		virtual Canvas draw(char pen = '*', char fillChar=' ') = 0;

		virtual double geometricArea() const = 0; 		// geometric area
		virtual double geometricPerimeter() const = 0; 	// geometric perimeter
		virtual int screenArea() const = 0; 				// Character count for drawn shape
		virtual int screenPerimeter() const = 0; 			// Character count for border of drwan shape

		// Virtual Functions
		//Returns descriptive string (implemented on page ")
		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& os, const Shape& s);

		virtual ~Shape() = default; 							// Virtual destructor Enables polymorphic deletion
		Shape(const Shape&) = default;							// Copy Constructor
		Shape(Shape&&) = default;								// Move constructor
		Shape& operator = (const Shape&) noexcept = default; 	// Copy Assignment operator
		Shape& operator = (Shape&&) noexcept = default; 		// Move Assignment operator
	};
#endif