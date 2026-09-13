//Real-Time Application 12 : Binary File for Fixed-Size Records. 
//Problem Scenario : A multimedia or embedded application stores fixed-size metadata records in a binary file for compact storage and faster sequential retrieval.

#include <cstring>
// <cstring>:
// Header file related to C-style string operations.
//
// Note:
// This particular program does not directly use any function
// from <cstring>, but it can be included when working with
// character arrays and C-style strings.

#include <fstream>
// <fstream>:
// Header file used for file handling.
//
// It provides:
// ofstream -> used to write data into a file.
// ifstream -> used to read data from a file.

#include <iostream>
// <iostream>:
// Header file used for input and output.
//
// It provides:
// cout -> displays normal output.
// cerr -> displays error messages.
// endl -> moves the cursor to the next line.

using namespace std;
// Allows us to use names such as cout, cerr, endl,
// ofstream, and ifstream without writing std::.


// Structure declaration
struct ImageMetadata
{
    /*
        struct:
        Keyword used to create a structure.

        A structure is a user-defined data type
        that groups related variables together.

        ImageMetadata:
        Name of the structure.
        It represents information about an image.
    */


    int width;
    // int:
    // Integer data type.

    // width:
    // Stores the width of the image in pixels.


    int height;
    // height:
    // Stores the height of the image in pixels.


    char format[10];
    /*
        char:
        Character data type.

        format:
        Character array used to store the image format.

        [10]:
        Reserves space for 10 characters.

        Examples of formats:
        "PNG"
        "JPEG"

        Since this is a character array, it can store
        a C-style string ending with the null character '\0'.
    */
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


    // Create the first image metadata object
    ImageMetadata image1{1920, 1080, "PNG"};

    /*
        ImageMetadata:
        Structure name.

        image1:
        Object name.

        {1920, 1080, "PNG"}:
        Aggregate initialization.

        The values are assigned in the order
        in which the structure members are declared:

        width  = 1920
        height = 1080
        format = "PNG"
    */


    // Create the second image metadata object
    ImageMetadata image2{1280, 720, "JPEG"};

    /*
        image2 contains:

        width  = 1280
        height = 720
        format = "JPEG"
    */


    // Create the third image metadata object
    ImageMetadata image3{3840, 2160, "PNG"};

    /*
        image3 contains:

        width  = 3840
        height = 2160
        format = "PNG"
    */


    // Open a binary file for writing
    ofstream output("images.bin", ios::binary);

    /*
        ofstream:
        Output file stream class.
        It is used to write data into a file.

        output:
        Name of the output file stream object.

        "images.bin":
        Name of the binary file.

        .bin:
        Common extension used for binary files.

        ios::binary:
        Opens the file in binary mode.

        Binary mode means data is written as raw bytes
        instead of formatted human-readable text.
    */


    // Check whether the output file opened successfully
    if (!output)
    {
        /*
            if:
            Conditional statement.

            !output:
            Checks whether the output file stream
            is not in a valid state.

            If the file cannot be opened,
            this condition becomes true.
        */

        cerr << "Unable to open binary file for writing."
             << endl;

        /*
            cerr:
            Standard error stream used to display
            error messages.

            <<:
            Insertion operator.

            endl:
            Moves the cursor to the next line.
        */

        return 1;
        /*
            Ends the program with error code 1.
            A non-zero value usually indicates an error.
        */
    }


    // Write image1 into the binary file
    output.write(
        reinterpret_cast<const char*>(&image1),
        sizeof(ImageMetadata)
    );

    /*
        output.write():
        write() is a member function used to write
        a specific number of bytes into a file.

        reinterpret_cast<const char*>(&image1):

        &image1:
        Address-of operator.
        It obtains the memory address of image1.

        reinterpret_cast:
        A C++ cast used to treat a memory address
        as another pointer type.

        const char*:
        Treats the memory as a pointer to characters.

        Why char*?
        File write operations work with a sequence of bytes.
        A char represents one byte of raw memory.

        const:
        Indicates that the data will not be modified
        through this pointer.

        sizeof(ImageMetadata):
        Returns the size of one ImageMetadata object
        in bytes.

        Therefore, this statement writes the complete
        image1 structure into the binary file.
    */


    // Write image2 into the binary file
    output.write(
        reinterpret_cast<const char*>(&image2),
        sizeof(ImageMetadata)
    );

    /*
        This writes the complete image2 structure
        into images.bin.

        The same number of bytes is written:
        sizeof(ImageMetadata)
    */


    // Write image3 into the binary file
    output.write(
        reinterpret_cast<const char*>(&image3),
        sizeof(ImageMetadata)
    );

    /*
        This writes the complete image3 structure
        into images.bin.
    */


    // Close the output file
    output.close();

    /*
        close():
        Closes the file after writing.

        It ensures that pending data is written
        and releases the file resource.
    */


    // Open the binary file for reading
    ifstream input("images.bin", ios::binary);

    /*
        ifstream:
        Input file stream class.
        It is used to read data from a file.

        input:
        Name of the input file stream object.

        "images.bin":
        Binary file to be read.

        ios::binary:
        Opens the file in binary mode.

        The file must be read in binary mode because
        the data was written as raw binary bytes.
    */


    // Check whether the input file opened successfully
    if (!input)
    {
        /*
            !input:
            Checks whether the input file stream
            is not valid.

            If the file cannot be opened,
            the condition becomes true.
        */

        cerr << "Unable to open binary file for reading."
             << endl;

        // Displays an error message.

        return 1;
        // Ends the program with an error code.
    }


    // Create an empty ImageMetadata object
    ImageMetadata item{};

    /*
        ImageMetadata:
        Structure name.

        item:
        Object used to temporarily store one record
        read from the binary file.

        {}:
        Value-initialization.

        It initializes the members to zero or empty values:

        width  = 0
        height = 0
        format = empty character array
    */


    // Variable used to number the records
    int recordNo = 1;

    /*
        int:
        Integer data type.

        recordNo:
        Stores the current record number.

        It starts from 1 because the first record
        will be displayed as Record 1.
    */


    // Display the report heading
    cout << "=== Image Metadata ===" << endl;

    /*
        cout:
        Standard output stream.

        "=== Image Metadata ===":
        Heading displayed on the screen.

        endl:
        Moves the cursor to the next line.
    */


    // Read image records from the binary file
    while (
        input.read(
            reinterpret_cast<char*>(&item),
            sizeof(ImageMetadata)
        )
    )
    {
        /*
            while:
            Repeats the block while the condition is true.

            input.read():
            Reads a fixed number of bytes from the binary file.

            reinterpret_cast<char*>(&item):

            &item:
            Gets the memory address of item.

            reinterpret_cast<char*>:
            Treats the memory of item as a character pointer.

            Unlike write(), const is not used here because
            the read() function must modify item by placing
            the data read from the file into it.

            sizeof(ImageMetadata):
            Specifies how many bytes should be read.

            The function reads one complete ImageMetadata
            record into item.

            The while loop continues as long as a complete
            record is successfully read.

            When the end of the file is reached,
            input.read() fails and the loop stops.
        */


        // Display the current record
        cout << "Record " << recordNo++ << ": "
             << item.width << " x " << item.height
             << " | " << item.format << endl;

        /*
            cout:
            Displays the output.

            "Record ":
            Displays the word Record.

            recordNo++:
            Displays the current record number,
            then increases recordNo by 1.

            ++:
            Increment operator.
            It increases a value by one.

            Since this is post-increment:
                recordNo++ 
            first uses the current value,
            then increments it.

            item.width:
            Accesses the width member of item.

            x:
            Displays the letter x between width and height.

            item.height:
            Accesses the height member.

            " | ":
            Displays a separator.

            item.format:
            Displays the image format.

            endl:
            Moves the cursor to the next line.

            Example output:
            Record 1: 1920 x 1080 | PNG
        */
    }


    return 0;
    /*
        return 0:
        Indicates that the program executed successfully.
    */
}