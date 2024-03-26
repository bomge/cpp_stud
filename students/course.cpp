#include "course.h"
#include <iostream>
using namespace std;

Course::Course(const string& name)
    : name(name), credits(credits) {}

Course::~Course() {}

string Course::getName() const {
    return name;
}



void Course::setName(const string& name) {
    this->name = name;
}

