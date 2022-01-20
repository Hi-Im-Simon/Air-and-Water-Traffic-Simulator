#ifndef PLANE_HPP
#define PLANE_HPP

#include <vector>

class Plane {
    public:
        Plane(float speed);
        float speed;
        std::pair<float, float> position;
        std::vector<int> route;
    protected:

};

#endif PLANE_HPP