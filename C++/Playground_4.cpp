#include<iostream>
#include "biTree.h"
using namespace std;

int main(){
    biTree *tree=new biTree();
    tree->insert(5, tree->root);
    tree->insert(2, tree->root);
    tree->insert(9, tree->root);
    tree->insert(1, tree->root);
    tree->insert(8, tree->root);
    tree->insert(15, tree->root);
    tree->insert(20, tree->root);
    tree->showPostorder(tree->root);
}