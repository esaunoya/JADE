#include "mainwin.h"

#include <gtkmm.h>
#include <iostream>

int main(int argc, char *argv[]) {

        auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.paint");
        Main_window win;
        return app->run(win);

}
