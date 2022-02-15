#ifndef SHIP_HPP
#define SHIP_HPP

class Ship : public Vehicle {
    private:
        int dock_depart_timer = 0;
        
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