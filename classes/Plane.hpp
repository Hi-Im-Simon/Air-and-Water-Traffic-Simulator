#ifndef PLANE_HPP
#define PLANE_HPP

#include "Airport.hpp"

class Plane {
    public:
        std::string name;
        std::vector<Airport> route;
        std::string last_airport;
        float max_speed = 804.67;    // (kmph) may be changed to be set by a user
        std::vector<float> route_lengths;
        float travelled = 0;
        std::string state;
        // WHAT DIFFERENT STATES MEAN:
        // idle - plane has 0/1 airport in its route, so it will never depart
        // departure - plane will start a flight in 15 minutes (with full speed to make it easier)
        // flight - plane is in air with full speed
        // landing - plane will land at an airport in 15 minutes
        // stopover - plane is in one of its connecting airports and waits (1 hour)
        // arrived - plane has finished the whole flight
        // waiting for landing spot - airport is full and plane is waiting for it to empty
        Plane(const std::string, const std::vector<Airport>);

        void print_info();
        void action();
        int land_plane(std::string);
        void depart_plane(std::string);

    protected:
        int land_depart_timer = 0;
        int stopover_timer = 0;
};

#endif