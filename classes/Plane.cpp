#include "Plane.hpp"

Plane::Plane(std::string name, std::vector<Airport> route) {
    this->name = name;
    this->route = route;
    this->speed = 900; // (kmph) may be changed to be set by a user
    this->travelled = 0;

    float route_length = 0;    
    if (!route.empty()) {
        for (int i = 0; i < route.size() - 1; i++) {
            route_length += sqrt(pow((route[i+1].x - route[i].x), 2.0) + pow((route[i+1].y - route[i].y), 2.0));
        }
    }

    this->route_length = route_length;
}