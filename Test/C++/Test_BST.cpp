#include<iostream>
using namespace std;
//-------------------- class node
class node{
	public:
		int num;
		node *left;
		node *right;
		int height;
		node(int numIn){
			num=numIn;
			left=nullptr;
			right=nullptr;
			height=0;
		}
};
//-------------------- class BST
class BST{
	public:
		node *root;
		int treeHeight;
		BST(){
			root=nullptr;
			treeHeight=0;
		}
		node *addNewNum(node *currNode, int newNum);
        int countHeightNum(node *currNode, int targetNum);
};
node *BST::addNewNum(node *currNode, int newNum){
    if(currNode==nullptr){
		return new node(newNum);
	}
    if(currNode->num<newNum){
        currNode->right=addNewNum(currNode->right, newNum);
    }
    else if(currNode->num>newNum){
        currNode->left=addNewNum(currNode->left, newNum);
    }
	// count height.
    
}
int BST::countHeightNum(node *currNode, int targetNum){
	if(currNode==nullptr){
		return 0;
	}
	
}
//-------------------- main
int main(){
	BST *bst=new BST();
	bst->addNewNum(bst->root, 10);
	bst->addNewNum(bst->root, 50);
	bst->addNewNum(bst->root, 6);
	
}