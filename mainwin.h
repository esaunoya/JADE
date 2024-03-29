#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();            // Exit the program
        void on_view_all_click();        // View all products
        void on_create_coffee_click();   // Create a new coffee product
        void on_create_donut_click();    // Create a new donut product
        void on_list_customers_click();  // List all customers
        void on_new_customer_click();    // Create a new customer
        void on_about_click();           // About dialog
        void on_new_click();
        void on_save_click();
        void on_save_as_click();
        void on_load_click();
    private:
        Store _store;
        Gtk::Label *msg;                      // Status message display
        Gtk::MenuItem *menuitem_new_coffee;   // Create -> Coffee
        Gtk::MenuItem *menuitem_new_donut;    // Create -> Donut
        Gtk::MenuItem *menuitem_new_order;    // Create -> Order
};
#endif
