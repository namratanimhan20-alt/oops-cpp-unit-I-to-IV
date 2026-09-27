# C++ Programming Project/Coding – Unit I to Unit IV

## Student Details

- Student Name: Namrata Nimhan
- ZPRN: 125UAD1192
- Class/Division: S.Y/E
- Course Name: Artificial Intelligence & Data Science
- Units: Unit I to Unit IV

## Programs Included
This repository contains the C++ real-time application programs and mini-projects completed as part of the Unit I to Unit IV coursework. 
The programs are organized unit-wise and demonstrate the concepts covered in each unit through practical application-based problems.

---

## Unit I – Fundamentals of Object Oriented Programming

### Program 01 – Smart Agriculture Sensor Monitor
This program models a smart agriculture monitoring system in which soil-moisture, temperature, and humidity sensors are represented as objects. 
Each sensor maintains a unique ID, current reading, and timestamp, with operations to update readings and display the current sensor status.

**File:**
- `Project_01.cpp`

### Program 02 – Student Attendance Management System
This program implements a student attendance management system using student details such as roll number, name, total classes, and attended classes. 
The attendance percentage is calculated automatically based on the total and attended classes.

**File:**
- `Project_02.cpp`

### Program 03 – E-Commerce Product Catalog
This program implements an e-commerce product catalog that maintains product ID, product name, price, and stock quantity. 
A static member is used to track the number of active product objects in the system.

**File:**
- `Project_03.cpp`

### Project 04 – Mini-Project: Smart Home Device Manager
This mini-project models smart home devices such as lights, thermostats, cameras, and door locks.
Each device maintains a device ID, location, status, and last-updated time. The system provides operations to switch devices on or off, change their status, and display an overall home dashboard.

**File:**
- `Project_04_Mini_Project.cpp`

---

## Unit II – Inheritance

### Program 01 – Employee Payroll System
This program implements an employee payroll system using an abstract base class and derived employee classes. 
It handles full-time employees, part-time employees, and interns with separate salary calculations. Inheritance, function overriding, and runtime polymorphism are used to implement employee-specific behavior.

**File:**
- `Project_01.cpp`

### Program 02 – Digital Payment Gateway
This program implements a digital payment gateway supporting Credit Card, UPI, and Net Banking payment methods.
A common abstract base class provides the basic payment structure, while derived classes implement their respective payment processing behavior. 
The program demonstrates inheritance, abstraction, runtime polymorphism, and smart pointer-based object management.

**File:**
- `Project_02.cpp`

### Program 03 – Vehicle Fleet Management
This program implements a vehicle fleet management system for different vehicle types such as trucks, delivery vans, and bikes. 
A common base class provides shared properties and operations, while derived classes provide vehicle-specific behavior. 
Virtual functions and polymorphism are used to display fleet information through a common interface.

**File:**
- `Project_03.cpp`

### Project 04 – Mini-Project: Banking System with Account Hierarchy
This mini-project implements a banking system using a base `Account` class and derived classes for Savings Account, Current Account, and Fixed Deposit Account. 
It manages account number, holder name, balance, deposit, withdrawal, and account-specific interest calculation. 
The implementation demonstrates inheritance, protected members, constructors and destructors, function overriding, abstract classes, virtual functions, and runtime polymorphism.

**File:**
- `Project_04_Mini_Project.cpp`

---

## Unit III – Polymorphism

### Program 01 – CAD Shape Drawing System
This program implements a computer-aided design system that handles circles, rectangles, and triangles through a common base-class interface. 
Each shape provides its own drawing operation and area calculation. The program demonstrates abstract classes, pure virtual functions, runtime polymorphism, and base-class interfaces.

**File:**
- `Project_01.cpp`

### Program 02 – Complex Number Calculator
This program implements a complex number calculator for performing arithmetic operations on complex numbers. 
Operator overloading is used so that arithmetic expressions can be written in a natural form. 
The program demonstrates operator overloading for practical numerical operations.

**File:**
- `Project_02.cpp`

### Program 03 – Input Validation Service
This program implements an input validation service for different types of user data such as marks, names, and payment amounts. 
Function overloading provides a common `validate()` interface for handling different input types. 
The program demonstrates compile-time polymorphism through overloaded functions.

**File:**
- `Project_03.cpp`

### Project 04 – Mini-Project: Media Player with Polymorphic Controls
This mini-project implements a media player using a base `Media` class and derived classes for Audio, Video, and Image.
It provides operations such as `play()`, `pause()`, `stop()`, and `showDetails()`. Media items are managed using a collection of base-class pointers to demonstrate runtime polymorphism.

**File:**
- `Project_04_Mini_Project.cpp`

---

## Unit IV – Files and Streams

### Program 01 – Student Record File System
This program implements a student record management system using a CSV-like text file.
Student records are written to a file and then read back to generate a report. The program demonstrates file opening, writing, reading, and processing of stored records.

**File:**
- `Project_01.cpp`

### Program 02 – Server Log Analyzer
This program implements a server log analysis system that reads log entries from a file and identifies error and critical messages. 
The application helps process stored log information and locate important system events efficiently.

**File:**
- `Project_02.cpp`

### Program 03 – Binary File for Fixed-Size Records
This program demonstrates the use of binary files for storing fixed-size metadata records.
Binary storage is used to represent compact records and support efficient sequential retrieval of stored data.

**File:**
- `Project_03.cpp`

### Project 04 – Mini-Project: Library Book Management System
This mini-project implements a library book management system using text-file storage. 
It stores ISBN, title, author, category, and availability information and supports adding, searching, issuing, returning, updating, and generating an availability report. 
File reading, writing, file handling, and error checking are used to maintain the stored records.

**File:**
- `Project_04_Mini_Project.cpp`

---

## Concepts Covered

### Unit I
- Objects and Classes
- Data Members and Member Functions
- Constructors and Destructors
- Functions
- Arrays and Strings
- Static Data Members
- Static Member Functions
- Inline Functions
- Friend Functions
- Control Structures

### Unit II
- Base and Derived Classes
- Protected Members
- Public Inheritance
- Class Hierarchies
- Constructors and Destructors in Derived Classes
- Function Overriding
- Abstract Classes
- Virtual Functions
- Runtime Polymorphism

### Unit III
- Polymorphism
- Function Overloading
- Operator Overloading
- Runtime Polymorphism
- Base-Class Pointers
- Virtual Functions
- Pure Virtual Functions
- Virtual Destructors
- Abstract Base Classes

### Unit IV
- File Handling
- Text Files
- Binary Files
- File Streams
- Opening and Closing Files
- Reading from Files
- Writing to Files
- File Navigation
- Error Handling

## Repository Structure

```text
oops-c-_mini_projects/
│
├── README.md
├── .gitignore
│
├── Unit_01/
│   ├── Project_01.cpp
│   ├── Project_02.cpp
│   ├── Project_03.cpp
│   └── Project_04_Mini_Project.cpp
│
├── Unit_02/
│   ├── Project_01.cpp
│   ├── Project_02.cpp
│   ├── Project_03.cpp
│   └── Project_04_Mini_Project.cpp
│
├── Unit_03/
│   ├── Project_01.cpp
│   ├── Project_02.cpp
│   ├── Project_03.cpp
│   └── Project_04_Mini_Project.cpp
│
└── Unit_04/
    ├── Project_01.cpp
    ├── Project_02.cpp
    ├── Project_03.cpp
    └── Project_04_Mini_Project.cpp
```
