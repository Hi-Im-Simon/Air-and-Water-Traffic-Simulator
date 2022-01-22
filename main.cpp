#define _WIN32_WINNT 0x0501
#include "libs/mingw.thread.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <ctype.h>
#include <math.h>

#include "classes/Airport.cpp"
#include "classes/Plane.cpp"

#include "app/common.hpp"
#include "app/common_functions.hpp"
#include "app/user.cpp"



int main() {
    std::cout << std::endl << "~~~~~ Welcome to the simulation! ~~~~~";

    std::thread thread_user(user_main);
    
    while (running) {
        // increment planes' travel distance
        for (Plane& plane : planes) {   // to wszystko jest przykładowe, można wyjebać i dać coś bardziej zaawansowanego
            if (plane.route.size() > 1) {
                float temp_travelled = plane.travelled + plane.speed / 60;  // increment by speed in km/min
                if (temp_travelled < plane.route_lengths.back())
                    plane.travelled = temp_travelled;
                else
                    plane.travelled = plane.route_lengths.back();
            }
        }

        simulation_time++;
        Sleep(1000 / simulation_speed); // możliwe że trzeba będzie zmienić pliki hpp na h, bo c++ może nie ogarniać bibliotek z C
    }

    thread_user.join();
    return 0;
}
