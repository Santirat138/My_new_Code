#include<iostream>
using namespace std;

//-------------------- class node
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
//-------------------- class bst
class bst{
    public:
        node *root;
        bst(){
            root=nullptr;
        }
        void insertNum(node *currNode, int newNum);
        void showPreorder(node *currNode);
        void showInorder(node *currNode);
        void showPostorder(node *nodeIn);
        node *deleteNum(node *currNode, int targetNum);
        node *findMaxLeftNode(node *currNode);
        int findMaxHeight(node *currNode);
        void showCurrLevel(node *currNode, int levelIn);
        void showLevelorder();
};
void bst::insertNum(node *currNode, int newNum){
    if(root==nullptr){
        root=new node(newNum);
    }
    else{
        if(currNode->num<newNum){
            if(currNode->right!=nullptr){
                insertNum(currNode->right, newNum);
            }
            else{
                currNode->right=new node(newNum);
            }
        }
        else if(currNode->num>newNum){
            if(currNode->left!=nullptr){
                insertNum(currNode->left, newNum);
            }
            else{
                currNode->left=new node(newNum);
            }
        }
    }
}
void bst::showPreorder(node *currNode){
    // Root Left Right
    if(currNode!=nullptr){
        cout<<currNode->num<<" ";
        showPreorder(currNode->left);
        showPreorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void bst::showInorder(node *currNode){
    // Left Root Right
    if(currNode!=nullptr){
        showInorder(currNode->left);
        cout<<currNode->num<<" ";
        showInorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void bst::showPostorder(node *currNode){
    // Left Right Root
    if(currNode!=nullptr){
        showPostorder(currNode->left);
        showPostorder(currNode->right);
        cout<<currNode->num<<" ";
    }
    else{
        cout<<"NULL ";
    }
}
node *bst::deleteNum(node *currNode, int targetNum){
    if(currNode==nullptr){
        return nullptr;
    }
    if(currNode->num<targetNum){
        currNode->left=deleteNum(currNode->left, targetNum);
    }
    else if(currNode->num>targetNum){
        currNode->right=deleteNum(currNode->right, targetNum);
    }
    if(currNode->num==targetNum){
        if((currNode->left==nullptr)&&(currNode->right==nullptr)){
            return nullptr;
        }
        else if(currNode->left==nullptr){
            return currNode->right;
        }
        else if(currNode->right==nullptr){
            return currNode->left;
        }
        else{
            node *maxLNode=findMaxLeftNode(currNode);
            currNode->num=maxLNode->num;
            deleteNum(currNode->left, maxLNode->num);
        }
    }
}
node *bst::findMaxLeftNode(node *currNode){
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
int bst::findMaxHeight(node *currNode){
    if(currNode==nullptr){
        return -1;
    }
    else{
        int lHeight=findMaxHeight(currNode->left);
        int rHeight=findMaxHeight(currNode->right);
        return max(lHeight, rHeight)+1;
    }
}
void bst::showCurrLevel(node *currNode, int levelIn){
    if(currNode==nullptr){
        return ;
    }
    if(levelIn==0){
        cout<<currNode->num<<" ";
    }
    else if(levelIn>0){
        showCurrLevel(currNode->left, levelIn-1);
        showCurrLevel(currNode->right, levelIn-1);
    }
}
void bst::showLevelorder(){
    int maxHeight=findMaxHeight(root);
    for(int i=0;i<=maxHeight;i++){
        showCurrLevel(root, i);
        cout<<endl;
    }
}