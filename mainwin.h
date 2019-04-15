#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();            // Exit the game
        void on_view_all_click();        // View all products
        void on_list_customers_click();        // View all customers
        void on_create_coffee_click();   // Create a new coffee product
        void on_create_donut_click();    // Create a new donut product
        void on_new_customer_click(); // Create a new customer
    private:
        Store _store;
        Gtk::Label *msg;
        Gtk::MenuItem *menuitem_new_coffee;
        Gtk::MenuItem *menuitem_new_donut;
        Gtk::MenuItem *menuitem_new_customer;

};
#endif
