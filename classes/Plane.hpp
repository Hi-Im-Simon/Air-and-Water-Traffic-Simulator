#ifndef PLANE_HPP
#define PLANE_HPP

class Plane {
    public:
        std::string name;
        std::vector<Airport> route;
        int speed;
        float route_length;
        float travelled;
        Plane(std::string name, std::vector<Airport> route);
};

#endif