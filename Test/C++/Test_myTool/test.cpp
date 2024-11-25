#include "BST_Tool.hpp"

//-------------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->addNumBy_itemId(bst->root, 1001, "item_1", 20, 30);
    bst->root=bst->addNumBy_itemId(bst->root, 1005, "item_2", 20, 50);
    bst->root=bst->addNumBy_itemId(bst->root, 1004, "item_3", 20, 90);
    bst->root=bst->addNumBy_itemId(bst->root, 1003, "item_4", 20, 40);
    bst->root=bst->addNumBy_itemId(bst->root, 1002, "item_5", 20, 20);
    bst->showLevelorder();
    cout<<endl;
    cout<<bst->findItem(bst->root, 1003)->itemData.itemId;
}