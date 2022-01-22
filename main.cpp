#define _WIN32_WINNT 0x0501
#include "libs/mingw.thread.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <ctype.h>
#include <math.h>

#include "app/common.hpp"

#include "classes/Airport.cpp"
#include "classes/Plane.cpp"

#include "app/common_functions.cpp"
#include "app/starting_objects.cpp"
#include "app/user.cpp"



int main() {
    std::cout << std::endl << "~~~~~ Welcome to the simulation! ~~~~~";

    std::thread thread_user(user_main);

    create_starting_objects();  // create airports etc that will be in the database from start
    
    while (running) {
        // increment planes' travel distance
        for (Plane& plane : planes) {   // to wszystko jest przykładowe, można wyjebać i dać coś bardziej zaawansowanego
            plane.action();
        }

        simulation_time++;
        Sleep(1000 / simulation_speed);
    }

    thread_user.join();
    return 0;
}
