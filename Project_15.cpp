//Real-Time Application 15 : Template-Based Stack. 
//Problem Scenario : A compiler, text editor, or undo-redo system needs stack behavior. A template stack lets one implementation 
//support integers, strings, commands, and other types. 

#include <iostream>      // Provides input and output functions such as cout and endl.
#include <stdexcept>     // Provides standard exception classes such as
                         // invalid_argument, overflow_error, underflow_error,
                         // and exception.

#include <string>        // Provides the string data type.

using namespace std;     // Allows us to use cout, string, exception, etc.
                         // without writing std:: before them.


// ------------------------------------------------------------
// Class Template: Stack
// ------------------------------------------------------------

// template tells the compiler that this is a generic class.
//
// typename T declares T as a placeholder for a data type.
//
// T can be replaced by:
// - int
// - double
// - string
// - or another suitable data type.
template <typename T>
class Stack
{
private:

    // T* means data is a pointer to a value of type T.
    //
    // It will point to a dynamically allocated array.
    //
    // For Stack<int>, data will point to an integer array.
    // For Stack<string>, data will point to a string array.
    T* data;

    // capacity stores the maximum number of elements
    // that the stack can contain.
    int capacity;

    // topIndex stores the index of the top element in the stack.
    //
    // Initially, it is -1, which means the stack is empty.
    int topIndex;


public:

    // --------------------------------------------------------
    // Constructor
    // --------------------------------------------------------

    // explicit prevents unwanted automatic conversion
    // from an integer into a Stack object.
    //
    // Stack(int size) is the constructor.
    // It receives the stack capacity as an argument.
    //
    // : capacity(size), topIndex(-1) is an initializer list.
    //
    // capacity(size) initializes capacity with size.
    // topIndex(-1) initializes topIndex to -1.
    Stack(int size)
        : capacity(size), topIndex(-1)
    {
        // Check whether the requested stack size is invalid.
        //
        // A stack must have a positive capacity.
        if (size <= 0)
        {
            // throw is used to generate an exception.
            //
            // invalid_argument is an exception class used when
            // a function receives an invalid argument.
            //
            // The message explains the reason for the error.
            throw invalid_argument(
                "Stack capacity must be positive."
            );
        }

        // new dynamically allocates an array.
        //
        // T[capacity] creates an array containing capacity elements.
        //
        // For Stack<int> with capacity 5:
        // data = new int[5];
        //
        // For Stack<string> with capacity 3:
        // data = new string[3];
        data = new T[capacity];
    }


    // --------------------------------------------------------
    // Deleted Copy Constructor
    // --------------------------------------------------------

    // This line prevents copying one Stack object into another.
    //
    // Stack(const Stack&) means a copy constructor.
    //
    // const Stack& means the source Stack is passed by
    // constant reference.
    //
    // = delete tells the compiler not to allow copying.
    //
    // This is useful because the class manages dynamically
    // allocated memory, and copying could cause memory problems.
    Stack(const Stack&) = delete;


    // --------------------------------------------------------
    // Deleted Copy Assignment Operator
    // --------------------------------------------------------

    // This prevents assignment between two Stack objects.
    //
    // For example, the following is not allowed:
    //
    // Stack<int> stack1(5);
    // Stack<int> stack2(5);
    // stack2 = stack1;
    //
    // The = delete syntax disables this operation.
    Stack& operator=(const Stack&) = delete;


    // --------------------------------------------------------
    // Destructor
    // --------------------------------------------------------

    // The destructor is automatically called when a Stack object
    // is destroyed or goes out of scope.
    //
    // The destructor name is the class name preceded by ~.
    ~Stack()
    {
        // delete[] releases the memory allocated for an array
        // using new[].
        //
        // This prevents memory leaks.
        delete[] data;
    }


    // --------------------------------------------------------
    // push() Function
    // --------------------------------------------------------

    // push() adds a new element to the top of the stack.
    //
    // const T& value means:
    // - T is the generic data type.
    // - & passes the value by reference, avoiding an unnecessary copy.
    // - const means the original value cannot be modified.
    void push(const T& value)
    {
        // Check whether the stack is full.
        //
        // If topIndex is capacity - 1, the top element is
        // already at the last available index.
        //
        // Example:
        // capacity = 5
        // Last valid index = 4
        if (topIndex == capacity - 1)
        {
            // overflow_error is thrown when we try to add
            // an element to a full stack.
            throw overflow_error("Stack overflow.");
        }

        // First increase topIndex by 1.
        //
        // ++topIndex is the pre-increment operator.
        // It increases topIndex before using its value.
        //
        // Then store value at the new top position.
        //
        // Example:
        // If topIndex = -1, ++topIndex becomes 0.
        // The value is stored at data[0].
        data[++topIndex] = value;
    }


    // --------------------------------------------------------
    // pop() Function
    // --------------------------------------------------------

    // pop() removes and returns the top element of the stack.
    //
    // T before the function name means the function returns
    // a value of the generic type T.
    T pop()
    {
        // Check whether the stack is empty.
        //
        // If topIndex is less than 0, there is no element
        // available to remove.
        if (topIndex < 0)
        {
            // underflow_error is thrown when we try to remove
            // an element from an empty stack.
            throw underflow_error("Stack underflow.");
        }

        // Return the element at the current topIndex.
        //
        // topIndex-- is the post-decrement operator.
        //
        // It first uses the current value of topIndex,
        // then decreases topIndex by 1.
        //
        // Example:
        // If topIndex = 2:
        // data[2] is returned.
        // Afterward, topIndex becomes 1.
        return data[topIndex--];
    }


    // --------------------------------------------------------
    // isEmpty() Function
    // --------------------------------------------------------

    // const after the function parentheses means that this
    // function does not modify the Stack object.
    //
    // bool means the function returns either true or false.
    bool isEmpty() const
    {
        // If topIndex is less than 0, the stack is empty.
        //
        // The expression returns:
        // true  -> if the stack is empty
        // false -> if the stack contains at least one element
        return topIndex < 0;
    }


    // --------------------------------------------------------
    // display() Function
    // --------------------------------------------------------

    // This function displays all elements in the stack.
    //
    // const means this function does not modify the stack.
    void display() const
    {
        // Start from the top element and move toward index 0.
        //
        // int i = topIndex:
        // Start at the current top.
        //
        // i >= 0:
        // Continue while i is a valid index.
        //
        // i--:
        // Move one position downward after each iteration.
        //
        // This displays the stack from top to bottom.
        for (int i = topIndex; i >= 0; i--)
        {
            // Print the element at index i followed by a space.
            cout << data[i] << " ";
        }

        // Move the cursor to the next line.
        cout << endl;
    }
};


// ------------------------------------------------------------
// main() Function
// ------------------------------------------------------------

int main()
{
    // try block contains code that may generate exceptions.
    try
    {
        // Create a Stack object for integers.
        //
        // Stack<int> means T becomes int.
        //
        // integerStack is the object name.
        //
        // (5) means the stack can store a maximum of 5 integers.
        Stack<int> integerStack(5);

        // Add 10 to the stack.
        integerStack.push(10);

        // Add 20 to the stack.
        integerStack.push(20);

        // Add 30 to the stack.
        integerStack.push(30);

        // Display a heading.
        cout << "Integer stack: ";

        // Display the integer stack from top to bottom.
        //
        // The insertion order is:
        // 10, 20, 30
        //
        // The display order is:
        // 30, 20, 10
        integerStack.display();

        // Remove and display the top element.
        //
        // The top element is 30.
        //
        // pop() returns 30 and then moves topIndex downward.
        cout << "Popped: " << integerStack.pop() << endl;


        // ----------------------------------------------------
        // String Stack
        // ----------------------------------------------------

        // Create a Stack object for strings.
        //
        // Stack<string> means T becomes string.
        //
        // commandStack can store a maximum of 3 strings.
        Stack<string> commandStack(3);

        // Add the string "Open file" to the stack.
        commandStack.push("Open file");

        // Add the string "Edit text" to the stack.
        commandStack.push("Edit text");

        // Add the string "Save file" to the stack.
        commandStack.push("Save file");

        // Display a heading.
        cout << "Command stack: ";

        // Display the command stack from top to bottom.
        //
        // The output order will be:
        // Save file, Edit text, Open file
        commandStack.display();
    }

    // --------------------------------------------------------
    // Exception Handling
    // --------------------------------------------------------

    // catch catches an exception thrown inside the try block.
    //
    // const exception& error means:
    // - exception is the base class for standard exceptions.
    // - & receives the exception by reference.
    // - const prevents modification of the exception.
    // - error is the name used to access the exception.
    catch (const exception& error)
    {
        // error.what() returns the error message.
        //
        // The message is printed after "Error: ".
        cout << "Error: " << error.what() << endl;
    }

    // Return 0 means the program executed successfully.
    return 0;
}