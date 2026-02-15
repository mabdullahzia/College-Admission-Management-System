#ifndef COLLEGE_H
#define COLLEGE_H
#include"Student.h"
#include<vector>
#include<algorithm>
using namespace std;

class College{
private:
    vector<Student> students;
    int rollCounter;
public:
    College(){rollCounter=1001;}
    void addStudent();
    void displayAll();
    void displayByDepartment(Department d);
    void displayTopStudents(int n);
};

#endif
