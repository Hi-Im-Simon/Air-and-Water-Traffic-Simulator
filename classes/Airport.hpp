#ifndef AIRPORT_HPP
#define AIRPORT_HPP

class Airport {
    public:
        std::string name;
        float x, y;
        int size, free_space;
        Airport(std::string name, float x, float y, int size);

        void print_info();
        int land_plane();
        void depart_plane();

    protected:
};

#endif