#ifndef BASKET_MANAGER_HPP
#define BASKET_MANAGER_HPP

#include <chrono>
#include <vector>
#include "Customer.hpp"
#include "ProductCatalogue.hpp"

struct ProductSelection
{
    Product product;
    int quantity;
};

class Basket
{
private:
    int id;
    Customer customer;
    std::chrono::system_clock::time_point dateTime;
    std::vector<ProductSelection> productSelections;

public:

    Basket(int id, Customer customer, std::vector<Product> products);
    ~Basket();

    std::vector<ProductSelection> GenerateProductSelections(std::vector<Product> products);
    void DisplayProducts();
    double GetTotal();
    bool AssignCustomer(Customer customer);
    void AddProduct(int productId, int quantity);
    std::vector<ProductSelection> GetProductSelections();
};

class BasketManager
{
private:
    std::vector<Basket> baskets;
    ProductCatalogue productCatalogue;

public:
    BasketManager();
    void CreateBasket(Customer customer);
    Basket GetBasket(int basketId);
};

#endif