#include "Student.h"
#include <iostream>
#include <vector>
using namespace std;

extern vector<Student> students;
extern int rollCounter;

Student::Student(string n, Department d, int sec) {
    name = n; dept = d; section = sec; rollNo = rollCounter++;
    if(dept == CS) subjects = {"OOP","DSA","Math"};
    else if(dept == Engineering) subjects = {"Physics","Math","Engineering"};
    else subjects = {"Biology","Chemistry","Physics"};
    marks.resize(subjects.size(), 0);
    percentage = 0;
    scholarship = 0;
}

void Student::calculatePercentage() {
    int total = 0;
    for(int i=0;i<marks.size();i++) total += marks[i];
    percentage = total * 1.0 / marks.size();
}

void Student::calculateScholarship() {
    if(percentage>90) scholarship=50;
    else if(percentage>75) scholarship=25;
    else scholarship=0;
}
