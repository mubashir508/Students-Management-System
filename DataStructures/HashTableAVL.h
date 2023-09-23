#ifndef PROJECT_NEW_HASHTABLEAVL_H
#define PROJECT_NEW_HASHTABLEAVL_H

#include <iostream>
#include "AVLStudent.h"
#include "../Models/Student.h"
using namespace std;

class HashTableAVL{
private:
    int tableSize;
public:
    AVLStudent* table;
    HashTableAVL();
    HashTableAVL(int size);
    void insertIntoTable(Student* property);
    int getIndex(int id);
    Student* getValueByID(int id);
    Student* getArray();
    void print(int i);
};

HashTableAVL::HashTableAVL() {
    tableSize = 2000;
    table = new AVLStudent[tableSize];
}

HashTableAVL::HashTableAVL( int size ) {
    this->tableSize = size;
    table = new AVLStudent[tableSize];
}

void HashTableAVL::insertIntoTable( Student* property ) {
    //get property id
    int index = getIndex(property->getcmsId());
    table[index].setRoot(table[index].insertNode(property,table[index].getRoot()));
}

int HashTableAVL::getIndex( int id ) {
    return (id % tableSize);
}

Student* HashTableAVL::getValueByID( int id ) {
    int index = getIndex(id);
    Student* aStudent = table[index].getStudent(id);
    return aStudent;
}

void HashTableAVL::print( int i ) {
    for(int j = 0; j < i; j++){
        table[j].printPreOrder(table[j].getRoot());
    }
}


#endif //PROJECT_NEW_HASHTABLEAVL_H
