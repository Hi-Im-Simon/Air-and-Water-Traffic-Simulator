#ifndef SHIP_HPP
#define SHIP_HPP

class Ship : public Vehicle {
    private:
        int moor_depart_timer = 0;
        
        std::string state;
        // WHAT DIFFERENT STATES MEAN:
        // idle - ship has 0/1 port in its route, so it will never depart
        // departure - ship will start sailing in 15 minutes (with full speed to make it easier)
        // sailing - ship alredy set to sea with full speed
        // mooring - ship will moor at a port in 15 minutes
        // stopover - ship is in one of its connecting ports and waits (1 hour)
        // arrived - ship has finished the whole cruise
        // waiting for a spot - port is full and the ship is waiting for it to empty
        
        std::vector<Harbor> route;
        std::string last_harbor;

        std::vector<float> route_lengths;

    public:
        // FUNCTIONS
        
        Ship(std::string, std::vector<Harbor>);
        
        void print_info();
        void action();
        void remPrep();

        bool moor_ship(std::string);
        void depart_ship(std::string);

        std::vector<Harbor> getRoute();
        std::string getLastHarbor();
};

#endif