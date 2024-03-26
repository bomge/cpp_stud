#pragma once
#include "student.h"
#include <vector>
using namespace std;

class StudentManager {
public:
    vector<Student> getStudentsWithAvgMarkAbove(const std::vector<Student>& students, double minAvgMark);
    void printAllStudentInfo(const std::vector<Student>& students);
};