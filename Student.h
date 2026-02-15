#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<vector>
using namespace std;

enum Department{CS,Engineering,Medical};

class Student{
private:
    string name;
    int rollNo;
    Department dept;
    int section;
    vector<string> subjects;
    vector<int> marks;
    double percentage;
    double scholarship;
public:
    Student(string n,Department d,int sec,int roll);
    void enterMarks();
    void calculatePercentage();
    void calculateScholarship();
    void display() const;

    int getRoll() const{return rollNo;}
    double getPercentage() const{return percentage;}
    Department getDept() const{return dept;}
    string getName() const{return name;}
};

#endif
