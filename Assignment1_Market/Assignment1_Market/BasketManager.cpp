#include "ProductCatalogue.hpp"
#include "Customer.hpp"
#include "BasketManager.hpp"

#include <iostream>
#include <vector>
#include <chrono>


BasketManager::BasketManager()
{
    baskets = std::vector<Basket>();
    productCatalogue = ProductCatalogue();
}

void BasketManager::CreateBasket(Customer customer)
{
    Basket basket(baskets.size(), customer, productCatalogue.GetProducts());
    baskets.push_back(basket);
}

Basket BasketManager::GetBasket(int basketId)
{
    return baskets[basketId];
}

Basket::Basket(int id, Customer customer, std::vector<Product> products)
{
    this->id = id;
    this->customer = customer;
    productSelections = GenerateProductSelections(products);
    dateTime = std::chrono::system_clock::now();
}

Basket::~Basket()
{
}

std::vector<ProductSelection> Basket::GenerateProductSelections(std::vector<Product> products)
{
    for (int i = 0; i < products.size(); i++)
    {
        productSelections.push_back(ProductSelection{ products[i], 0 });
    }
    return productSelections;
}

void Basket::DisplayProducts()
{
    for (int i = 0; i < sizeof(productSelections); i++)
    {

    }
}

bool Basket::AssignCustomer(Customer customer)
{
    this->customer = customer;
    return true;
}

void  Basket::AddProduct(int productId, int quantity)
{
    for (int i = 0; i < productSelections.size(); i++)
    {
        if (productSelections[i].product.id == productId)
        {
            productSelections[i].quantity += quantity;
        }
    }
}

std::vector<ProductSelection> Basket::GetProductSelections()
{
    return std::vector<ProductSelection>();
}
