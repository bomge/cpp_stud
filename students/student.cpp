#include "Student.h"
#include <numeric>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include "person.h"
#include <iostream>
#include <sstream>  
#include <iomanip>  

using namespace std;

Student::Student(const string& name, int age, int id)
    : Person(name, age), id(id) {}

Student::~Student() {
    for (Course* course : courses) {
        //delete course;
    }
}

int Student::getId() const {
    return id;
}


const list<Course*>& Student::getCourses() const {
    return courses;
}


void Student::setId(int id) {
    this->id = id;
}

void Student::addCourse(Course* course) {
    courses.push_back(course);
    marks[course] = -1.0;
}

void Student::removeCourse(Course* course) {
    auto it = find(courses.begin(), courses.end(), course);
    if (it != courses.end()) {
        courses.erase(it);
        marks.erase(course);
        delete course;
    }
}

double Student::getAverageMarkAcrossAllCourses() const {
    if (marks.empty()) {
        return 0.0;
    }

    double sum = 0.0;
    int count = 0;
    for (const auto& pair : marks) {
        if (pair.second >= 0.0) {
            sum += pair.second;
            count++;
        }
    }

    return sum / count;
}

string Student::getInfo() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(1);
    stream << "Name: " << getName() << ", Age: " << getAge() << ", Avg Mark: " << getAverageMarkAcrossAllCourses();
    return stream.str();
}

string Student::getFullInfo() const {
    string info = getInfo() + "\nCourses:\n";
    for (const Course* course : getCourses()) {
        info += " - " + course->getName() + "\n";
    }
    return info;
}

void Student::setMarkForCourse(Course* course, double mark) {
    auto it = find(courses.begin(), courses.end(), course);
    if (it != courses.end()) {
        if (mark < 0.0 || mark > 10.0) {
            throw invalid_argument("Mark must be between 0 and 10");
        }
        marks[course] = mark;
    }
    else {
        throw invalid_argument("Student is not participate in this course");
    }
}


