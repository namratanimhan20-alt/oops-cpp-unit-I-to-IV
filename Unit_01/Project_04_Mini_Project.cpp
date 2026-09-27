//Mini-Project Problem Statement :
//Smart Home Device Manager : Model smart devices such as lights, thermostats, cameras, and door locks. Each device should have a device ID, location, status, and last-updated time. 
//Implement operations to switch devices on or off, change status, and display an overall home dashboard. 

#include <iostream> // Provides input and output operations using cin and cout.
#include <iomanip>  // Provides formatting functions such as setw and left.
#include <string>  // Provides the string data type.
#include <ctime>  // Provides functions to work with date and time.

using namespace std;// Allows standard library names to be used without std::.


// Class representing a smart home device.
class SmartDevice
{
private:

    string deviceId; // Stores the unique ID of the device.
    string deviceType; // Stores the type of the smart device.
    string location;  // Stores the location of the device.
    string status;   // Stores the current status of the device.
    string lastUpdated;  // Stores the last-updated time of the device.

    // Static data member stores the total number of devices created.
    static int totalDevices;

    // Utility function used internally to get the current system time.
    string getCurrentTime() const
    {
        time_t currentTime = time(nullptr); // Get the current system time.

        string timeValue = ctime(&currentTime); // Convert the time into readable text.

        // Remove the newline character added by ctime().
        if (!timeValue.empty() && timeValue.back() == '\n')
        {
            timeValue.pop_back();
        }

        return timeValue; // Return the formatted current time.
    }

public:

    // Constructor initializes all the details of a smart device.
    SmartDevice(string id, string type, string deviceLocation, string deviceStatus)
    {
        deviceId = id;  // Store the device ID.
        deviceType = type; // Store the device type.
        location = deviceLocation;  // Store the device location.
        status = deviceStatus;  // Store the initial status.

        lastUpdated = getCurrentTime();  // Store the current time.

        totalDevices++;  // Increase the total device count.
    }


    // Destructor is called automatically when the object is destroyed.
    ~SmartDevice()
    {
        totalDevices--; // Decrease the total device count.
    }


    // Function to switch the device ON.
    void switchOn()
    {
        status = "ON"; // Change the device status to ON.

        lastUpdated = getCurrentTime();// Update the last-updated time.

        cout << deviceId << " switched ON successfully." << endl;
    }


    // Function to switch the device OFF.
    void switchOff()
    {
        status = "OFF";  // Change the device status to OFF.

        lastUpdated = getCurrentTime();  // Update the last-updated time.

        cout << deviceId << " switched OFF successfully." << endl;
    }


    // Function to change the status of the device.
    void changeStatus(string newStatus)
    {
        status = newStatus;  // Store the new status.

        lastUpdated = getCurrentTime(); // Update the last-updated time.

        cout << deviceId << " status changed to "
             << status << "." << endl;
    }


    // Inline function returns true when the device is ON.
    inline bool isOn() const
    {
        return status == "ON"; // Check whether the current status is ON.
    }


    // Static member function displays the total number of devices.
    static void displayTotalDevices()
    {
        cout << "Total Devices  : "
             << totalDevices << endl;
    }


    // Friend function can access private members of SmartDevice.
    friend void displayDashboard(const SmartDevice devices[], int size);
};


// Definition of the static data member outside the class.
int SmartDevice::totalDevices = 0;


// Friend function displays the overall home dashboard.
void displayDashboard(const SmartDevice devices[], int size)
{
    // Display the dashboard heading.
    cout << "\n=============================="<< endl;

    cout << "SMART HOME DASHBOARD"<< endl;

    cout << "==========================="<< endl;


    // Display the column headings.
    cout << left
         << setw(10) << "ID"
         << setw(22) << "Device Type"
         << setw(18) << "Location"
         << setw(12) << "Status"
         << "Last Updated" << endl;


    // Display a separator line.
    cout << "-----------------------------"<< endl;


    // Loop through all devices in the array.
    for (int i = 0; i < size; i++)
    {
        // Display the details of the current device.
        cout << left
             << setw(10) << devices[i].deviceId
             << setw(22) << devices[i].deviceType
             << setw(18) << devices[i].location
             << setw(12) << devices[i].status
             << devices[i].lastUpdated
             << endl;
    }


    // Display another separator line.
    cout << "------------------------------"<< endl;


    // Display the total number of devices.
    SmartDevice::displayTotalDevices();
}


// Function to display the status of individual devices.
void displayDeviceStatus(const SmartDevice devices[], int size)
{
    cout << "\nDEVICE STATUS CHECK" << endl;
    cout << "==========================="<< endl;


    // Loop through all devices.
    for (int i = 0; i < size; i++)
    {
        // Display the device ID.
        cout << devices[i].deviceId
             << " is currently ";

        // Check whether the device is ON.
        if (devices[i].isOn())
        {
            cout << "ON";
        }
        else
        {
            cout << "not ON";
        }

        // Move to the next line.
        cout << "." << endl;
    }
}


// Main function where program execution begins.
int main()
{
    // Display the project title.
    cout << "======================="<< endl;

    cout << "SMART HOME DEVICE MANAGER"<< endl;

    cout << "======================="<< endl;
    
    // Create a Light object.
    SmartDevice light(
        "L001",
        "Light",
        "Living Room",
        "OFF"
    );


    // Create a Thermostat object.
    SmartDevice thermostat(
        "T001",
        "Thermostat",
        "Bedroom",
        "OFF"
    );


    // Create a Camera object.
    SmartDevice camera(
        "C001",
        "Camera",
        "Main Entrance",
        "OFF"
    );


    // Create a Door Lock object.
    SmartDevice doorLock(
        "D001",
        "Door Lock",
        "Main Door",
        "LOCKED"
    );


    // Store all devices inside an array.
    SmartDevice devices[] =
    {
        light,
        thermostat,
        camera,
        doorLock
    };


    // Display the device operations heading.
    cout << "\nDEVICE OPERATIONS" << endl;

    cout << "=============================="<< endl;


    // Switch the living room light ON.
    devices[0].switchOn();


    // Change the thermostat status.
    devices[1].changeStatus("24 C");


    // Switch the entrance camera ON.
    devices[2].switchOn();


    // Change the door lock status.
    devices[3].changeStatus("UNLOCKED");


    // Switch the camera OFF.
    devices[2].switchOff();


    // Display whether the devices are currently ON.
    displayDeviceStatus(devices, 4);


    // Display the overall home dashboard.
    displayDashboard(devices, 4);


    // Display the completion message.
    cout << "\nSmart Home Device Manager executed successfully."
         << endl;


    // Return 0 to indicate successful execution.
    return 0;
}