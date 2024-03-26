#pragma once
#include "person.h"
#include "course.h"
#include <list>
#include <map>
#include <string>
using namespace std;

class Student : public Person {
public:
    Student(const std::string& name, int age, int id);
    ~Student();

    int getId() const;
    const std::list<Course*>& getCourses() const;
    double getMarkForCourse(const Course* course) const;

    void setId(int id);
    void addCourse(Course* course);
    void removeCourse(Course* course);
    void setMarkForCourse(Course* course, double mark);
    double getAverageMarkAcrossAllCourses() const;

    string getInfo() const;
    string getFullInfo() const;

private:
    int id;
    list<Course*> courses;
    map<Course*, double> marks;
};