#include "person.h"
#include <iostream>
using namespace std;

Person::Person(const std::string& name, int age)
    : name(name), age(age) {}

Person::~Person() {}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

