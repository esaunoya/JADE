#pragma once
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

class Product {
  public:
    Product(std::string name, double price, double cost);
    Product(std::istream& ist);
    void save(std::ostream& ost);
    std::string name();
    virtual std::string to_string();
  protected:
    std::string _name;
    double _price;
    double _cost;
};
