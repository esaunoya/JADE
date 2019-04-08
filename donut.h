#ifndef __DONUT_H
#define __DONUT_H

#include "product.h"

enum Frosting { Unfrosted, Chocolate, Vanilla, Pink };
enum Filling { Unfilled, Creme, Bavarian, Strawberry };

class Donut : public Product {

public:
  Donut(std::string name, double price, double cost, Frosting frosting, Filling filling);

private:
  Frosting _frosting;
  bool _sprinkles;
  Filling _filling;

}

#endif
