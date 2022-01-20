void user_tasks() {
    std::string command;

    while (running) {
        std::cin >> command;

        if (command == "exit") {
            running = false;
        }
        else if (command == "count") {
            std::cout << simulation_time << std::endl;
        }
    }
}