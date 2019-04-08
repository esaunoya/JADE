include "main_window.h"
#include "dialogs.h"

Main_window::Main_window() {
    Dialogs::set_window(this);

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("JADE");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
/*
    //         N E W   S T O R E
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_click));
    filemenu->append(*menuitem_new);

    //         O P E N   S T O R E
    // Append Open to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_open_click));
    filemenu->append(*menuitem_open);

    //         S A V E   S T O R E
    // Append save to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
    filemenu->append(*menuitem_save);

    //         S A V E  A S  S T O R E
    // Append save as to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_save_as->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_as_click));
    filemenu->append(*menuitem_save_as);
*/
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);


    //     C R E A T E
    // Create a Product menu and add to the menu bar
    Gtk::MenuItem *menuitem_product = Gtk::manage(new Gtk::MenuItem("_Product", true));
    menubar->append(*menuitem_product);
    Gtk::Menu *productmenu = Gtk::manage(new Gtk::Menu());
    menuitem_product->set_submenu(*productmenu);

    //         A D D   P R O D U C T
    // Append New to the File menu
    Gtk::MenuItem *_menuitem_add_product = Gtk::manage(new Gtk::MenuItem("_Add", true));
    _menuitem_add_product->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_product_click));
    productmenu->append(*_menuitem_add_product);

    //         L I S T   P R O D U C T S
    // Append List Products to the Product menu
    Gtk::MenuItem *_menuitem_list_products = Gtk::manage(new Gtk::MenuItem("_List", true));
    _menuitem_list_products->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_products_click));
    productmenu->append(*_menuitem_list_products);

/*
    //     O R D E R
    // Create a order menu and add to the menu bar
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *ordermenu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*ordermenu);

    //         A D D   O R D E R
    // Append New to the File menu
    Gtk::MenuItem *_menuitem_add_order = Gtk::manage(new Gtk::MenuItem("_Add", true));
    _menuitem_add_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_order_click));
    ordermenu->append(*_menuitem_add_order);

    //         L I S T   O R D E R S
    // Append List orders to the order menu
    Gtk::MenuItem *_menuitem_list_orders = Gtk::manage(new Gtk::MenuItem("_List", true));
    _menuitem_list_orders->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_orders_click));
    ordermenu->append(*_menuitem_list_orders);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           H E L P
    // Append Help to the Help menu
    Gtk::MenuItem *menuitem_helps = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menuitem_helps->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_help_click));
    helpmenu->append(*menuitem_helps);

    //           T E S T   (Easter Egg)
    // Append test to the Help menu
    Gtk::MenuItem *menuitem_test = Gtk::manage(new Gtk::MenuItem("_Test", true));
    menuitem_test->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_test_click));
    helpmenu->append(*menuitem_test);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);
*//*
    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     O N E   S T I C K
    // Add a icon for taking one stick
    button1_on_image = Gtk::manage(new Gtk::Image{"button1_on.png"});
    button1_off_image = Gtk::manage(new Gtk::Image{"button1_off.png"});
    button1 = Gtk::manage(new Gtk::ToolButton(*button1_on_image));
    button1->set_tooltip_markup("Select one stick");
    button1->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_button1_click));
    toolbar->append(*button1);

    //     T W O   S T I C K S
    // Add a icon for taking two sticks
    button2_on_image = Gtk::manage(new Gtk::Image{"button2_on.png"});
    button2_off_image = Gtk::manage(new Gtk::Image{"button2_off.png"});
    button2 = Gtk::manage(new Gtk::ToolButton(*button2_on_image));
    button2->set_tooltip_markup("Select two sticks");
    button2->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_button2_click));
    toolbar->append(*button2);

    //     T H R E E   S T I C K S
    // Add a icon for taking three sticks
    button3_on_image = Gtk::manage(new Gtk::Image{"button3_on.png"});
    button3_off_image = Gtk::manage(new Gtk::Image{"button3_off.png"});
    button3 = Gtk::manage(new Gtk::ToolButton(*button3_on_image));
    button3->set_tooltip_markup("Select three sticks");
    button3->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_button3_click));
    toolbar->append(*button3);

    //     C O M P U T E R   P L A Y E R
    // Add a toggle button to enable computer to play as Player 2
    Gtk::Image *robot_image = Gtk::manage(new Gtk::Image{"freepik_robot.png"});
    computer_player = Gtk::manage(new Gtk::ToggleToolButton(*robot_image));
    computer_player->set_tooltip_markup("Enable for computer to be Player 2");
    computer_player->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_computer_player_click));
    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);
    toolbar->append(*computer_player);

    //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit game");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);
*/
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    data = Gtk::manage(new Gtk::Label());
    // sticks->set_has_frame(false);
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);

    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_click();
}

Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////
/*
void Main_window::on_new_click() {
    controller = new Controller{this};
}
void Main_window::on_open_click() {
    controller->load();
}
void Main_window::on_save_click() {
    controller->save(false);
}
void Main_window::on_save_as_click() {
    controller->save();
}
*/
void Main_window::on_quit_click() {
    hide();
}
void Main_window::on_add_product_click() {
    controller->add_product();
}
void Main_window::on_list_products_click() {
    controller->list_all_products();
}
/*
void Main_window::on_add_order_click() {
    controller->add_order();
}
void Main_window::on_list_orders_click() {
    controller->list_all_orders();
}
void Main_window::on_help_click() {
    controller->help();
}
void Main_window::on_test_click() {
    controller->easter_egg();
}
*/
/*
void Main_window::on_about_click() {
    Glib::ustring s = "<span size='24000' weight='bold'>MavMart</span>\n<span size='large'>Copyright 2019 by George F. Rice</span>\n<span size='small'>Licensed under Creative Commons Attribution 4.0 International</span>";
    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}
*/
// /////////////////
// U T I L I T I E S
// /////////////////
