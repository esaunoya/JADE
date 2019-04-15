#include "customer.h"
#include <sstream>
#include <iostream>
#include <iomanip>


Customer::Customer(std::string customer, std::string customer_phone)
  : _customer{customer}, _customer_phone{customer_phone} {}

Customer::Customer(){
  _customer = "John Doe";
  _customer_phone = "1234567890";
}

std::string Customer::name() {return _customer;}
std::string Customer::phone() {return _customer_phone;}

std::string Product::to_string(){
  std::ostringstream oss;
  oss << _customer << ", " << _customer_phone;
  return oss.str();
}
