//Real-Time Application 10 : Student Record File System.
//Problem Scenario : A college stores student data in a CSV-like text file. The application writes records, then reads them back to produce a report. 

#include <fstream>
// <fstream>: Header file used for file handling.
// It provides ofstream and ifstream.
//
// ofstream:
// Used to write data into a file.
//
// ifstream:
// Used to read data from a file.

#include <iostream>
// <iostream>: Header file used for input and output.
// It provides cout, cerr, and endl.

#include <sstream>
// <sstream>: Header file used for string streams.
// stringstream allows us to read and separate data
// stored inside a string.

#include <string>
// <string>: Header file used for the string data type.

using namespace std;
// Allows us to use names such as cout, string,
// ofstream, ifstream, and stringstream without std::.


// Class declaration
class Student
{
private:
    // private:
    // Members under private can only be accessed
    // directly inside the Student class.

    int rollNo;
    // int: Integer data type.
    // rollNo: Stores the student's roll number.

    string name;
    // string: Stores text.
    // name: Stores the student's name.

    double marks;
    // double: Stores decimal values.
    // marks: Stores the student's marks.


public:
    // public:
    // Members under public can be accessed
    // from outside the class.


    // Default constructor
    Student() : rollNo(0), marks(0.0)
    {
    }

    /*
        Student():
        This is a default constructor.
        It has the same name as the class.

        It is called when an object is created
        without passing any arguments.

        : rollNo(0), marks(0.0):
        This is a member initializer list.

        rollNo(0):
        Initializes rollNo with 0.

        marks(0.0):
        Initializes marks with 0.0.

        name is automatically initialized as an empty string.
    */


    // Parameterized constructor
    Student(int r, string n, double m)
        : rollNo(r), name(n), marks(m)
    {
    }

    /*
        Student(int r, string n, double m):
        This is a parameterized constructor.
        It accepts three values.

        int r:
        Parameter used for the roll number.

        string n:
        Parameter used for the student's name.

        double m:
        Parameter used for the marks.

        : rollNo(r), name(n), marks(m):
        Initializes the data members.

        rollNo(r):
        Assigns r to rollNo.

        name(n):
        Assigns n to name.

        marks(m):
        Assigns m to marks.
    */


    // Function to save student data into a file
    void saveToFile(ofstream& out) const
    {
        /*
            void:
            The function does not return any value.

            saveToFile:
            Function name.

            ofstream& out:
            out is a reference to an output file stream.

            ofstream:
            Used for writing data to a file.

            &:
            Reference symbol.
            It allows the function to work with the original
            file stream instead of making a copy.

            const:
            This function does not modify the Student object.
        */

        out << rollNo << ',' << name << ',' << marks << '\n';

        /*
            out:
            Represents the file opened for writing.

            <<:
            Insertion operator.
            Sends data into the file.

            rollNo:
            Writes the student's roll number.

            ',':
            Writes a comma after the roll number.

            name:
            Writes the student's name.

            ',':
            Writes another comma after the name.

            marks:
            Writes the student's marks.

            '\n':
            Inserts a newline character.
            It moves the next record to a new line.

            Example line written to the file:

            101,Rahul Patil,85.5
        */
    }


    // Function to load student data from one line
    bool loadFromLine(const string& line)
    {
        /*
            bool:
            Return type.
            The function returns either true or false.

            loadFromLine:
            Function name.

            const string& line:
            line contains one complete line read from the file.

            const:
            The original string will not be modified.

            &:
            Passes the string by reference to avoid copying it.
        */


        string rollText;
        // Stores the roll number as text temporarily.

        string marksText;
        // Stores the marks as text temporarily.

        stringstream stream(line);
        /*
            stringstream:
            Creates a stream from the string line.

            stream:
            Name of the stringstream object.

            line:
            The line from the file is placed inside the stream.

            Example:
            line = "101,Rahul Patil,85.5"
        */


        // Read the roll number text
        if (!getline(stream, rollText, ','))
            return false;

        /*
            getline():
            Reads characters from a stream.

            stream:
            The stringstream from which data is read.

            rollText:
            Stores the data that is read.

            ',':
            Acts as a delimiter.
            Reading stops when a comma is found.

            For this line:
            "101,Rahul Patil,85.5"

            rollText receives:
            "101"

            !:
            Logical NOT operator.
            It reverses true to false and false to true.

            if (!getline(...)):
            If reading fails, return false.

            return false:
            Indicates that the line could not be loaded.
        */


        // Read the student's name
        if (!getline(stream, name, ','))
            return false;

        /*
            This getline() reads the next part of the line.

            The second field is:
            "Rahul Patil"

            name receives:
            "Rahul Patil"

            The comma is used as the delimiter again.

            If reading fails, the function returns false.
        */


        // Read the marks text
        if (!getline(stream, marksText))
            return false;

        /*
            This getline() reads the remaining part of the line.

            No delimiter is provided here.
            Therefore, it reads until the end of the line.

            marksText receives:
            "85.5"

            If reading fails, return false.
        */


        // Convert the roll number from string to integer
        rollNo = stoi(rollText);

        /*
            stoi():
            Means "string to integer".

            rollText:
            Contains the roll number as text.

            Example:
            "101" becomes 101.

            The converted integer is assigned to rollNo.
        */


        // Convert the marks from string to double
        marks = stod(marksText);

        /*
            stod():
            Means "string to double".

            marksText:
            Contains marks as text.

            Example:
            "85.5" becomes 85.5.

            The converted decimal value is assigned to marks.
        */


        return true;
        /*
            If all fields were successfully read and converted,
            return true.

            true means the line was loaded successfully.
        */
    }


    // Function to display student details
    void display() const
    {
        /*
            void:
            This function does not return a value.

            display:
            Function name.

            const:
            The function does not modify the Student object.
        */

        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks
             << endl;

        /*
            cout:
            Displays output on the screen.

            <<:
            Insertion operator used to send data to cout.

            "Roll: ":
            Displays the label Roll.

            rollNo:
            Displays the student's roll number.

            " | Name: ":
            Displays a separator and the Name label.

            name:
            Displays the student's name.

            " | Marks: ":
            Displays another separator and the Marks label.

            marks:
            Displays the student's marks.

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
        Return type of the main function.

        main():
        Program execution starts from here.
    */


    // Open a file for writing
    ofstream outFile("students.csv");

    /*
        ofstream:
        Output file stream class.
        It is used to write data into a file.

        outFile:
        Name of the file stream object.

        "students.csv":
        Name of the file to be created or opened.

        .csv:
        Means Comma-Separated Values.
        Data fields are separated using commas.

        If the file does not exist, it is usually created.
        If it already exists, its previous contents are
        overwritten by default.
    */


    // Check whether the file opened successfully
    if (!outFile)
    {
        /*
            !outFile:
            Checks whether opening the file failed.

            If the file stream is not in a valid state,
            the condition becomes true.
        */

        cerr << "Unable to open students.csv for writing."
             << endl;

        /*
            cerr:
            Standard error stream.
            It is used to display error messages.

            endl:
            Moves to the next line.
        */

        return 1;
        /*
            Ends the program with error code 1.
            A non-zero value generally indicates an error.
        */
    }


    // Create the first Student object
    Student s1(101, "Rahul Patil", 85.5);

    /*
        Student:
        Class name.

        s1:
        Object name.

        101:
        Roll number.

        "Rahul Patil":
        Student name.

        85.5:
        Student marks.

        This calls the parameterized constructor.
    */


    // Create the second Student object
    Student s2(102, "Priya Sharma", 92.0);

    /*
        s2 contains:
        Roll number: 102
        Name: Priya Sharma
        Marks: 92.0
    */


    // Create the third Student object
    Student s3(103, "Amit Kulkarni", 78.5);

    /*
        s3 contains:
        Roll number: 103
        Name: Amit Kulkarni
        Marks: 78.5
    */


    // Save the first student's data
    s1.saveToFile(outFile);
    /*
        Calls saveToFile() using s1.
        The data is written into students.csv.
    */


    // Save the second student's data
    s2.saveToFile(outFile);
    /*
        Calls saveToFile() using s2.
    */


    // Save the third student's data
    s3.saveToFile(outFile);
    /*
        Calls saveToFile() using s3.
    */


    // Close the output file
    outFile.close();

    /*
        close():
        Closes the file.

        It ensures that all pending data is written
        and releases the file resource.

        After closing, outFile is no longer used
        for writing.
    */


    // Open the same file for reading
    ifstream inFile("students.csv");

    /*
        ifstream:
        Input file stream class.
        It is used to read data from a file.

        inFile:
        Name of the input file stream object.

        "students.csv":
        File from which student records will be read.
    */


    // Check whether the input file opened successfully
    if (!inFile)
    {
        /*
            If the file cannot be opened for reading,
            this condition becomes true.
        */

        cerr << "Unable to open students.csv for reading."
             << endl;

        // Display an error message.

        return 1;
        // End the program with an error code.
    }


    // Display the report heading
    cout << "=== Student Report ===" << endl;

    /*
        cout:
        Displays text on the screen.

        "=== Student Report ===":
        Heading of the report.

        endl:
        Moves the cursor to the next line.
    */


    // Variable to store one line read from the file
    string line;

    /*
        line:
        Stores one complete line from students.csv.

        Example:
        "101,Rahul Patil,85.5"
    */


    // Read the file line by line
    while (getline(inFile, line))
    {
        /*
            while:
            Repeats a block of code while the condition is true.

            getline(inFile, line):
            Reads one complete line from the input file
            and stores it in line.

            The loop continues as long as a line is successfully read.

            When the end of the file is reached,
            getline() fails and the loop stops.
        */


        // Create an empty Student object
        Student student;

        /*
            student:
            Object of the Student class.

            Since no arguments are passed,
            the default constructor is called.

            Initially:
            rollNo = 0
            name = ""
            marks = 0.0
        */


        // Load the data from the current line
        if (student.loadFromLine(line))
        {
            /*
                student.loadFromLine(line):
                Sends the current file line to the function.

                The function:
                1. Separates the line using commas.
                2. Extracts roll number, name, and marks.
                3. Converts roll number to int.
                4. Converts marks to double.
                5. Returns true if successful.

                if:
                Checks whether the function returned true.
            */


            // Display the loaded student details
            student.display();

            /*
                Calls display() using the student object.

                It prints the student's roll number,
                name, and marks.
            */
        }
    }


    return 0;
    /*
        return 0:
        Indicates successful completion of the program.
    */
}