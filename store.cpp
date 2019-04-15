#include "store.h"
#include <sstream>

Store::Store(std::string store_name) : _name{store_name} { }

std::string Store::name() {return _name;}

// Product Management
void Store::add_product(Product* product) {_products.push_back(product);}

int Store::number_of_products() {return _products.size();}

std::string Store::product_to_string(int product){
  std::ostringstream oss;
  oss << _products[product];
  return oss.str();
}

std::ostream& operator<<(std::ostream& ost, Store& store){
  ost << "Store " << store._name << std::endl << std::endl;
  ost << "Products " << std::endl;
  for(auto p : store._products) ost << " " << p->to_string() << std::endl;
  return ost;
}
