bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void create_starting_objects() {
    airports.push_back(Airport("Warsaw", 1000, 1000, 2));
    airports.push_back(Airport("Poznan", 500, 800, 1));
    airports.push_back(Airport("Moscow", 4000, 2000, 3));
}