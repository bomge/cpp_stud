#pragma once
#include <string>
using namespace std;

class Person {
public:
    Person(const std::string& name, int age);
    virtual ~Person();

    string getName() const;
    int getAge() const;

    void setName(const std::string& name);
    void setAge(int age);
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

protected:
    string name;
    int age;
};
