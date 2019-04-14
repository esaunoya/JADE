#pragma once

#include "product.h"
#include <vector>

class Store {
public:
  Store(std::string store_name);
  std::string name() const; // Returns store name

  // Product Management
  void add_product(Product* product); // Add a new product to stock
  int number_of_products(); // # of products defined
  std::string product_to_string(int product); // string version of a product

  friend std::ostream& operator<<(std::ostream& ost, Store& store);

private:
  std::string _name;
  std::vector<Product> _products;
};
