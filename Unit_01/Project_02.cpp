//Real-Time Application 2: Student Attendance Management System 
//Problem Scenario : An educational institution needs to track the attendance of students. Each student has a roll number, name, total classes, 
//and attended classes. The system calculates the attendance percentage automatically. 

// Include the input-output stream library.
// It provides cout and endl for displaying output.
#include <iostream>

// Include the string library.
// It allows us to use the string data type.
#include <string>

// Allows us to use cout, string, etc.
// without writing std:: before them.
using namespace std;


// Define a class named Student.
// A class is a blueprint for creating Student objects.
class Student {

private:
    // Private data members.
    // These store the information of each student.

    int rollNo;
    // Stores the roll number of the student.
    // Example: 101

    string name;
    // Stores the name of the student.
    // Example: "Rahul"

    int totalDays;
    // Stores the total number of days
    // for which attendance has been marked.

    int presentDays;
    // Stores the number of days
    // on which the student was present.


public:
    // Public members can be accessed through
    // the object's public functions.


    // Constructor of the Student class.
    // It is called automatically when an object is created.
    //
    // int r       -> receives the roll number
    // string n    -> receives the student's name
    Student(int r, string n)

        // Member initializer list.
        // It initializes the data members
        // using the values passed to the constructor.
        : rollNo(r),
          name(n),
          totalDays(0),
          presentDays(0)
    {
        // Constructor body.
        // It is empty because the members
        // are initialized above.
    }


    // Function to mark attendance.
    // bool isPresent can store either true or false.
    //
    // true  -> student is present
    // false -> student is absent
    void markAttendance(bool isPresent)
    {
        // Increase the total number of days by 1.
        // Every time attendance is marked,
        // one more day is added.
        totalDays++;


        // Check whether the student is present.
        if (isPresent)
        {
            // If isPresent is true,
            // increase the present days by 1.
            presentDays++;
        }
    }


    // Function to calculate attendance percentage.
    // double means the function returns a decimal value.
    //
    // const means this function does not modify
    // the Student object's data.
    double getAttendancePercentage() const
    {
        // Check whether attendance has been marked
        // for at least one day.
        if (totalDays == 0)
        {
            // If no attendance is recorded,
            // return 0.0% to avoid division by zero.
            return 0.0;
        }


        // Calculate attendance percentage.
        //
        // presentDays * 100.0 -> converts the calculation
        // into a decimal calculation.
        //
        // Divide by totalDays to get the percentage.
        return (presentDays * 100.0) / totalDays;
    }


    // Function to display the student's details.
    // const means this function does not modify the object.
    void display() const
    {
        // Display the roll number.
        cout << "Roll: " << rollNo

             // Display a separator and the student's name.
             << " | Name: " << name

             // Call getAttendancePercentage()
             // to calculate and display attendance.
             << " | Attendance: "
             << getAttendancePercentage()
             << "%"

             // Move to the next line.
             << endl;
    }
};


// Program execution starts from main().
int main()
{
    // Create the first Student object.
    //
    // 101      -> roll number
    // "Rahul"  -> student name
    //
    // The constructor initializes:
    // rollNo = 101
    // name = "Rahul"
    // totalDays = 0
    // presentDays = 0
    Student s1(101, "Rahul");


    // Create the second Student object.
    //
    // 102      -> roll number
    // "Priya"  -> student name
    Student s2(102, "Priya");


    // Mark Rahul as present.
    // totalDays = 1
    // presentDays = 1
    s1.markAttendance(true);


    // Mark Rahul as present again.
    // totalDays = 2
    // presentDays = 2
    s1.markAttendance(true);


    // Mark Rahul as absent.
    // totalDays = 3
    // presentDays remains 2
    s1.markAttendance(false);


    // Mark Priya as present.
    // totalDays = 1
    // presentDays = 1
    s2.markAttendance(true);


    // Mark Priya as present again.
    // totalDays = 2
    // presentDays = 2
    s2.markAttendance(true);


    // Mark Priya as present again.
    // totalDays = 3
    // presentDays = 3
    s2.markAttendance(true);


    // Display Rahul's details and attendance percentage.
    s1.display();


    // Display Priya's details and attendance percentage.
    s2.display();


    // Return 0 indicates successful program execution.
    return 0;
}