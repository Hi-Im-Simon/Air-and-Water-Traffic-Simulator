#define _WIN32_WINNT 0x0501
#include "libs/mingw.thread.h"

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

#include "classes/Plane.cpp"
#include "classes/Airport.cpp"

#include "app/common.hpp"
#include "app/user.cpp"



int main() {
    std::cout << std::endl << "~~~~~ Welcome to the simulation! ~~~~~";

    std::thread thread_user(user_main);

    Airport ap("pepe");
    airports.push_back(ap);
    Airport aaa("eo");
    airports.push_back(aaa);

    
    while (running) {
        // code

        simulation_time++;
        Sleep(1000 / simulation_speed); // możliwe że trzeba będzie zmienić pliki hpp na h, bo c++ może nie ogarniać bibliotek z C
    }

    thread_user.join();
    return 0;
}
