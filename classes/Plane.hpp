#ifndef PLANE_HPP
#define PLANE_HPP


class Plane : public Vehicle {
    private:
        int land_depart_timer = 0;
        
        std::vector<Airport> route;
        std::string last_airport;

        std::vector<float> route_lengths;

    public:
        // FUNCTIONS
        
        Plane(const std::string, std::vector<Airport>);
        
        void print_info();
        void action();
        void remPrep();

        int land_plane(std::string);
        void depart_plane(std::string);

        std::vector<Airport> getRoute();
        std::string getLastAirport();
};

#endif