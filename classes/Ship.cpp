#include "Ship.hpp"

Ship::Ship(std::string name, std::vector<Harbor> route) {
    this->name = name;
    this->route = route;

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
    if (state == "mooring" || state == "stopover" || state == "arrived")
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
            if (moor_depart_timer >= departure_length) {
                depart_ship(last_harbor);
            }
            else
                this->moor_depart_timer += 1;
        }
        else if (state == "sailing") {
            float temp_travelled = travelled + this->max_speed / 60;  // increment by speed in km/min
            for (int i=0; i<route_lengths.size(); i++){
                // std::cout << travelled << " " << temp_travelled << " / " << route_lengths[i] << std::endl; 
                if (travelled < route_lengths[i] && temp_travelled >= route_lengths[i]) {
                    this->travelled = route_lengths[i];
                    this->last_harbor = route[i].getName();

                    if (moor_ship(last_harbor))
                        this->state = "mooring";
                    else
                        this->state = "waiting for landing spot";
                    return;
                }
            }
            this->travelled = temp_travelled;
        }
        else if (state == "waiting for a spot" && moor_ship(last_harbor)) {
            this->state = "mooring";
        }
        else if (state == "mooring") {
            if (moor_depart_timer >= landing_length) {
                this->moor_depart_timer = 0;
                if (travelled == route_lengths.back())  // if plane has arrived to its final destination
                    this->state = "arrived";
                else                                    // if plane has arrived to one of its stopover airports
                    this->state = "stopover";
            }
            else
                this->moor_depart_timer += 1;
        }
        else if (state == "stopover") {
            if (stopover_timer >= stopover_length) {
                this->stopover_timer = 0;
                this->state = "departure";
            }
            else
                this->stopover_timer += 1;
        }
    }
}

bool Ship::moor_ship(std::string sp) {
    for (Harbor& harbor : harbors) {
        if (harbor.getName() == sp) {
            if (harbor.moor_ship())
                return 1;
            return 0;
        }
    }
    return 0;
}

void Ship::depart_ship(std::string sp) {
    // Change the state of the plane
    this->moor_depart_timer = 0;
    this->state = "sail";

    // Remove the plane from its airport
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