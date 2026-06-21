// LL_parallelogram.cpp
#include "LL_Parallelogram.h"

	LL_Parallelogram::LL_Parallelogram(int width, int height, const std::string& name)
		: Parallelogram(width, height, name) {};

	Canvas LL_Parallelogram::draw(char pen, char fillChar) {
		Canvas canvas(width + height - 1, height, fillChar);  // frame + fillChar already drawn
		for (int y = 0; y < height; ++y) {
			int offset = y;  // shift left each row
			for (int x = 0; x < width; ++x) {
				int drawX = x + offset;
				canvas.put(pen, drawX, y);
			}
		}
		return canvas;
	}
