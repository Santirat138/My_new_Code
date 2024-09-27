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
//------------------ class BST
class BST{
	public:
		node *root;
		int maxTreeHeight;
		BST(){
			root=nullptr;
			maxTreeHeight=0;
		}
		node *insertNum(node *currNode, int newNum);
		int findHeight(node *currNode);
		void updateTreeHeight();
		void showCurrLevel(node *currNode, int levelIn);
		void showLevelorder();
		node *findNum(node *currNode, int targetNum);
		int findHeightNum(int targetNum);
		
		node *deleteNum(node *currNode, int targetNum);

		node *findMaxLeftNum(node *currNode);
		node *findMinRightNum(node *currNode);
		node *findShortestNode(node *node1, node *node2);
};
node *BST::insertNum(node *currNode, int newNum){
	if(currNode==nullptr){
		currNode=new node(newNum);
		currNode->currHeight=1;
		updateTreeHeight();
		return currNode;
	}
	if(currNode->num<newNum){
		currNode->right=insertNum(currNode->right, newNum);
	}
	else if(currNode->num>newNum){
		currNode->left=insertNum(currNode->left, newNum);
	}
	currNode->currHeight=findHeight(currNode);
	updateTreeHeight();
	return currNode;
}
int BST::findHeight(node *currNode){
	if(currNode==nullptr){
		return 0;
	}
	int lHeight=findHeight(currNode->left);
	int rHeight=findHeight(currNode->right);
	return max(lHeight, rHeight)+1;
}
void BST::updateTreeHeight(){
	maxTreeHeight=findHeight(root);
}
void BST::showCurrLevel(node *currNode, int levelIn){
	if(currNode==nullptr){
		return ;
	}
	if(levelIn==0){
		cout<<currNode->num<<" ";
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
}
int BST::findHeightNum(int targetNum){
	if(root==nullptr){
		cout<<endl<<"Root is not exist."<<endl;
		return 0;
	}
	node *targetNode=findNum(root, targetNum);
	if(targetNode==nullptr){
		cout<<endl<<targetNum<<" is not exist."<<endl;
		return 0;
	}
	int currHeight=findHeight(targetNode);
	return currHeight;
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
			node *maxLNode=findMaxLeftNum(currNode);
			node *minRNode=findMinRightNum(currNode);
			
			node *tempNode=findShortestNode(maxLNode, minRNode);
			currNode->num=tempNode->num;
			if(tempNode==maxLNode){
				currNode->left=deleteNum(currNode->left, tempNode->num);
			}
			else if(tempNode==minRNode){
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
node *BST::findShortestNode(node *node1, node *node2){
	int heightNode1=findHeight(node1);
	int heightNode2=findHeight(node2);
	if(heightNode1<heightNode2){
		return node1;
	}
	else{
		return node2;
	}
}
