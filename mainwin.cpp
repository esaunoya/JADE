#include "mainwin.h"
#include "java.h"
#include "donut.h"

#include <ostream>
#include <iostream>

Mainwin::Mainwin() : _store{Store{"JADE"}} {

  ///////////////
  //           //
  // GUI SETUP //
  //           //
  ///////////////

  set_title("JADE - Java and Donut Express");
  set_default_size(800, 600);

  // Put a vertical box container as the Window contents
  Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
  add(*vbox);

  //
  // MENU
  //

  // Add a menu bar as the top item in the vertical Box
  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
  vbox -> pack_start(*menubar, Gtk::PACK_SHRINK, 0);

  // FILE

  // Create a File menu and add to the menu bar
  Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar -> append(*menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file -> set_submenu(*filemenu);

  // --- QUIT

  // Append Quit to the File menu
  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit -> signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
  filemenu -> append(*menuitem_quit);

  // VIEW

  //Create a View menu and add to the menu MenuBar
  Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
  menubar -> append(*menuitem_view);
  Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
  menuitem_view -> set_submenu(*viewmenu);

  // --- CUSTOMERS
  Gtk::MenuItem *menuitem_view_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
  menuitem_view_customers -> signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers_click));
  viewmenu -> append(*menuitem_view_customers);

  // --- ALL PRODUCTS
  Gtk::MenuItem *menuitem_all_products = Gtk::manage(new Gtk::MenuItem("_All Products", true));
  menuitem_all_products -> signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
  viewmenu -> append(*menuitem_all_products);

  // CREATE
  Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
  menubar->append(*menuitem_create);
  Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
  menuitem_create->set_submenu(*createmenu);

  // --- CUSTOMER
  menuitem_new_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
  menuitem_new_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_new_customer_click));
  createmenu->append(*menuitem_new_customer);

  // --- COFFEE
  menuitem_new_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee", true));
  menuitem_new_coffee->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
  createmenu->append(*menuitem_new_coffee);

  // --- DONUT
  menuitem_new_donut = Gtk::manage(new Gtk::MenuItem("_Donut", true));
  menuitem_new_donut->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
  createmenu->append(*menuitem_new_donut);

  // STATUS BAR DISPLAY


  // Make the box and everything in it visible
  vbox -> show_all();

}

Mainwin::~Mainwin() {}

///////////////
//           //
// CALLBACKS //
//           //
///////////////

void Mainwin::on_view_all_click() { // View all products
  std::ostringstream oss;
  oss << _store << std::endl;
  Gtk::MessageDialog d{*this, oss.str()};
  int result = d.run();
}

void Mainwin::on_list_customers_click() { // View all products

}

void Mainwin::on_new_customer_click() { // Create a new coffee product

//  _store.add_product(c);
}

void Mainwin::on_create_coffee_click() { // Create a new coffee product
  int darkness = rand() % DARK_LEVELS;
  double price = 5.00;
  double cost = 2.00;
  Java* c = new Java{"Coffee", price, cost, darkness};
  int shot_clock = rand() % 4; // vary the number of shots
  while (shot_clock--) {
    Shot shot = (Shot)((rand() % (shot_to_string.size()-1))+1);
    c->add_shot(shot);
  }
  _store.add_product(c);
}

void Mainwin::on_create_donut_click() { // Create a new donut product
  Frosting frosting = (Frosting)(rand()%frosting_to_string.size());
  Filling filling = (Filling)(rand()%filling_to_string.size());
  Donut* d = new Donut{"Donut", 0.75, 0.25, frosting, true, filling};
  _store.add_product(d);
}

void Mainwin::on_quit_click(){
  close();
}
