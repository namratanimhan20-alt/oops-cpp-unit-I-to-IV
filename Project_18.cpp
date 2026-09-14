//Real-Time Application 18: Student Grade Analytics 
//Problem Scenario : An academic analytics tool calculates average, minimum, maximum, unique marks, top performers, and grade distribution. 

// Includes the algorithm library.
// Provides min_element(), max_element(), and sort().
#include <algorithm>

// Includes the input-output library.
// Provides cout and endl.
#include <iostream>

// Includes the map container.
// Stores data as key-value pairs.
#include <map>

// Includes the numeric library.
// Provides accumulate() for calculating the total.
#include <numeric>

// Includes the queue library.
// Provides priority_queue().
#include <queue>

// Includes the set container.
// Stores unique elements in sorted order.
#include <set>

// Includes the vector container.
// Stores multiple elements in a sequence.
#include <vector>

// Allows us to use cout, vector, map, etc.
// without writing std:: before each name.
using namespace std;


// The main() function is the starting point of execution.
int main() {

    // Creates a vector named marks.
    // It stores the marks of students as double values.
    vector<double> marks{
        85.5, 92.0, 78.5, 88.0,
        95.5, 72.0, 89.5, 91.0
    };


    // accumulate() calculates the sum of all marks.
    //
    // marks.begin() = iterator pointing to the first mark.
    // marks.end()   = iterator pointing just after the last mark.
    // 0.0           = initial value of the total.
    //
    // The result is stored in the double variable total.
    double total = accumulate(
        marks.begin(),
        marks.end(),
        0.0
    );


    // Calculates the average.
    // marks.size() gives the number of elements in the vector.
    double average = total / marks.size();


    // Prints the average marks.
    cout << "Average: " << average << endl;


    // min_element() finds the smallest mark.
    // It returns an iterator pointing to that mark.
    // The * operator gets the actual value from the iterator.
    cout << "Minimum: "
         << *min_element(marks.begin(), marks.end())
         << endl;


    // max_element() finds the largest mark.
    // The * operator gets the actual value from the iterator.
    cout << "Maximum: "
         << *max_element(marks.begin(), marks.end())
         << endl;


    // Sorts the marks in ascending order.
    // Ascending means smallest to largest.
    sort(marks.begin(), marks.end());


    // Prints a heading.
    // \n inserts a new line before the heading.
    cout << "\nMarks in ascending order: ";


    // Range-based for loop.
    // It visits every mark in the vector.
    // double mark stores the current mark.
    for (double mark : marks) {

        // Prints the current mark followed by a space.
        cout << mark << " ";

    } // End of for loop.


    // Moves the cursor to the next line.
    cout << endl;



    // Creates a max-heap priority queue named topPerformers.
    //
    // priority_queue<double> stores double values.
    // By default, the largest value has the highest priority.
    //
    // marks.begin() and marks.end() insert all marks
    // from the vector into the priority queue.
    priority_queue<double> topPerformers(
        marks.begin(),
        marks.end()
    );


    // Prints the heading for the top three marks.
    cout << "\nTop three marks:" << endl;


    // Loop to print the top three marks.
    //
    // int i = 0       -> starts the counter at 0.
    // i < 3           -> allows at most 3 iterations.
    // !topPerformers.empty()
    //                   -> checks that the queue is not empty.
    //
    // The && operator means BOTH conditions must be true.
    for (
        int i = 0;
        i < 3 && !topPerformers.empty();
        i++
    ) {

        // top() returns the largest element in the priority queue.
        cout << topPerformers.top() << endl;

        // pop() removes the largest element.
        // This allows the next-highest mark to become the top.
        topPerformers.pop();

    } // End of top-three loop.



    // Creates a set named uniqueMarks.
    //
    // A set stores only unique values.
    // Duplicate values are automatically removed.
    // Set elements are stored in sorted order.
    //
    // The constructor inserts all marks from the vector.
    set<double> uniqueMarks(
        marks.begin(),
        marks.end()
    );


    // Prints the heading for unique marks.
    cout << "\nUnique marks: ";


    // Loops through every element in the set.
    // Since it is a set, each value appears only once.
    for (double mark : uniqueMarks) {

        // Prints the unique mark followed by a space.
        cout << mark << " ";

    } // End of unique marks loop.


    // Moves the cursor to the next line.
    cout << endl;



    // Creates a map named gradeDistribution.
    //
    // char  = key type, used for grades such as 'A', 'B', 'C', 'D'.
    // int   = value type, used to store the count of each grade.
    //
    // Example:
    // 'A' -> 3
    // 'B' -> 2
    map<char, int> gradeDistribution;


    // Loops through every mark in the vector.
    for (double mark : marks) {

        // Checks whether the mark is 90 or above.
        if (mark >= 90)

            // Increases the count of grade A by 1.
            gradeDistribution['A']++;


        // If the first condition is false,
        // checks whether the mark is 80 or above.
        else if (mark >= 80)

            // Increases the count of grade B by 1.
            gradeDistribution['B']++;


        // If the previous conditions are false,
        // checks whether the mark is 70 or above.
        else if (mark >= 70)

            // Increases the count of grade C by 1.
            gradeDistribution['C']++;


        // If none of the above conditions are true,
        // the mark is below 70.
        else

            // Increases the count of grade D by 1.
            gradeDistribution['D']++;

    } // End of grade calculation loop.



    // Prints the heading for grade distribution.
    cout << "\nGrade distribution:" << endl;


    // Loops through each key-value pair in the map.
    // item.first  = grade letter.
    // item.second = number of students with that grade.
    for (const auto& item : gradeDistribution) {

        // Prints the grade and its count.
        cout << item.first
             << " : "
             << item.second
             << endl;

    } // End of grade distribution loop.


    // Indicates that the program finished successfully.
    return 0;

} // End of main().