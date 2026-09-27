//Mini-Project Problem Statement :
//Library Book Management System : Store book details—ISBN, title, author, category, and availability—in a text file. 
//Support adding, searching, issuing, returning, updating, and generating an availability report. 

#include <iostream> // Provides input and output operations using cin and cout.
#include <fstream> // Provides file input and output operations.
#include <string> // Provides the string data type.
#include <vector> // Provides the vector container.
#include <sstream> // Provides string stream operations.

using namespace std; // Allows standard library names to be used without std::.


// Stores the details of one library book.
struct Book
{
    string isbn; // Stores the ISBN of the book.
    string title; // Stores the title of the book.
    string author; // Stores the author name.
    string category; // Stores the category of the book.
    bool available; // Stores whether the book is currently available.
};


// Name of the text file used to store book records.
const string FILE_NAME = "library_books.txt";


// Converts the availability value into text for file storage.
string availabilityToString(bool available)
{
    if (available) // Checks whether the book is available.
    {
        return "Available"; // Returns Available when the book can be issued.
    }

    return "Issued"; // Returns Issued when the book is not available.
}


// Converts text from the file into a boolean availability value.
bool stringToAvailability(const string& value)
{
    return value == "Available"; // Returns true only when the value is Available.
}


// Converts a Book object into one line for the text file.
string bookToLine(const Book& book)
{
    return book.isbn + "|" +
           book.title + "|" +
           book.author + "|" +
           book.category + "|" +
           availabilityToString(book.available);
}


// Converts one line from the text file into a Book object.
bool lineToBook(const string& line, Book& book)
{
    string availability; // Stores the availability field temporarily.

    stringstream stream(line); // Creates a string stream from the file line.

    // Reads all five fields separated by the | symbol.
    if (!getline(stream, book.isbn, '|') ||
        !getline(stream, book.title, '|') ||
        !getline(stream, book.author, '|') ||
        !getline(stream, book.category, '|') ||
        !getline(stream, availability))
    {
        return false; // Returns false when the record is malformed.
    }

    book.available = stringToAvailability(availability); // Converts availability into bool.

    return true; // Indicates that the record was read successfully.
}


// Reads all books from the text file.
vector<Book> loadBooks()
{
    vector<Book> books; // Stores all books read from the file.

    ifstream inputFile(FILE_NAME); // Opens the text file for reading.

    if (!inputFile) // Checks whether the file opened successfully.
    {
        return books; // Returns an empty list when the file does not exist.
    }

    string line; // Stores one line read from the file.

    // Read the file one line at a time.
    while (getline(inputFile, line))
    {
        if (line.empty()) // Checks for an empty line.
        {
            continue; // Skips the empty line.
        }

        Book book; // Creates a temporary Book object.

        if (lineToBook(line, book)) // Converts the line into book data.
        {
            books.push_back(book); // Adds the valid book to the collection.
        }
    }

    inputFile.close(); // Closes the input file.

    return books; // Returns all successfully read books.
}


// Writes all books to the text file.
bool saveBooks(const vector<Book>& books)
{
    ofstream outputFile(FILE_NAME); // Opens the file for writing.

    if (!outputFile) // Checks whether the file opened successfully.
    {
        cout << "Error: Unable to open the file for writing." << endl;
        return false; // Stops the operation when the file cannot be opened.
    }

    // Write every book record to the file.
    for (const Book& book : books)
    {
        outputFile << bookToLine(book) << endl; // Writes one book per line.
    }

    outputFile.close(); // Closes the output file.

    return true; // Indicates successful file writing.
}


// Adds a new book to the library.
void addBook()
{
    vector<Book> books = loadBooks(); // Reads the existing records from the file.

    Book book; // Creates a new Book object.

    cout << "\nADD NEW BOOK" << endl;
    cout << "========================================" << endl;

    cout << "Enter ISBN: ";
    getline(cin, book.isbn); // Reads the ISBN.

    // Check whether the ISBN already exists.
    for (const Book& existingBook : books)
    {
        if (existingBook.isbn == book.isbn)
        {
            cout << "Error: A book with this ISBN already exists." << endl;
            return; // Stops the operation when a duplicate is found.
        }
    }

    cout << "Enter Title: ";
    getline(cin, book.title); // Reads the book title.

    cout << "Enter Author: ";
    getline(cin, book.author); // Reads the author name.

    cout << "Enter Category: ";
    getline(cin, book.category); // Reads the book category.

    book.available = true; // New books are available by default.

    books.push_back(book); // Adds the new book to the collection.

    if (saveBooks(books)) // Saves the updated records to the file.
    {
        cout << "Book added successfully." << endl;
    }
}


// Searches for a book using its ISBN.
void searchBook()
{
    vector<Book> books = loadBooks(); // Reads book records from the file.

    string isbn; // Stores the ISBN entered by the user.

    cout << "\nSEARCH BOOK" << endl;
    cout << "========================================" << endl;

    cout << "Enter ISBN to search: ";
    getline(cin, isbn); // Reads the ISBN.

    bool found = false; // Tracks whether the book was found.

    // Search through all books.
    for (const Book& book : books)
    {
        if (book.isbn == isbn) // Checks whether the ISBN matches.
        {
            cout << "ISBN          : " << book.isbn << endl;
            cout << "Title         : " << book.title << endl;
            cout << "Author        : " << book.author << endl;
            cout << "Category      : " << book.category << endl;
            cout << "Availability  : "
                 << availabilityToString(book.available) << endl;

            found = true; // Marks the book as found.
            break; // Stops searching after finding the book.
        }
    }

    if (!found) // Checks whether no matching book was found.
    {
        cout << "Book not found." << endl;
    }
}


// Issues a book to a library user.
void issueBook()
{
    vector<Book> books = loadBooks(); // Reads all records from the file.

    string isbn; // Stores the ISBN of the book to be issued.

    cout << "\nISSUE BOOK" << endl;
    cout << "========================================" << endl;

    cout << "Enter ISBN to issue: ";
    getline(cin, isbn); // Reads the ISBN.

    bool found = false; // Tracks whether the book was found.

    // Search through all books.
    for (Book& book : books)
    {
        if (book.isbn == isbn) // Checks whether the ISBN matches.
        {
            found = true; // Marks the book as found.

            if (!book.available) // Checks whether the book is already issued.
            {
                cout << "Book is already issued." << endl;
                return; // Stops the operation.
            }

            book.available = false; // Changes the status to issued.

            if (saveBooks(books)) // Saves the updated status to the file.
            {
                cout << "Book issued successfully." << endl;
            }

            return; // Ends the function after issuing the book.
        }
    }

    if (!found) // Checks whether the book was not found.
    {
        cout << "Book not found." << endl;
    }
}


// Returns an issued book.
void returnBook()
{
    vector<Book> books = loadBooks(); // Reads all records from the file.

    string isbn; // Stores the ISBN of the returned book.

    cout << "\nRETURN BOOK" << endl;
    cout << "========================================" << endl;

    cout << "Enter ISBN to return: ";
    getline(cin, isbn); // Reads the ISBN.

    bool found = false; // Tracks whether the book was found.

    // Search through all books.
    for (Book& book : books)
    {
        if (book.isbn == isbn) // Checks whether the ISBN matches.
        {
            found = true; // Marks the book as found.

            if (book.available) // Checks whether the book is already available.
            {
                cout << "Book is already available." << endl;
                return; // Stops the operation.
            }

            book.available = true; // Changes the status to available.

            if (saveBooks(books)) // Saves the updated status to the file.
            {
                cout << "Book returned successfully." << endl;
            }

            return; // Ends the function after returning the book.
        }
    }

    if (!found) // Checks whether the book was not found.
    {
        cout << "Book not found." << endl;
    }
}


// Updates the details of an existing book.
void updateBook()
{
    vector<Book> books = loadBooks(); // Reads all records from the file.

    string isbn; // Stores the ISBN of the book to update.

    cout << "\nUPDATE BOOK" << endl;
    cout << "========================================" << endl;

    cout << "Enter ISBN to update: ";
    getline(cin, isbn); // Reads the ISBN.

    bool found = false; // Tracks whether the book was found.

    // Search through all books.
    for (Book& book : books)
    {
        if (book.isbn == isbn) // Checks whether the ISBN matches.
        {
            found = true; // Marks the book as found.

            cout << "Enter new title: ";
            getline(cin, book.title); // Updates the title.

            cout << "Enter new author: ";
            getline(cin, book.author); // Updates the author.

            cout << "Enter new category: ";
            getline(cin, book.category); // Updates the category.

            if (saveBooks(books)) // Saves the updated record to the file.
            {
                cout << "Book updated successfully." << endl;
            }

            return; // Ends the function after updating the book.
        }
    }

    if (!found) // Checks whether the book was not found.
    {
        cout << "Book not found." << endl;
    }
}


// Generates a report of all books and their availability.
void generateAvailabilityReport()
{
    vector<Book> books = loadBooks(); // Reads all books from the file.

    cout << "\nAVAILABILITY REPORT" << endl;
    cout << "========================================" << endl;

    if (books.empty()) // Checks whether there are no records.
    {
        cout << "No book records are available." << endl;
        return; // Stops the report when there are no books.
    }

    int availableCount = 0; // Stores the number of available books.
    int issuedCount = 0; // Stores the number of issued books.

    // Display every book in the report.
    for (const Book& book : books)
    {
        cout << "ISBN          : " << book.isbn << endl;
        cout << "Title         : " << book.title << endl;
        cout << "Author        : " << book.author << endl;
        cout << "Category      : " << book.category << endl;
        cout << "Availability  : "
             << availabilityToString(book.available) << endl;
        cout << "----------------------------------------" << endl;

        if (book.available) // Checks whether the book is available.
        {
            availableCount++; // Increases the available count.
        }
        else
        {
            issuedCount++; // Increases the issued count.
        }
    }

    cout << "Total Books    : " << books.size() << endl;
    cout << "Available Books: " << availableCount << endl;
    cout << "Issued Books   : " << issuedCount << endl;
}


// Main function where program execution begins.
int main()
{
    int choice; // Stores the menu choice selected by the user.

    // Display the application title.
    cout << "========================================" << endl;
    cout << "     LIBRARY BOOK MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;

    // Repeatedly display the menu until the user chooses Exit.
    do
    {
        cout << "\nMENU" << endl;
        cout << "========================================" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Update Book" << endl;
        cout << "6. Availability Report" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        // Check whether the user entered a valid integer.
        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number." << endl;

            cin.clear(); // Clears the error state of cin.
            cin.ignore(1000, '\n'); // Removes invalid input from the buffer.

            continue; // Returns to the menu.
        }

        // Remove the newline left by cin.
        cin.ignore(1000, '\n');

        // Execute the selected operation.
        switch (choice)
        {
        case 1:
            addBook(); // Calls the function to add a book.
            break;

        case 2:
            searchBook(); // Calls the function to search for a book.
            break;

        case 3:
            issueBook(); // Calls the function to issue a book.
            break;

        case 4:
            returnBook(); // Calls the function to return a book.
            break;

        case 5:
            updateBook(); // Calls the function to update a book.
            break;

        case 6:
            generateAvailabilityReport(); // Generates the availability report.
            break;

        case 7:
            cout << "Exiting Library Book Management System." << endl;
            break;

        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }

    } while (choice != 7); // Continue until the user selects Exit.

    return 0; // Indicates successful program execution.
}