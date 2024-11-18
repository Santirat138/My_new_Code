#include "BST_Tool.hpp"

//-------------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->addNum(bst->root, 1, "_", 10, 10);
    bst->root=bst->addNum(bst->root, 2, "_", 15, 10);
    bst->root=bst->addNum(bst->root, 3, "_", 10, 20);
    bst->showPostorder(bst->root);
}