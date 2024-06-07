#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include"Class.h"
//const int SCmaxrow = 100;
//const int MAX_PRODUCTS = 100;

using namespace std;

void ShoppingCart::AddProducttoSC() {
    string purchasedProductName, purchasedProductQuantity;

    cin.ignore();

    cout << "Enter the product's name you want to add to your shopping cart (or 'done' to finish): ";
    getline(cin, purchasedProductName);

    // Check if the user wants to finish adding products
    if (purchasedProductName == "done" || purchasedProductQuantity == "done") {
        return;
    }
    cout << "Enter the product's quantity you want to add to your shopping cart: ";
    getline(cin, purchasedProductQuantity);

    // Convert the product name to lowercase for case-insensitive comparison
    transform(purchasedProductName.begin(), purchasedProductName.end(), purchasedProductName.begin(), [](unsigned char c) {
        return tolower(c);
        });

    // Validate the product
    string validProducts[MAX_PRODUCTS];
    string validPrices[MAX_PRODUCTS];
    int validProductsCount = 0;

    ReadValidProductsFromFile("Text.txt", validProducts, validPrices, validProductsCount);

    string productPrice;
    if (!IsProductValid(purchasedProductName, validProducts, validPrices, validProductsCount, productPrice)) {
        cout << "Invalid product. Please enter a valid product." << endl;
        AddProducttoSC(); // Recursively ask for a valid product
        return;
    }

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (purchased_product_name[i].empty()) {
            purchased_product_name[i] = purchasedProductName;
            purchased_product_price[i] = productPrice;
            purchased_product_quantity[i] = purchasedProductQuantity;
            break;
        }
    }

    // Open the file for writing and append the new product information
    ofstream file("shoppingcart.txt", ios::app);
    if (file.is_open()) {
        file << purchasedProductName << ", " << purchasedProductQuantity << "\n";
        file.close();
        cout << "Product added to shopping cart successfully!" << endl;
    }
    else {
        cout << "Error opening file for writing!" << endl;
    }

    // Recursive call to add more products
    AddProducttoSC();
}

void ShoppingCart::ReadValidProductsFromFile(const string& filename, string validProducts[], string validPrices[], int& validProductsCount) {
    ifstream file(filename);
    validProductsCount = 0;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string productName, productPrice;

            if (getline(ss, productName, ',') && getline(ss, productPrice, ',')) {
                // Remove leading and trailing spaces from the product name and price
                productName = TrimString(productName);
                productPrice = TrimString(productPrice);

                validProducts[validProductsCount] = productName;
                validPrices[validProductsCount] = productPrice;
                validProductsCount++;
            }
        }

        file.close();
    }
    else {
        cout << "Error opening file: " << filename << endl;
    }
}

bool ShoppingCart::IsProductValid(const string& productName, const string validProducts[], const string validPrices[], int validProductsCount, string& price) {
    // Convert the input product name to lowercase for case-insensitive comparison
    string lowercaseProductName = productName;
    transform(lowercaseProductName.begin(), lowercaseProductName.end(), lowercaseProductName.begin(), [](unsigned char c) {
        return tolower(c);
        });

    for (int i = 0; i < validProductsCount; i++) {
        string lowercaseValidProduct = validProducts[i];
        transform(lowercaseValidProduct.begin(), lowercaseValidProduct.end(), lowercaseValidProduct.begin(), [](unsigned char c) {
            return tolower(c);
            });

        if (lowercaseProductName == lowercaseValidProduct) {
            price = validPrices[i];
            return true; // Valid product found
        }
    }

    return false; // Product not found
}

string ShoppingCart::TrimString(const string& str) {
    string trimmed = str;
    size_t first = trimmed.find_first_not_of(" \t");
    size_t last = trimmed.find_last_not_of(" \t");

    if (first != string::npos && last != string::npos) {
        trimmed = trimmed.substr(first, (last - first + 1));
    }
    else {
        trimmed.clear();
    }

    return trimmed;
}

void ShoppingCart::showSCproducts() {
    cout << "Shopping cart products:" << endl;

    int counter = 0;
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (!purchased_product_name[i].empty()) {
            counter++;
            cout << "Product " << counter << ":" << endl;
            cout << "Name: " << purchased_product_name[i] << endl;
            cout << "Price: " << purchased_product_price[i] << endl;
            cout << "Quantity: " << purchased_product_quantity[i] << endl;
            cout << endl;
        }
    }

    if (counter == 0) {
        cout << "No products found in the shopping cart." << endl;
    }
}
void Receipt::GenerateReceipt(const ShoppingCart& cart) {
    cout << "------ Receipt ------" << endl;

    double totalPrice = 0.0;
    // total_orders = 0.0;
    // total_sales = 0.0;
    int counter = 0;
    for (int i = 0; i < SCmaxrow; i++) {
        if (!cart.purchased_product_name[i].empty()) {
            counter++;
            // Calculate the total price for the product
            double productPrice = stod(cart.purchased_product_price[i]);
            int productQuantity = stoi(cart.purchased_product_quantity[i]);
            double productTotalPrice = productPrice * productQuantity;
            totalPrice += productTotalPrice;

            cout << "Product " << counter << ":" << endl;
            cout << "Name: " << cart.purchased_product_name[i] << endl;
            cout << "Price: " << productPrice << endl;
            cout << "Quantity: " << productQuantity << endl;
            cout << "Total Price: " << productTotalPrice << endl;
            cout << endl;
        }
    }

    //total_orders = total_orders + 1;
   // total_sales = total_sales + totalPrice;
    cout << "---------------------" << endl;
    cout << "Total Price: " << totalPrice << endl;
}
