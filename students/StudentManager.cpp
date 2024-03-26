#include "student.h"
#include <vector>
#include <algorithm>
#include "StudentManager.h"
#include <iostream>
using namespace std;

vector<Student> StudentManager::getStudentsWithAvgMarkAbove(const std::vector<Student>& students, double minAvgMark) {
    vector<Student> result;

    for (const Student& student : students) {
        if (student.getAverageMarkAcrossAllCourses() >= minAvgMark) {
            result.push_back(student);
        }
    }

    return result;
}

void StudentManager::printAllStudentInfo(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << student.getFullInfo() << std::endl;
    }
}