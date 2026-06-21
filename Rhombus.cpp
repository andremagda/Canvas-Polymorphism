#include "Rhombus.h"

// Constructor - just pass to base Quadrilateral constructor
Rhombus::Rhombus(int diagonal, const std::string& name)
    : Quadrilateral(
        (diagonal % 2 == 0) ? diagonal + 1 : diagonal,  // make diagonal odd if even
        (diagonal % 2 == 0) ? diagonal + 1 : diagonal,
        name) {}

// Geometric area: (w * h) / 2.0
double Rhombus::geometricArea() const {
    return (width * height) / 2.0;
}

// Geometric perimeter: 2 * sqrt(2) * h
double Rhombus::geometricPerimeter() const {
    return 2 * std::sqrt(2) * height;
}

// Screen area: (h^2 + 1) / 2
int Rhombus::screenArea() const {
    return (height * height + 1) / 2;
}

// Screen perimeter:
// if w > 1 and h > 1: 2 * (h - 1)
// if w == 1 or h == 1: 1
int Rhombus::screenPerimeter() const {
    if (width > 1 && height > 1)
        return 2 * (height - 1);
    else
        return 1;
}

Canvas Rhombus::draw(char pen, char fillChar) {
   Canvas canvas(width, height, fillChar);
    int mid = height / 2 ;

    for (int row = 0; row < height; ++row) {
        int distFromMid = row <= mid ? row : (height - 1 - row);
        int numPens = 2 * distFromMid + 1;

        int startCol = (width - numPens) / 2;
        int endCol = startCol + numPens;

        for (int col = startCol; col < endCol; ++col) {
            canvas.put(pen, col, row);
        }
    }
    return canvas;
}

// Canvas Rhombus::draw(char pen, char fillChar) {
//     // Create canvas including frame space
//     Canvas canvas(height, height, fillChar);

//     // Set the frame
//     canvas.setCornerFrame('+');
//     canvas.setHorizontalFrame('-');
//     canvas.setVerticalFrame('|');

//     // Middle row index of drawable area (inside the frame)
//     int mid = (height - 2) / 2;

//     // Draw rhombus inside the frame (rows 1..height-2)
//     for (int i = 0; i <= mid; ++i) {
//         int startX = mid - i + 1;    // +1 to shift right of left frame
//         int endX = mid + i + 1;      // +1 same reason
//         int row = i + 1;             // +1 to shift below top frame

//         for (int x = startX; x <= endX; ++x) {
//             canvas.put(pen, row, x);
//         }
//     }

//     // Bottom half
//     for (int i = mid + 1; i < height - 2; ++i) {
//         int offset = i - mid - 1;
//         int startX = offset + 1;                 // shift right of frame
//         int endX = height - 3 - offset + 1;     // shift left of frame
//         int row = i + 1;

//         for (int x = startX; x <= endX; ++x) {
//             canvas.put(pen, row, x);
//         }
//     }

//     return canvas;
// }

