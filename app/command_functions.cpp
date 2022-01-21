std::string await_user_command_input() {
    std::string command;
    std::cout << "Choose an action ([menu] - display the menu): ";
    std::cin >> command;
    return command;
}

void command_planes() {
    if (planes.size() < 1) {
        std::cout << std::endl << "There are no planes in the database yet. Exiting..." << std::endl;
    }
    else {
        std::string prefix = "";
        for (Plane& plane : planes) {
            std::cout << std::endl << "Name: " << plane.name << ", Route: ";

            for (std::string airport : plane.route) {
                std::cout << prefix << airport; 
                prefix = " - ";
            }
        }

        std::cout << std::endl;
    }
}

void command_addplane() {
    std::string name, temp_airport;
    std::vector<std::string> route;
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

    Plane plane(name);

    // get route
    std::cin.ignore();
    while (true) {
        int valid_airport = false;
        std::cout << "Name of airport " << route_i++ << " (hit enter to finish): ";
        std::getline(std::cin, temp_airport);

        if (temp_airport.length() == 0)
            break;

        if (route.size() == 0 || route.back() != temp_airport) {    // check if plane isn't trying to go from-to the same airport
            for (Airport& airport : airports) {
                if (airport.name == temp_airport) {
                    route.push_back(temp_airport);
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
    
    plane.route = route;
    planes.push_back(plane);
    std::cout << std::endl << "Successfully added a new plane!" << std::endl;
}

void command_time() {
    std::cout << std::endl << "Pogram has simulated " << simulation_time << " real life minutes." << std::endl;
}

void command_exit() {
    running = false;
}