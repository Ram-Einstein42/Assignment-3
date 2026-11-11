// File: main.cpp
// Name: Ram Basnet
// Purpose: Create two rectangles and display their measurements.

// A Sophisticated Rectangle Class
#include <iostream>
#include <stdexcept>
#include "Rectangle.hpp" // include definition of class Rectangle

/*

Create a sophisticated Rectangle class. This class stores only the Cartesian coordinates of the four corners of the
rectangle. The constructor calls a set function that accepts four sets of coordinates and verifies that
each of these is in the first quadrant with no single x- or y-coordinate larger than 20.0. The set function
also verifies that the supplied coordinates do, in fact, specify a rectangle.

Provide member functions that calculate the length, width, perimeter and area. The length is the larger of the two
dimensions.

Include a predicate function square that determines whether the rectangle is a square.
*/

// Pre-condition: The Point and Rectangle classes are available.
// Post-condition: Displays the measurements and square check for two rectangles.
int main()
{
    Point w{1.0, 1.0}; // First rectangle's bottom-left corner.
    Point x{5.0, 1.0}; // First rectangle's bottom-right corner.
    Point y{5.0, 3.0}; // First rectangle's top-right corner.
    Point z{1.0, 3.0}; // First rectangle's top-left corner.
    Point j{0.0, 0.0}; // Second rectangle's bottom-left corner.
    Point k{1.0, 0.0}; // Second rectangle's bottom-right corner.
    Point m{1.0, 1.0}; // Second rectangle's top-right corner.
    Point n{0.0, 1.0}; // Second rectangle's top-left corner.

    Rectangle r1{z, y, x, w}; // Stores the first rectangle.
    std::cout << "Rectangle 1:\n";
    std::cout << "length = " << r1.length();
    std::cout << "\nwidth = " << r1.width();
    std::cout << "\nperimeter = " << r1.perimeter();
    std::cout << "\narea = " << r1.area();
    std::cout << "\nThe rectangle " << (r1.square() ? "is" : "is not") << " a square.\n";

    Rectangle r2{j, k, m, n}; // Stores the second rectangle.
    std::cout << "\nRectangle 2:\n";
    std::cout << "length = " << r2.length();
    std::cout << "\nwidth = " << r2.width();
    std::cout << "\nperimeter = " << r2.perimeter();
    std::cout << "\narea = " << r2.area();
    std::cout << "\nThe rectangle " << (r2.square() ? "is" : "is not") << " a square.\n";

    return 0;
}