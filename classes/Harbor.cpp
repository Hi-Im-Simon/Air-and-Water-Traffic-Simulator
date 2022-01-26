#include "Harbor.hpp"

Harbor::Harbor(std::string name, float x, float y, int size) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->size = size;
    this->free_space = size;
}

void Harbor::print_info() {
    std::cout << std::endl << "[Name]: " << name << ", [Position]: " << x << " x " << y << " [Empty/Size]: " << free_space << "/" << size;
}

bool Harbor::moor_ship() {
    if (free_space > 0) {
        free_space -= 1;
        return 1;
    }
    else
        return 0;
}

void Harbor::depart_ship() {
    free_space += 1;
}

std::string Harbor::getName(){
    return this->name;
};

float Harbor::getX(){
    return this->x;
}

float Harbor::getY(){
    return this->y;
}

int Harbor::getSize(){
    return this->size;
}

int Harbor::getFreeSpace(){
    return this->free_space;
}