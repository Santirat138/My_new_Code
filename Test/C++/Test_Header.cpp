#include "HBinarySearchTree.hpp"

//------------------ function

//------------------ main
int main(){
    BST *bst=new BST();
    bst->root=bst->insertNum(bst->root, 50);
    bst->root=bst->insertNum(bst->root, 40);
    bst->root=bst->insertNum(bst->root, 30);
    bst->root=bst->insertNum(bst->root, 80);
    bst->root=bst->insertNum(bst->root, 45);
    bst->showLevelorder();
}
//------------------ function
