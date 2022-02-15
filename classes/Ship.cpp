#include "Ship.hpp"

Ship::Ship(std::string name, std::vector<Harbor> route) {
    this->name = name;
    this->route = route;
    this->max_speed = 53.523;

    if (route.size() > 0) {
        this->last_harbor = route[0].getName();
    }

    if (route.size() > 1) {
        this->state = "departure";
        float length = 0;
        route_lengths.push_back(0);
        for (int i = 0; i < route.size() - 1; i++) {
            length += sqrt(pow((route[i+1].getX() - route[i].getX()), 2.0) + pow((route[i+1].getY() - route[i].getY()), 2.0));
            route_lengths.push_back(length);
        }
    }
    else 
        this->state = "idle";

    this->route_lengths = route_lengths;
}

void Ship::print_info() {
    std::string prefix = "";

    std::cout << std::endl << "[Name]: " << this->name << " [State]: " << this->state;
    if (state == "docking" || state == "stopover" || state == "arrived")
        std::cout << " in " << last_harbor;
    else if (state == "departure")
        std::cout << " from " << last_harbor;
    std::cout << "\t[Route]: ";

    if (route.size() == 0)
        std::cout << "-";
    else if (route.size() == 1)
        std::cout << route[0].getName();
    else {
        for (Harbor port : route) {
            std::cout << prefix << port.getName(); 
            prefix = " - ";
        }
    }

    if (route.size() > 1) {
        std::cout << " = " << route_lengths.back() << "km" << "\t[Travelled]: " << travelled << "km";
    }
}

void Ship::action() {
    if (route.size() > 1) {
        if (state == "departure") {
            if (dock_depart_timer >= set_sail_length) {
                depart_ship(last_harbor);
            }
            else
                this->dock_depart_timer += 1;
        }
        else if (state == "sailing") {
            float temp_travelled = travelled + this->max_speed / 60;  // increment by speed in km/min
            for (int i=0; i<route_lengths.size(); i++){
                // std::cout << travelled << " " << temp_travelled << " / " << route_lengths[i] << std::endl; 
                if (travelled < route_lengths[i] && temp_travelled >= route_lengths[i]) {
                    this->travelled = route_lengths[i];
                    this->last_harbor = route[i].getName();

                    if (dock_ship(last_harbor))
                        this->state = "docking";
                    else
                        this->state = "waiting for a spot";
                    return;
                }
            }
            this->travelled = temp_travelled;
        }
        else if (state == "waiting for a spot" && dock_ship(last_harbor)) {
            this->state = "docking";
        }
        else if (state == "docking") {
            if (dock_depart_timer >= docking_length) {
                this->dock_depart_timer = 0;
                if (travelled == route_lengths.back())  // if ship has arrived to its final destination
                    this->state = "arrived";
                else                                    // if ship has arrived to one of its stopover harbors
                    this->state = "stopover";
            }
            else
                this->dock_depart_timer += 1;
        }
        else if (state == "stopover") {
            if (stopover_timer >= harbor_length) {
                this->stopover_timer = 0;
                this->state = "departure";
            }
            else
                this->stopover_timer += 1;
        }
    }
}

bool Ship::dock_ship(std::string sp) {
    for (Harbor& harbor : harbors) {
        if (harbor.getName() == sp) {
            if (harbor.dock_ship())
                return 1;
            return 0;
        }
    }
    return 0;
}

void Ship::depart_ship(std::string sp) {
    // Change the state of the ship
    this->dock_depart_timer = 0;
    this->state = "sailing";

    // Remove the ship from its airport
    for (Harbor& harbor : harbors) {
        if (harbor.getName() == sp)
            harbor.depart_ship();
    }
}

std::vector<Harbor> Ship::getRoute(){
    return route;
}

std::string Ship::getLastHarbor(){
    return last_harbor;
}

void Ship::remPrep(){
    if (route.size() > 0 && (state == "idle" || state == "departure" || state == "docking" || state == "stopover" || state == "arrived")) {
        this->depart_ship(last_harbor);
    }
}