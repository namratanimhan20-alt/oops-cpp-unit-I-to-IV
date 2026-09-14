//Real-Time Application 16: Employee Directory and Salary Lookup 
//Problem Scenario An HR platform maintains a collection of employees, sorts them for reporting, and performs fast salary lookup by employee name. 

// Includes the algorithm library for sort() and max_element().
#include <algorithm>

// Includes the input-output library for cout and endl.
#include <iostream>

// Includes the map container.
#include <map>

// Includes the string data type.
#include <string>

// Includes the vector container.
#include <vector>

// Allows us to use names like cout, vector, map, and string
// without writing std:: before each one.
using namespace std;


// Defines a class named Employee.
class Employee {

public:
    // Stores the employee's name.
    string name;

    // Stores the employee's age.
    int age;

    // Stores the employee's salary.
    double salary;


    // Constructor of the Employee class.
    // It is called when an Employee object is created.
    Employee(string n, int a, double s)

        // Initializes name with the value of n.
        : name(n),

          // Initializes age with the value of a.
          age(a),

          // Initializes salary with the value of s.
          salary(s) {}

}; // End of the Employee class.



// The main() function is where program execution begins.
int main() {

    // Creates a vector named staff.
    // The vector stores multiple Employee objects.
    vector<Employee> staff{

        // Creates the first Employee object.
        // Name = Alice, Age = 30, Salary = 70000.
        {"Alice", 30, 70000},

        // Creates the second Employee object.
        {"Bob", 25, 50000},

        // Creates the third Employee object.
        {"Charlie", 35, 80000},

        // Creates the fourth Employee object.
        {"Diana", 28, 60000}

    }; // End of vector initialization.



    // Creates a map named salaryByName.
    // The key is a string (employee name).
    // The value is a double (employee salary).
    map<string, double> salaryByName;


    // A range-based for loop that visits every employee in staff.
    // const means we will not modify the employee.
    // auto automatically determines the employee's data type.
    // & avoids creating a copy of each Employee object.
    for (const auto& employee : staff) {

        // Stores the employee's salary in the map.
        // employee.name is the key.
        // employee.salary is the value.
        salaryByName[employee.name] = employee.salary;

    } // End of for loop.



    // Sorts the employees in the staff vector.
    // staff.begin() points to the first element.
    // staff.end() points just after the last element.
    sort(staff.begin(), staff.end(),

         // Lambda function used to compare two Employee objects.
         // first and second represent two employees being compared.
         [](const Employee& first, const Employee& second) {

             // Returns true if the first employee is younger.
             // This sorts employees in ascending order of age.
             return first.age < second.age;

         } // End of lambda function.
    ); // End of sort().



    // Prints a heading on the screen.
    cout << "=== Employees Sorted by Age ===" << endl;


    // Loops through the sorted staff vector.
    for (const auto& employee : staff) {

        // Prints the employee's name.
        cout << employee.name

             // Prints a separator and the employee's age.
             << " | Age: " << employee.age

             // Prints a separator and the employee's salary.
             << " | Salary: Rs. " << employee.salary

             // Moves the cursor to the next line.
             << endl;

    } // End of for loop.



    // Creates a string variable named query.
    // We want to search for the salary of Bob.
    string query = "Bob";


    // Searches for the name stored in query inside the map.
    // find() returns an iterator pointing to the matching element.
    auto found = salaryByName.find(query);


    // Checks whether the name was found.
    // end() means the search reached the end without finding it.
    if (found != salaryByName.end()) {

        // Prints the employee's name and salary.
        cout << "\nSalary of " << query

             // found->second gives the salary (the map's value).
             << ": Rs. " << found->second

             // Moves to the next line.
             << endl;

    } // End of if statement.



    // Finds the employee with the highest salary.
    // max_element() returns an iterator to the largest element.
    auto highestPaid = max_element(

        // Searches through the entire staff vector.
        staff.begin(), staff.end(),

        // Lambda function used to compare two Employee objects.
        [](const Employee& first, const Employee& second) {

            // Returns true when the first salary is lower.
            // This helps max_element() identify the highest salary.
            return first.salary < second.salary;

        } // End of lambda function.

    ); // End of max_element().



    // Prints the name of the highest-paid employee.
    cout << "Highest-paid employee: " << highestPaid->name

         // Prints the highest-paid employee's salary.
         << " | Rs. " << highestPaid->salary

         // Moves the cursor to the next line.
         << endl;


    // Indicates that the program completed successfully.
    return 0;

} // End of main().