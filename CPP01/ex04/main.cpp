//
// Created by Redouane Elkaboussi on 6/3/23.
//

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

std::string readFile(const char *string);

void changing(std::string &fileContent, std::string haystack, std::string needle);

void writing(const std::string &filename, const std::string &fileContent);

/* args = {filename, string 1, string 2} */
int main(int argc, const char *argv[]) {
    std::string fileContent;

    if (argc != 4) {
        std::cerr << "Error: invalid arguments" << std::endl;
        std::cerr << "Usage: ./exec {filename} {string 1} {string 2}" << std::endl;
        return (EXIT_FAILURE);
    }
    fileContent = readFile(argv[1]);
    changing(fileContent, argv[2], argv[3]);
    writing(std::string(argv[1]), fileContent);
    return 0;
}

std::string readFile(const char *string) {
    char byte;
    std::string content;
    std::ifstream filePtr;

    filePtr.open(string);
    if (filePtr.fail()) {
        std::cerr << "Error: can't open '" << string << "' file." << std::endl;
        exit(EXIT_FAILURE);
    }
    while (filePtr.get(byte)) {
        content += byte;
    }
    filePtr.close();
    return content;
}

void changing(std::string &fileContent, std::string haystack, std::string needle) {
    if (haystack.empty() || haystack == needle)
        return;
    while (true) {
        size_t position = fileContent.find(haystack);
        if (position == std::string::npos)
            break;
        fileContent.erase(position, haystack.length());
        fileContent.insert(position, needle);
    }
}

void writing(const std::string &filename, const std::string &fileContent) {
    std::ofstream file;
    file.open((filename + ".replace").c_str());
    file << fileContent;
    file.close();

}
