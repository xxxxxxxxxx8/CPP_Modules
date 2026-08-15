
#include <easyfind.hpp>
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    int searchValue = 3;
    std::cout << "Searching for " << searchValue << " in vector: ";
    std::cout << (easyfind(vec, searchValue) != -1 ? "Found!" : "Not Found!") << std::endl;

    searchValue = 6;
    std::cout << "Searching for " << searchValue << " in vector: ";
    std::cout << (easyfind(vec, searchValue) != -1 ? "Found!" : "Not Found!") << std::endl;

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    searchValue = 30;
    std::cout << "Searching for " << searchValue << " in list: ";
    std::cout << (easyfind(lst, searchValue) != -1 ? "Found!" : "Not Found!") << std::endl;

    searchValue = 60;
    std::cout << "Searching for " << searchValue << " in list: ";
    std::cout << (easyfind(lst, searchValue) != -1 ? "Found!" : "Not Found!") << std::endl;

    std::vector<int> emptyVec;
    searchValue = 3;
    std::cout << "Searching for " << searchValue << " in empty vector: ";
    std::cout << (easyfind(emptyVec, searchValue) != -1 ? "Found!" : "Not Found!") << std::endl;

    std::vector<int> vecWithDuplicates;
    vecWithDuplicates.push_back(1);
    vecWithDuplicates.push_back(3);
    vecWithDuplicates.push_back(5);
    vecWithDuplicates.push_back(3);
    vecWithDuplicates.push_back(7);

    searchValue = 3;
    std::cout << "Searching for " << searchValue << " in vector with duplicates: ";
    std::cout << (easyfind(vecWithDuplicates, searchValue) != -1 ? "Found!" : "Not Found!") << std::endl;

    return 0;
}
