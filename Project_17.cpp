//Real-Time Application 17: Web Server Log Analysis 
//Problem Scenario : A monitoring tool counts incoming web requests by IP address and reports the most frequent request sources. The same logic can support traffic analysis, capacity planning, and basic security monitoring

// Includes the algorithm library.
// It provides the sort() function used later.
#include <algorithm>

// Includes the input-output library.
// It provides cout and endl for displaying output.
#include <iostream>

// Includes the map container.
// A map stores data in key-value pairs.
#include <map>

// Includes the string data type.
// It is used to store IP addresses and requests.
#include <string>

// Includes the utility library.
// It provides pair, which stores two values together.
#include <utility>

// Includes the vector container.
// A vector stores multiple elements in a sequence.
#include <vector>

// Allows us to use cout, string, vector, map, and pair
// without writing std:: before each name.
using namespace std;


// Defines a structure named LogEntry.
// A structure groups related data members together.
struct LogEntry {

    // Stores the IP address of the user making the request.
    string ip;

    // Stores the HTTP request made by the user.
    string request;

}; // End of the LogEntry structure.



// The main() function is the starting point of the program.
int main() {

    // Creates a vector named logs.
    // The vector stores multiple LogEntry objects.
    vector<LogEntry> logs{

        // First log entry:
        // IP address = 192.168.1.1
        // Request = GET /index.html
        {"192.168.1.1", "GET /index.html"},

        // Second log entry.
        {"192.168.1.2", "POST /api/data"},

        // Third log entry.
        {"192.168.1.1", "GET /about.html"},

        // Fourth log entry.
        {"192.168.1.3", "GET /contact.html"},

        // Fifth log entry.
        {"192.168.1.1", "GET /products.html"},

        // Sixth log entry.
        {"192.168.1.2", "GET /api/users"},

        // Seventh log entry.
        {"192.168.1.1", "POST /api/order"},

        // Eighth log entry.
        {"192.168.1.4", "GET /index.html"},

        // Ninth log entry.
        {"192.168.1.1", "GET /services.html"},

        // Tenth log entry.
        {"192.168.1.2", "GET /api/products"}

    }; // End of vector initialization.



    // Creates a map named requestCount.
    // The key is a string representing an IP address.
    // The value is an int representing the number of requests.
    map<string, int> requestCount;


    // Range-based for loop to visit every log entry.
    // const means the entry will not be modified.
    // auto automatically detects the type of entry.
    // & avoids making a copy of each LogEntry object.
    for (const auto& entry : logs) {

        // Uses the IP address as the key in the map.
        // If the IP does not exist, map[] creates it
        // with a default integer value of 0.
        // ++ increases the request count by 1.
        requestCount[entry.ip]++;

    } // End of counting loop.



    // Creates a vector named ranked.
    // Each element is a pair containing:
    // first  = IP address (string)
    // second = request count (int).
    //
    // requestCount.begin() points to the first map element.
    // requestCount.end() points just after the last map element.
    //
    // This copies all key-value pairs from the map into the vector.
    vector<pair<string, int>> ranked(
        requestCount.begin(),
        requestCount.end()
    );


    // Sorts the ranked vector.
    // ranked.begin() points to the first element.
    // ranked.end() points just after the last element.
    sort(
        ranked.begin(),
        ranked.end(),

        // Lambda function used to compare two pairs.
        // first and second represent two elements of ranked.
        [](const auto& first, const auto& second) {

            // first.second = request count of the first IP.
            // second.second = request count of the second IP.
            //
            // The > operator sorts in descending order.
            // Therefore, the IP with more requests comes first.
            return first.second > second.second;

        } // End of lambda function.
    ); // End of sort().



    // Prints the heading.
    cout << "=== Request Count by IP Address ===" << endl;


    // Loops through every pair in the sorted ranked vector.
    // const means the item will not be modified.
    // auto automatically detects the pair's type.
    // & avoids making a copy of the pair.
    for (const auto& item : ranked) {

        // item.first contains the IP address.
        // item.second contains the number of requests.
        cout << item.first
             << " : "
             << item.second
             << " requests"
             << endl;

    } // End of output loop.


} // End of main().