#include<iostream>
#define nullNum -1
using namespace std;

//---------------------- class biNode
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

//---------------------- class tree
class biTree{
    public:
        node2 *root;
        biTree(){
            root=nullptr;
        }
        void insertNumInTree(node2 *currNode, int newNum);
        void showPreorder(node2 *currNode);
        void showInorder(node2 *currNode);
};
void biTree::insertNumInTree(node2 *currNode, int newNum){
    if(root==nullptr){
        root=new node2(newNum);
    }
    else{
        if(newNum>currNode->num){
            if(currNode->right!=nullptr){
                insertNumInTree(currNode->right, newNum);
            }
            else{
                currNode->right=new node2(newNum);
            }
        }
        else if(newNum<currNode->num){
            if(currNode->left!=nullptr){
                insertNumInTree(currNode->left, newNum);
            }
            else{
                currNode->left=new node2(newNum);
            }
        }
    }
}
void biTree::showPreorder(node2 *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showPreorder(currNode->left);
        showPreorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::showInorder(node2 *currNode){
    if(currNode!=NULL){
        showInorder(currNode->left);
        cout<<currNode->num<<" ";
        showInorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}