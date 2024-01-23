#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include <iostream>
#include <string>
#include <vector>

class Product
{
    //private:

public:
    int id;
    std::string name;
    double price;
    Product(int id, std::string name, double price);
};

class ProductCatalogue
{
private:
    std::vector<Product> products;
public:
    ProductCatalogue()
        : products({
              Product(1, "Spicy Pepper", 10.0f),
              Product(2, "Sunshroom", 5.0f),
              Product(3, "Hydromelon", 12.0f),
              Product(4, "Voltfruit", 7.0f),
              Product(5, "Safflina", 10.0f),
              Product(6, "Swift Carrot", 3.0f),
              Product(7, "Endura Carrot", 4.0f)
            }) {
    }

    void AddProduct(Product product);
    bool RemoveProduct(int productId);
    std::vector<Product> GetProducts();
};

#endif