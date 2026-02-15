#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;

enum Department { CS, Engineering, Medical };

class Student {
public:
    string name;
    int rollNo;
    Department dept;
    int section;
    vector<string> subjects;
    vector<int> marks;
    double percentage;
    double scholarship;

    Student(string n, Department d, int sec);
    void calculatePercentage();
    void calculateScholarship();
};

#endif
