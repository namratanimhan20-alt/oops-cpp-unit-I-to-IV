//Real-Time Application 7: CAD Shape Drawing System 
//Problem Scenario : A computer-aided design application handles circles, rectangles, and triangles. Each shape is drawn and its area is 
//calculated through a common base-class interface

// Include the input-output stream library.
// It provides cout and endl for displaying output.
#include <iostream>

// Include the memory library.
// It provides unique_ptr and make_unique().
#include <memory>

// Include the vector library.
// It allows us to store multiple shape objects.
#include <vector>

// Allows us to use cout, vector, etc.
// without writing std:: before them.
using namespace std;

// BASE CLASS: Shape

// Define a class named Shape.
// This is the base class for different shapes.
class Shape {

public:
    // Public members can be accessed from outside
    // the class through objects or pointers.


    // Pure virtual function to calculate area.
    //
    // virtual -> Allows derived classes to provide
    //            their own implementation.
    //
    // double -> The function returns a decimal value.
    //
    // area() -> Function name.
    //
    // const -> The function does not modify the object.
    //
    // = 0 -> Makes this a pure virtual function.
    //        Therefore, Shape is an abstract class.
    virtual double area() const = 0;


    // Pure virtual function to draw the shape.
    //
    // void -> The function does not return a value.
    //
    // draw() -> Function name.
    //
    // const -> The function does not modify the object.
    //
    // = 0 -> Makes this a pure virtual function.
    virtual void draw() const = 0;


    // Virtual destructor.
    //
    // It ensures proper destruction of derived objects
    // through a base-class pointer.
    //
    // = default -> Uses the compiler-generated destructor.
    virtual ~Shape() = default;
};

// DERIVED CLASS: Circle

// Circle inherits publicly from Shape.
class Circle : public Shape {

private:
    // Stores the radius of the circle.
    double radius;


public:
    // Constructor of Circle.
    //
    // explicit prevents unwanted implicit conversion
    // from a double to a Circle object.
    //
    // Example:
    // Circle c(5.0);  // Allowed
    // Circle c = 5.0; // Prevented because of explicit
    explicit Circle(double r)

        // Member initializer list.
        // Initializes radius using r.
        : radius(r)
    {
        // Constructor body is empty because
        // radius is initialized above.
    }


    // Override the pure virtual area() function
    // declared in the Shape class.
    //
    // override confirms that this function
    // replaces the base-class virtual function.
    double area() const override
    {
        // Formula for the area of a circle:
        // π × radius × radius
        //
        // 3.14159265359 is an approximate value of π.
        return 3.14159265359 * radius * radius;
    }


    // Override the pure virtual draw() function.
    void draw() const override
    {
        // Display the radius of the circle.
        cout << "Drawing circle with radius "
             << radius
             << endl;
    }
};

// DERIVED CLASS: Rectangle

// Rectangle inherits publicly from Shape.
class Rectangle : public Shape {

private:
    // Stores the length of the rectangle.
    double length;

    // Stores the width of the rectangle.
    double width;


public:
    // Constructor of Rectangle.
    //
    // l -> length
    // w -> width
    Rectangle(double l, double w)

        // Initialize length and width.
        : length(l),
          width(w)
    {
        // Constructor body.
    }


    // Override the area() function.
    double area() const override
    {
        // Formula for rectangle area:
        // length × width
        return length * width;
    }


    // Override the draw() function.
    void draw() const override
    {
        // Display the rectangle's dimensions.
        cout << "Drawing rectangle "
             << length
             << " x "
             << width
             << endl;
    }
};


// DERIVED CLASS: Triangle

// Triangle inherits publicly from Shape.
class Triangle : public Shape {

private:
    // Stores the base of the triangle.
    double base;

    // Stores the height of the triangle.
    double height;


public:
    // Constructor of Triangle.
    //
    // b -> base
    // h -> height
    Triangle(double b, double h)

        // Initialize base and height.
        : base(b),
          height(h)
    {
        // Constructor body.
    }


    // Override the area() function.
    double area() const override
    {
        // Formula for triangle area:
        // 1/2 × base × height
        //
        // 0.5 is used instead of 1/2
        // because 1/2 with integers would give 0.
        return 0.5 * base * height;
    }


    // Override the draw() function.
    void draw() const override
    {
        // Display the triangle's dimensions.
        cout << "Drawing triangle with base "
             << base
             << " and height "
             << height
             << endl;
    }
};

// MAIN FUNCTION

// Program execution starts from main().
int main()
{
    // Create a vector named shapes.
    //
    // unique_ptr<Shape> means each element
    // is a smart pointer that owns one Shape object.
    //
    // The vector can store objects of derived classes
    // such as Circle, Rectangle, and Triangle
    // through base-class pointers.
    vector<unique_ptr<Shape>> shapes;


    // Create a Circle object dynamically
    // and add it to the shapes vector.
    //
    // 5.0 -> radius
    shapes.push_back(
        make_unique<Circle>(5.0)
    );


    // Create a Rectangle object dynamically
    // and add it to the shapes vector.
    //
    // 4.0 -> length
    // 6.0 -> width
    shapes.push_back(
        make_unique<Rectangle>(4.0, 6.0)
    );


    // Create a Triangle object dynamically
    // and add it to the shapes vector.
    //
    // 3.0 -> base
    // 8.0 -> height
    shapes.push_back(
        make_unique<Triangle>(3.0, 8.0)
    );


    // Display the heading.
    cout << "=== CAD Shape System ===" << endl;


    // Range-based for loop.
    //
    // const -> We will not modify the unique_ptr
    //          while accessing it.
    //
    // auto -> Automatically determines the variable type.
    //
    // & -> shape refers to the existing unique_ptr
    //      instead of making a copy.
    for (const auto& shape : shapes)
    {
        // -> is the arrow operator.
        //
        // shape is a unique_ptr.
        // shape->draw() calls the draw() function
        // of the object managed by the pointer.
        //
        // Because draw() is virtual,
        // the correct derived-class version is called.
        shape->draw();


        // Call the area() function through the pointer.
        //
        // Because area() is virtual,
        // the appropriate derived-class implementation
        // is selected at runtime.
        cout << "Area: "
             << shape->area()
             << " square units"
             << endl;
    }


    // Return 0 indicates successful program execution.
    //
    // When main() ends, unique_ptr automatically
    // destroys the objects it owns.
    return 0;
}