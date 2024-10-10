#include<iostream>
using namespace std;
//--------------------- class node
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
//--------------------- class toolsBox
class toolsBox{
	public:
		int countHeight(node *currNode);
		void showPostorder(node *currNode);
		void showInorder(node *currNode);
		void showPreorder(node *currNode);
		void showCurrLevel(node *currNode, int levelIn);
		void showLevelorder(node *root);
};
int toolsBox::countHeight(node *currNode){
	if(currNode==nullptr){
		return 0;
	}
	int L_Height=countHeight(currNode->left);
	int R_Height=countHeight(currNode->right);
	return max(L_Height, R_Height)+1;
}
void toolsBox::showPostorder(node *currNode){
    if(currNode!=nullptr){
        showPostorder(currNode->left);
        showPostorder(currNode->right);
        cout<<currNode->num<<" ";
    }
    else{
        return ;
    }
}
void toolsBox::showInorder(node *currNode){
	if(currNode!=nullptr){
		showInorder(currNode->left);
		cout<<currNode->num<<" ";
		showInorder(currNode->right);
	}
	else{
		return ;
	}
}
void toolsBox::showPreorder(node *currNode){
	if(currNode!=nullptr){
		cout<<currNode->num<<" ";
		showPreorder(currNode->left);
		showPreorder(currNode->right);
	}
	else{
		return ;
	}
}
void toolsBox::showCurrLevel(node *currNode, int levelIn){
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
void toolsBox::showLevelorder(node *root){
	int treeHeight=countHeight(root);
	for(int i=0;i<=treeHeight;i++){
		showCurrLevel(root, i);
	}
}
//--------------------- class BST
class BST{
	public:
		node *root;
		toolsBox *tool;
		BST(){
			root=nullptr;
			tool=new toolsBox();
		}
		node *addNum(node *currNode, int newNum);
        node *deleteNum(node *currNode, int targetNum);
		node *findMaxLeftNode(node *currNode);
		node *findMinRightNode(node *currNode);
		node *findShortestSide(node *nodeIn);
};
node *BST::addNum(node *currNode, int newNum){
	if(currNode==nullptr){
		currNode=new node(newNum);
	}
	if(currNode->num<newNum){
		currNode->right=addNum(currNode->right, newNum);
	}
	else if(currNode->num>newNum){
		currNode->left=addNum(currNode->left, newNum);
	}
	return currNode;
}
node *BST::deleteNum(node *currNode, int targetNum){
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
			node *tempNode=findShortestSide(currNode);
			currNode->num=tempNode->num;
			if(tempNode==currNode->left){
				currNode->left=deleteNum(currNode->left, tempNode->num);
			}
			else if(tempNode==currNode->right){
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
node *BST::findMaxLeftNode(node *currNode){
	if(currNode->left!=nullptr){
		currNode=currNode->left;
		while(currNode->right!=nullptr){
			currNode=currNode->right;
		}
	}
	return currNode;
}
node *BST::findMinRightNode(node *currNode){
	if(currNode->right!=nullptr){
		currNode=currNode->right;
		while(currNode->left!=nullptr){
			currNode=currNode->left;
		}
	}
	return currNode;
}

node *BST::findShortestSide(node *nodeIn){
	if((nodeIn->left==nullptr)&&(nodeIn->right==nullptr)){
		return nullptr;
	}
	else if((nodeIn->left!=nullptr)&&(nodeIn->right!=nullptr)){
		int L_Height=tool->countHeight(nodeIn->left);
		int R_Height=tool->countHeight(nodeIn->right);
			if(L_Height<R_Height){
			return nodeIn->left;
		}
		else{
			return nodeIn->right;
		}
	}
	else if(nodeIn->left==nullptr){
		return nodeIn->right;
	}
	else if(nodeIn->right==nullptr){
		return nodeIn->left;
	}

}
//--------------------- main
int main(){
	BST *bst=new BST();
	bst->root=bst->addNum(bst->root, 40);
	bst->root=bst->addNum(bst->root, 15);
	bst->root=bst->addNum(bst->root, 45);
	bst->root=bst->addNum(bst->root, 5);
	bst->root=bst->addNum(bst->root, 25);
	bst->root=bst->addNum(bst->root, 42);
	bst->root=bst->addNum(bst->root, 6);
	bst->root=bst->addNum(bst->root, 20);
	bst->root=bst->addNum(bst->root, 41);
	bst->root=bst->addNum(bst->root, 43);
	bst->root=bst->addNum(bst->root, 15);
	bst->tool->showLevelorder(bst->root);
	cout<<endl;
	bst->root=bst->deleteNum(bst->root, 6);
	bst->tool->showLevelorder(bst->root);
}