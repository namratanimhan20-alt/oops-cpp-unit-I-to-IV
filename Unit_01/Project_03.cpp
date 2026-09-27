//Real-Time Application 3: E-Commerce Product Catalog 
//Problem Scenario : An online store maintains product details such as product ID, product name, price, and stock quantity. A static member tracks 
//the number of active product objects. 

// Include the input-output stream library.
// It provides cout and endl for displaying output.
#include <iostream>

// Include the string library.
// It allows us to use the string data type.
#include <string>

// Allows us to use cout, string, etc.
// without writing std:: before them.
using namespace std;


// Define a class named Product.
// A class is a blueprint for creating product objects.
class Product {

private:
    // Private data members.
    // These store the details of each product.

    int productId;
    // Stores the unique ID of the product.
    // Example: 1001

    string productName;
    // Stores the name of the product.
    // Example: "Laptop"

    double price;
    // Stores the price of the product.
    // double allows decimal values.

    int stockQuantity;
    // Stores the number of products available in stock.

    static int totalProducts;
    // A static data member is shared by ALL objects
    // of the Product class.
    //
    // It does not create a separate copy for every object.
    // It keeps track of the total number of Product objects
    // currently alive.


public:
    // Public members can be accessed from outside the class
    // through objects.


    // Constructor of the Product class.
    // It is automatically called when a Product object
    // is created.
    //
    // id    -> product ID
    // name  -> product name
    // p     -> product price
    // stock -> available stock quantity
    Product(int id, string name, double p, int stock)

        // Member initializer list.
        // It initializes the data members
        // using the values passed to the constructor.
        : productId(id),
          productName(name),
          price(p),
          stockQuantity(stock)
    {
        // Increase the shared totalProducts counter
        // whenever a new Product object is created.
        totalProducts++;
    }


    // inline means the function is a candidate for
    // inline expansion by the compiler.
    //
    // int means this function returns an integer.
    // const means it does not modify the object.
    inline int getId() const
    {
        // Return the product ID.
        return productId;
    }


    // Inline function to return the product name.
    // string means the function returns text.
    inline string getName() const
    {
        // Return the product name.
        return productName;
    }


    // Inline function to return the product price.
    // double means the function returns a decimal value.
    inline double getPrice() const
    {
        // Return the product price.
        return price;
    }


    // Function to update the stock quantity.
    // quantity is the new stock value.
    void updateStock(int quantity)
    {
        // Replace the old stock quantity
        // with the new quantity.
        stockQuantity = quantity;
    }


    // Static member function.
    // It belongs to the class rather than a particular object.
    //
    // It can be called using:
    // Product::getTotalProducts()
    static int getTotalProducts()
    {
        // Return the shared totalProducts value.
        return totalProducts;
    }


    // Function to display product details.
    // const means this function does not modify the object.
    void display() const
    {
        // Display the product ID.
        cout << "ID: " << productId

             // Display the product name.
             << " | Product: " << productName

             // Display the price.
             << " | Price: Rs. " << price

             // Display the stock quantity.
             << " | Stock: " << stockQuantity

             // Move to the next line.
             << endl;
    }


    // Destructor of the Product class.
    // It is automatically called when an object is destroyed.
    ~Product()
    {
        // Decrease the shared totalProducts counter
        // when a Product object is destroyed.
        totalProducts--;
    }
};


// Define and initialize the static data member.
// A static data member must have one definition
// outside the class.
int Product::totalProducts = 0;


// Program execution starts from main().
int main()
{
    // Create the first Product object.
    //
    // 1001      -> product ID
    // "Laptop"  -> product name
    // 55000     -> price
    // 15        -> stock quantity
    //
    // The constructor is called automatically.
    // totalProducts becomes 1.
    Product p1(1001, "Laptop", 55000, 15);


    // Create the second Product object.
    // totalProducts becomes 2.
    Product p2(1002, "Mouse", 450, 50);


    // Create the third Product object.
    // totalProducts becomes 3.
    Product p3(1003, "Keyboard", 1200, 30);


    // Display the heading.
    cout << "=== Product Catalog ===" << endl;


    // Display the details of the first product.
    p1.display();


    // Display the details of the second product.
    p2.display();


    // Display the details of the third product.
    p3.display();


    // \n inserts a blank line before the heading.
    //
    // Product::getTotalProducts()
    // calls the static member function using the class name.
    //
    // It returns the shared count of Product objects.
    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts()
         << endl;


    // Return 0 indicates successful program execution.
    //
    // When main() ends, local objects p3, p2, and p1
    // are destroyed automatically in reverse order.
    // Their destructors decrease totalProducts.
    return 0;
}