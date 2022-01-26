std::string await_user_command_input() {    // alternative command input without displaying the whole menu
    std::string command;
    std::cout << "Choose an action ([menu] - display the menu): ";
    std::cin >> command;

    return command;
}

void command_planes() {
    int size = 0;
    for (Vehicle* vehicle : vehicles)
        if(dynamic_cast<Plane*>(vehicle)!=nullptr){
            vehicle->print_info();
            size++;
        }
    if (size == 0){
        std::cout << std::endl << "There are no planes in the database yet. Exiting...";
    }
}

void command_airports() {
    if (airports.size() < 1) {
        std::cout << std::endl << "There are no airports in the database yet. Exiting..." << std::endl;
    }
    else {
        for (Airport airport : airports)
            airport.print_info();
        std::cout << std::endl;
    }
}

void command_addplane() {
    std::string name, temp_airport;
    std::vector<Airport> route;
    // int speed;  // might add later
    int route_i = 1;

    // get name
    bool valid_name;
    do {
        valid_name = true;
        std::cout << std::endl << "Name of the plane: ";
        std::cin >> name;

        for (Vehicle* vehicle : vehicles) {
            if (vehicle->getName() == name && !(dynamic_cast<Plane*>(vehicle) == nullptr)) {
                std::cout << "This name is already taken! Try again...";
                valid_name = false;
            }
        }
    } while (!valid_name);

    // get route
    std::cin.ignore();
    while (true) {
        bool valid_airport = false;
        std::cout << "Name of airport " << route_i++ << " (hit enter to finish): ";
        std::getline(std::cin, temp_airport);

        if (temp_airport.length() == 0)
            break;

        if (route.size() == 0 || route.back().getName() != temp_airport) {    // check if plane isn't trying to go from-to the same airport
            for (Airport& airport : airports) {
                if (airport.getName() == temp_airport) {
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

    // check if there is a free space in the starting airport
    
    // add to BD
    Plane *plane = new Plane(name,route);

    if(!plane->land_plane(route[0].getName()))
        std::cout << std::endl << "Primary airport can't fit another plane! Exiting..." << std::endl;
    else {
        vehicles.push_back(plane);
        std::cout << std::endl << "Successfully added a new plane!" << std::endl;
    }
}

void command_remplane() {
    std::string name;
    std::cout << std::endl << "Name of the plane to remove: ";
    std::cin >> name;
    
    for (int i=0; i<vehicles.size(); i++) {
        if (vehicles[i]->getName() == name && !(dynamic_cast<Plane*>(vehicles[i]) == nullptr)) {
            vehicles[i]->remPrep();
            vehicles.erase(vehicles.begin() + i);
            break;
        }
    }
}

void command_addairport() {
    std::string name, x_str, y_str, size_str;

    // get name
    bool valid_name;
    do {
        valid_name = true;
        std::cout << std::endl << "Name of the airport: ";
        std::cin >> name;

        for (Airport& airport : airports) {
            if (airport.getName() == name) {
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

    std::cout << "How many planes can the airport fit: ";
    std::cin >> size_str;
    while (!is_number(size_str)) {
        std::cout << "Positions have to be numbers! Try again..." << std::endl << "X position: ";
        std::cin >> size_str;
    }

    float x = std::stof(x_str);
    float y = std::stof(y_str);
    int size = std::stod(size_str);

    Airport airport(name, x, y, size);
    airports.push_back(airport);
    std::cout << std::endl << "Successfully added a new airport!" << std::endl;
}

void command_ships(){
    int size = 0;
    for (Vehicle* vehicle : vehicles)
        if(dynamic_cast<Ship*>(vehicle)!=nullptr){
            vehicle->print_info();
            size++;
        }
    if (size == 0){
        std::cout << std::endl << "There are no ships in the database yet. Exiting...";
    }
    std::cout << std::endl;
}

void command_harbors(){
    if (harbors.size() < 1) {
        std::cout << std::endl << "There are no harbors in the database yet. Exiting..." << std::endl;
    }
    else {
        for (Harbor harbor : harbors)
            harbor.print_info();
        std::cout << std::endl;
    }
}

void command_addship(){
    std::string name, temp_harbor;
    std::vector<Harbor> route;
    // int speed;  // might add later
    int route_i = 1;

    // get name
    bool valid_name;
    do {
        valid_name = true;
        std::cout << std::endl << "Name of the ship: ";
        std::cin >> name;

        for (Vehicle* vehicle : vehicles) {
            if (vehicle->getName() == name && !(dynamic_cast<Ship*>(vehicle) == nullptr)) {
                std::cout << "This name is already taken! Try again...";
                valid_name = false;
            }
        }
    } while (!valid_name);

    // get route
    std::cin.ignore();
    while (true) {
        bool valid_harbor = false;
        std::cout << "Name of harbor " << route_i++ << " (hit enter to finish): ";
        std::getline(std::cin, temp_harbor);

        if (temp_harbor.length() == 0)
            break;

        if (route.size() == 0 || route.back().getName() != temp_harbor) {    // check if plane isn't trying to go from-to the same airport
            for (Harbor& harbor : harbors) {
                if (harbor.getName() == temp_harbor) {
                    route.push_back(harbor);
                    valid_harbor = true;
                }
            }
        }
        else {
            std::cout << "A plane can't visit the same airport it's currently in! (skipped)" << std::endl;
            valid_harbor = true;
        }
        
        if (!valid_harbor) {
            std::cout << "This airport doesn't exist! (skipped)" << std::endl;
            valid_harbor = true;
        }
    }

    // check if there is a free space in the starting airport
    
    // add to BD
    Ship *ship = new Ship(name,route);

    if(!ship->moor_ship(route[0].getName()))
        std::cout << std::endl << "Primary harbor can't fit another ship! Exiting..." << std::endl;
    else {
        vehicles.push_back(ship);
        std::cout << std::endl << "Successfully added a new ship!" << std::endl;
    }
}

void command_remship(){
    std::string name;
    std::cout << std::endl << "Name of the ship to remove: ";
    std::cin >> name;

    for (int i=0; i<vehicles.size(); i++) {
        if (vehicles[i]->getName() == name && !(dynamic_cast<Ship*>(vehicles[i]) == nullptr)) {
            vehicles[i]->remPrep();
            vehicles.erase(vehicles.begin() + i);
            break;
        }
    }
}

void command_addharbor(){
    std::string name, x_str, y_str, size_str;

    // get name
    bool valid_name;
    do {
        valid_name = true;
        std::cout << std::endl << "Name of the harbor: ";
        std::cin >> name;

        for (Harbor& harbor : harbors) {
            if (harbor.getName() == name) {
                std::cout << "This name is already taken! Try again...";
                valid_name = false;
            }
        }
    } while (!valid_name);

    std::cout << "X coordinate (km): ";
    std::cin >> x_str;
    while (!is_number(x_str)) {
        std::cout << "Positions have to be integers! Try again..." << std::endl << "X coordinate (km): ";
        std::cin >> x_str;
    }

    std::cout << "Y coordinate (km): ";
    std::cin >> y_str;
    while (!is_number(y_str)) {
        std::cout << "Positions have to be integers! Try again..." << std::endl << "Y coordinate (km): ";
        std::cin >> y_str;
    }

    std::cout << "How many ships can the harbor fit: ";
    std::cin >> size_str;
    while (!is_number(size_str)) {
        std::cout << "Harbor must be and intiger! Try again..." << std::endl << "How many ships can the harbor fit: ";
        std::cin >> size_str;
    }

    float x = std::stof(x_str);
    float y = std::stof(y_str);
    int size = std::stod(size_str);

    Harbor harbor(name, x, y, size);
    harbors.push_back(harbor);
    std::cout << std::endl << "Successfully added a new harbor!" << std::endl;
}

void command_time() {
    std::cout << std::endl << "Pogram has simulated " << simulation_time << " real life minutes." << std::endl;
}

void command_exit() {
    running = false;
}