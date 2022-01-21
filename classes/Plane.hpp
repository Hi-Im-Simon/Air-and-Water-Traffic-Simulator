#ifndef PLANE_HPP
#define PLANE_HPP

#include <vector>

class Plane {
    public:
        std::string name;
        std::vector<std::string> route;
        Plane(std::string name);
};

#endif