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
node2 *nullNode2=new node2(nullNum);
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
        void showPostorder(node2 *currNode);
        void deleteNumInTree(node2 *&currNode, int targetNum);
        node2 *findMaxLeft(node2 *currNode);
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
void biTree::showPostorder(node2 *currNode){
    if(currNode!=nullptr){
        showPostorder(currNode->left);
        showPostorder(currNode->right);
        cout<<currNode->num<<" ";
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::deleteNumInTree(node2 *&currNode, int targetNum){
    if(root==nullptr){
        return ;
    }
    else{
        if(currNode->num<targetNum){
            deleteNumInTree(currNode->right, targetNum);
        }
        else if(currNode->num>targetNum){
            deleteNumInTree(currNode->left, targetNum);
        }
        else{
            node2 *maxLeftNode=findMaxLeft(currNode);
            currNode->num=maxLeftNode->num;
            deleteNumInTree(currNode->left, maxLeftNode->num);
        }
    }
}
node2 *biTree::findMaxLeft(node2 *currNode){
    if(root==nullptr){
        return nullNode2;
    }
    else{
        currNode=currNode->left;
        for(node2 *currNode=root; currNode->right!=nullptr; currNode=currNode->right){}
        return currNode;
    }
}