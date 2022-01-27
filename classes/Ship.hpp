#ifndef SHIP_HPP
#define SHIP_HPP

class Ship : public Vehicle {
    private:
        int dock_depart_timer = 0;
        
        std::string state;
        // WHAT DIFFERENT STATES MEAN:
        // idle - ship has 0/1 port in its route, so it will never depart
        // departure - ship will start sailing in 15 minutes (with full speed to make it easier)
        // sailing - ship alredy set to sea with full speed
        // docking - ship will dock at a port in 15 minutes
        // stopover - ship is in one of its connecting ports and waits (1 hour)
        // arrived - ship has finished the whole cruise
        // waiting for a spot - port is full and the ship is waiting for it to empty
        
        std::vector<Harbor> route;
        std::string last_harbor;

        std::vector<float> route_lengths;

    public:
        // FUNCTIONS
        
        Ship(const std::string, const std::vector<Harbor>);
        
        void print_info();
        void action();
        void remPrep();

        bool dock_ship(std::string);
        void depart_ship(std::string);

        std::vector<Harbor> getRoute();
        std::string getLastHarbor();
};

#endif