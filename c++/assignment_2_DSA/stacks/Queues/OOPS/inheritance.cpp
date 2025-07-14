//Q8 heirarchial inheritance
#include<iostream>
#include<string>
using namespace std;
class LibraryUser{
string name;
int id;
string contact_no;
public:
getInfo(){
    cout<<"enter your name "<<endl;
    fflush(stdin);
    getline(cin,name);
    cout<<"enter your id "<<endl;
    cin>>id;
    cout<<"enter your contact no. "<<endl;
    fflush(stdin);
    cin>>contact_no;
}
showInfo(){
    cout<<"Name: "<<name<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"Contact: "<<contact_no<<endl;
}
};
class Student:protected LibraryUser{
string grade;
public:
getGrade(){
    getInfo();
    cout<<"enter students's grade"<<endl;
    fflush(stdin);
    getline(cin,grade);
}
showGrade(){
    showInfo();
    cout<<"Grade: "<<grade<<endl;
}
};
class Teacher:protected LibraryUser{
string dept;
public:
getDept(){
    getInfo();
    cout<<"enter your department "<<endl;
    fflush(stdin);
    getline(cin,dept);
}
showDept(){
    showInfo();
    cout<<"Department: "<<dept<<endl;
}
};
int main(){
Student s;
Teacher t;
string pos;
cout<<"enter your position"<<endl;
fflush(stdin);
getline(cin,pos);
if(pos=="Student"){
    s.getGrade();
    s.showGrade();
}
if(pos=="Teacher"){
    t.getDept();
    t.showDept();
}


}