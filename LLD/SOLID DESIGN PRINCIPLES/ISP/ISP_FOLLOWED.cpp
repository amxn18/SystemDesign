#include<bits/stdc++.h>
using namespace std;

class TwoDimensionalShape {
    public:
    virtual double area() = 0; // Calculate area
};

class ThreeDimensionalShape {
    public:
    virtual double area() = 0; // Calculate surface area
    virtual double volume() = 0; // Calculate volume
};

class Square: public TwoDimensionalShape {
    double side;
    public:
    // Constructor to initialize side length
    Square(double s) : side(s) {}
    // Override area method to calculate area of square
    double area() override {
        return side * side; // Area of square
    }
};

class Rectangle: public TwoDimensionalShape {
    double length, width;
    public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}
    // Override area method to calculate area of rectangle
    double area() override {
        return length * width; // Area of rectangle
    }
};


class Cube: public ThreeDimensionalShape {
    double side;
    public:
    // Constructor to initialize side length
    Cube(double s) : side(s) {}
    // Override area method to calculate surface area of cube
    double area() override {
        return 6 * side * side; // Surface area of cube
    }
    
    // Override volume method to calculate volume of cube
    double volume() override {
        return side * side * side; // Volume of cube
    }
};

int main() {
    // Create instances of shapes
    Square square(5);
    Rectangle rectangle(4, 6);
    Cube cube(3);

    // Calculate and print areas
    cout << "Area of square: " << square.area() << endl;
    cout << "Area of rectangle: " << rectangle.area() << endl;
    cout << "Surface area of cube: " << cube.area() << endl;
    
    // Calculate and print volume of cube
    cout << "Volume of cube: " << cube.volume() << endl;

    return 0;
}   


// ISP Followed Explanation:// In this implementation, we have separated the TwoDimensionalShape and ThreeDimensionalShape interfaces.
// This allows us to define specific methods for two-dimensional and three-dimensional shapes without forcing all shapes to implement methods that are not applicable to them.
// The Square and Rectangle classes implement the TwoDimensionalShape interface, which only requires the area method.
// The Cube class implements the ThreeDimensionalShape interface, which requires both area and volume methods.
// This adheres to the Interface Segregation Principle (ISP) by ensuring that classes only implement methods that are relevant to them, reducing unnecessary complexity and potential runtime errors.