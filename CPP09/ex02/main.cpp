//
// Created by redone on 9/7/23.
//

#include "PmergeMe.hpp"
#include <iomanip>

void fillContainer(std::vector<int>&, const char **);
void fillContainer(std::deque<int>&, const char **);

int main(int argc, const char *argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe {m_listDeque of random numbers}." << std::endl;
        return 1;
    }

    if (argc == 2) {
        return 0;
    }
    // clock_t startVector = clock();

    std::deque<int> dq;
    std::vector<int> vc;

    fillContainer(dq, argv);
    fillContainer(vc, argv);

    std::string before ="before: ";
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); it ++) {
        char buffer[50];
        sprintf(buffer, "%d", *it);
        std::string nbr (buffer);
        before += buffer;
        before += " ";
    }

    clock_t startDeque = clock(); PmergeMe Sdeque(dq); clock_t endDeque = clock();
    clock_t startVector = clock(); PmergeMe Svector(vc); clock_t endVector = clock();

    double durationDeque = ((endDeque - startDeque) / (double)CLOCKS_PER_SEC) * 1000000;
    double durationVector = ((endVector - startVector) / (double)CLOCKS_PER_SEC) * 1000000;

    std::string after = "after: ";
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); it ++) {
        char buffer[50];
        sprintf(buffer, "%d", *it);
        std::string nbr (buffer);
        after += buffer;
        after += " ";
    }

    std::cout << before << std::endl;
    std::cout << after << std::endl;
    std::cout << "Time to process a range of " << " elements with std::vector : " << std::fixed << std::setprecision(6) << durationVector << " us" << std::endl;
    std::cout << "Time to process a range of " << " elements with std::deque : " << std::fixed << std::setprecision(6) << durationDeque << " us" << std::endl;

    return 0;
}

void fillContainer(std::deque<int>& container, const char *args[]) {
    for (int i = 1; args[i]; ++ i) {
        char *pEnd;
        long v = strtol(args[i], &pEnd, 10);
        while (*pEnd && std::iswspace(*pEnd)) ++pEnd;
        if (*pEnd != 0) {
            std::cerr << "Error: invalid number \"" << args[i] << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (v < 0) {
            std::cerr << "Error: negative number \"" << args[i] << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        container.push_back(v);
    }
}

void fillContainer(std::vector<int>& container, const char *args[]) {
    for (int i = 1; args[i]; ++ i) {
        char *pEnd;
        long v = strtol(args[i], &pEnd, 10);
        while (*pEnd && std::iswspace(*pEnd)) ++pEnd;
        if (*pEnd != 0) {
            std::cerr << "Error: invalid number \"" << args[i] << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        if (v < 0) {
            std::cerr << "Error: negative number \"" << args[i] << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        container.push_back(v);
    }
}

