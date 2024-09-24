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
        node *deleteKey(node *currNode, int key);
        node *findNum(node *currNode, int key);
        node *findLargestLeftNum(node *currNode);
        int findHeight(node *currNode);
        void showCurrLevel(node *currNode, int levelIn);
        void showLevelorder();
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
node *biTree::deleteKey(node *currNode, int key){
    if(currNode==nullptr){
        cout<<"Can't delete."<<endl;
        return currNode;
    }
    if(currNode->num>key){
        currNode->left=deleteKey(currNode->left, key);
        return currNode;
    }
    else if(currNode->num<key){
        currNode->right=deleteKey(currNode->right, key);
        return currNode;
    }
    else{
        if((currNode->left==nullptr)&&(currNode->right==nullptr)){
            return nullptr;
        }
        if((currNode->left!=nullptr)&&(currNode->right!=nullptr)){
            int maxLeftNum=findLargestLeftNum(currNode)->num;
            currNode->num=maxLeftNum;
            currNode->left=deleteKey(currNode->left, maxLeftNum);
            return currNode;
        }
        if(currNode->left!=nullptr){
            return currNode->left;
        }
        if(currNode->right!=nullptr){
            return currNode->right;
        }
    }
}
node *biTree::findNum(node *currNode, int key){
    if(currNode==nullptr){
        return nullptr;
    }
    if(currNode->num>key){
        return findNum(currNode->left, key);
    }
    return findNum(currNode->right, key);
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
int biTree::findHeight(node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return max(leftHeight, rightHeight)+1;
    }
}
void biTree::showCurrLevel(node *currNode, int levelIn){
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
void biTree::showLevelorder(){
    int treeHeight=findHeight(root);
    for(int i=0;i<=treeHeight;i++){
        showCurrLevel(root, i);
        cout<<endl;
    }
}
//----------------------------- main
int main(){
    biTree *tree=new biTree();
    vector<int> array({1, 10, 5, 13, 3, 8, 50, 9, 25, 70, 20, 35, 85});
    for(int i=0;i<array.size();i++){
        tree->insertNewNum(tree->root, array.at(i));
    }
    tree->root=tree->deleteKey(tree->root, 10);
    tree->showLevelorder();
}