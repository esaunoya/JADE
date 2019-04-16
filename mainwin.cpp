#include "mainwin.h"
#include "dialogs.h"
#include "java.h"
#include "donut.h"

#include <ostream>
#include <iostream>
#include <regex>

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
  msg = Gtk::manage(new Gtk::Label());
  msg->set_hexpand(true);
  vbox->add(*msg);

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
  Gtk::MessageDialog d{*this, _store.customer_list()};
  int result = d.run();
}

void Mainwin::on_new_customer_click() {
    Gtk::Dialog *dialog = new Gtk::Dialog("New Customer", *this);

    // Name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // Phone Number
    Gtk::HBox b_phone;

    Gtk::Label l_phone{"Phone:"};
    l_phone.set_width_chars(15);
    b_phone.pack_start(l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry e_phone;
    e_phone.set_max_length(50);
    b_phone.pack_start(e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_phone, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("Create", 1);
    dialog->show_all();

    int result;
    std::string name, phone;
    std::regex re_phone{"[(]?(\\d{3,3}[-)])?\\d{3,3}-\\d{4,4}"};
    bool fail = true;  // set to true if any data is invalid

    while (fail) {
        fail = false;  // optimist!
        result = dialog->run();
        if (result != 1) {delete dialog; return;}
        name = e_name.get_text();
        if (name.size() == 0) {
            e_name.set_text("### Invalid ###");
            fail = true;
        }
        phone = e_phone.get_text();
        if(!std::regex_match(phone,re_phone)) {
            e_phone.set_text("### Invalid ###");
            fail = true;
        }
    }
    Customer* customer = new Customer{name, phone};
    _store.add_customer(customer);

    delete dialog;
}

/*void Mainwin::on_create_coffee_click() { // Create a new coffee product
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
}*/

void Mainwin::on_create_coffee_click() { // Create a new coffee product
  std::string name;
  int shot, darkness;
  double price, cost;

  Shot shots;


  Gtk::Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Create Coffee");

  // Coffee NAME
  Gtk::HBox b_name;

  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(15);
  b_name.pack_start(l_name, Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(50);
  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

  // Coffee PRICE
  Gtk::HBox b_price;

  Gtk::Label l_price{"Price:"};
  l_price.set_width_chars(15);
  b_price.pack_start(l_price, Gtk::PACK_SHRINK);

  Gtk::Entry e_price;
  e_price.set_max_length(50);
  b_price.pack_start(e_price, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

  // DONUT COST
  Gtk::HBox b_cost;

  Gtk::Label l_cost{"Cost:"};
  l_cost.set_width_chars(15);
  b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

  Gtk::Entry e_cost;
  e_cost.set_max_length(50);
  b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

  //COFFEE DARKNESS
  Gtk::HBox b_darkness;

  Gtk::Label l_darkness{"Darkness:"};
  l_darkness.set_width_chars(15);
  b_darkness.pack_start(l_darkness, Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_darkness;
  c_darkness.set_size_request(160);
  c_darkness.append("Blond");
  c_darkness.append("Light");
  c_darkness.append("Medium");
  c_darkness.append("Dark");
  c_darkness.append("Extra Dark");

  b_darkness.pack_start(c_darkness, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_darkness, Gtk::PACK_SHRINK);


  // SHOTS
  Gtk::HBox b_shot;

  Gtk::Label l_shot{"Shot:"};
  l_shot.set_width_chars(15);
  b_shot.pack_start(l_shot, Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_shot;
  c_shot.set_size_request(160);
  c_shot.append("NONE");
  c_shot.append("Chocolate");
  c_shot.append("Vanilla");
  c_shot.append("Peppermint");
  c_shot.append("Hazelnut");

  b_shot.pack_start(c_shot, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_shot, Gtk::PACK_SHRINK);


  // Show dialog
  dialog->add_button("Cancel", 0);
  dialog->add_button("OK", 1);
  dialog->show_all();
  int result = dialog->run();

  dialog->close();
  //while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  try{
    if (result == 1) {
      name = e_name.get_text();
      price = std::stod(e_price.get_text());
      cost = std::stod(e_cost.get_text());

      shot = c_shot.get_active_row_number();
      darkness = c_darkness.get_active_row_number();

			Java* j = new Java{name, price, cost, darkness};


			_store.add_product(j);
    }
  } catch (std::exception e) {
    Dialogs::message("Unable to create new coffee", "ERROR");
  }
}

/*void Mainwin::on_create_donut_click() { // Create a new donut product
  Frosting frosting = (Frosting)(rand()%frosting_to_string.size());
  Filling filling = (Filling)(rand()%filling_to_string.size());
  Donut* d = new Donut{"Donut", 0.75, 0.25, frosting, true, filling};
  _store.add_product(d);
}*/

void Mainwin::on_create_donut_click() { // Create a new donut product

  std::string name;
  int frosting, filling, sprinkle;
  double price, cost;
  bool sprinkles;

  Frosting frostings;
  Filling fillings;

  Gtk::Dialog *dialog = new Gtk::Dialog();
  dialog->set_title("Create Donut");

  // DONUT NAME
  Gtk::HBox b_name;

  Gtk::Label l_name{"Name:"};
  l_name.set_width_chars(15);
  b_name.pack_start(l_name, Gtk::PACK_SHRINK);

  Gtk::Entry e_name;
  e_name.set_max_length(50);
  b_name.pack_start(e_name, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

  // DONUT PRICE
  Gtk::HBox b_price;

  Gtk::Label l_price{"Price:"};
  l_price.set_width_chars(15);
  b_price.pack_start(l_price, Gtk::PACK_SHRINK);

  Gtk::Entry e_price;
  e_price.set_max_length(50);
  b_price.pack_start(e_price, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_price, Gtk::PACK_SHRINK);

  // DONUT COST
  Gtk::HBox b_cost;

  Gtk::Label l_cost{"Cost:"};
  l_cost.set_width_chars(15);
  b_cost.pack_start(l_cost, Gtk::PACK_SHRINK);

  Gtk::Entry e_cost;
  e_cost.set_max_length(50);
  b_cost.pack_start(e_cost, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);

  // FROSTING
  Gtk::HBox b_frosting;

  Gtk::Label l_frosting{"Frosting:"};
  l_frosting.set_width_chars(15);
  b_frosting.pack_start(l_frosting, Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_frosting;
  c_frosting.set_size_request(160);
  c_frosting.append("Unfrosted");
  c_frosting.append("Chocolate Top");
  c_frosting.append("Vanilla Top");
  c_frosting.append("Pink Top");

  b_frosting.pack_start(c_frosting, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_frosting, Gtk::PACK_SHRINK);

  // FILLING
  Gtk::HBox b_filling;

  Gtk::Label l_filling{"Filling:"};
  l_filling.set_width_chars(15);
  b_filling.pack_start(l_filling, Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_filling;
  c_filling.set_size_request(160);
  c_filling.append("Unfilled");
  c_filling.append("Creme");
  c_filling.append("Bavaian");
  c_filling.append("Strawberry");

  b_filling.pack_start(c_filling, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_filling, Gtk::PACK_SHRINK);

  // SPRINKLES
  Gtk::HBox b_sprinkle;

  Gtk::Label l_sprinkle{"Sprinkles?:"};
  l_sprinkle.set_width_chars(15);
  b_sprinkle.pack_start(l_sprinkle, Gtk::PACK_SHRINK);

  Gtk::ComboBoxText c_sprinkle;
  c_sprinkle.set_size_request(160);
  c_sprinkle.append("NO");
  c_sprinkle.append("YES");

  b_sprinkle.pack_start(c_sprinkle, Gtk::PACK_SHRINK);
  dialog->get_vbox()->pack_start(b_sprinkle, Gtk::PACK_SHRINK);

  // Show dialog
  dialog->add_button("Cancel", 0);
  dialog->add_button("OK", 1);
  dialog->show_all();
  int result = dialog->run();

  dialog->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration();

  try{
    if (result == 1) {
      name = e_name.get_text();
      price = std::stod(e_price.get_text());
      cost = std::stod(e_cost.get_text());

      sprinkle = c_sprinkle.get_active_row_number();
      frosting = c_frosting.get_active_row_number();
      filling = c_filling.get_active_row_number();
      // converting returned int from gui to Frosting enum type
      if(frosting == 1){
        frostings = Frosting::Unfrosted;
      }
      else if(frosting == 2){
        frostings = Frosting::Chocolate_top;
      }
      else if(frosting == 3){
        frostings = Frosting::Vanilla_top;
      }
      else if(frosting == 4){
        frostings = Frosting::Pink_top;
      }
      // converting returned int from gui to Filling enum type
      if(filling == 1){
        fillings = Filling::Unfilled;
      }
      else if(filling == 2){
        fillings = Filling::Creme;
      }
      else if(filling == 3){
        fillings = Filling::Bavarian;
      }

      else if(filling == 4){
        fillings = Filling::Strawberry;
      }
      if(sprinkle == 1){
        sprinkles == false;
      }
      else if(sprinkle == 2){
        sprinkles == true;
      }
      Donut* d = new Donut{name, price, cost, frostings, sprinkles, fillings};
      _store.add_product(d);
    }
  } catch (std::exception e) {
    Dialogs::message("Unable to create new donut", "ERROR");
  }


}

void Mainwin::on_quit_click(){
  close();
}
