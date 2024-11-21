#include "BST_Tool.hpp"

//-------------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->addNum(bst->root, 1001, "item_1", 20, 30);
    bst->root=bst->addNum(bst->root, 1002, "item_2", 20, 50);
    bst->root=bst->addNum(bst->root, 1003, "item_3", 90, 90);
    bst->root=bst->addNum(bst->root, 1004, "item_4", 20, 35);
    bst->root=bst->addNum(bst->root, 1005, "item_5", 10, 5);
    bst->showLevelorder();
}