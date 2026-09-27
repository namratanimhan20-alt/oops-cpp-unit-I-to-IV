//Real-Time Application 2 : Server Log Analyzer 
//Problem Scenario : A DevOps monitoring tool reads a server log and lists error and critical messages. This helps developers find system failures quickly. 

#include <fstream>
// #include:
// Preprocessor directive used to include a library.

// <fstream>:
// Header file used for file handling.

// It provides:
// ofstream -> used for writing into a file.
// ifstream -> used for reading from a file.

#include <iostream>
// <iostream>:
// Header file used for input and output.

// It provides:
// cout  -> displays normal output.
// cerr  -> displays error messages.
// endl  -> moves the cursor to the next line.

#include <string>
// <string>:
// Header file used to work with the string data type.

#include <vector>
// <vector>:
// Header file used to work with the vector container.

// A vector stores multiple values dynamically.

using namespace std;
// using namespace std:
// Allows us to use standard library names such as
// string, vector, cout, ofstream, and ifstream
// without writing std:: before each name.


// Structure declaration
struct LogEntry
{
    // struct:
// Keyword used to create a structure.

// A structure is a user-defined data type
// that groups related variables together.

    string line;
    // string:
// Data type used to store text.

    // line:
// Variable that stores one complete log entry.
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
    ofstream sampleLog("server.log");

    /*
        ofstream:
        Output file stream class.
        It is used to write data into a file.

        sampleLog:
        Name of the file stream object.

        "server.log":
        Name of the file that will be created or opened.

        If server.log does not exist, it will be created.

        If it already exists, its previous contents
        are overwritten by default.
    */


    // Check whether the file was opened successfully
    if (!sampleLog)
    {
        /*
            if:
            Conditional statement.

            !sampleLog:
            Checks whether the file stream is not valid.

            !:
            Logical NOT operator.
            It reverses the condition.

            If the file could not be created or opened,
            the condition becomes true.
        */

        cerr << "Unable to create log file." << endl;

        /*
            cerr:
            Standard error stream.
            It is used to display error messages.

            <<:
            Insertion operator.
            Sends text to cerr.

            "Unable to create log file.":
            Error message.

            endl:
            Moves the cursor to the next line.
        */

        return 1;
        /*
            return 1:
            Ends the program and returns 1.

            A non-zero return value generally indicates
            that an error occurred.
        */
    }


    // Write the first log entry into the file
    sampleLog << "2026-09-09 08:00:00 INFO Server started\n";

    /*
        sampleLog:
        Represents the file opened for writing.

        <<:
        Insertion operator.
        Sends data into the file.

        "2026-09-09":
        Date of the log entry.

        "08:00:00":
        Time of the log entry.

        "INFO":
        Log level.
        It indicates a normal information message.

        "Server started":
        Description of the event.

        \n:
        Newline escape sequence.
        It moves the next log entry to a new line.
    */


    // Write the second log entry
    sampleLog << "2026-09-09 08:10:00 WARNING High memory usage\n";

    /*
        WARNING:
        Log level indicating a possible problem.

        High memory usage:
        Description of the warning event.
    */


    // Write the third log entry
    sampleLog << "2026-09-09 08:20:00 ERROR Database connection failed\n";

    /*
        ERROR:
        Log level indicating that an error occurred.

        Database connection failed:
        Description of the error event.
    */


    // Write the fourth log entry
    sampleLog << "2026-09-09 08:30:00 INFO Backup completed\n";

    /*
        INFO:
        Indicates a normal informational message.

        Backup completed:
        Description of the event.
    */


    // Write the fifth log entry
    sampleLog << "2026-09-09 08:40:00 CRITICAL Disk space low\n";

    /*
        CRITICAL:
        Log level indicating a serious or critical problem.

        Disk space low:
        Description of the critical event.
    */


    // Close the file after writing
    sampleLog.close();

    /*
        close():
        Closes the file.

        It ensures that pending data is written
        and releases the file resource.

        After this line, sampleLog is no longer
        used for writing.
    */


    // Open the log file for reading
    ifstream logFile("server.log");

    /*
        ifstream:
        Input file stream class.
        It is used to read data from a file.

        logFile:
        Name of the input file stream object.

        "server.log":
        File from which the log entries will be read.
    */


    // Check whether the file was opened successfully
    if (!logFile)
    {
        /*
            !logFile:
            Checks whether the file could not be opened
            for reading.
        */

        cerr << "Unable to open server.log." << endl;
        // Displays an error message.

        return 1;
        // Ends the program with an error code.
    }


    // Create a vector to store error entries
    vector<LogEntry> errors;

    /*
        vector:
        A dynamic container that stores multiple values.

        <LogEntry>:
        Specifies that the vector will store LogEntry objects.

        errors:
        Name of the vector.

        Initially, the vector is empty.

        This vector will store only log entries
        containing ERROR or CRITICAL.
    */


    // Variable to store one line read from the file
    string line;

    /*
        string:
        Data type used to store text.

        line:
        Stores one complete log line at a time.

        Example:
        "2026-09-09 08:20:00 ERROR Database connection failed"
    */


    // Read the log file line by line
    while (getline(logFile, line))
    {
        /*
            while:
            Loop that repeats while its condition is true.

            getline(logFile, line):
            Reads one complete line from logFile
            and stores it in the variable line.

            The loop continues while a line is successfully read.

            When the end of the file is reached,
            getline() fails and the loop stops.
        */


        // Check whether the line contains ERROR or CRITICAL
        if (line.find("ERROR") != string::npos ||
            line.find("CRITICAL") != string::npos)
        {
            /*
                if:
                Checks whether a condition is true.

                line.find("ERROR"):
                Searches for the word "ERROR" inside line.

                find():
                A string function used to search for
                a particular substring.

                string::npos:
                A special constant that means
                "the substring was not found."

                line.find("ERROR") != string::npos:
                Means the word "ERROR" was found.

                !=:
                Not-equal comparison operator.

                ||:
                Logical OR operator.
                The condition is true if at least one
                of the two conditions is true.

                Complete condition:
                Select the line if it contains:
                1. ERROR
                OR
                2. CRITICAL
            */


            // Add the matching log entry to the vector
            errors.push_back({line});

            /*
                errors:
                Vector storing selected log entries.

                push_back():
                Adds a new element at the end of the vector.

                {line}:
                Creates a LogEntry structure object
                and initializes its line member with
                the current line.

                Example:
                If line contains:
                "2026-09-09 08:20:00 ERROR Database connection failed"

                Then that complete line is stored
                inside the errors vector.
            */
        }
    }


    // Display the report heading
    cout << "=== Critical Log Events ===" << endl;

    /*
        cout:
        Standard output stream used to display text.

        "=== Critical Log Events ===":
        Heading displayed on the screen.

        endl:
        Moves the cursor to the next line.
    */


    // Display every selected log entry
    for (const auto& entry : errors)
    {
        /*
            for:
            Looping statement.

            const:
            Means the entry will not be modified
            inside the loop.

            auto:
            Allows the compiler to automatically determine
            the data type of entry.

            &:
            Reference symbol.
            It avoids copying each LogEntry object.

            entry:
            Represents one LogEntry object from errors.

            errors:
            The vector being traversed.

            This is called a range-based for loop.
            It visits every element in the vector.
        */


        cout << entry.line << endl;

        /*
            entry:
            Represents the current LogEntry object.

            .:
            Member access operator.
            It is used to access a member of a structure or class.

            line:
            The string member inside LogEntry.

            cout << entry.line:
            Displays the stored log line.

            endl:
            Moves the cursor to the next line.
        */
    }


    // Display the total number of critical events
    cout << "Total critical events: " << errors.size() << endl;

    /*
        errors.size():
        Returns the number of elements stored
        in the errors vector.

        In this program:
        ERROR entry       -> 1
        CRITICAL entry    -> 1

        Total = 2

        The value 2 is displayed after the message.
    */


    return 0;
    /*
        return 0:
        Indicates that the program executed successfully.
    */
}