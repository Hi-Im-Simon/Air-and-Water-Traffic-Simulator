#ifndef PLANE_HPP
#define PLANE_HPP

class Plane {
    public:
        std::string name;
        std::vector<Airport> route;
        int speed;
        std::vector<float> route_lengths;
        float travelled;
        Plane(std::string name, std::vector<Airport> route);
};

#endif