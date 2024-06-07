#pragma once

#include<iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <string>

class Products {
private:

    string productname, producttype, productprice, productquantity;
	static const int maxrow = 30;
	std::string product_quantity[maxrow];
	std::string product_name[maxrow];
	std::string product_type[maxrow];
	std::string product_price[maxrow];

public:
    void UpdateProduct(string search);
    void SearchProduct(const string& searchQuery);
    void DeleteProduct(std::string search);
    void ListProduct();
    void AddProduct();
};


class store {
public:
    void ShowInfo();
};


