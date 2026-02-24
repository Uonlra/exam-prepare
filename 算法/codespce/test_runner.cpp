#include <iostream>

#include "exercise.h"

int main() {
    const std::string message = build_message();
    if (message.find("Hello") == std::string::npos) {
        std::cerr << "TEST FAILED: unexpected message: " << message << std::endl;
        return 1;
    }

    std::cout << "TEST OK: " << message << std::endl;
    return 0;
}

