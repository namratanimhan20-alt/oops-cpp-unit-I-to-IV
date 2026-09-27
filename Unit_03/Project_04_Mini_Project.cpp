//Mini-Project Problem Statement :
//Media Player with Polymorphic Controls :  Create a base class Media with derived classes Audio, Video, and Image. 
//Provide operations such as play(), pause(), stop(), and showDetails(). Manage media items using a collection of base-class pointers. 

#include <iostream> // Provides input and output operations using cin and cout.
#include <string> // Provides the string data type.
#include <vector> // Provides the vector container.

using namespace std; // Allows standard library names to be used without std::.


// Abstract base class representing a general media item.
class Media
{
protected:
    string title; // Stores the title of the media item.
    string fileName; // Stores the file name of the media item.

public:

    // Constructor initializes the common media details.
    Media(string mediaTitle, string mediaFileName)
    {
        title = mediaTitle; // Assigns the media title.
        fileName = mediaFileName; // Assigns the media file name.
    }

    // Virtual destructor allows proper destruction of derived objects.
    virtual ~Media()
    {
        cout << "Media object destroyed." << endl;
    }

    // Pure virtual function for playing the media.
    virtual void play() = 0;

    // Pure virtual function for pausing the media.
    virtual void pause() = 0;

    // Pure virtual function for stopping the media.
    virtual void stop() = 0;

    // Pure virtual function for displaying media details.
    virtual void showDetails() const = 0;
};


// Derived class representing an audio media item.
class Audio : public Media
{
private:
    string artist; // Stores the artist name.

public:

    // Constructor initializes the audio details.
    Audio(string mediaTitle, string mediaFileName, string mediaArtist)
        : Media(mediaTitle, mediaFileName)
    {
        artist = mediaArtist; // Assigns the artist name.
    }

    // Destructor of the Audio class.
    ~Audio()
    {
        cout << "Audio object destroyed." << endl;
    }

    // Overrides play() for audio.
    void play() override
    {
        cout << "Playing audio: " << title << endl;
    }

    // Overrides pause() for audio.
    void pause() override
    {
        cout << "Audio paused: " << title << endl;
    }

    // Overrides stop() for audio.
    void stop() override
    {
        cout << "Audio stopped: " << title << endl;
    }

    // Overrides showDetails() for audio.
    void showDetails() const override
    {
        cout << "Media Type     : Audio" << endl;
        cout << "Title          : " << title << endl;
        cout << "File Name      : " << fileName << endl;
        cout << "Artist         : " << artist << endl;
    }
};


// Derived class representing a video media item.
class Video : public Media
{
private:
    string resolution; // Stores the video resolution.

public:

    // Constructor initializes the video details.
    Video(string mediaTitle, string mediaFileName, string mediaResolution)
        : Media(mediaTitle, mediaFileName)
    {
        resolution = mediaResolution; // Assigns the video resolution.
    }

    // Destructor of the Video class.
    ~Video()
    {
        cout << "Video object destroyed." << endl;
    }

    // Overrides play() for video.
    void play() override
    {
        cout << "Playing video: " << title << endl;
    }

    // Overrides pause() for video.
    void pause() override
    {
        cout << "Video paused: " << title << endl;
    }

    // Overrides stop() for video.
    void stop() override
    {
        cout << "Video stopped: " << title << endl;
    }

    // Overrides showDetails() for video.
    void showDetails() const override
    {
        cout << "Media Type     : Video" << endl;
        cout << "Title          : " << title << endl;
        cout << "File Name      : " << fileName << endl;
        cout << "Resolution     : " << resolution << endl;
    }
};


// Derived class representing an image media item.
class Image : public Media
{
private:
    string format; // Stores the image format.

public:

    // Constructor initializes the image details.
    Image(string mediaTitle, string mediaFileName, string imageFormat)
        : Media(mediaTitle, mediaFileName)
    {
        format = imageFormat; // Assigns the image format.
    }

    // Destructor of the Image class.
    ~Image()
    {
        cout << "Image object destroyed." << endl;
    }

    // Overrides play() for image.
    void play() override
    {
        cout << "Displaying image: " << title << endl;
    }

    // Overrides pause() for image.
    void pause() override
    {
        cout << "Image display paused: " << title << endl;
    }

    // Overrides stop() for image.
    void stop() override
    {
        cout << "Image display stopped: " << title << endl;
    }

    // Overrides showDetails() for image.
    void showDetails() const override
    {
        cout << "Media Type     : Image" << endl;
        cout << "Title          : " << title << endl;
        cout << "File Name      : " << fileName << endl;
        cout << "Format         : " << format << endl;
    }
};


// Function to display details and perform controls using a base-class pointer.
void demonstrateMedia(Media* media)
{
    cout << "----------------------------------------" << endl;

    // Display the details of the current media item.
    media->showDetails();

    // Play the media item.
    media->play();

    // Pause the media item.
    media->pause();

    // Stop the media item.
    media->stop();

    cout << "----------------------------------------" << endl;
}


// Main function where program execution begins.
int main()
{
    // Display the application title.
    cout << "========================================" << endl;
    cout << "      MEDIA PLAYER WITH POLYMORPHIC" << endl;
    cout << "              CONTROLS" << endl;
    cout << "========================================" << endl;


    // Create an Audio object.
    Audio audio(
        "Perfect",
        "perfect.mp3",
        "Ed Sheeran"
    );

    // Create a Video object.
    Video video(
        "Nature Documentary",
        "nature.mp4",
        "1920x1080"
    );

    // Create an Image object.
    Image image(
        "Mountain View",
        "mountain.jpg",
        "JPEG"
    );


    // Create a collection of base-class pointers.
    vector<Media*> mediaItems;

    // Store the address of the Audio object.
    mediaItems.push_back(&audio);

    // Store the address of the Video object.
    mediaItems.push_back(&video);

    // Store the address of the Image object.
    mediaItems.push_back(&image);


    // Demonstrate polymorphic media controls.
    cout << "\nMEDIA PLAYER OPERATIONS" << endl;
    cout << "========================================" << endl;


    // Traverse through the collection of base-class pointers.
    for (Media* media : mediaItems)
    {
        // Perform media-specific operations through the base-class pointer.
        demonstrateMedia(media);
    }


    // Display the completion message.
    cout << "\nMedia Player executed successfully." << endl;

    // Return 0 to indicate successful program execution.
    return 0;
}