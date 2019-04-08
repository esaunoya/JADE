#include "product.h"

#include <iostream>
#include <iomanip>

Product::Product(std::string name, double price, double cost) : _name{name}, _price{price}, _cost{cost} {}

/*
Product::Product(std::istream& ist) {
    std::getline(ist, _name);
    ist >> _price; ist.ignore();
}*/

/*
void Product::save(std::ostream& ost) {
    ost << _name << '\n' << _price << '\n';
}*/

std::string Product::name() const {return _name;}

std::string Product::to_string(){
  std::cout << product._name << " ($" << std::fixed << std::setprecision(2) << product._price << ')';
}

//double Product::price() const {return _price;}

/*
std::ostream& operator<<(std::ostream& ost, const Product& product) {
    ost << product._name << " ($" << std::fixed << std::setprecision(2) << product._price << ')';
    return ost;
}
*/
