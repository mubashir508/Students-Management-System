
#ifndef PROJECT_NEW_FUNCTIONS_H
#define PROJECT_NEW_FUNCTIONS_H

#include <iostream>
#include <string>
#include "../DataStructures/AVLName.h"
#include "../DataStructures/AVLNameSortsName.h"
using namespace std;

void searchForgName(AVLName* names, string gName){
    names->printBygName(gName);
}

void searchForsName( AVLNameSortsName* sNames, string sName){
    sNames->printBysName(sName);
}

void searchStudentByID(int id, HashTableAVL* table){
    Student* aStudent = table->getValueByID(id);
    if(aStudent) aStudent->print();
}


#endif //PROJECT_NEW_FUNCTIONS_H
