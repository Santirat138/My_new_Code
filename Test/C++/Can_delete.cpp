#include<iostream>
using namespace std;
//------------------------- class node
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
			height=1;
		}
};
//------------------------- class toolBox
class toolsBox{
	public:
		int getHeight(node *nodeIn);
		node *findMinHeight(node *node1, node *node2);
};
int toolsBox::getHeight(node *nodeIn){
	if(nodeIn==nullptr){
		return 0;
	}
	else{
		return nodeIn->height;
	}
}
node *toolsBox::findMinHeight(node *node1, node *node2){
	int height1=getHeight(node1);
	int height2=getHeight(node2);
	if(height1>height2){
		return node1;
	}
	return node2;
}
//------------------------- class BST
class BST{
	public:
		toolsBox *tool;
		node *root;
		BST(){
			tool=new toolsBox();
			root=nullptr;
		}
		node *addNum(node *currNode, int newNum);
		node *deleteNum(node *currNode, int targetNum);
		node *findMaxLeft(node *currNode);
		node *findMinRight(node *currNode);
		void showPostorder(node *currNode);
};
node *BST::addNum(node *currNode, int newNum){
	if(currNode==nullptr){
		return new node(newNum);
	}
	if(currNode->num<newNum){
		currNode->left=addNum(currNode->left, newNum);
	}
	else if(currNode->num>newNum){
		currNode->right=addNum(currNode->right, newNum);
	}
	else{
		cout<<endl<<"	Reject "<<newNum<<endl;
	}
	return currNode;
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
	else{
		if((currNode->left==nullptr)&&(currNode->right==nullptr)){
			return nullptr;
		}
		else if((currNode->left!=nullptr)&&(currNode->right!=nullptr)){
			node *maxLeft=findMaxLeft(currNode);
			node *minRight=findMinRight(currNode);
			node *tempNode=tool->findMinHeight(maxLeft, minRight);
			currNode->num=tempNode->num;
			if(tempNode==currNode->left){
				currNode->left=deleteNum(currNode->left, tempNode->num);
			}
			else if(tempNode==currNode->right){
				currNode->right=deleteNum(currNode->right, tempNode->num);
			}
		}
	}
	return currNode;
}
node *BST::findMaxLeft(node *currNode){
	if(currNode->left!=nullptr){
		currNode=currNode->left;
		while(currNode->right!=nullptr){
			currNode=currNode->right;
		}
		return currNode;
	}
	return nullptr;
}
node *BST::findMinRight(node *currNode){
	if(currNode->right!=nullptr){
		currNode=currNode->right;
		while(currNode->left!=nullptr){
			currNode=currNode->left;
		}
		return currNode;
	}
	return nullptr;
}
void BST::showPostorder(node *currNode){
    if(currNode!=nullptr){
        showPostorder(currNode->left);
        showPostorder(currNode->right);
        cout<<currNode->num<<" ";
    }
    else{
        cout<<"NULL ";
    }
}
//------------------------- main
int main(){
	BST *bst=new BST();
	bst->root=bst->addNum(bst->root, 50);
	bst->root=bst->addNum(bst->root, 80);
	bst->root=bst->addNum(bst->root, 40);
	bst->root=bst->addNum(bst->root, 25);
	bst->root=bst->addNum(bst->root, 90);
	bst->root=bst->addNum(bst->root, 45);
	bst->root=bst->deleteNum(bst->root, 50);
	bst->showPostorder(bst->root);
}