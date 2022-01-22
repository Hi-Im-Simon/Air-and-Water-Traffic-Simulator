#include "Airport.hpp"

Airport::Airport(std::string name, float x, float y, int size) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->size = size;
    this->free_space = size;
}

void Airport::print_info() {
    std::cout << std::endl << "[Name]: " << name << ", [Position]: " << x << " x " << y << " [Empty/Size]: " << free_space << "/" << size;
}

int Airport::land_plane() {
    if (free_space > 0) {
        free_space -= 1;
        return 1;
    }
    else
        return 0;
}

void Airport::depart_plane() {
    free_space += 1;
}