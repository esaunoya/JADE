#include "view.h"
#include <sstream>

View::View(Store& store) : _store{store} { }

std::string View::main_menu(bool _gui) {
  return R"(
    :)
)";
}

/*
std::string View::help(bool _gui) {
    if (_gui) {
        return R"(
                    <span font='18' weight='bold' underline='double'>Welcome to C1325 MavMart</span><span font='18'><sup><small>™</small></sup></span>

by Professor George F. Rice
<span font='7'>Copyright 2019. Licensed under the Gnu General Public License 3.0
https://www.gnu.org/licenses/gpl-3.0.en.html</span>

This program manages an on-line store named MavMart, which sells
generic products such as you would find at Walmart, K-Mart, or Target.

<b>Adding a new product (option 1)</b> requires only the product name
and price. The name is any string of text, and the price is any number.

<b>Listing all products (option 2)</b> displays all information known about
the products available at MavMart.

<b>Placing an order (option 4)</b> requires a buyer's email address. The email
address is any string of text, and is not verified. Then, products may
be selected by their automatically generated product number with
associated quantity. Entering special product number -1 completes
the order.

<b>Listing all orders (option 5)</b> simply lists every order in the system.
WARNING: This may be a very long list.

<b>Save Data (option 7)</b> writes all data to the specified file in the current folder.

<b>Load Data (option 8)</b> lists all available data file, and loads the specified
file, replacing any existing data <span color='red'>without warning.</span>

<i>Undocumented option 42 adds test data.</i>
)";
    } else {
        return R"(
This program manages an on-line store named MavMart, which sells
generic products such as you would find at Walmart, K-Mart, or Target.

Adding a new product (option 1) requires only the product name
and price. The name is any string of text, and the price is any number.

Listing all products (option 2) displays all information known about
the products available at MavMart.

Placing an order (option 4) requires a buyer's email address. The email
address is any string of text, and is not verified. Then, products may
be selected by their automatically generated product number with
associated quantity. Entering special product number -1 completes
the order.

Listing all orders (option 5) simply lists every order in the system.
WARNING: This may be a very long list.

Save Data (option 7) writes all data to the specified file in the current folder.

Load Data (option 8) lists all available data file, and loads the specified
file, replacing any existing data <span color='red'>without warning.
)";
    }
}
*/
