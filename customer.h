#pragma once
#include <string>
#include <ostream>

class Customer {
public:
  Customer(std::string customer, std::string customer_phone);
  Customer();

  std::string name();
  std::string phone();
  
  virtual std::string to_string();

protected:
  std::string _customer;
  std::string _customer_phone;

};
