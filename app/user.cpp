#include "command_functions.cpp"

void display_menu() {
    std::cout << std::endl
            //   << "- [routes] - list all current routes for planes and ships" << std::endl
              << "- [planes] - list all planes and their current routes" << std::endl
              << "- [ships] - list all ships and their current routes" << std::endl
            //   << "- [addroute] - add a new route" << std::endl
              << "- [addplane] - add a new plane" << std::endl
              << "- [addship] - add a new ship" << std::endl
              << "- [time] - show current simulation time" << std::endl

              << "- [exit] - leave the simulation" << std::endl
              << "Choose an action: ";
}

void process_command(std::string command) {
    if (command == "menu") {
        return;     // menu will be display from the next iteration of the user_main loop
    }
    else if (command == "planes") {
        command_planes();
        process_command(await_user_command_input());
    }
    else if (command == "addplane") {
        command_addplane();
        process_command(await_user_command_input());
    }
    else if (command == "time") {
        command_time();
        process_command(await_user_command_input());
    }
    else if (command == "exit") {
        command_exit();
    }
    else {
        std::cout << std::endl << "##### Wrong command! Try again... #####";
    }
}

void user_main() {
    std::string command;

    while (running) {
        display_menu();
        std::cin >> command;

        process_command(command);        
    }
}