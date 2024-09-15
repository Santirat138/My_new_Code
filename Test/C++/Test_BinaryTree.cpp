#include<iostream>
#include<vector>
#define nullNum -1
using namespace std;
//----------------------------- class node
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
node *nullNode=new node(nullNum);
//----------------------------- class biTree
class biTree{
    public:
        node *root;
        biTree(){
            root=nullptr;
        }
        void insertNewNum(node *currNode, int newNum);
        void showPreorder(node *currNode);
        void showInorder(node *currNode);
        void showPostorder(node *nodeIn);
        void deleteNum(node *&currNode, int targetNum);
        node *findLargestLeftNum(node *currNode);
        node *findSmallestRightNum(node *currNode);
};
void biTree::insertNewNum(node *currNode, int newNum){
    if(root==nullptr){
        root=new node(newNum);
    }
    else{
        if(newNum<currNode->num){
            if(currNode->left==nullptr){
                currNode->left=new node(newNum);
            }
            else{
                insertNewNum(currNode->left, newNum);
            }
        }
        else if(newNum>currNode->num){
            if(currNode->right==nullptr){
                currNode->right=new node(newNum);
            }
            else{
                insertNewNum(currNode->right, newNum);
            }
        }
        else{
            cout<<"Error."<<endl;
        }
    }
}
void biTree::showPreorder(node *nodeIn){
    if(nodeIn!=NULL){
        cout<<nodeIn->num<<" ";
        showPreorder(nodeIn->left);
        showPreorder(nodeIn->right);
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::showInorder(node *nodeIn){
    if(nodeIn!=nullptr){
        showInorder(nodeIn->left);
        cout<<nodeIn->num<<" ";
        showInorder(nodeIn->right);
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::showPostorder(node *nodeIn){
    if(nodeIn!=nullptr){
        showPostorder(nodeIn->left);
        showPostorder(nodeIn->right);
        cout<<nodeIn->num<<" ";
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::deleteNum(node *&currNode, int targetNum) {
    if (currNode == nullptr) {
        return;
    }
    if (targetNum < currNode->num) {
        deleteNum(currNode->left, targetNum);
    } else if (targetNum > currNode->num) {
        deleteNum(currNode->right, targetNum);
    } else {
        if (currNode->left == nullptr) {
            node *temp = currNode->right;
            delete currNode;
            currNode = temp;
        } else if (currNode->right == nullptr) {
            node *temp = currNode->left;
            delete currNode;
            currNode = temp;
        } else {
            node *maxLeftNode = findLargestLeftNum(currNode);
            currNode->num = maxLeftNode->num;
            deleteNum(currNode->left, maxLeftNode->num);
        }
    }
}

node *biTree::findLargestLeftNum(node *currNode){
    if(currNode==nullptr){
        return nullNode;
    }
    else{
        currNode=currNode->left;
        while(currNode->right!=NULL){
            currNode=currNode->right;
        }
        return currNode;
    }
}
node *biTree::findSmallestRightNum(node *currNode){
    if(currNode==nullptr){
        return nullNode;
    }
    else{
        currNode=currNode->right;
        while(currNode->left!=nullptr){
            currNode=currNode->left;
        }
        return currNode;
    }
}
//----------------------------- main
int main(){
    biTree *tree=new biTree();
    vector<int> array({50, 40, 85, 15, 45, 60, 90, 5, 25, 42, 55, 75, 87, 95, 6, 20, 41, 43, 53, 70, 80, 88, 13, 65, 76, 77, 78});
    for(int i=0;i<array.size();i++){
        tree->insertNewNum(tree->root, array.at(i));
    }
    tree->showPreorder(tree->root);
    cout<<endl;
    tree->deleteNum(tree->root, 85);
    tree->showPreorder(tree->root);
}