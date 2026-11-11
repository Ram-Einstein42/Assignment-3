// File: Rectangle.hpp
// Name: Ram Basnet
// Purpose: Store points, check rectangles, and calculate their measurements.

#pragma once

// bunch of includes
#include <stdexcept>

// A class to store x and y coords.
class Point
{
private:
    double x{}; // Stores the x-coordinate.
    double y{}; // Stores the y-coordinate.

public:
    // Sets the point's x- and y-coordinates.
    // Pre-condition: Two coordinate values are provided.
    // Post-condition: Stores the given x- and y-coordinates.
    Point(double xValue, double yValue) : x{xValue}, y{yValue}
    {
    }

    // Gives back the x-coordinate.
    // Pre-condition: The point has been created.
    // Post-condition: Returns x without changing the point.
    double getX() const
    {
        return x;
    }

    // Gives back the y-coordinate.
    // Pre-condition: The point has been created.
    // Post-condition: Returns y without changing the point.
    double getY() const
    {
        return y;
    }
};

// A rectangle stores the points for its four corners.
class Rectangle
{
private:
    static constexpr double MIN_COORD = 0.0; // Smallest allowed coordinate.
    static constexpr double MAX_COORD = 20.0; // Largest allowed coordinate.
    static constexpr int POINT_COUNT = 4; // Number of rectangle corners.

    Point point1{0.0, 0.0}; // Stores the first corner.
    Point point2{0.0, 0.0}; // Stores the second corner.
    Point point3{0.0, 0.0}; // Stores the third corner.
    Point point4{0.0, 0.0}; // Stores the fourth corner.

    // Finds the horizontal distance using x-coordinates.
    // Pre-condition: The corners are valid and stored in order.
    // Post-condition: Returns the positive horizontal side length.
    double hSideLength() const
    {
        return point2.getX() - point1.getX();
    }

    // Finds the vertical distance using y-coordinates.
    // Pre-condition: The corners are valid and stored in order.
    // Post-condition: Returns the positive vertical side length.
    double vSideLength() const
    {
        return point4.getY() - point1.getY();
    }

public:
    // Receives four points and sends them to setCoord.
    // Pre-condition: Four Point objects are provided.
    // Post-condition: Creates a valid rectangle or throws an error.
    Rectangle(Point p1, Point p2, Point p3, Point p4)
    {
        setCoord(p1, p2, p3, p4);
    }

    // return larger length
    // Pre-condition: The rectangle has valid corners.
    // Post-condition: Returns the longer side without changing the rectangle.
    double length() const
    {
        if (hSideLength() > vSideLength())
        {
            return hSideLength();
        }
        else
        {
            return vSideLength();
        }
    }

    // return width
    // Pre-condition: The rectangle has valid corners.
    // Post-condition: Returns the shorter side without changing the rectangle.
    double width() const
    {
        if (hSideLength() > vSideLength())
        {
            return vSideLength();
        }
        else
        {
            return hSideLength();
        }
    }

    // perimeter
    // Pre-condition: The rectangle has valid corners.
    // Post-condition: Returns the total distance around the rectangle.
    double perimeter() const
    {
        return 2*(length() + width());
    }

    // area
    // Pre-condition: The rectangle has valid corners.
    // Post-condition: Returns the area without changing the rectangle.
    double area() const
    {
        return length()*width();
    }

    // bool square
    // Pre-condition: The rectangle has valid corners.
    // Post-condition: Returns true for equal side lengths, otherwise false.
    bool square() const
    {
        if (hSideLength() == vSideLength())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Pre-condition: Four Point objects are provided in any order.
    // Post-condition: Saves valid axis-aligned corners in order, or throws an error without changing the stored points.
    void setCoord(Point p1, Point p2, Point p3, Point p4)
    {
        Point points[POINT_COUNT]{p1, p2, p3, p4}; // Holds the four input points.

        double minX = p1.getX(); // Smallest x-coordinate found.
        double maxX = p1.getX(); // Largest x-coordinate found.
        double minY = p1.getY(); // Smallest y-coordinate found.
        double maxY = p1.getY(); // Largest y-coordinate found.

        // checks for 0-20 coords
        // Finding the smallest and largest x and y coords
        for (int i = 0; i < POINT_COUNT; i++) // i selects the current point.
        {
            double xCoord = points[i].getX(); // Current point's x-coordinate.
            double yCoord = points[i].getY(); // Current point's y-coordinate.

            if (!(xCoord >= MIN_COORD && xCoord <= MAX_COORD && yCoord >= MIN_COORD && yCoord <= MAX_COORD))
            {
                throw std::invalid_argument("A point is outside the allowed range. Please enter 0-20.");
            }

            if (xCoord < minX) minX = xCoord;
            if (xCoord > maxX) maxX = xCoord;
            if (yCoord < minY) minY = yCoord;
            if (yCoord > maxY) maxY = yCoord;
        }

        // reject if doesnt make a rectangle
        if (minX == maxX || minY == maxY)
        {
            throw std::invalid_argument("The points do not make a rectangle.");
        }

        // store each corners
        Point bottomLeft = p1; // Holds the bottom-left corner once found.
        Point bottomRight = p1; // Holds the bottom-right corner once found.
        Point topRight = p1; // Holds the top-right corner once found.
        Point topLeft = p1; // Holds the top-left corner once found.
        bool hasBottomLeft = false; // Tracks whether the bottom-left corner was found.
        bool hasBottomRight = false; // Tracks whether the bottom-right corner was found.
        bool hasTopRight = false; // Tracks whether the top-right corner was found.
        bool hasTopLeft = false; // Tracks whether the top-left corner was found.

        // match each input point to its corner
        for (int i = 0; i < POINT_COUNT; i++) // i selects the current point.
        {
            double xCoord = points[i].getX(); // Current point's x-coordinate.
            double yCoord = points[i].getY(); // Current point's y-coordinate.

            if (xCoord == minX && yCoord == minY)
            {
                bottomLeft = points[i];
                hasBottomLeft = true;
            }
            else if (xCoord == maxX && yCoord == minY)
            {
                bottomRight = points[i];
                hasBottomRight = true;
            }
            else if (xCoord == maxX && yCoord == maxY)
            {
                topRight = points[i];
                hasTopRight = true;
            }
            else if (xCoord == minX && yCoord == maxY)
            {
                topLeft = points[i];
                hasTopLeft = true;
            }
        }

        // another rejection
        if (!hasBottomLeft || !hasBottomRight || !hasTopRight || !hasTopLeft)
        {
            throw std::invalid_argument("The points do not make a rectangle.");
        }

        // Save the points in order.
        point1 = bottomLeft;
        point2 = bottomRight;
        point3 = topRight;
        point4 = topLeft;
    }
};