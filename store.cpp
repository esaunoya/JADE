#include "store.h"
#include <vector>
Store::Store(std::string store_name) : _name{store_name} { }

Store::Store(std::istream &ist)
{
    std::getline(ist, _name);

    // NEED TO PASS DONUT / JAVA NOT PRODUCT
    //int products;
    //ist >> products; ist.ignore();
    //while(products-- > 0) _products.push_back(Product{ist});
    //int customers;
    //ist >> customers; ist.ignore();
    //while(customers-- > 0) _customers.push_back(Customer{ist});
}

void Store::save(std::ostream& ost) {
    ost << _name << '\n';
    //ost << _products.size() << '\n';
    //for (auto& p : _products) p->save(ost);
    //ost << _customers.size() << '\n';
    //for (auto& c : _customers) c->save(ost);
}

std::string Store::name() {return _name;}

void Store::add_product(Product* product) {_products.push_back(product);}
int Store::number_of_products() {return _products.size();}
std::string Store::product_to_string(int product) {
    std::ostringstream oss;
    oss << _products[product];
    return oss.str();
}

void Store::add_customer(Customer* customer) {_customers.push_back(customer);}
int Store::number_of_customers() {return _customers.size();}
std::string Store::customer_to_string(int customer) {
    std::ostringstream oss;
    oss << *_customers[customer];
    return oss.str();
}

std::ostream& operator<<(std::ostream& ost, Store& store) {
    ost << "Store " << store._name << std::endl << std::endl;
    ost << "Products: " << std::endl;
    for (auto p : store._products) ost << "  " << p->to_string() << std::endl;
    return ost;
}
