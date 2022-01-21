#define _WIN32_WINNT 0x0501
#include "libs/mingw.thread.h"

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctype.h>

#include "classes/Plane.cpp"
#include "classes/Airport.cpp"

#include "app/common.hpp"
#include "app/common_functions.hpp"
#include "app/user.cpp"



int main() {
    std::cout << std::endl << "~~~~~ Welcome to the simulation! ~~~~~";

    std::thread thread_user(user_main);
    
    while (running) {
        // code

        simulation_time++;
        Sleep(1000 / simulation_speed); // możliwe że trzeba będzie zmienić pliki hpp na h, bo c++ może nie ogarniać bibliotek z C
    }

    thread_user.join();
    return 0;
}
