#include "Plane.hpp"

Plane::Plane(std::string name, std::vector<Airport> route) {
    this->name = name;
    this->route = route;
    this->speed = 900; // (kmph) may be changed to be set by a user
    this->travelled = 0;


    if (!route.empty()) {
        float length = 0;
        route_lengths.push_back(0);
        for (int i = 0; i < route.size() - 1; i++) {
            length += sqrt(pow((route[i+1].x - route[i].x), 2.0) + pow((route[i+1].y - route[i].y), 2.0));
            route_lengths.push_back(length);
        }
    }

    this->route_lengths = route_lengths;
}