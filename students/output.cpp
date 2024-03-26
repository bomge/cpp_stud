#include <iostream>
#include <list>
#include "Person.h"
#include <vector>
using namespace std;

template <typename T>
void printList(const std::list<T>& lst) {
    for (const T& elem : lst) {
        cout << elem << std::endl;
    }
}

template <typename T>
void printList(const std::vector<T>& vec) {
    for (const T& elem : vec) {
        cout << elem << std::endl;
    }
}

