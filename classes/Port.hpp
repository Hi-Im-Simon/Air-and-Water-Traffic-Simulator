#ifndef PORT_HPP
#define PORT_HPP

class Port {
    protected:
        std::string name;
        float x, y;
        int size, free_space;

    public:
        std::string getName();
        float getX();
        float getY();
        int getSize();
        int getFreeSpace();

        void print_info();
};

#endif