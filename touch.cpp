#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

const char invalid_chars[] = { '/', '\\', ':', '*', '+', ',', ';', '<', '>', '?', '=', '|', '"', '\'', '[', ']', '{', '}' };

bool is_valid_filename(const std::string& filename) {
    for (char c : filename) {
        if (std::find(std::begin(invalid_chars), std::end(invalid_chars), c) != std::end(invalid_chars)) {
            return false;
        }
    }
    return true;
}

bool file_exists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

void create_empty_file(const std::string& filename) {
    if (!file_exists(filename)) {
        std::ofstream file(filename);
    }
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv + 1, argv + argc);

    for (const std::string& arg : args) {
        if (is_valid_filename(arg)) {
            create_empty_file(arg);
        }     
    }
    return 0;
}



 