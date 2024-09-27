#include<iostream>
#include "HBinarySearchTree.hpp"
using namespace std;
//------------------ function

//------------------ main
int main(){
    BST *bst=new BST();
    bst->root=bst->insertNum(bst->root, 50);
    bst->root=bst->insertNum(bst->root, 70);
    bst->root=bst->insertNum(bst->root, 40);
    bst->root=bst->insertNum(bst->root, 8);
    bst->showLevelorder();
    cout<<endl<<endl;
    cout<<bst->root->left->left->currHeight;
}
//------------------ function
