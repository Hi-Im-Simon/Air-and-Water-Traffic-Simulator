#ifndef AIRPORT_HPP
#define AIRPORT_HPP

class Airport : public Port {

    public:
        Airport(const std::string, const float, const float, const int);
        
        int land_plane();
        void depart_plane();
        
};

#endif