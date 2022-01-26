#define _WIN32_WINNT 0x0501
#include "libs/mingw.thread.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h>
#include <ctype.h>
#include <math.h>

#include "app/common.cpp"   // common values and reusable functions
#include "classes/declarations.cpp" // all classes and starting objects
#include "app/user.cpp"

int main() {
    create_starting_objects();

    std::cout << std::endl << "~~~~~ Welcome to the simulation! ~~~~~";    

    std::thread thread_user(user_main);

    while (running) {
        // increment planes' travel distance
        // for (Plane& plane : planes) { 
        //     plane.action();
        // }
        
        for (Vehicle *vehicle : vehicles) {
            vehicle->action();
        }

        simulation_time++;
        Sleep(1000 / simulation_speed);
    }

    thread_user.join();
    return 0;
}
