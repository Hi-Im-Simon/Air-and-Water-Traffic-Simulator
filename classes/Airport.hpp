#ifndef AIRPORT_HPP
#define AIRPORT_HPP

class Airport {
    private:
        std::string name;
        float x, y;
        int size, free_space;

    public:
        Airport(std::string, float, float, int);

        std::string getName();
        float getX();
        float getY();
        int getSize();
        int getFreeSpace();

        void print_info();
        int land_plane();
        void depart_plane();
        
};

#endif