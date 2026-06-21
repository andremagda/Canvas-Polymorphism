// RL_parallelogram.cpp
#include "RL_Parallelogram.h"

	RL_Parallelogram::RL_Parallelogram(int width, int height, const std::string& name)
		: Parallelogram(width, height, name) {}

	Canvas RL_Parallelogram::draw(char pen, char fillChar) {
		Canvas canvas(width + height - 1, height, fillChar);  // frame + fillChar already drawn
		for (int y = 0; y < height; ++y) {
			int offset = height - y - 1;  // shift right each row
			for (int x = 0; x < width; ++x) {
				int drawX = x + offset;
				canvas.put(pen, drawX, y); 
			}
		}
		return canvas;
	}