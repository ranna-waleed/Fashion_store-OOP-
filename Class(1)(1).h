#pragma once
#include<iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
const int MAX_PRODUCTS = 100;


//const int maxrow = 50;
//int product_quantity[maxrow] = {};
//string product_name[maxrow] = {};
//string product_type[maxrow] = {};
//double product_price[maxrow] = {};

#include <iostream>
#include <regex>



class User {
private:
    std::string Name;
    std::string Email;
    double Age;
    std::string Address;
    std::string Gender;

public:
    // Default constructor
    User():Age(0) {}

    // Parameterized constructor
    User(const std::string& N, const std::string& em, double ag, const std::string& address, const std::string& gen)
        : Name(N), Email(em), Age(ag), Address(address), Gender(gen) {}

    // Function to enter user data
    void enter_data() {
        std::cout << "Enter your name: ";
        std::cin.ignore();
        std::getline(std::cin, Name);

        // Email validation loop
        bool validEmail = false;
        while (!validEmail) {
            std::cout << "Enter your email: ";
            std::cin >> Email;

            // Email validation using regular expression
            std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
            if (std::regex_match(Email, emailRegex)) {
                validEmail = true;
            }
            else {
                std::cout << "Invalid email format. Please enter a valid email." << std::endl;
            }
        }

        std::cout << "Enter your age: ";
        std::cin >> Age;

        std::cin.ignore();
        std::cout << "Enter your address: ";
        std::getline(std::cin, Address);

        std::cout << "Enter your gender: ";
        std::cin >> Gender;
    }

    // Function to display user information
    void show_info() const {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Email: " << Email << std::endl;
        std::cout << "Age: " << Age << std::endl;
        std::cout << "Address: " << Address << std::endl;
        std::cout << "Gender: " << Gender << std::endl;
    }
};


const int SCmaxrow = 100;



const int WLmaxrow = 30;



//-------------------------------------------------------
class Wishlist {
private:
    std::string wishlist_product_name[WLmaxrow];

    bool IsProductValid(const std::string& productName, const std::string validProducts[], int validProductsCount)
    {
        // Convert the input product name to lowercase for case-insensitive comparison
        std::string lowercaseProductName = productName;
        std::transform(lowercaseProductName.begin(), lowercaseProductName.end(), lowercaseProductName.begin(), [](unsigned char c) {
            return std::tolower(c);
            });

        for (int i = 0; i < validProductsCount; i++)
        {
            std::string lowercaseValidProduct = validProducts[i];
            std::transform(lowercaseValidProduct.begin(), lowercaseValidProduct.end(), lowercaseValidProduct.begin(), [](unsigned char c) {
                return std::tolower(c);
                });

            if (lowercaseProductName == lowercaseValidProduct) {
                return true; // Valid product found
            }
        }
        
        return false; // Product not found
    }

    void ReadValidProductsFromFile(const std::string& filename, std::string validProducts[], int& validProductsCount)
    {
        std::ifstream file(filename);
        validProductsCount = 0;

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::size_t commaPos1 = line.find(',');

                if (commaPos1 != std::string::npos)
                {
                    std::string productName = line.substr(0, commaPos1);

                    // Remove leading and trailing spaces from the product name
                    productName = productName.substr(productName.find_first_not_of(" \t"));
                    productName = productName.substr(0, productName.find_last_not_of(" \t") + 1);

                    validProducts[validProductsCount] = productName;
                    validProductsCount++;

                    if (validProductsCount >= MAX_PRODUCTS) {
                        break; // Reached the maximum number of products to read
                    }
                }
            }
            file.close();
        }
        else
        {
            std::cout << "Error opening file: " << filename << std::endl;
        }
    }

public:
    void AddProducttoWL()
    {
        std::string wishlistProductName;

        std::cin.ignore();

        std::cout << "Enter the product's name you want to add to your wishlist (or 'done' to finish): ";
        std::getline(std::cin, wishlistProductName);

        // Check if the user wants to finish adding products
        if (wishlistProductName == "done") {
            return;
        }

        // Convert the product name to lowercase for case-insensitive comparison
        std::transform(wishlistProductName.begin(), wishlistProductName.end(), wishlistProductName.begin(), [](unsigned char c) {
            return std::tolower(c);
            });

        // Validate the product
        std::string validProducts[MAX_PRODUCTS];
        int validProductsCount = 0;
        ReadValidProductsFromFile("Text.txt", validProducts, validProductsCount);

        if (!IsProductValid(wishlistProductName, validProducts, validProductsCount)) {
            std::cout << "Invalid product. Please enter a valid product." << std::endl;
            AddProducttoWL(); // Recursively ask for a valid product
            return;
        }

        for (int i = 0; i < WLmaxrow; i++)
        {
            if (wishlist_product_name[i].empty())
            {
                wishlist_product_name[i] = wishlistProductName;
                break;
            }
        }

        // Open the file for writing and append the new product information
        std::ofstream file("wishlist.txt", std::ios::app);
        if (file.is_open())
        {
            file << wishlistProductName << "\n";
            file.close();
            std::cout << "Product added to wishlist successfully!" << std::endl;
        }
        else
        {
            std::cout << "Error opening file for writing!" << std::endl;
        }

        // Recursive call to add more products
        AddProducttoWL();
    }

    void showWLproducts()
    {
        system("CLS");
        std::cout << "             Wishlist Products           " << std::endl;
        std::cout << "===========================================" << std::endl;

        int counter = 0;
        std::cout << "No.\t|\tProduct Name" << std::endl
            << "---------------------------------------------" << std::endl;
        for (int x = 0; x < WLmaxrow; x++)
        {
            if (!wishlist_product_name[x].empty())
            {
                counter++;
                std::cout << " " << counter << "\t" << wishlist_product_name[x] << std::endl;
            }
        }

        if (counter == 0)
        {
            std::cout << "\t\tNo products found in the wishlist" << std::endl;
        }

        std::cout << "========================================" << std::endl;
    }
};





//talet mo7wala

//class ShoppingCart {
//private:
//    string purchased_product_name[MAX_PRODUCTS];
//    string purchased_product_quantity[MAX_PRODUCTS];
//    string purchased_product_price[MAX_PRODUCTS];
//
//public:
//    void AddProducttoSC();
//    void ReadValidProductsFromFile(const string& filename, string validProducts[], string validPrices[], int& validProductsCount);
//    bool IsProductValid(const string& productName, const string validProducts[], const string validPrices[], int validProductsCount, string& price);
//    string TrimString(const string& str);
//    void showSCproducts();
//};


//class giftcard :public receipt
//{
//private:
//    int giftcard_amount;
//    double finalprice;
//public:
//    void buy_giftcard(giftcard_amount) {};
//    int redeem_giftcard();
//    void set_giftcard_amont(int amount) { giftcard_amount = amount; }
//    int get_giftcard_amount() { return giftcard_amount; }
//};

class Review {
private:
    string storeName = "Fashion store";
    string review;
public:
    void showReview() {
        cout << "Welcome to " << storeName << " Review Class!" << endl;
        cout << "Please rate our online store from 1 to 5. (1 = poor, 2 = fair, 3 = good, 4 = very good, 5 = excellent)" << endl;
        int rating;
        cin >> rating;
        if (rating <= 2) {
            cout << "We're sorry to hear that you didn't enjoy your experience. Could you please provide some feedback on what we could improve?" << endl;
            string feedback;
            getline(cin, feedback);
            cout << "Thank you for the feedback! We'll do our best to address your concerns." << endl;
        }

        else {
            cout << "We're glad to hear that you had a good experience! We'd love to hear more about what you enjoyed about our online store. Could you please provide some feedback?" << endl;
            string feedback;
            getline(cin, feedback);
            cout << "Thank you for the feedback! We appreciate your business and hope to see you again soon at " << storeName << "." << endl;
        }
        cout << "\n What is your review : ";
        cin >> review;
    }
};

//class Receipt {
//public:
//
//    void GenerateReceipt();
//};



//      --------------------------------------------------------------


class ShoppingCart {
private:
    string purchased_product_name[SCmaxrow];
    string purchased_product_quantity[SCmaxrow];
    string purchased_product_price[SCmaxrow];

public:
    void AddProducttoSC();
    void ReadValidProductsFromFile(const string& filename, string validProducts[], string validPrices[], int& validProductsCount);
    bool IsProductValid(const string& productName, const string validProducts[], const string validPrices[], int validProductsCount, string& price);
    string TrimString(const string& str);
    void showSCproducts();

    friend class Receipt;
};

class Receipt {
public:
    void GenerateReceipt(const ShoppingCart& cart);
};
