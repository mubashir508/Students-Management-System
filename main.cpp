#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include "CSV/csv.h"
#include "DataStructures/HashTableAVL.h"
#include "Models/Info.h"
#include "printFunction.h"
#include "Functions/Functions.h"
using namespace std;

string pathToCSV = "F:/Code/cpp/DSA/Final Project/CSV-Parser-Analytics/CSV/student_record.csv";

AVLNameSortsName *namesTree;
AVLName *nameTree;
HashTableAVL *cmsTable;


void storeInStructures(string path, int size){

    cmsTable = new HashTableAVL(200000);


    nameTree = new AVLName();


    namesTree = new AVLNameSortsName();

    std::ifstream in(pathToCSV);
    if (in.fail()){
        (cout << "File not found" << endl);
        return;
    }
    int counter = 0;


    int cmsId,age, year;
    string residentialStatus, depName, city, province, email, sName, gName, gender,major;
    double gpa, cgpa;


    while(in.good() and counter <= 200000)
    {
        std::vector<std::string> row = csv_read_row(in, ',');
        if(counter != 0){
            for(int i = 0,leng = row.size(); i < leng; i++){
                switch ( i ) {
                    case 0:
                        !row[i].empty() ? cmsId = stoi(row[i]) : cmsId = 0;
                        break;
                    case 1:
                        email = row[i];
                        break;
                    case 2:
                        sName = row[i];
                        break;
                    case 3:
                        gName = row[i];
                        break;
                    case 4:
                        gender = row[i];
                        break;
                    case 5:
                        !row[i].empty() ? age = stoi(row[i]) : age = 0;
                        break;
                    case 6:
                        major = row[i];
                        break;
                    case 7:
                        depName = row[i];
                        break;
                    case 8:
                        !row[i].empty() ? gpa = stod(row[i]) : gpa = 0;
                        break;
                    case 9:
                        !row[i].empty() ? cgpa = stod(row[i]) : cgpa = 0;
                        break;
                    case 10:
                        !row[i].empty() ? year = stoi(row[i]) : year = 0;
                        break;
                    case 11:
                        residentialStatus = row[i];
                        break;
                    case 12:
                        city = row[i];
                        break;
                    case 13:
                        province = row[i];
                        break;
                    
                    default:
                        break;
                }
            }
            Info *info = new Info(age, depName, gpa, cgpa, province, city, gender, major);
            Name* name = new Name(sName, gName);
            Student *prop = new Student(cmsId, residentialStatus, email, year, info, name);

            
            //Insert Name Into Name Tree according to gName
            nameTree->setRoot(nameTree->insertNode(name, nameTree->getRoot(), prop));

            //Insert Name Into Name Tree according to sName
            namesTree->setRoot(namesTree->insertNode(name, namesTree->getRoot(), prop));

            //Insert the student data into hash table
            cmsTable->insertIntoTable(prop);
        }
        counter++;
    }
    in.close();
}


class Mainmenu{
public:
    Mainmenu(){
        cout << "Welcome to the Student Management System" << endl;
        //create a while loop that asks for exit or load data
        //if load data is selected then call the load data function
        int choice;
        do{
            cout << "1. Load Data" << endl;
            cout << "2. Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    storeInStructures(pathToCSV, 200000);
                    break;
                case 2:
                    cout << "Thank you for using the Students Record Management" << endl;
                    return;
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                    break;
            }
        }while(choice != 2 && choice != 1);

        choice = 0;
        string name;
        do{
            cout << "1. Search by Guardian Name" << endl;
            cout << "2. Search by Student Name" << endl;
            cout << "3. Search Student by CMS ID" << endl;
            cout << "4. Print all Students" << endl;
            cout << "5. Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Please enter the name of Guardian" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    getline(cin, name);
                    searchForgName(nameTree, name);
                    break;
                case 2:
                    cout << "Please enter the name of the Student" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    getline(cin, name);
                    searchForsName(namesTree, name);
                    break;
                case 4:
                    cmsTable->print(200000);
                    break;
                case 3:
                    cout << "Please enter the CMS ID of the Student" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    int index;
                    cin >> index;
                    searchStudentByID(index, cmsTable);
                    break;
                case 5:
                    cout << "Thank you for using the Students Record Management" << endl;
                    return;
                    break;
                default:
                    cout << "Invalid Choice" << endl;
                    break;
            }
        }while(choice != 3 && choice != 2 && choice != 1 && choice != 4 && choice != 5);

    }

};



int main(){

    Mainmenu menu;

}
