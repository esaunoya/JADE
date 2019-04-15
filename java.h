#pragma once

#include "product.h"
#include <ostream>
#include <vector>

enum Shot {None, Chocolate, Vanilla, Peppermint, Hazelnut};
const std::vector<std::string> shot_to_string =
  {"none", "chocolate", "vanilla", "peppermint", "hazelnut"};

const int DARK_LEVELS = 5;

class Java : public Product {

public:
  Java(std::string name, double price, double cost, int darkness);
  void add_shot(Shot shot);
  std::string to_string() override;

protected:
  int _darkness;
  std::vector<Shot> _shots;
};
