#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class Vehicle {
    protected:
        float max_speed = 804.67;    // (kmph) may be changed to be set by a user
        int land_depart_timer = 0;
        int stopover_timer = 0;
        std::string name;
        
        std::string state;
        
        // WHAT DIFFERENT STATES MEAN: idle = 
        // idle - plane has 0/1 airport in its route, so it will never depart
        // departure - plane will start a flight in 15 minutes (with full speed to make it easier)
        // flight - plane is in air with full speed
        // landing - plane will land at an airport in 15 minutes
        // stopover - plane is in one of its connecting airports and waits (1 hour)
        // arrived - plane has finished the whole flight
        // waiting for landing spot - airport is full and plane is waiting for it to empty
    
        float travelled = 0;

    public:
        
        virtual void print_info() = 0;
        virtual void action() = 0;
        virtual void remPrep() = 0;     // prepare for removal
        
        std::string getName();
        std::string getState();

};

#endif