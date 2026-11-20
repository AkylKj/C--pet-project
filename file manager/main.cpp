#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;


// Check file spot

int main() {
    std::filesystem::path path = "/path/to/directory";

    if (std::filesystem::exists(path)) {
        std::cout << "Directory exists: " << path << std::endl;
    } else {
        std::cout << "Directory does not exist: " << path << std::endl;
    }

    return 0;
}
