#include<iostream>
#define nullNum -1
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
//-------------------- class BST
class BST{
    public:
        node *root;
        BST(){
            root=nullptr;
        }
        void insertNum(node *currNode, int newNum);
        void showPreorder(node *currNode);  // root ->left ->right
        void showInorder(node *currNode);   // left -> root ->right
        void showPostorder(node *currNode); // left -> right ->root
        node *deleteKey(node *currNode, int key);
        node *findMinRightNum(node *currNode);
        void showCurrLevel(node *currNode, int currLevel);
        void showLevelorder();
        int findTreeHeight(node *currNode);
};
void BST::insertNum(node *currNode, int newNum){
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
void BST::showPreorder(node *currNode){
    if(currNode==nullptr){
        return ;
    }
    cout<<currNode->num<<",";
    showPreorder(currNode->left);
    showPreorder(currNode->right);
}
void BST::showInorder(node *currNode){
    if(currNode==nullptr){
        return ;
    }
    showInorder(currNode->left);
    cout<<currNode->num<<",";
    showInorder(currNode->right);
}
void BST::showPostorder(node *currNode){
    if(currNode==nullptr){
        return ;
    }
    showPostorder(currNode->left);
    showPostorder(currNode->right);
    cout<<currNode->num<<",";
}
node *BST::deleteKey(node *currNode, int key){
    if(currNode==nullptr){
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
            node* minRightNode=findMinRightNum(currNode);
            currNode->num=minRightNode->num;
            currNode->right=deleteKey(currNode->right, minRightNode->num);
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
node *BST::findMinRightNum(node *currNode){
    if(currNode==nullptr){
        return nullptr;
    }
    if(currNode->right!=nullptr){
        currNode=currNode->right;
        while(currNode->left!=nullptr){
            currNode=currNode->left;
        }
        return currNode;
    }
    else{
        return nullptr;
    }
}
void BST::showCurrLevel(node *currNode, int currLevel){
    if(currNode==nullptr){
        return ;
    }
    if(currLevel==0){
        cout<<currNode->num<<",";
    }
    else{
        showCurrLevel(currNode->left, currLevel-1);
        showCurrLevel(currNode->right, currLevel-1);
    }
}
void BST::showLevelorder(){
    int treeHeight=findTreeHeight(root);
    for(int i=0;i<=treeHeight;i++){
        showCurrLevel(root, i);
        cout<<"|";
    }
}
int BST::findTreeHeight(node *currNode){
    if(currNode==nullptr){
        return nullNum;
    }
    else{
        int leftHeight=findTreeHeight(currNode->left);
        int rightHeight=findTreeHeight(currNode->right);
        return max(leftHeight, rightHeight)+1;
    }
}
//-------------------- functions
void mainFunc();
//-------------------- main
int main(){
    mainFunc();
}
//-------------------- functions
void mainFunc(){
    BST *bst=new BST();
    char chIn;
    int numIn;
    do{
        cin>>chIn;
        if(chIn=='a'){
            cin>>numIn;
            bst->insertNum(bst->root, numIn);
        }
        else if(chIn=='d'){
            cin>>numIn;
            bst->root=bst->deleteKey(bst->root, numIn);
        }
        else if(chIn=='b'){
            bst->showLevelorder();
            cout<<endl;
        }
        else if(chIn=='i'){
            bst->showInorder(bst->root);
            cout<<endl;
        }
        else if(chIn=='p'){
            bst->showPreorder(bst->root);
            cout<<endl;
        }
        else if(chIn=='t'){
            bst->showPostorder(bst->root);
            cout<<endl;
        }
    }
    while(chIn!='x');
}