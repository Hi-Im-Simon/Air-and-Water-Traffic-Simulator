#define _WIN32_WINNT 0x0501

#include "libs/mingw.thread.h"
#include <iostream>
#include <windows.h>

// to miało być współbieżnie, ale c++ jest ułomny i nie ma współbieżności, którą by można prosto zrobić
// jak ktoś ogarnia to by było kozak
void user_tasks() {
    int p;
    std::cin >> p;
}

int main() {
    std::thread thread1(user_tasks);
    
    while (true) {
        std::cout << "eo" << std::endl;

        Sleep(1000); // możeliwe że trzeba będzie zmienić pliki hpp na h, bo c++ może nie ogarniać bibliotek z C
    }
}
