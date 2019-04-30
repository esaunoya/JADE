#include "order.h"

int Order::_next_order_number = 0;

Order::Order() : _order_number{_next_order_number++}, _is_paid{false}, _is_filled{false} {_next_order_number+=1;}

void Order::add_product(Product *product){
  _products.push_back(product);
}

bool Order::is_paid() const{
  return _is_paid;
}

void Order::pay() const{
  _is_paid = true;
}

bool Order::is_filled() const{
  return _is_filled;
}

void Order::fill() const{
  _is_filled = true;
}
