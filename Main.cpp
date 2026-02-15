#include<iostream>
#include"College.h"
using namespace std;

int main(){
    College c;
    int choice;
    do{
        cout<<"1.Add 2.DisplayAll 3.ByDept 4.Top 0.Exit:";cin>>choice;
        switch(choice){
            case 1:c.addStudent();break;
            case 2:c.displayAll();break;
            case 3:{
                int d;cout<<"Dept(0-CS,1-Eng,2-Med):";cin>>d;
                c.displayByDepartment(static_cast<Department>(d));
                break;
            }
            case 4:{
                int n;cout<<"Top N students:";cin>>n;
                c.displayTopStudents(n);
                break;
            }
        }
    }while(choice!=0);
}
