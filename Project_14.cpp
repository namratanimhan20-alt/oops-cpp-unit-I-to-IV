//Real-Time Application 14 : Generic Sorting Service.
//Problem Scenario : A data-processing application must sort integers, floating-point values, and strings. A function template avoids writing 
//and maintaining separate sorting functions for each type.

#include <iostream>     // Provides input and output functions such as cout and endl.
#include <string>      // Provides the string data type.
#include <vector>      // Provides the vector container.

using namespace std;    // Allows us to use cout, vector, string, and endl
                       // without writing std:: before each one.


// ------------------------------------------------------------
// Function Template: sortItems()
// ------------------------------------------------------------

// template tells the compiler that this is a generic function.
// typename T declares T as a placeholder for a data type.
//
// For example:
// T can become int
// T can become double
// T can become string
//
// vector<T>& values means:
// - vector<T> is a vector containing elements of type T.
// - & means the vector is passed by reference.
// - Passing by reference allows us to modify the original vector.
// - values is the name of the vector.
template <typename T>
void sortItems(vector<T>& values)
{
    // size_t is an unsigned integer type generally used for sizes
    // and indexes of containers.
    //
    // i = 0 means the loop starts from the first element.
    // i < values.size() means the loop continues until the last index.
    // i++ increases i by 1 after every iteration.
    for (size_t i = 0; i < values.size(); i++)
    {
        // This inner loop starts from the element after i.
        //
        // j = i + 1 means we compare the current element at i
        // with all the elements that come after it.
        for (size_t j = i + 1; j < values.size(); j++)
        {
            // Compare the element at index j with the element
            // at index i.
            //
            // If values[j] is smaller than values[i],
            // they need to be exchanged.
            //
            // The < operator works for:
            // - integers
            // - decimal numbers
            // - strings, using alphabetical/lexicographical order
            if (values[j] < values[i])
            {
                // Create a temporary variable of type T.
                //
                // It stores the value currently present at values[i]
                // before that value gets replaced.
                T temp = values[i];

                // Copy the smaller value at index j into index i.
                values[i] = values[j];

                // Copy the original value stored in temp into index j.
                //
                // This completes the swapping process.
                values[j] = temp;
            }
        }
    }
}


// ------------------------------------------------------------
// Function Template: displayItems()
// ------------------------------------------------------------

// This is another function template.
//
// const vector<T>& values means:
// - vector<T> can contain any data type.
// - & passes the vector by reference, avoiding an unnecessary copy.
// - const means the function cannot modify the vector.
// - values is the vector parameter.
template <typename T>
void displayItems(const vector<T>& values)
{
    // Range-based for loop.
    //
    // const auto& value means:
    // - const prevents modification of each element.
    // - auto allows the compiler to automatically determine the type.
    // - & means value refers to the original element instead of copying it.
    // - value represents each element of the vector one by one.
    for (const auto& value : values)
    {
        // Print the current element followed by a space.
        cout << value << " ";
    }

    // endl moves the cursor to the next line.
    cout << endl;
}


// ------------------------------------------------------------
// main() Function
// ------------------------------------------------------------

int main()
{
    // Create a vector of integers.
    //
    // vector<int> means the vector stores integer values.
    // ids is the name of the vector.
    // The values inside {} are the initial elements.
    vector<int> ids{64, 34, 25, 12, 22, 11, 90};

    // Create a vector of double values.
    //
    // double stores decimal numbers.
    vector<double> scores{3.14, 2.71, 1.41, 9.99, 0.50};

    // Create a vector of strings.
    //
    // string stores text.
    vector<string> cities{"Pune", "Mumbai", "Nashik", "Aurangabad"};


    // --------------------------------------------------------
    // Sorting the Integer Vector
    // --------------------------------------------------------

    // Display a heading before displaying the integer values.
    cout << "Integer IDs before sorting: ";

    // Call the displayItems() function template.
    //
    // The compiler automatically identifies T as int
    // because ids is a vector<int>.
    displayItems(ids);

    // Call the sortItems() function template.
    //
    // Here, T becomes int.
    // The original ids vector is sorted in ascending order.
    sortItems(ids);

    // Display a heading after sorting.
    cout << "Integer IDs after sorting: ";

    // Display the sorted integer vector.
    displayItems(ids);


    // --------------------------------------------------------
    // Sorting the Double Vector
    // --------------------------------------------------------

    // Display the scores before sorting.
    cout << "Scores before sorting: ";

    // Here, T becomes double.
    displayItems(scores);

    // Sort the scores vector in ascending order.
    sortItems(scores);

    // Display a heading after sorting.
    cout << "Scores after sorting: ";

    // Display the sorted scores.
    displayItems(scores);


    // --------------------------------------------------------
    // Sorting the String Vector
    // --------------------------------------------------------

    // Display the city names before sorting.
    cout << "Cities before sorting: ";

    // Here, T becomes string.
    displayItems(cities);

    // Sort the city names in alphabetical order.
    sortItems(cities);

    // Display a heading after sorting.
    cout << "Cities after sorting: ";

    // Display the sorted city names.
    displayItems(cities);

    // Return 0 indicates that the program executed successfully.
    return 0;
}