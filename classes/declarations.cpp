#include "declarations.hpp"

void create_starting_objects() {
    airports.push_back(Airport("Warsaw", 2332.94, 5798.31, 2));
    airports.push_back(Airport("Poznan", 1879.45, 5817.45, 1));
    airports.push_back(Airport("Moscow", 4175.86, 6188.70, 3));
    harbors.push_back(Harbor("Gdynia", 2031.65, 6087.45, 3));
    harbors.push_back(Harbor("Swinoujscie", 1676.46, 6018.34, 2));
    harbors.push_back(Harbor("Riga", 2846.38, 6346.21, 4));

}