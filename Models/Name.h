
#ifndef PROJECT_NEW_NAME_H
#define PROJECT_NEW_NAME_H

#include<string>

using namespace std;

class Name{
    string sName, gName;
    AVLStudent *properties;
public:
    Name(string sName, string gName);
    void printForName();
    void printFromStudent();
    string getsName();
    string getgName();
    void insertStudent(Student* aStudent);
    Student* getFirstStudentInserted();
    void printFromTree();
};

Name::Name(string sName, string gName){
this->sName = sName;
this->gName = gName;
properties = new AVLStudent();
}

void Name::printForName(){
    cout << "Student Name: " << sName << endl;
    cout << "Guardian Name: " << gName << endl;
    cout << "_____Students_____" << endl;
    properties->printPreOrder(properties->getRoot());
}
void Name::printFromStudent(){
    cout << "Student Name: " << sName << endl;
    cout << "Guardian Name: " << gName << endl;
}
string Name::getsName(){
    return sName;
}
string Name::getgName(){
    return gName;
}
void Name::insertStudent(Student* aStudent){
    properties->setRoot(properties->insertNode(aStudent, properties->getRoot()));
}
Student* Name::getFirstStudentInserted(){
    return properties->getRootObject();
}

void Name::printFromTree() {
    cout << "Student  Name: " << sName << endl;
    cout << "Guardian Name: " << gName << endl;
}

#endif //PROJECT_NEW_NAME_H
