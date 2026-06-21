#include "Canvas.h"

		// Parameterized contructor
		Canvas::Canvas (size_t w, size_t h, char fill) 
			 : width(w + 2), height(h + 2), fillChar(fill) {
			grid.resize(height, std::vector<char>(width, fillChar));
			setVerticalFrame('|');
			setHorizontalFrame ('-');
			setCornerFrame('+');
		};

		// Getters
		int Canvas::getWidth() const {
			return width;
		};

		int Canvas::getHeight() const {
			return height;
		};

		char Canvas::getFillChar() const {
			return fillChar;
		};

		char Canvas::getVerticalFrame() const{
			return verticalFrame;
		};

		char Canvas::getHorizontalFrame() const{
			return horizontalFrame;
		};

		char Canvas::getCornerFrame() const{
			return cornerFrame;
		};

		// Setters
		void Canvas::setWidth(int w) {
			width = w;
			for (auto& row : grid) {
				row.resize(width, fillChar);  // resize each row
				}
		}; //Should resize grid appropriately

		void Canvas::setHeight(int h){
			height = h;
			grid.resize(height, std::vector<char>(width, fillChar));
		}; // Should resize grid appropriately

		void Canvas::setFillChar(char c) {
			fillChar = c;
			for (auto& row : grid) {
				std::fill (row.begin (), row.end(), fillChar);
			}
		};

		void Canvas::setVerticalFrame(char c) {
			verticalFrame = c;
			for (size_t i = 1; i < height - 1; ++i) {  // Skip top and bottom rows (corners)
				grid[i][0] = verticalFrame;            // Left border
				grid[i][width - 1] = verticalFrame;    // Right border
			}
		}

		void Canvas::setHorizontalFrame(char c) {
			horizontalFrame = c;
			if (grid.empty()) return;

			// Top row (skip first and last column)
			std::fill(grid[0].begin() + 1, grid[0].end() - 1, horizontalFrame);

			// Bottom row (skip first and last column)
			std::fill(grid[height - 1].begin() + 1, grid[height - 1].end() - 1, horizontalFrame);
		}

		// Setter for corner frame character and updates the four corners of the grid
		void Canvas::setCornerFrame(char c) {
			cornerFrame = c;
			if (grid.empty()) return;

			int lastRow = grid.size() - 1;
			int lastCol = grid[0].size() - 1;

			grid[0][0] = cornerFrame;            // top-left corner
			grid[0][lastCol] = cornerFrame;      // top-right corner
			grid[lastRow][0] = cornerFrame;      // bottom-left corner
			grid[lastRow][lastCol] = cornerFrame; // bottom-right corner
		}

		// Place a character at specific coordinates
		// Ignores out-of-bound writes
		void Canvas::put(char c, int x, int y){
			int row = y + 1;
    		int col = x + 1;
			if (col > 0 && col < width && row > 0 && row < height) {
        		grid[row][col] = c;
			}
		};

		// Access character at specific coordinates.
		// Throws std::out_of_range on out-of-bound coordinates
		char Canvas::get(int x, int y) const {
			int row = y - 1;
			int col = x - 1;

			if (col >= 0 && col < width && row >= 0 && row < height) {
				return grid[row][col];
			}
			throw std::out_of_range("Coordinates out of bounds");
		};
		
		// Clear entire canvas using fillChar
		void Canvas::clear(){
			for (size_t i = 1; i < height - 1; ++i) {
				for (size_t j = 1; j < width - 1; ++j) {
					grid[i][j] = fillChar;
				}
			}
		}

		// Fill entire canvas using fillCh
		void Canvas::fill(char fillCh) {
			for (size_t row = 1; row + 1 < height; ++row) {       // skip first and last row (frame)
				for (size_t col = 1; col + 1 < width; ++col) {    // skip first and last col (frame)
					grid[row][col] = fillCh;
				}
			}
		};

		// Write a string horizontally starting at given coordinates
		void Canvas::write_horizontal (int x, int y, const std::string& text) {		
			//if (y < 0 || y >= static_cast<int>(height) - 1) return; // Outside vertical bounds

			for (size_t i = 0; i < text.size(); ++i) {
				// int col = x + static_cast<int>(i); // x = starting column
				// if (col >= 0 && col < static_cast<int>(width)) {
				// 	grid[y][col] = text[i]; // grid[y][x] = grid[row][column]

				int col = x + i;
				int row = y;
				if (row >= 0 && row < height && col >= 0 && col < width) {
					grid[row][col] = text[i];
				}
			}
		};

		// Write a string vertically starting at given coordinates
		void Canvas::write_vertical (int x, int y, const std::string& text) {
			
			if (x < 0 || x >= static_cast<int>(width) - 1) return; // Outside horizontal bounds

			for (size_t i = 0; i < text.size(); ++i) {
				int row = y + static_cast<int>(i);
				if (row >= 0 && row < static_cast<int>(height) - 1) {
					grid[row][x] = text[i];
				}
			}
		};

		void Canvas::rotate(){
		std::vector<std::vector<char>> rotatedGrid(width, std::vector<char>(height, fillChar));

		// Only rotate inner contents (without frame)
		for (int r = 1; r < height - 1; ++r) {
			for (int c = 1; c < width - 1; ++c) {
				rotatedGrid[c][height - 1 - r] = grid[r][c];
			}
		}

		// Re-draw frame after rotation
		// Top and bottom borders
		for (int c = 0; c < height; ++c) {
			rotatedGrid[0][c] = (c == 0 || c == height - 1) ? '+' : '-';
			rotatedGrid[width - 1][c] = (c == 0 || c == height - 1) ? '+' : '-';
		}
		// Left and right borders
		for (int r = 1; r < width - 1; ++r) {
			rotatedGrid[r][0] = '|';
			rotatedGrid[r][height - 1] = '|';
		}
		grid = std::move(rotatedGrid);
		std::swap(width, height);
	}

		// Overlay another canvas at specified position
		// Clips out-of-bound regions
		void Canvas::overlay(const Canvas& other, int x, int y) {
			for (int r = 1; r < other.height - 1; ++r) {
				int targetRow = y + r - 1;
				if (targetRow < 0 || targetRow >= height) continue;

				for (int c = 1; c < other.width - 1; ++c) {
					int targetCol = x + c - 1;
					if (targetCol < 0 || targetCol >= width) continue;
				if (other.grid[r][c] != other.fillChar) {
					grid[targetRow][targetCol] = other.grid[r][c];
				}
				// Copy ALL characters, including dots
            //grid[targetRow][targetCol] = other.grid[r][c];
				}
			}
		}

		// Output Operator: Outputs canvas with frame ***************
		std::ostream& operator<< (std::ostream& os, const Canvas& canvas){
			for (const auto& row : canvas.grid) {
				for (char cell : row) {
					os << cell;
				}
				os << '\n';
			}
			return os;
		};