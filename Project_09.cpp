//Real-Time Application 9 : Input Validation Service 
//Problem Scenario : A business application validates different kinds of user data, including marks, names, and payment amounts. 
//Function overloading offers a common, readable validate() interface.

#include <cctype>
// <cctype>: Header file that provides character-related functions.
// isalpha() is available through this header.
// isalpha() checks whether a character is an alphabetic letter.

#include <iostream>
// <iostream>: Header file used for input and output.
// It provides cout and endl.

#include <string>
// <string>: Header file used to work with the string data type.

using namespace std;
// using namespace std:
// Allows us to use standard library names such as
// cout, endl, and string without writing std:: before them.


// Class declaration
class Validator
{
public:
    // public:
    // Access specifier.
    // Functions declared under public can be called
    // from outside the class.


    // Function 1: Validate marks
    bool validate(int marks) const
    {
        /*
            bool:
            Return type of the function.
            It can return either true or false.

            validate:
            Function name.

            int marks:
            The function accepts an integer parameter named marks.
            It is used to store marks obtained by a student.

            const:
            Means this function will not modify the Validator object.
        */

        return marks >= 0 && marks <= 100;
        /*
            return:
            Sends the result back to the calling statement.

            marks >= 0:
            Checks whether marks are greater than or equal to 0.

            marks <= 100:
            Checks whether marks are less than or equal to 100.

            &&:
            Logical AND operator.
            Both conditions must be true.

            Valid marks must be between 0 and 100, including
            both 0 and 100.

            Examples:
            88  -> true
            120 -> false
            -5  -> false
        */
    }


    // Function 2: Validate amount
    bool validate(double amount) const
    {
        /*
            This is another validate() function.

            double amount:
            Accepts a decimal number representing an amount.

            This function checks whether the amount is:
            Greater than 0
            AND less than or equal to 1,000,000
        */

        return amount > 0.0 && amount <= 1000000.0;
        /*
            amount > 0.0:
            Checks that the amount is greater than zero.

            amount <= 1000000.0:
            Checks that the amount is at most one million.

            &&:
            Both conditions must be true.

            Examples:
            4500.50 -> true
            0.0     -> false
            1500000 -> false
        */
    }


    // Function 3: Validate name
    bool validate(const string& name) const
    {
        /*
            const string& name:

            string:
            Data type used to store text.

            name:
            Parameter that stores the name entered by the user.

            &:
            Reference symbol.
            It avoids making a separate copy of the string.

            const:
            The function cannot modify the original string.

            This function checks whether the name:
            1. Is not empty.
            2. Contains only alphabets and spaces.
        */


        // Check whether the name is empty
        if (name.empty())
        {
            /*
                if:
                Conditional statement.

                name.empty():
                Checks whether the string contains no characters.

                If the name is empty, the function returns false.
            */

            return false;
            // false means the name is invalid.
        }


        // Loop through every character in the name
        for (char ch : name)
        {
            /*
                for:
                Looping statement.

                char ch:
                ch is a character variable.
                It stores one character at a time.

                :
                This is used in a range-based for loop.

                name:
                The loop visits every character present in name.

                Example:
                For "Priya Sharma", ch will contain:
                'P', 'r', 'i', 'y', 'a', ' ',
                'S', 'h', 'a', 'r', 'm', 'a'
            */


            // Check whether the character is invalid
            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
            {
                /*
                    isalpha():
                    Checks whether a character is an alphabetic letter.

                    static_cast<unsigned char>(ch):
                    Converts ch into unsigned char before passing it
                    to isalpha().
                    This is a safe way to use character-checking functions.

                    !:
                    Logical NOT operator.
                    It reverses the result.

                    !isalpha(...):
                    Means the character is NOT an alphabet.

                    ch != ' ':
                    Checks whether ch is not a space.

                    &&:
                    Logical AND operator.

                    Complete condition:
                    The character is invalid if:
                    1. It is not an alphabet.
                    2. It is also not a space.

                    Therefore, digits and special characters are rejected.

                    Examples of invalid characters:
                    1
                    2
                    @
                    #
                    _
                */

                return false;
                // Immediately returns false because the name is invalid.
            }
        }


        return true;
        /*
            If the loop finishes without finding an invalid character,
            the name contains only alphabets and spaces.

            true means the name is valid.
        */
    }
};


// Main function
int main()
{
    /*
        int:
        Return type of the main function.

        main():
        The program execution starts from this function.
    */


    // Create an object of the Validator class
    Validator validator;
    /*
        Validator:
        Class name.

        validator:
        Object name.

        This object is used to call the validate() functions.
    */


    // Display Boolean values as true or false
    cout << boolalpha;
    /*
        cout:
        Used to display output.

        <<:
        Insertion operator.

        boolalpha:
        A stream manipulator.
        It makes Boolean values appear as:
            true
            false

        Without boolalpha:
            true  would be displayed as 1
            false would be displayed as 0
    */


    // Validate marks: 88
    cout << "Marks 88 valid: "
         << validator.validate(88)
         << endl;
    /*
        "Marks 88 valid: ":
        Displays the label.

        validator.validate(88):
        Calls the validate() function that accepts int,
        because 88 is an integer.

        The selected function is:

            bool validate(int marks) const

        88 is between 0 and 100, so the result is true.

        endl:
        Moves the cursor to the next line.
    */


    // Validate marks: 120
    cout << "Marks 120 valid: "
         << validator.validate(120)
         << endl;
    /*
        validator.validate(120):
        Calls validate(int marks).

        120 is greater than 100.
        Therefore, the result is false.
    */


    // Validate amount: 4500.50
    cout << "Amount 4500.50 valid: "
         << validator.validate(4500.50)
         << endl;
    /*
        4500.50 is a decimal value, so the compiler calls:

            bool validate(double amount) const

        4500.50 is greater than 0
        and less than or equal to 1,000,000.

        Therefore, the result is true.
    */


    // Validate a valid name
    cout << "Name Priya Sharma valid: "
         << validator.validate(string("Priya Sharma"))
         << endl;
    /*
        string("Priya Sharma"):
        Creates a string object containing "Priya Sharma".

        The compiler calls:

            bool validate(const string& name) const

        The name contains only alphabets and a space.
        Therefore, the result is true.
    */


    // Validate an invalid name
    cout << "Name Priya123 valid: "
         << validator.validate(string("Priya123"))
         << endl;
    /*
        string("Priya123"):
        Creates a string object containing "Priya123".

        The name contains the digits 1, 2, and 3.

        Digits are neither alphabets nor spaces.
        Therefore, the function returns false.
    */


    return 0;
    /*
        return 0:
        Indicates that the program ended successfully.
    */
}