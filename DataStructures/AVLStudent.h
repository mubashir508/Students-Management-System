
#ifndef PROJECT_NEW_AVLPROPERTY_H
#define PROJECT_NEW_AVLPROPERTY_H

#include "../Models/Student.h"


#include<iostream>
using namespace std;


struct NodeAVL{
    Student* obj;
    NodeAVL* left, *right;
    int height;
    NodeAVL(){
        obj = nullptr;
        left = right = nullptr;
        height = 1;
    }
};

class AVLStudent{
private:
    NodeAVL* root, *loc, *ploc;
public:
    AVLStudent();
    bool isEmpty();
    NodeAVL* insertNode(Student *value, NodeAVL* temp);
    void searchNode(Student *value);
    int getBalanceFactor(NodeAVL* temp);
    int getHeight(NodeAVL* temp);
    NodeAVL* rightRotate(NodeAVL* tempRoot);
    NodeAVL* leftRotate(NodeAVL* tempRoot);
    void deleteNode(Student *value);
    void printPreOrder( NodeAVL* temp);
    NodeAVL* getRoot();
    void setRoot(NodeAVL* temp);
    int updateHeight(NodeAVL* temp);
    Student* getStudent(int id);
    void searchNode(int id);
    Student* getRootObject();
};


AVLStudent::AVLStudent() {
    root = loc = ploc = nullptr;
}


bool AVLStudent::isEmpty() {
    return root == nullptr;
}


NodeAVL* AVLStudent::insertNode( Student* value, NodeAVL* temp ) {
    if(temp == nullptr){
        auto* newNode = new NodeAVL;
        newNode->obj = value;
        return newNode;
    }
    else if( temp->obj->getcmsId() == value->getcmsId()){
        //Node with that value already exists, avoid duplication.
        return temp;
    }
    else if( temp->obj->getcmsId() > value->getcmsId()){
        //go left
        temp->left = insertNode(value, temp->left);
    }else{
        temp->right = insertNode(value, temp->right);
    }

    //change the heights
    temp->height = 1 + max(( getHeight(temp->left)), getHeight(temp->right));

    //balance the tree with rotations
    int balanceFactor = getBalanceFactor(temp);
    if(balanceFactor < -1){
        //right side heavier
        if(value->getcmsId() < temp->right->obj->getcmsId() ){
            //right left rotation
            temp->right = rightRotate(temp->right);
            return leftRotate(temp);
        }else{
            return leftRotate(temp);
        }
    }else if(balanceFactor > 1){
        //left side heavier
        if(value->getcmsId() > temp->left->obj->getcmsId()){
            //left right rotation
            temp->left = leftRotate(temp->left);
            return rightRotate(temp);
        }else{
            return rightRotate(temp);
        }
    }
    return temp;
}


void AVLStudent::searchNode( Student* value ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getcmsId() != value->getcmsId() and loc != nullptr){
            ploc = loc;
            if(value->getcmsId() < loc->obj->getcmsId()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}


int AVLStudent::getBalanceFactor( NodeAVL *temp ) {
    if(temp == nullptr) return 0;
    return ( getHeight(temp->left) - getHeight(temp->right) );
}


int AVLStudent::getHeight( NodeAVL *temp ) {
    if(temp == nullptr) return 0;
    return temp->height;
}


NodeAVL *AVLStudent::rightRotate( NodeAVL *tempRoot ) {
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


NodeAVL *AVLStudent::leftRotate( NodeAVL *tempRoot ) {
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


void AVLStudent::deleteNode( Student* value ) {
    if(!isEmpty()){
        //tree exists
        searchNode(value);
        NodeAVL* loc1, *ploc1;
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

        if( loc->obj->getcmsId() == value->getcmsId()){
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


void AVLStudent::printPreOrder( NodeAVL *temp ) {
    if(temp != nullptr){
        temp->obj->print();
        cout << "___________________________________" << endl;
        printPreOrder(temp->left);
        printPreOrder(temp->right);
    }
}


NodeAVL *AVLStudent::getRoot() {
    return root;
}


void AVLStudent::setRoot( NodeAVL *temp ) {
    root = temp;
}


int AVLStudent::updateHeight( NodeAVL *temp ) {
    if(temp){
        return(1+(max(getHeight(temp->left), getHeight(temp->right))));
    }
    return 0;
}

Student* AVLStudent::getStudent( int id ) {
    searchNode(id);

    if(loc == nullptr || loc->obj->getcmsId() != id){
        cout << "Student not found" << endl;
        return nullptr;
    }
    return loc->obj;
}

void AVLStudent::searchNode( int id ) {
    loc = ploc = nullptr;
    if(!isEmpty()){
        loc = root;
        while( loc->obj->getcmsId() != id and loc != nullptr){
            ploc = loc;
            if(id < loc->obj->getcmsId()){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
    }
}

Student *AVLStudent::getRootObject() {
    if(root) return root->obj;
    return nullptr;
}


#endif //PROJECT_NEW_AVLPROPERTY_H
