#include "Harbor.hpp"

Harbor::Harbor(std::string name, float x, float y, int size) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->size = size;
    this->free_space = size;
}

bool Harbor::dock_ship() {
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