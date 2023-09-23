//
// Created by Muhammad Sunaam on 02/01/2023.
//

#ifndef PROJECT_NEW_AVLNameSortsNameSORTAGENCY_H
#define PROJECT_NEW_AVLNameSortsNameSORTAGENCY_H

#include "../Models/Name.h"

#include<iostream>
using namespace std;

class AVLNameSortsName{
private:
    Node* root, *loc, *ploc;
public:
    AVLNameSortsName();
    bool isEmpty();
    Node* insertNode(Name *value, Node* temp, Student* property);
    void searchNode(Name *value);
    int getBalanceFactor(Node* temp);
    int getHeight(Node* temp);
    Node* rightRotate(Node* tempRoot);
    Node* leftRotate(Node* tempRoot);
    void deleteNode(Name *value);
    void printPreOrder( Node* temp);
    Node* getRoot();
    void setRoot(Node* temp);
    int updateHeight(Node* temp);
    Name* getsName(string sName);
    void searchNode(string sName);
    void printBysName(string sName);
};


AVLNameSortsName::AVLNameSortsName() {
    root = loc = ploc = nullptr;
}


bool AVLNameSortsName::isEmpty() {
    return root == nullptr;
}


Node* AVLNameSortsName::insertNode( Name* value, Node* temp, Student* property ) {
    if(temp == nullptr){
        auto* newNode = new Node;
        newNode->obj = value;
        newNode->properties->setRoot(newNode->properties->insertNode(property, newNode->properties->getRoot()));
        return newNode;
    }
    else if( temp->obj->getsName() == value->getsName()){
        //Node with that value already exists, avoid duplication.
        //But Insert the values of properties
        temp->properties->setRoot(temp->properties->insertNode(property, temp->properties->getRoot()));
        temp->obj->insertStudent(property);
        return temp;
    }
    else if( temp->obj->getsName() > value->getsName()){
        //go left
        temp->left = insertNode(value, temp->left, property);
    }else{
        temp->right = insertNode(value, temp->right, property);
    }

    //change the heights
    temp->height = 1 + max(( getHeight(temp->left)), getHeight(temp->right));

    //balance the tree with rotations
    int balanceFactor = getBalanceFactor(temp);
    if(balanceFactor < -1){
        //right side heavier
        if(value->getsName() < temp->right->obj->getsName() ){
            //right left rotation
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }else{
            return leftRotate(temp);
        }
    }else if(balanceFactor > 1){
        //left side heavier
        if(value->getsName() > temp->left->obj->getsName()){
            //left right rotation
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }else{
            return rightRotate(temp);
        }
    }
    return temp;
}


void AVLNameSortsName::searchNode( Name* name ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getsName() != name->getsName() and loc != nullptr){
            ploc = loc;
            if(name->getsName() < loc->obj->getsName()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}


int AVLNameSortsName::getBalanceFactor( Node *temp ) {
    if(temp == nullptr) return 0;
    return ( getHeight(temp->left) - getHeight(temp->right) );
}


int AVLNameSortsName::getHeight( Node *temp ) {
    if(temp == nullptr) return 0;
    return temp->height;
}


Node *AVLNameSortsName::rightRotate( Node *tempRoot ) {
    auto* x = tempRoot;
    auto* y = x->left;
    auto* temp = y->right;
    y->right = x;
    x->left = temp;
    //update heights
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    return y;
}


Node *AVLNameSortsName::leftRotate( Node *tempRoot ) {
    auto* x = tempRoot;
    auto* y = x->right;
    auto* temp = y->left;
    y->left = x;
    x->right = temp;
    //update heights
    x->height = updateHeight(x);
    y->height = updateHeight(y);
    return y;
}


void AVLNameSortsName::deleteNode( Name* value ) {
    if(!isEmpty()){
        //tree exists
        searchNode(value);
        Node* loc1, *ploc1;
        loc1 = loc; ploc1 = ploc;

        //case 1: Node has two children
        if(loc->right!=nullptr and loc->left!=nullptr){
            //find rightmost child in the left subtree for replacement
            ploc = loc;
            loc = loc->left;
            while(loc->right!=nullptr){
                ploc = loc;
                loc=loc->right;
            }
        }

        //case 2: Node has right subtree only
        if(loc->left == nullptr and loc->right != nullptr){
            if(loc == root){
                root = root->right;
            }
            else if (ploc->left == loc){
                ploc->left = loc->right;
            }else{
                ploc->right = loc->right;
            }
            loc->right = nullptr;
        }

            //case 3: Node has left subtree only
        else if(loc->right == nullptr and loc->left != nullptr){
            if(loc == root){
                root = root->left;
            }
            else if (ploc->right == loc){
                ploc->right = loc->left;
            }else{
                ploc->left = loc->left;
            }
            loc->left = nullptr;
        }

            //case 4: Node is a leaf
        else if (loc->right == nullptr and loc->left == nullptr){
            if(loc == root){
                root = nullptr;
            }
            else if(ploc->left == loc){
                ploc->left = nullptr;
            }else {
                ploc->right = nullptr;
            }
        }

        if( loc->obj->getsName() == value->getsName()){
            delete loc;
        }else{
            //replacement node is loc
            //Node to be deleted is loc1
            loc->left = loc1->left;
            loc->right = loc1->right;
            if(ploc1->right == loc1){
                ploc1->right = loc;
            }else{
                ploc1->left = loc;
            }
            delete loc1;
        }
    }else{
        //empty tree
        return;
    }
}


void AVLNameSortsName::printPreOrder( Node *temp ) {
    if(temp != nullptr){
        temp->obj->printForName();
        cout << "___________________________________" << endl;
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
}


Node *AVLNameSortsName::getRoot() {
    return root;
}


void AVLNameSortsName::setRoot( Node *temp ) {
    root = temp;
}


int AVLNameSortsName::updateHeight( Node *temp ) {
    if(temp){
        return(1+(max(getHeight(temp->left), getHeight(temp->right))));
    }
    return 0;
}

Name* AVLNameSortsName::getsName( string sName ) {
    searchNode(sName);
    if(loc != nullptr and loc->obj->getsName() == sName){
        return loc->obj;
    }
    return nullptr;
}

void AVLNameSortsName::searchNode( string sName ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while(  loc != nullptr and loc->obj->getsName() != sName){
            ploc = loc;
            if(sName < loc->obj->getsName()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}

void AVLNameSortsName::printBysName( string sName ) {
    searchNode(sName);
    if(loc == nullptr){
        cout << "Student not found" << endl;
        return;
    }else{
        loc->obj->printFromStudent();
        loc->properties->printPreOrder(loc->properties->getRoot());
    }
}

#endif //PROJECT_NEW_AVLNameSortsNameSORTAGENCY_H
