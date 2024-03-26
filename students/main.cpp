#include "student.h"
#include "course.h"
#include "StudentManager.h"
#include <iostream>
#include <list>
#include <functional>
#include "person.h"
#include <vector>
#include "output.cpp"
using namespace std;

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << "Name: " << person.getName() << ", Age: " << person.getAge();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    return os << student.getInfo();
    //return os<<student.getFullInfo();
}

std::ostream& operator<<(std::ostream& os, const Course& course) {
    os << course.getName();
    return os;
}


int main() {
    Course math("Mathematics");
    Course physics("Physics");
    Course cs("Computer Science");

    Student john("John Doe", 20, 12345);
    john.addCourse(&math);
    john.addCourse(&physics);

    Student jane("Jane Smith", 21, 67890);
    jane.addCourse(&cs);
    jane.addCourse(&math);

    try {
        john.setMarkForCourse(&math, 8);
        john.setMarkForCourse(&physics, 8);
        jane.setMarkForCourse(&cs, 1);
        jane.setMarkForCourse(&math,2);
        jane.setMarkForCourse(&physics, 0.0); //exception, doesnt participate in course
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    //overload cout
    //cout << john << "\n";
    //cout << jane << "\n";
    
    //create list of students
    vector<Student> students;
    students.push_back(john);
    students.push_back(jane);

    StudentManager manager;
    cout << "All students:\n";
    manager.printAllStudentInfo(students);
    //printList(students);

    //filter students by avg mark
    double avgMarkThreshold = 5.0;
    vector<Student> goodStudents = manager.getStudentsWithAvgMarkAbove(students, avgMarkThreshold);

    cout << "\nStudents with avgMark >= " << avgMarkThreshold << ":\n";
    printList(goodStudents);

    return 0;
}