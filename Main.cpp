#include <iostream>
#include "Student.h"
#include <vector>
using namespace std;

vector<Student> students;
int rollCounter = 1001;

void addStudent() {
    string name; int deptChoice, section;
    cout << "Enter Name: "; cin.ignore(); getline(cin,name);
    cout << "Department(0-CS,1-Eng,2-Med): "; cin >> deptChoice;
    cout << "Section: "; cin >> section;
    Student s(name, static_cast<Department>(deptChoice), section);
    for(int i=0;i<s.subjects.size();i++){
        cout << "Marks for " << s.subjects[i] << ": ";
        cin >> s.marks[i];
    }
    s.calculatePercentage();
    s.calculateScholarship();
    students.push_back(s);
}

void displayStudents() {
    for(auto &s: students){
        cout << s.rollNo << " " << s.name << " Dept:" << s.dept << " Sec:" << s.section
             << " %:" << s.percentage << " Sch:" << s.scholarship << "%\n";
    }
}

int main(){
    int choice;
    do{
        cout << "1.Add 2.Display 0.Exit: "; cin >> choice;
        switch(choice){
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
        }
    }while(choice!=0);
}
