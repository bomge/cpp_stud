#pragma once
#include <string>
using namespace std;

class Course {
public:
    Course(const std::string& name);
    ~Course();

    string getName() const;

    void setName(const std::string& name);

private:
    string name;
    int credits;
};