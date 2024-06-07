#include "Products.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

const int maxrow = 30;
//string product_quantity[maxrow] = {};
//string product_name[maxrow] = {};
//string product_type[maxrow] = {};
//string product_price[maxrow] = {};

void Products::UpdateProduct(string search)
{
    cin.ignore();

    cout << "Enter the product's name: ";
    getline(cin, productname);

    cout << "Enter product's price: ";
    getline(cin, productprice);

    cout << "Enter product's type: ";
    getline(cin, producttype);

    cout << "Enter product's quantity: ";
    getline(cin, productquantity);

    for (int i = 0; i < maxrow; i++)
    {
        if (product_name[i].empty())
        {
            product_name[i] = productname;
            product_quantity[i] = productquantity;
            product_type[i] = producttype;
            product_price[i] = productprice;
            break;
        }
    }

    // Open the file for writing and append the new product information
    ofstream file("Text.txt", ios::app);
    if (file.is_open())
    {
        file << productname << "," << productprice << "," << producttype << "," << productquantity << "\n";
        file.close();
        cout << "Product added successfully!" << endl;
    }
    else
    {
        cout << "Error opening file for writing!" << endl;
    }
}

void Products::SearchProduct(const string& searchQuery)
{
    // Open the file for reading
    std::ifstream file("Text.txt");

    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return;
    }

    // Loop over each line of the file and search for matches
    std::string line;
    bool found = false;
    while (std::getline(file, line))
    {
        // Split the line into columns using commas as separator
        std::stringstream input(line);
        std::string name, price, type, quantity;
        std::getline(input, name, ',');
        std::getline(input, price, ',');
        std::getline(input, type, ',');
        std::getline(input, quantity);

        // Check if the product name matches the search query
        if (name == searchQuery)
        {
            cout << "                                                 " << endl;
            std::cout << "Search results for " << searchQuery << ":" << std::endl;
            cout << "                                      " << endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Price: " << price << std::endl;
            std::cout << "Type: " << type << std::endl;
            std::cout << "Quantity: " << quantity << std::endl;
            found = true;
            break; // Stop searching after the first match
        }
    }

    // Close the file
    file.close();

    // Print a message if no matches were found
    if (!found)
    {
        std::cout << "No matching products found." << std::endl;
    }
}

void Products::DeleteProduct(std::string search)
{
    // Open the file for reading
    std::ifstream inFile("Text.txt");
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return;
    }

    int i = 0;
    std::string line;
    while (std::getline(inFile, line) && i < maxrow) {
        std::stringstream input(line);
        std::getline(input, product_name[i], ',');
        std::getline(input, product_price[i], ',');
        std::getline(input, product_type[i], ',');
        std::getline(input, product_quantity[i], ',');
        i++;
    }

    inFile.close();

    // Find the index of the search string
    int index = -1;
    for (int i = 0; i < maxrow; i++) {
        if (product_name[i] == search) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cout << "Product not found" << std::endl;
        return;
    }

    // Remove the product from the arrays
    product_name[index] = "";
    product_price[index] = "";
    product_type[index] = "";
    product_quantity[index] = "";

    // Open the file for writing
    std::ofstream outFile("Text.txt");
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    // Write the modified data to the file
    for (int i = 0; i < maxrow; i++) {
        if (product_name[i] != "") {
            outFile << product_name[i] << "," << product_price[i] << "," << product_type[i] << "," << product_quantity[i] << std::endl;
        }
    }

    outFile.close();

    std::cout << "Product deleted successfully!" << std::endl;
}

void Products::ListProduct() {
    std::ifstream file("Text.txt");

    if (file.is_open()) {
        std::string line;
        int i = 0;
        while (std::getline(file, line) && i < maxrow) {
            std::stringstream input(line);
            std::getline(input, product_name[i], ',');
            std::getline(input, product_price[i], ',');
            std::getline(input, product_type[i], ',');
            std::getline(input, product_quantity[i]);

            i++;
        }

        file.close();

        for (int i = 0; i < maxrow; i++) {
            if (!product_name[i].empty()) {
                std::cout << "Name: " << product_name[i] << std::endl;
                std::cout << "Price: " << product_price[i] << std::endl;
                std::cout << "Type: " << product_type[i] << std::endl;
                std::cout << "Quantity: " << product_quantity[i] << std::endl;
                std::cout << std::endl;
            }
        }
    }
    else {
        std::cout << "Error opening file for reading!" << std::endl;
    }
}

void Products::AddProduct()
{
    cin.ignore();

    cout << "Enter the product's name: ";
    getline(cin, productname);

    cout << "Enter product's price: ";
    getline(cin, productprice);

    cout << "Enter product's type: ";
    getline(cin, producttype);

    cout << "Enter product's quantity: ";
    getline(cin, productquantity);

    for (int i = 0; i < maxrow; i++)
    {
        if (product_name[i].empty())
        {
            product_name[i] = productname;
            product_quantity[i] = productquantity;
            product_type[i] = producttype;
            product_price[i] = productprice;
            break;
        }
    }

    // Open the file for writing and append the new product information
    ofstream file("Text.txt", ios::app);
    if (file.is_open())
    {
        file << productname << "," << productprice << "," << producttype << "," << productquantity << "\n";
        file.close();
        cout << "Product added successfully!" << endl;
    }
    else
    {
        cout << "Error opening file for writing!" << endl;
    }
}

void store::ShowInfo()
{
    cout << "Welcome to our fashion store!\n\n";
    cout << "At our store, we're passionate about providing\n our customers with the latest and greatest fashion trends at affordable prices.\n\n";
    cout << "Our team of experienced fashion experts carefully\n curates our collections to ensure that we offer a wide variety of styles, from classic to trendy, that will suit any taste and occasion.\n\n";
    cout << "We strive to provide excellent customer service,\n and we're committed to making your shopping experience with us a pleasant and enjoyable one.\n\n";
    cout << "Thank you for choosing our store for your fashion needs.\n We look forward to helping you look and feel your best!\n\n";
}
