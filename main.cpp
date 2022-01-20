#define _WIN32_WINNT 0x0501
#include "libs/mingw.thread.h"

#include <iostream>
#include <windows.h>
#include <string>

#include "app/common.hpp"
#include "app/user.cpp"


int main() {
    std::thread thread_user(user_tasks);
    
    while (running) {
        

        simulation_time++;
        Sleep(500); // możliwe że trzeba będzie zmienić pliki hpp na h, bo c++ może nie ogarniać bibliotek z C
    }

    thread_user.join();
    return 0;
}
