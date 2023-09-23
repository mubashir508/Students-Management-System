
#ifndef PROJECT_NEW_PROPERTY_H
#define PROJECT_NEW_PROPERTY_H
#include <string>
#include "Info.h"

//#include "Name.h"
using namespace std;
class Name;
class Student{
    int cmsId, year;
    string residentialStatus, email;
    Info* gInfo;
    Name* name;
public:
    string getDate();
    void print();
    int getcmsId() const;
    Student();
    bool isEmpty() const;
    Student(int id,string rStatus, string email, long int year,  Info* info, Name* name);
    bool operator= (Student obj2);
};

int Student::getcmsId() const {
    return cmsId;
}

bool Student::isEmpty() const {
    return cmsId == 0;
}

Student::Student( int id, string rStatus, string email, long int year, Info *info, Name* name) {
    cmsId = id;
    this->residentialStatus = rStatus;
    this->email = email;
    this->year = year;
    this->gInfo = info;
    this->name = name;
}

Student::Student() {
    cmsId = 0;
    this->residentialStatus = "";
    this->email = "";
    this->year = 0;
    this->gInfo = nullptr;
    this->name = nullptr;
}



bool Student::operator=(Student obj1) {
    return (this->cmsId == obj1.cmsId);
}

string Student::getDate() {
    return email;
}


#endif //PROJECT_NEW_PROPERTY_H
