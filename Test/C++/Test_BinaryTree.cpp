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
        node *deleteKey(node *currNode, int key);
        node *findNum(node *currNode, int key);
        node *findLargestLeftNum(node *currNode);
        node *findSmallestRightNum(node *currNode);
        int findHeight(node *currNode);
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
    }
    else if (targetNum > currNode->num) {
        deleteNum(currNode->right, targetNum);
    }
    else {
        if (currNode->left == nullptr) {
            node *temp = currNode->right;
            currNode = temp;
        }
        else if (currNode->right == nullptr) {
            node *temp = currNode->left;
            currNode = temp;
        }
        else {
            node *maxLeftNode = findLargestLeftNum(currNode);
            currNode->num = maxLeftNode->num;
            deleteNum(currNode->left, maxLeftNode->num);
        }
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
int biTree::findHeight(node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else {
            return rightHeight + 1;
        }
    }
}

//----------------------------- main
int main(){
    biTree *tree=new biTree();
    /* vector<int> array({10, 5, 20, 3, 7, 15, 25});
    for(int i=0;i<array.size();i++){
        tree->insertNewNum(tree->root, array.at(i));
    }
    tree->showPreorder(tree->root);
    cout<<endl;
    tree->deleteNum(tree->root, 85);
    tree->deleteNum(tree->root, 13);
    tree->showPreorder(tree->root);
    cout<<endl<<endl<<tree->findHeight(tree->root); */
    tree->insertNewNum(tree->root, 50);

}