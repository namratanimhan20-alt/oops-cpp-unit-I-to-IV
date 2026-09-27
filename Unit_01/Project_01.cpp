//Real-Time Application 1: Smart Agriculture Sensor Monitor 
//Problem Scenario : A smart farm collects data from soil-moisture, temperature, and humidity sensors. Every sensor is represented as an 
//object with a unique ID, a current reading, and a time stamp. The monitoring software must update readings and display sensor status. 

// Include the input-output stream library.
// It provides cout and endl for displaying output.
#include <iostream>

// Include the string library.
// It allows us to use the string data type.
#include <string>

// Include the vector library.
// It allows us to store multiple SoilSensor objects
// in a dynamic array.
#include <vector>

// This allows us to use names like cout, string, and vector
// without writing std:: before each one.
using namespace std;


// Define a class named SoilSensor.
// A class is a blueprint for creating objects.
class SoilSensor {

private:
    // Private data members.
    // These variables store the details of each sensor.

    string sensorId;
    // Stores the unique ID of the sensor.
    // Example: "S001"

    double moistureLevel;
    // Stores the moisture level of the soil.
    // double is used for decimal values.
    // Example: 45.2

    string timestamp;
    // Stores the time at which the reading was taken.
    // Example: "08:00"


public:
    // Public members can be accessed from outside the class,
    // such as in the main() function.

    // Constructor of the SoilSensor class.
    // It is automatically called when an object is created.
    SoilSensor(string id, double moisture, string time)

        // Member initializer list.
        // It initializes the private data members
        // using the values passed to the constructor.
        : sensorId(id),
          moistureLevel(moisture),
          timestamp(time)
    {
        // The constructor body is empty because
        // the values have already been initialized above.
    }


    // Function to update the sensor's reading.
    // newMoisture is the new moisture value.
    // newTime is the new reading time.
    void readSensor(double newMoisture, string newTime)
    {
        // Update the moistureLevel with the new value.
        moistureLevel = newMoisture;

        // Update the timestamp with the new time.
        timestamp = newTime;
    }


    // Function to display the sensor's information.
    // const means this function will not modify the object.
    void displayData() const
    {
        // Display the sensor ID.
        cout << "Sensor: " << sensorId

             // Display a separator and the moisture value.
             << " | Moisture: " << moistureLevel << "%"

             // Display a separator and the timestamp.
             << " | Time: " << timestamp

             // endl moves to the next line.
             << endl;
    }
};


// Program execution starts from main().
int main()
{
    // Create a vector named farmSensors.
    // It stores multiple objects of the SoilSensor class.
    vector<SoilSensor> farmSensors;


    // emplace_back() creates a SoilSensor object
    // directly inside the vector and adds it.
    //
    // "S001"  -> sensor ID
    // 45.2    -> moisture level
    // "08:00" -> timestamp
    farmSensors.emplace_back("S001", 45.2, "08:00");


    // Add the second sensor object to the vector.
    farmSensors.emplace_back("S002", 52.8, "08:00");


    // Add the third sensor object to the vector.
    farmSensors.emplace_back("S003", 38.5, "08:00");


    // Display the heading for the morning readings.
    cout << "=== Morning Sensor Readings ===" << endl;


    // Range-based for loop.
    //
    // const means we will not modify the sensor object
    // while displaying it.
    //
    // auto automatically identifies the data type.
    //
    // & means sensor refers to the original object
    // instead of making a copy.
    for (const auto& sensor : farmSensors)
    {
        // Call displayData() for each sensor object.
        sensor.displayData();
    }


    // Access the first object in the vector.
    // Vector indexing starts from 0.
    // Therefore, farmSensors[0] means the S001 sensor.
    //
    // Update its moisture level to 47.5
    // and its timestamp to "09:00".
    farmSensors[0].readSensor(47.5, "09:00");


    // Print a blank line using \n,
    // then display the heading for the updated reading.
    cout << "\n=== Updated Reading ===" << endl;


    // Display the updated information of the first sensor.
    farmSensors[0].displayData();


    // Return 0 indicates that the program executed successfully.
    return 0;
}