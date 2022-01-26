#ifndef HARBOR_HPP
#define HARBOR_HPP

class Harbor {
    private:
        std::string name;
        float x, y;
        int size, free_space;

    public:
        Harbor(std::string, float, float, int);

        std::string getName();
        float getX();
        float getY();
        int getSize();
        int getFreeSpace();

        void print_info();
        bool moor_ship();
        void depart_ship();
        
};

#endif