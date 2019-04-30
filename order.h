#pragma once
#include "product.h"
#include <vector>

class Order{
protected:
  std::vector<Product *> _products;
private:
  static int _next_order_number;
  int _order_number;
  mutable bool _is_paid;
  mutable bool _is_filled;
public:
  Order();
  void add_product(Product *product);
  bool is_paid() const;
  void pay() const;
  bool is_filled() const;
  void fill() const;
};
