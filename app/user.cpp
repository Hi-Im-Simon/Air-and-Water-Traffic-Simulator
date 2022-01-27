#include "command_functions.cpp"

void display_menu() {
    std::cout << std::endl
              //   << "- [routes] - list all current routes for planes and ships" << std::endl
              //   << "- [addroute] - add a new route" << std::endl
              << "- [planes] - list all planes and their current routes" << std::endl
              << "- [airports] - list all airports" << std::endl
              << "- [addplane] - add a new plane" << std::endl
              << "- [remplane] - remove a chosen plane" << std::endl
              << "- [addairport] - add a new airport" << std::endl
              << "- [ships] - list all ships and their current routes" << std::endl
              << "- [harbors] - list all ship harbors" << std::endl
              << "- [addship] - add a new ship" << std::endl
              << "- [remship] - remove a chosen ship" << std::endl
              << "- [addharbor] - add a new ship harbor" << std::endl

              << std::endl
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
    else if (command == "airports") {
        command_airports();
        process_command(await_user_command_input());
    }
    else if (command == "addplane") {
        command_addplane();
        process_command(await_user_command_input());
    }
    else if (command == "remplane") {
        command_remplane();
        process_command(await_user_command_input());
    }
    else if (command == "addairport") {
        command_addairport();
        process_command(await_user_command_input());
    }
    else if (command == "ships") {
        command_ships();
        process_command(await_user_command_input());
    }
    else if (command == "harbors") {
        command_harbors();
        process_command(await_user_command_input());
    }
    else if (command == "addship") {
        command_addship();
        process_command(await_user_command_input());
    }
    else if (command == "remship") {
        command_remship();
        process_command(await_user_command_input());
    }
    else if (command == "addharbor") {
        command_addharbor();
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