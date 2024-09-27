#include<iostream>
using namespace std;
//------------------ class node
class node{
	public:
		int num;
		node *left;
		node *right;
		node(int numIn){
			num=numIn;
			left=nullptr;
			right=nullptr;
		}
};
//------------------ class BST
class BST{
	public:
		node *root;
		int treeHeight;
		BST(){
			root=nullptr;
			treeHeight=0;
		}
		node *insertNum(node *currNode, int newNum);
		void setTreeHeight(node *currNode, int currLH, int currRH);
};
node *BST::insertNum(node *currNode, int newNum){
	if(currNode==nullptr){
		return new node(newNum);
	}
	if(currNode->num<newNum){
		currNode->right=insertNum(currNode->right, newNum);
	}
	else if(currNode->num>newNum){
		currNode->left=insertNum(currNode->left, newNum);
	}
	return currNode;
}
void BST::setTreeHeight(node *currNode, int currLH, int currRH){
	// Postorder(left --> right --> root)
    if(currNode==nullptr){
		return ;
	}
	setTreeHeight(currNode->left);
	setTreeHeight(currNode->right);
	return max(lHeight, rHeight)+1;
}

//------------------ main
int main(){

}