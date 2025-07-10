#include<bits/stdc++.h>
using namespace std;

// Single Interface Segregation Principle (ISP) Violation Example: A class that violates the Interface Segregation Principle (ISP)
// Single interface for all shapes

class Shape {
    public:
    virtual double area() = 0; // Calculate area
    virtual double volume() = 0; // Calculate perimeter
};

class Square: public Shape {
    double side;
    public:
    // Constructor to initialize side length
    Square(double s) : side(s) {}
    // Override area method to calculate area of square
    // Override volume method to throw an error since square does not have volume
    double area() override {
        return side * side; // Area of square
    }
    
    double volume() override {
        throw runtime_error("Square does not have volume"); // Not applicable for square
    }
};

class Rectangle: public Shape {
    double length, width;
    public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}
    // Override area method to calculate area of rectangle
    // Override volume method to throw an error since rectangle does not have volume
    double area() override {
        return length * width; // Area of rectangle
    }
    
    double volume() override {
        throw runtime_error("Rectangle does not have volume"); // Not applicable for rectangle
    }
};

class Cube: public Shape {
    double side;
    public:
    // Constructor to initialize side length
    Cube(double s) : side(s) {}
    // Override area method to calculate area of cube
    // Override volume method to calculate volume of cube
    double area() override {
        return 6 * side * side; // Surface area of cube
    }
    
    double volume() override {
        return side * side * side; // Volume of cube
    }
};


int main() {
    try {
        Shape* square = new Square(5);
        cout << "Square Area: " << square->area() << endl;
        cout << "Square Volume: " << square->volume() << endl; // This will throw an error

        Shape* rectangle = new Rectangle(4, 6);
        cout << "Rectangle Area: " << rectangle->area() << endl;
        cout << "Rectangle Volume: " << rectangle->volume() << endl; // This will throw an error

        Shape* cube = new Cube(3);
        cout << "Cube Area: " << cube->area() << endl;
        cout << "Cube Volume: " << cube->volume() << endl;

        delete square;
        delete rectangle;
        delete cube;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl; // Catch and print the error message
    }
    
    return 0;
}



// ISP Violation Explanation:
// The Shape interface violates the Interface Segregation Principle (ISP) because it forces all shapes to implement both area and volume methods.
// This is not appropriate for shapes like Square and Rectangle, which do not have a volume.
// Here Every Sub Class has to override both thr methods, even if they are not applicable.
// This leads to unnecessary complexity and potential runtime errors.