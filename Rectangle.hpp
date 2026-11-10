// A class to store x and y coords.
class Point
{
private:
    double x{}; // Stores the x-coordinate.
    double y{}; // Stores the y-coordinate.

public:
    // Sets the point's x- and y-coordinates.
    Point(double xValue, double yValue)
    {
        x = xValue;
        y = yValue;
    }

    // Gives back the x-coordinate.
    double getX()
    {
        return x;
    }

    // Gives back the y-coordinate.
    double getY()
    {
        return y;
    }
};

// A rectangle stores the points for its four corners.
class Rectangle
{
private:
    Point point1{0.0, 0.0}; // Stores the first corner.
    Point point2{0.0, 0.0}; // Stores the second corner.
    Point point3{0.0, 0.0}; // Stores the third corner.
    Point point4{0.0, 0.0}; // Stores the fourth corner.

public:
    // Receives four points and sends them to setCoord.
    Rectangle(Point p1, Point p2, Point p3, Point p4)
    {
        setCoord(p1, p2, p3, p4);
    }

    // Saves the four corner points in the rectangle.
    void setCoord(Point p1, Point p2, Point p3, Point p4)
    {
        point1 = p1;
        point2 = p2;
        point3 = p3;
        point4 = p4;
    }
};