// Add function show path from root to target node.
#include<iostream>
using namespace std;
//------------------ class node
class node{
	public:
		int num;
		node *left;
		node *right;
		int currHeight;
		node(int numIn){
			num=numIn;
			left=nullptr;
			right=nullptr;
			currHeight=0;
		}
};
//------------------ class toolsBox
class toolsBox{
	public:
		int getHeight(node *nodeIn){
			if(nodeIn==nullptr){
				return 0;
			}
			return nodeIn->currHeight;
		}
};
//------------------ class BST
class BST{
	public:
		node *root;
		toolsBox *tool;
		int maxTreeHeight;
		BST(){
			root=nullptr;
			tool=new toolsBox();
			maxTreeHeight=0;
		}
		node *insertNum(node *currNode, int newNum);
		void updateTreeHeight();
		void showCurrLevel(node *currNode, int levelIn);
		void showLevelorder();
		node *findNum(node *currNode, int targetNum);
		node *deleteNum(node *currNode, int targetNum);
		node *findMaxLeftNum(node *currNode);
		node *findMinRightNum(node *currNode);
		int findHeightDifference(node *node1, node *node2);
		void showNodePath(node *currNode, int targetNum);
		void isCurrNodeBalance(node *currNode);
};
node *BST::insertNum(node *currNode, int newNum){
	if(currNode==nullptr){
		currNode=new node(newNum);
	}
	if(currNode->num<newNum){
		currNode->right=insertNum(currNode->right, newNum);
	}
	else if(currNode->num>newNum){
		currNode->left=insertNum(currNode->left, newNum);
	}
	// Error ???

	updateTreeHeight();
	return currNode;
}
void BST::updateTreeHeight(){
	maxTreeHeight=tool->getHeight(root);
}
void BST::showCurrLevel(node *currNode, int levelIn){
	if(currNode==nullptr){
		return ;
	}
	if(levelIn==0){
		cout<<currNode->num<<" ("<<currNode->currHeight<<"), ";
	}
	else{
		showCurrLevel(currNode->left, levelIn-1);
		showCurrLevel(currNode->right, levelIn-1);
	}
}
void BST::showLevelorder(){
	for(int i=0;i<=maxTreeHeight;i++){
		showCurrLevel(root, i);
		cout<<endl;
	}
}
node *BST::findNum(node *currNode, int targetNum){
	if(currNode==nullptr){
		return nullptr;
	}
	if(currNode->num<targetNum){
		return findNum(currNode->right, targetNum);
	}
	else if(currNode->num>targetNum){
		return findNum(currNode->left, targetNum);
	}
	else if(currNode->num==targetNum){
		return currNode;
	}
	return nullptr;
}
node *BST::deleteNum(node *currNode, int targetNum){
	if(currNode==nullptr){
		return nullptr;
	}
	if(currNode->num<targetNum){
		currNode->right=deleteNum(currNode->right, targetNum);
	}
	else if(currNode->num>targetNum){
		currNode->left=deleteNum(currNode->left, targetNum);
	}
	else if(currNode->num==targetNum){
		if((currNode->left==nullptr)&&(currNode->right==nullptr)){
			return nullptr;
		}
		else if((currNode->left!=nullptr)&&(currNode->right!=nullptr)){
			// Change.
			int leftHeight=tool->getHeight(currNode->left);
			int rightHeight=tool->getHeight(currNode->right);
			node *tempNode;
			currNode->num=tempNode->num;
			if(tempNode==currNode->left){
				currNode->left=deleteNum(currNode->left, tempNode->num);
			}
			else{
				currNode->right=deleteNum(currNode->right, tempNode->num);
			}
		}
		else if(currNode->left==nullptr){
			return currNode->right;
		}
		else if(currNode->right==nullptr){
			return currNode->left;
		}
	}
	return currNode;
}
node *BST::findMaxLeftNum(node *currNode){
	if(currNode->left!=nullptr){
		currNode=currNode->left;
		while(currNode->right!=nullptr){
			currNode=currNode->right;
		}
		return currNode;
	}
	else{
		return nullptr;
	}
}
node *BST::findMinRightNum(node *currNode){
	if(currNode->right!=nullptr){
		currNode=currNode->right;
		while(currNode->left!=nullptr){
			currNode=currNode->left;
		}
		return currNode;
	}
	else{
		return nullptr;
	}
}
int BST::findHeightDifference(node *node1, node *node2){
	return abs(node1->currHeight-node2->currHeight);
}
void BST::showNodePath(node *currNode, int targetNum){
	if(currNode==nullptr){
		return ;
	}
	if(currNode->num<targetNum){
		cout<<"Go right"<<endl;
		showNodePath(currNode->right, targetNum);
	}
	else if(currNode->num>targetNum){
		cout<<"Go left"<<endl;
		showNodePath(currNode->left, targetNum);
	}
	else if(currNode->num==targetNum){
		cout<<"Found "<<currNode->num<<endl;
	}
}
void BST::isCurrNodeBalance(node *currNode){
	int lH=tool->getHeight(currNode->left);
	int rH=tool->getHeight(currNode->right);
	if(abs(lH-rH)>1){
		cout<<currNode->num<<" is not balance."<<endl;
	}
}
//------------------ functions

