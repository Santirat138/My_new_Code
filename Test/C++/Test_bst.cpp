#include<iostream>
#include "bst.hpp"
using namespace std;

int main(){
    bst *BST=new bst();
    BST->insertNum(BST->root, 50);
    BST->insertNum(BST->root, 15);
    BST->insertNum(BST->root, 78);
    BST->insertNum(BST->root, 55);
    BST->insertNum(BST->root, 23);
    BST->insertNum(BST->root, 25);
    BST->insertNum(BST->root, 57);
    BST->insertNum(BST->root, 10);
    BST->showLevelorder();
}