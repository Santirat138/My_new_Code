#include<iostream>
using namespace std;
//-------------------- class node2
class node2{
    public:
        int num;
        node2 *left;
        node2 *right;
        node2(int numIn){
            num=numIn;
            left=nullptr;
            right=nullptr;
        }
};
//-------------------- class toolsBox
class toolsBox{
    public:
        int getHeight(node2 *nodeIn);
        node2 *findShortestSide(node2 *nodeIn);
};
int toolsBox::getHeight(node2 *nodeIn){
    if(nodeIn==nullptr){
        return 0;
    }
    int L_Height=getHeight(nodeIn->left);
    int R_Height=getHeight(nodeIn->left);
    return max(L_Height, R_Height)+1;
}
node2 *toolsBox::findShortestSide(node2 *nodeIn){
    if(nodeIn==nullptr){
        return nullptr;
    }
    if((nodeIn->left==nullptr)&&(nodeIn->right==nullptr)){
        return nullptr;
    }
    else if((nodeIn->left!=nullptr)&&(nodeIn->right!=nullptr)){
        int L_Height=getHeight(nodeIn->left);
        int R_Height=getHeight(nodeIn->right);
        if(L_Height<R_Height){
            return nodeIn->left;
        }
        return nodeIn->right;
    }
    else if(nodeIn->left==nullptr){
        return nodeIn->right;
    }
    else if(nodeIn->right==nullptr){
        return nodeIn->left;
    }
}
//-------------------- class BST
class BST{
    public:
        node2 *root;
        toolsBox *tool;
        BST(){
            root=nullptr;
            tool=new toolsBox();
        }
        node2 *addNum(node2 *currNode, int newNum);
        node2 *deleteNum(node2 *currNode, int targetNum);
        node2 *findMaxLeftNode(node2 *nodeIn);
        node2 *findMinRightNode(node2 *nodeIn);
        void showPostorder(node2 *currNode);
        void showPreorder(node2 *currNode);
        void showInorder(node2 *currNode);
        void showCurrLevel(node2 *currNode, int levelIn);
        void showLevelorder();
};
node2 *BST::addNum(node2 *currNode, int newNum){
    if(currNode==nullptr){
        return new node2(newNum);
    }
    if(currNode->num<newNum){
        currNode->right=addNum(currNode->right, newNum);
    }
    else if(currNode->num>newNum){
        currNode->left=addNum(currNode->left, newNum);
    }
    return currNode;
}
node2 *BST::deleteNum(node2 *currNode, int targetNum){
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
            node2 *tempNode=tool->findShortestSide(currNode);
            currNode->num=tempNode->num;
            if(tempNode==currNode->left){
                int maxLeftNum=findMaxLeftNode(currNode)->num;
                currNode->left=deleteNum(currNode->left, maxLeftNum);
            }
            else if(tempNode==currNode->right){
                int minRightNum=findMinRightNode(currNode)->num;
                currNode->right=deleteNum(currNode->right, minRightNum);
            }
        }
        else if(currNode->left==nullptr){
            currNode=currNode->right;
        }
        else if(currNode->right==nullptr){
            currNode=currNode->left;
        }
        return currNode;
    }
}
node2 *BST::findMaxLeftNode(node2 *nodeIn){
    if(nodeIn->left!=nullptr){
        nodeIn=nodeIn->left;
        while(nodeIn->right!=nullptr){
            nodeIn=nodeIn->right;
        }
        return nodeIn;
    }
    return nullptr;
}
node2 *BST::findMinRightNode(node2 *nodeIn){
    if(nodeIn->right!=nullptr){
        nodeIn=nodeIn->right;
        while(nodeIn->left!=nullptr){
            nodeIn=nodeIn->left;
        }
        return nodeIn;
    }
    return nullptr;
}
void BST::showPostorder(node2 *currNode){
	if(currNode!=nullptr){
		showPostorder(currNode->left);
		showPostorder(currNode->right);
		cout<<currNode->num<<" ";
	}
	return ;
}
void BST::showPreorder(node2 *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showPreorder(currNode->left);
        showPreorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void BST::showInorder(node2 *currNode){
    if(currNode!=NULL){
        showInorder(currNode->left);
        cout<<currNode->num<<" ";
        showInorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void BST::showCurrLevel(node2 *currNode, int levelIn){
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
    int treeHeight=tool->getHeight(root);
    for(int i=0;i<=treeHeight;i++){
        showCurrLevel(root, i);
    }
}
