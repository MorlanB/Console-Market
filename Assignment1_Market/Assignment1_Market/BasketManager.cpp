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
    std::cout << "Products in basket:\n\n";
    std::cout << "ID" << "\t" << "Name" << "\t\t\t" << "Price" <<  "\t" << "Amount" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    for (int i = 0; i < 7; i++)
    {
        std::cout << productSelections[i].product.id << "\t" << productSelections[i].product.name << "\t\t" << productSelections[i].product.price << "\t" << " x " << productSelections[i].quantity << "\t" << (productSelections[i].product.price * productSelections[i].quantity) << std::endl;
    }

    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "\t\t\t\tTotal: " << "\t\t" << GetTotal() << std::endl;
    std::cout << std::endl;
}

double Basket::GetTotal()
{
    double total = 0;
    for (int i = 0; i < productSelections.size(); i++)
    {
        total += productSelections[i].product.price * productSelections[i].quantity;
    }
    return total;
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

    std::cout << "Product added to basket" << productId << " x " << quantity << std::endl;
}

std::vector<ProductSelection> Basket::GetProductSelections()
{
    return productSelections;
}
