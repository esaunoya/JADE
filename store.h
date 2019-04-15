#pragma once

#include "product.h"
#include "customer.h"
#include <vector>

class Store {
public:
  Store(std::string store_name);
  std::string name(); // Returns store name

  // Product Management
  void add_product(Product* product); // Add a new product to stock
  void add_customer(Customer* customer);
  int number_of_products(); // # of products defined
  int number_of_customers();
  std::string product_to_string(int product); // string version of a product
  std::string customer_to_string(int customer);

  friend std::ostream& operator<<(std::ostream& ost, Store& store);

private:
  std::string _name;
  std::vector<Product*> _products;
  std::vector<Customer*> _customers;
};
