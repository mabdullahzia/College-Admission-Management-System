#include"College.h"
#include<iostream>
using namespace std;

Student::Student(string n,Department d,int sec,int roll){
    name=n;dept=d;section=sec;rollNo=roll;
    if(dept==CS) subjects={"OOP","DSA","Math"};
    else if(dept==Engineering) subjects={"Physics","Math","Engineering"};
    else subjects={"Biology","Chemistry","Physics"};
    marks.resize(subjects.size(),0);
    percentage=0;
    scholarship=0;
}

void Student::enterMarks(){
    cout<<"Enter marks for "<<name<<":\n";
    for(int i=0;i<subjects.size();i++){
        cout<<subjects[i]<<":";
        cin>>marks[i];
    }
}

void Student::calculatePercentage(){
    int total=0;
    for(int m:marks) total+=m;
    percentage=total*1.0/marks.size();
}

void Student::calculateScholarship(){
    if(percentage>=90) scholarship=50;
    else if(percentage>=75) scholarship=25;
    else scholarship=0;
}

void Student::display() const{
    cout<<"Roll:"<<rollNo<<" Name:"<<name
        <<" Dept:"<<dept<<" Sec:"<<section
        <<" %:"<<percentage<<" Sch:"<<scholarship<<"%\n";
}

void College::addStudent(){
    string n;int sec,deptChoice;
    cout<<"Enter student name:";cin.ignore();getline(cin,n);
    cout<<"Department(0-CS,1-Eng,2-Med):";cin>>deptChoice;
    cout<<"Section:";cin>>sec;
    Student s(n,static_cast<Department>(deptChoice),sec,rollCounter++);
    s.enterMarks();
    s.calculatePercentage();
    s.calculateScholarship();
    students.push_back(s);
}

void College::displayAll(){
    for(auto &s:students) s.display();
}

void College::displayByDepartment(Department d){
    for(auto &s:students) if(s.getDept()==d) s.display();
}

void College::displayTopStudents(int n){
    vector<Student> temp=students;
    sort(temp.begin(),temp.end(),[](Student &a,Student &b){return a.getPercentage()>b.getPercentage();});
    for(int i=0;i<n && i<temp.size();i++) temp[i].display();
}
