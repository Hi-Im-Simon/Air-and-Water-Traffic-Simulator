#ifndef AIRPORT_HPP
#define AIRPORT_HPP

class Airport {
    public:
        std::string name;
        float x, y;
        int size, free_space;
        Airport(std::string, float, float, int);

        void print_info();
        int land_plane();
        void depart_plane();

    protected:
};

#endif