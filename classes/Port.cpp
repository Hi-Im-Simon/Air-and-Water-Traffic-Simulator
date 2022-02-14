#include "Port.hpp"


void Port::print_info() {
    std::cout << std::endl << "[Name]: " << name << ", [Position]: " << x << " x " << y << " [Empty/Size]: " << free_space << "/" << size;
}

std::string Port::getName(){
    return this->name;
};

float Port::getX(){
    return this->x;
}

float Port::getY(){
    return this->y;
}

int Port::getSize(){
    return this->size;
}

int Port::getFreeSpace(){
    return this->free_space;
}