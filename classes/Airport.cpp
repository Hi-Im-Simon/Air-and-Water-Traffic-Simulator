#include "Airport.hpp"

Airport::Airport(const std::string name, const float x, const float y, const int size) {
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

std::string Airport::getName(){
    return this->name;
};

float Airport::getX(){
    return this->x;
}

float Airport::getY(){
    return this->y;
}

int Airport::getSize(){
    return this->size;
}

int Airport::getFreeSpace(){
    return this->free_space;
}