#include <iostream>
#include <string>

std::string upperCase(std::string str) {
    std::string buffer;

    for (int i = {0}; str[i]; i++) {
        buffer += char(toupper(str[i]));
    }
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <param>" << std::endl;
        return 1;
    }
    std::string buffer;
    while (true) {
        std::getline(std::cin, buffer);
        if (std::cin.eof())
            break;
        if (buffer == "EXIT")
            break;
        std::cout << upperCase(buffer) << std::endl;
    }
    return 0;
}
