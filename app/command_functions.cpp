std::string await_user_command_input() {    // alternative command input without displaying the whole menu
    std::string command;
    std::cout << "Choose an action ([menu] - display the menu): ";
    std::cin >> command;
    return command;
}

void command_planes() {
    if (planes.size() < 1)
        std::cout << std::endl << "There are no planes in the database yet. Exiting..." << std::endl;
    else {
        for (Plane& plane : planes)
            plane.print_info();
        std::cout << std::endl;
    }
}

void command_airports() {
    if (airports.size() < 1) {
        std::cout << std::endl << "There are no airports in the database yet. Exiting..." << std::endl;
    }
    else {
        for (Airport& airport : airports) {
            std::cout << std::endl << "Name: " << airport.name << ", Position: " << airport.x << " x " << airport.y;
        }

        std::cout << std::endl;
    }
}

void command_addplane() {
    std::string name, temp_airport;
    std::vector<Airport> route;
    // int speed;  // might add later
    int route_i = 1;

    // get name
    int valid_name;
    do {
        valid_name = true;
        std::cout << std::endl << "Name of the plane: ";
        std::cin >> name;

        for (Plane& plane : planes) {
            if (plane.name == name) {
                std::cout << "This name is already taken! Try again...";
                valid_name = false;
            }
        }
    } while (!valid_name);

    // get route
    std::cin.ignore();
    while (true) {
        int valid_airport = false;
        std::cout << "Name of airport " << route_i++ << " (hit enter to finish): ";
        std::getline(std::cin, temp_airport);

        if (temp_airport.length() == 0)
            break;

        if (route.size() == 0 || route.back().name != temp_airport) {    // check if plane isn't trying to go from-to the same airport
            for (Airport& airport : airports) {
                if (airport.name == temp_airport) {
                    route.push_back(airport);
                    valid_airport = true;
                }
            }
        }
        else {
            std::cout << "A plane can't visit the same airport it's currently in! (skipped)" << std::endl;
            valid_airport = true;
        }
        
        if (!valid_airport) {
            std::cout << "This airport doesn't exist! (skipped)" << std::endl;
            valid_airport = true;
        }
    }
    
    // add to BD
    Plane plane(name, route);
    planes.push_back(plane);
    std::cout << std::endl << "Successfully added a new plane!" << std::endl;
}

void command_addairport() {
    std::string name, x_str, y_str;

    // get name
    int valid_name;
    do {
        valid_name = true;
        std::cout << std::endl << "Name of the airport: ";
        std::cin >> name;

        for (Airport& airport : airports) {
            if (airport.name == name) {
                std::cout << "This name is already taken! Try again...";
                valid_name = false;
            }
        }
    } while (!valid_name);

    std::cout << "X coordinate (km): ";
    std::cin >> x_str;
    while (!is_number(x_str)) {
        std::cout << "Positions have to be numbers! Try again..." << std::endl << "X position: ";
        std::cin >> x_str;
    }

    std::cout << "Y coordinate (km): ";
    std::cin >> y_str;
    while (!is_number(y_str)) {
        std::cout << "Positions have to be numbers! Try again..." << std::endl << "Y position: ";
        std::cin >> y_str;
    }

    float x = std::stof(x_str);
    float y = std::stof(y_str);

    Airport airport(name, x, y);
    airports.push_back(airport);
    std::cout << std::endl << "Successfully added a new airport!" << std::endl;
}

void command_time() {
    std::cout << std::endl << "Pogram has simulated " << simulation_time << " real life minutes." << std::endl;
}

void command_exit() {
    running = false;
}