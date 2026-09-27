//Real-Time Application 2 : Complex Number Calculator 
//Problem Scenario : Engineering, signal processing, and simulation applications use complex numbers. Operator overloading allows arithmetic 
//expressions to be written naturally. 

#include <iostream> 
// #include: Preprocessor directive used to include a library.
// <iostream>: Header file that provides input and output features.
// It allows us to use cout and endl.

using namespace std;
// using: Keyword used to introduce something.
// namespace: A container that holds names.
// std: Standard C++ namespace.
// This line allows us to write cout instead of std::cout.


// Class declaration
class Complex
{
private:
    // private: Access specifier.
    // Members declared under private can only be accessed
    // directly inside the class.

    double real;
    // double: Data type used to store decimal numbers.
    // real: Variable that stores the real part of a complex number.

    double imag;
    // imag: Variable that stores the imaginary part
    // of a complex number.

public:
    // public: Access specifier.
    // Members declared under public can be accessed
    // from outside the class.

    
    // Constructor
    Complex(double r = 0.0, double i = 0.0)
        : real(r), imag(i)
    {
    }
    /*
        Complex: Constructor name, same as the class name.

        double r = 0.0:
        Parameter r stores the real part.
        If no value is provided, r gets the default value 0.0.

        double i = 0.0:
        Parameter i stores the imaginary part.
        If no value is provided, i gets the default value 0.0.

        : real(r), imag(i):
        This is called a member initializer list.

        real(r):
        Initializes the data member real with the value of r.

        imag(i):
        Initializes the data member imag with the value of i.

        The constructor body is empty because the values
        are initialized using the initializer list.
    */


    // Operator overloading for addition (+)
    Complex operator+(const Complex& other) const
    {
        /*
            Complex:
            The function returns an object of type Complex.

            operator+:
            This function overloads the + operator.

            It allows us to add two Complex objects using:
                c1 + c2

            const Complex& other:
            other is the second Complex object.

            const:
            The function promises not to modify the other object.

            &:
            Reference symbol.
            It avoids making an unnecessary copy of the object.

            const at the end:
            It promises that this function will not modify
            the current object.
        */

        return Complex(real + other.real, imag + other.imag);
        /*
            return:
            Sends a value back to the place where the function
            was called.

            Complex(...):
            Creates and returns a new Complex object.

            real + other.real:
            Adds the real parts of the two complex numbers.

            imag + other.imag:
            Adds the imaginary parts of the two complex numbers.

            Formula:
            (a + bi) + (c + di)
            = (a + c) + (b + d)i
        */
    }


    // Operator overloading for subtraction (-)
    Complex operator-(const Complex& other) const
    {
        /*
            operator-:
            Overloads the minus operator.

            It allows us to subtract two Complex objects using:
                c1 - c2
        */

        return Complex(real - other.real, imag - other.imag);
        /*
            real - other.real:
            Subtracts the real parts.

            imag - other.imag:
            Subtracts the imaginary parts.

            Formula:
            (a + bi) - (c + di)
            = (a - c) + (b - d)i
        */
    }


    // Operator overloading for multiplication (*)
    Complex operator*(const Complex& other) const
    {
        /*
            operator*:
            Overloads the multiplication operator.

            It allows us to multiply two Complex objects using:
                c1 * c2
        */

        return Complex(
            real * other.real - imag * other.imag,
            // Calculates the real part of the product.

            real * other.imag + imag * other.real
            // Calculates the imaginary part of the product.
        );

        /*
            Formula for multiplication:

            (a + bi)(c + di)

            = ac + adi + bci + bdi²

            Since i² = -1:

            = (ac - bd) + (ad + bc)i

            Therefore:

            Real part      = ac - bd
            Imaginary part = ad + bc
        */
    }


    // Operator overloading for equality comparison (==)
    bool operator==(const Complex& other) const
    {
        /*
            bool:
            Return type that can store either true or false.

            operator==:
            Overloads the equality operator.

            It allows us to compare two Complex objects using:
                c1 == c2
        */

        return real == other.real && imag == other.imag;
        /*
            real == other.real:
            Checks whether both real parts are equal.

            imag == other.imag:
            Checks whether both imaginary parts are equal.

            &&:
            Logical AND operator.
            It returns true only when both conditions are true.

            The two complex numbers are equal only if:
            1. Their real parts are equal.
            2. Their imaginary parts are equal.
        */
    }


    // Function to display a complex number
    void display() const
    {
        /*
            void:
            Means the function does not return any value.

            display:
            Name of the function.

            const:
            This function does not modify the object.
        */

        cout << real << " + " << imag << "i" << endl;
        /*
            cout:
            Used to display output on the screen.

            <<:
            Insertion operator.
            It sends data to cout.

            real:
            Displays the real part.

            " + ":
            Displays the plus sign and spaces.

            imag:
            Displays the imaginary part.

            "i":
            Represents the imaginary unit.

            endl:
            Moves the cursor to the next line.
        */
    }
};


// Main function
int main()
{
    /*
        int:
        Return type of main.
        It returns an integer value to the operating system.

        main():
        The execution of the C++ program starts here.
    */


    // Creating the first Complex object
    Complex c1(3.0, 4.0);
    /*
        Complex:
        Class name.

        c1:
        Object name.

        3.0:
        Value assigned to the real part.

        4.0:
        Value assigned to the imaginary part.

        Therefore:
        c1 = 3 + 4i
    */


    // Creating the second Complex object
    Complex c2(1.0, 2.0);
    /*
        c2 = 1 + 2i
    */


    // Displaying the first complex number
    cout << "C1: ";
    // Prints the text "C1: ".

    c1.display();
    // Calls the display() function using object c1.
    // Output: 3 + 4i


    // Displaying the second complex number
    cout << "C2: ";
    // Prints the text "C2: ".

    c2.display();
    // Calls display() using object c2.
    // Output: 1 + 2i


    // Addition of two complex numbers
    cout << "Sum: ";
    // Prints the label "Sum: ".

    (c1 + c2).display();
    /*
        c1 + c2:
        Calls the overloaded operator+ function.

        Calculation:
        c1 = 3 + 4i
        c2 = 1 + 2i

        Sum:
        (3 + 1) + (4 + 2)i
        = 4 + 6i

        (c1 + c2):
        Produces a temporary Complex object.

        .display():
        Calls display() on that temporary object.
    */


    // Subtraction of two complex numbers
    cout << "Difference: ";
    // Prints the label "Difference: ".

    (c1 - c2).display();
    /*
        c1 - c2:
        Calls the overloaded operator- function.

        Calculation:
        (3 - 1) + (4 - 2)i
        = 2 + 2i
    */


    // Multiplication of two complex numbers
    cout << "Product: ";
    // Prints the label "Product: ".

    (c1 * c2).display();
    /*
        c1 * c2:
        Calls the overloaded operator* function.

        Calculation:

        (3 + 4i)(1 + 2i)

        Real part:
        (3 × 1) - (4 × 2)
        = 3 - 8
        = -5

        Imaginary part:
        (3 × 2) + (4 × 1)
        = 6 + 4
        = 10

        Product:
        -5 + 10i
    */


    return 0;
    /*
        return:
        Sends a value back from the main function.

        0:
        Indicates that the program executed successfully.
    */
}