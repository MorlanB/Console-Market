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