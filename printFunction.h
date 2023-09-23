
#include "Models/Student.h"
#include "DataStructures/AVLName.h"
#include <iostream>
using namespace std;

void Student::print() {
    if(cmsId != 0){
        cout << "CMS ID: " << cmsId << endl;
        name->printFromStudent();
        cout << "E-mail: " << email << endl;
        gInfo->print();
        cout << "Residential Status: " << residentialStatus << endl;
        cout << "Year: " << year << endl;
    }else{
        cout << "Empty Slot" << endl;
    }

}