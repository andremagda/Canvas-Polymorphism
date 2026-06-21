# CANVAS, POLYMORPHISM, INHERITANCE

**Author:** Andrea Delgado
---------------------
## OVERVIEW

This project explores fundamentals object-oriented programming concepts in C++, including
class inheritance, polymorphism, virtual and pure virtual functions, and the Rule of Five.

The project simulates geometric shape rendering on a virtual canvas using character-based
drawing. Here are the key goals:
	• Design a Canvas class for 2D text-based rendering
	• Implement a class hierarchy for geometric shapes using inheritance
	• Utilize virtual functions and polymorphism for dynamic behavior
	• Calculate both geometric and screen-based area/perimeter
	• Apply exception handling and the Rule of Five
---------------------
## CLASS STRUCTURE

- Canvas
- Shape
- Quadrilateral
- Parallelogram
- LL_Parallelogram
- RL_Parallelogram
- Rectangle
- Rhombus
- Triangle
- Isosceles
- RightTriangle
---------------------
## FUNCTIONALITIES

1. Canvas Operations (test_Canvas()):
	• The output produced by this function can be found in test_Canvas_Output.pdf.
2. Shape Operations (test_Shapes()):
	• The output produced by this function can be found in test_Shapes_Output.pdf.
3. Polymorphism (test_Polymorphism()):
	• Theoutputproducedbythisfunctioncanbefoundintest_Polymorphism_Output.pdf.
4. Advanced Features (test_draw_house()):
	• This function creates a complex drawings by combining multiple shapes
	• The output generated can be found in the file test_draw_house_output.pdf.
---------------------
## COMPILE AND RUN THE PROGRAM 

```bash
g++ Shape.cpp Rhombus.cpp Canvas.cpp Quadrilateral.cpp Rectangle.cpp \
    RightTriangle.cpp Isosceles.cpp Triangle.cpp \
    LL_Parallelogram.cpp RL_Parallelogram.cpp Parallelogram.cpp \
    -o main

./main
```
--------------------
## SAMPLE OUTPUTS

![Canvas Output](./canvas_house.png)
