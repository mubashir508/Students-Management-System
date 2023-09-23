
#ifndef PROJECT_NEW_LOCATION_H
#define PROJECT_NEW_LOCATION_H

#include<string>
#include<iostream>

using namespace std;

class Info{
    double gpa, cgpa;
    string depName,province,city,gender,major;
    int age;
public:
    Info();
    Info(int id, string name, double gpa, double cgpa, string province, string city,string gender,string major);
    void print();
};

Info::Info() {
    this->age = 0;
    this->gender="";
    this->major = "";
    this->depName = "";
    this->gpa = 0;
    this->cgpa = 0;
    this->city = "";
    this->province = "";
}

Info::Info(int id, string name, double gpa, double cgpa, string province, string city,string gender,string major) {
    this->age = id;
    this->gender=gender;
    this->depName = name;
    this->gpa = gpa;
    this->cgpa = cgpa;
    this->province = province;
    this->city = city;
    this->major = major;
}

void Info::print() {
    cout << "Gender: "<<gender<<endl;
    cout << "Age: " << age << endl;
    cout << "Major: " << major << endl;
    cout << "Department Name: " << depName << endl;
    cout << "GPA: " << gpa << endl;
    cout << "CGPA: " << cgpa << endl;
    cout << "Province: " << province << endl;
    cout << "City: " << city << endl;
}

#endif //PROJECT_NEW_LOCATION_H
