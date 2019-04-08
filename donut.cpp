#include "donut.h"

Donut::Donut(std::string name, double price, double cost, Frosting frosting, Filling filling) : Product{name, price, cost}, _frosting{frosting}, _filling{filling} {}
