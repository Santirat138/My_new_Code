#include<iostream>
using namespace std;

//--------------------- class node
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
//--------------------- class toolsBox
class toolsBox{
    public:
        int getHeight(node *targetNode);
        int countHeight(node *targetNode);
};
int toolsBox::getHeight(node *targetNode){
    if(targetNode==nullptr){
        return 0;
    }
    return targetNode->height;
}
int toolsBox::countHeight(node *targetNode){
    if(targetNode==nullptr){
        return 0;
    }
    int leftHeight=countHeight(targetNode->left);
    int rightHeight=countHeight(targetNode->right);
    return max(leftHeight, rightHeight)+1;
}
//--------------------- class BST
class BST{
    public:
        toolsBox *tool=new toolsBox();
        node *root;
        BST(){
            root=nullptr;
        }
        node *addNum(node *currNode, int newNum);
        void showInorder(node *currNode);
        void showPreorder(node *currNode);
        void showPostorder(node *currNode);
        void showCurrLevel(node *currNode, int levelIn);
        void showLevelorder();
        node *deleteNum(node *currNode, int targetNum);
        node *getMaxLeftNode(node *currNode);

};
node *BST::addNum(node *currNode, int newNum){
    if(currNode==nullptr){
        return new node(newNum);
    }
    if(currNode->num<newNum){
        currNode->right=addNum(currNode->right, newNum);
    }
    else if(currNode->num>newNum){
        currNode->left=addNum(currNode->left, newNum);
    }
    currNode->height=tool->countHeight(currNode);
    return currNode;
}
void BST::showInorder(node *currNode){
    if(currNode==nullptr){
        return ;
    }
    showInorder(currNode->left);
    cout<<currNode->num<<" ";
    showInorder(currNode->right);
}
void BST::showPreorder(node *currNode){
    if(currNode==nullptr){
        return ;
    }
    cout<<currNode->num<<" ";
    showPreorder(currNode->left);
    showPreorder(currNode->right);
}
void BST::showPostorder(node *currNode){
    if(currNode==nullptr){
        return ;
    }
    showPostorder(currNode->left);
    showPostorder(currNode->right);
    cout<<currNode->num<<" ";
}
void BST::showCurrLevel(node *currNode, int levelIn){
    if(currNode==nullptr){
        return ;
    }
    if(levelIn==0){
        cout<<currNode->num<<" ";
    }
    showCurrLevel(currNode->left, levelIn-1);
    showCurrLevel(currNode->right, levelIn-1);
}
void BST::showLevelorder(){
    int treeHeight=tool->countHeight(root);
    for(int i=0;i<=treeHeight;i++){
        showCurrLevel(root, i);
    }
}
node *BST::deleteNum(node *currNode, int targetNum){
    if(currNode==nullptr){
        return currNode;
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
            node *temp=getMaxLeftNode(currNode);
            currNode->num=temp->num;
            currNode->left=deleteNum(currNode->left, temp->num);
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
node *BST::getMaxLeftNode(node *currNode){
    if(currNode=nullptr){
        return nullptr;
    }
    if(currNode->left!=nullptr){
        currNode=currNode->left;
        while(currNode->right!=nullptr){
            currNode=currNode->right;
        }
        return currNode;
    }
    return nullptr;
}
//--------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->addNum(bst->root, 50);
    bst->root=bst->addNum(bst->root, 25);
    bst->root=bst->addNum(bst->root, 28);
    bst->root=bst->addNum(bst->root, 60);
    bst->showLevelorder();
}