#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <string>
#include <iostream> // For std::ostream
#include <stdexcept> // For std::out_of_range

//using std::string;
using std::vector;

class Canvas {
	private:
		std::vector<std::vector<char>> grid;
		int width; //x
		int height; //y
		char fillChar = ' '; 
		char verticalFrame = '|';
		char horizontalFrame = '-';
		char cornerFrame = '+';

	public:
		// Parameterized contructor
		Canvas (size_t width, size_t height, char fillChar = ' ');

		// Getters
		int getWidth() const;
		int getHeight() const;
		char getFillChar() const;
		char getVerticalFrame() const;
		char getHorizontalFrame() const;
		char getCornerFrame() const;

		// Setters
		void setWidth(int w); //Should resize grid appropriately
		void setHeight(int h); // Should resize grid appropriately
		void setFillChar(char c);
		void setVerticalFrame(char c);
		void setHorizontalFrame(char c);
		void setCornerFrame(char c);

		// Place a character at specific coordinates
		// Ignores out-of-bound writes
		void put(char c, int x, int y);

		// Access character at specific coordinates.
		// Throws std::out_of_range on out-of-bound coordinates
		char get(int x, int y) const;
		
		void clear(); // Clear entire canvas using fillChar
		void fill(char fillCh); // Fill entire canvas using fillCh

		// Write a string horizontally starting at given coordinates
		void write_horizontal(int x, int y, const std::string& text);

		// Write a string vertically starting at given coordinates
		void write_vertical(int x, int y, const std::string& text);

		// Rotate canvas contents 90 degrees clockwise
		void rotate();

		// Overlay another canvas at specified position
		// Clips out-of-bound regions
		void overlay(const Canvas& other, int x, int y);

		// Output Operator: Outputs canvas with frame
		friend std::ostream& operator<<(std::ostream& os, const Canvas& canvas);

		//RULE OF FIVE
		//Canvas();  // Default constructor
		Canvas(const Canvas& other) = default; //copy constructor
		Canvas& operator = (const Canvas& other) = default; // Copy assignment operator
		Canvas(Canvas&& other) noexcept = default; //move contructor
		Canvas& operator = (Canvas&& other) noexcept = default; //Move assignment operator
		~Canvas() = default;
};
#endif 