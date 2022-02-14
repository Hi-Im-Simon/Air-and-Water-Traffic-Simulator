#ifndef HARBOR_HPP
#define HARBOR_HPP

class Harbor : public Port {
    public:
        Harbor(const std::string, const float, const float, const int);

        bool dock_ship();
        void depart_ship();
        
};

#endif