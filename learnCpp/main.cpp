#include <iostream>
#include <string>

std::string upperCase(char *str) {
    std::string buffer;

    for (int i = 0; str[i]; i++) {
        buffer += char(toupper(str[i]));
    }
    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <param>" << std::endl;
        return 1;
    }
    std::cout << upperCase(argv[1]) << std::endl;

    return 0;
}
