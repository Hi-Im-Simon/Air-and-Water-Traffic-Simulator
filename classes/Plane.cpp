#include "Plane.hpp"

Plane::Plane(std::string name, std::vector<Airport> route) {
    this->name = name;
    this->route = route;

    if (route.size() > 0) {
        this->last_airport = route[0].getName();
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

void Plane::print_info() {
    std::string prefix = "";

    std::cout << std::endl << "[Name]: " << this->name << " [State]: " << this->state;
    if (state == "landing" || state == "stopover" || state == "arrived")
        std::cout << " in " << last_airport;
    else if (state == "departure")
        std::cout << " from " << last_airport;
    std::cout << "\t[Route]: ";
    
    if (route.size() == 0)
        std::cout << "-";
    else if (route.size() == 1)
        std::cout << route[0].getName();
    else {
        for (Airport airport : route) {
            std::cout << prefix << airport.getName(); 
            prefix = " - ";
        }
    }

    if (route.size() > 1) {
        std::cout << " = " << route_lengths.back() << "km" << "\t[Travelled]: " << travelled << "km";
    }
}

void Plane::action() {
    if (route.size() > 1) {
        if (state == "departure") {
            if (land_depart_timer >= departure_length) {
                depart_plane(last_airport);
            }
            else
                this->land_depart_timer += 1;
        }
        else if (state == "flight") {
            float temp_travelled = travelled + this->max_speed / 60;  // increment by speed in km/min
            for (int i=0; i<route_lengths.size(); i++){
                // std::cout << travelled << " " << temp_travelled << " / " << route_lengths[i] << std::endl; 
                if (travelled < route_lengths[i] && temp_travelled >= route_lengths[i]) {
                    this->travelled = route_lengths[i];
                    this->last_airport = route[i].getName();

                    if (land_plane(last_airport))
                        this->state = "landing";
                    else
                        this->state = "waiting for landing spot";
                    return;
                }
            }
            this->travelled = temp_travelled;
        }
        else if (state == "waiting for landing spot" && land_plane(last_airport)) {
            this->state = "landing";
        }
        else if (state == "landing") {
            if (land_depart_timer >= landing_length) {
                this->land_depart_timer = 0;
                if (travelled == route_lengths.back())  // if plane has arrived to its final destination
                    this->state = "arrived";
                else                                    // if plane has arrived to one of its stopover airports
                    this->state = "stopover";
            }
            else
                this->land_depart_timer += 1;
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

int Plane::land_plane(std::string ap) {
    for (Airport& airport : airports) {
        if (airport.getName() == ap) {
            if (airport.land_plane())
                return 1;
            return 0;
        }
    }
    return 0;
}

void Plane::depart_plane(std::string ap) {
    // Change the state of the plane
    this->land_depart_timer = 0;
    this->state = "flight";

    // Remove the plane from its airport
    for (Airport& airport : airports) {
        if (airport.getName() == ap)
            airport.depart_plane();
    }
}

std::vector<Airport> Plane::getRoute(){
    return route;
}

std::string Plane::getLastAirport(){
    return last_airport;
}

void Plane::remPrep(){
    if (route.size() > 0 && (state == "idle" || state == "departure" || state == "landing" || state == "stopover" || state == "arrived")) {
        this->depart_plane(last_airport);
    }
}