#include "ProductCatalogue.hpp"

#include <vector>
#include <string>

bool ProductCatalogue::RemoveProduct(int productId)
{
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].id == productId)
		{
			products.erase(products.begin() + i);
			return true;
		}
	}
	return false;
}

std::vector<Product> ProductCatalogue::GetProducts()
{
	return products;
}

int ProductCatalogue::GenerateProductId()
{
	int newId = products.size() + 1;
	while (GetProduct(newId).id > -1)
		newId++;

	return newId;
}

Product ProductCatalogue::GetProduct(int productId)
{
for (int i = 0; i < products.size(); i++)
	{
		if (products[i].id == productId)
		{
			return products[i];
		}
	}
	return Product(-1, "", -1);
}

void ProductCatalogue::DisplayProducts()
{
	std::cout << "Product Catalogue" << std::endl << std::endl;
	std::cout << " ID" << "\t" << "Name" << "\t\t\t" << "Price" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < products.size(); i++)
	{
		std::cout << " " << products[i].id << "\t" << products[i].name << "\t\t" << products[i].price << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void ProductCatalogue::AddProduct(Product product)
{
	products.push_back(product);
}

Product::Product(int id, std::string name, double price)
{
	this->id = id;
	this->name = name;
	this->price = price;
}