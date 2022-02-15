#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle {
    protected:
        float max_speed = 804.67;    // (kmph) may be changed to be set by a user
        int stopover_timer = 0;
        std::string name;
        
        std::string state;
        
        // WHAT DIFFERENT STATES MEAN FOR PLANES:
        // idle - plane has 0/1 airport in its route, so it will never depart
        // departure - plane will start a flight in 15 minutes (with full speed to make it easier)
        // flight - plane is in air with full speed
        // landing - plane will land at an airport in 15 minutes
        // stopover - plane is in one of its connecting airports and waits (1 hour)
        // arrived - plane has finished the whole flight
        // waiting for landing spot - airport is full and plane is waiting for it to empty
        
        // WHAT DIFFERENT STATES MEAN FOR SHIPS:
        // idle - ship has 0/1 harbor in its route, so it will never depart
        // departure - ship will start sailing in 15 minutes (with full speed to make it easier)
        // sailing - ship alredy set to sea with full speed
        // docking - ship will dock at a harbor in 15 minutes
        // stopover - ship is in one of its connecting harbors and waits (1 hour)
        // arrived - ship has finished the whole cruise
        // waiting for a spot - harbor is full and the ship is waiting for it to empty
    
        float travelled = 0;

    public:
        
        virtual void print_info() = 0;
        virtual void action() = 0;
        virtual void remPrep() = 0;     // prepare for removal
        
        std::string getName();
        std::string getState();

};

#endif