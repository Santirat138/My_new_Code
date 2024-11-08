// Test BST.
#include<iostream>
using namespace std;
//--------------------------- class node
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
//--------------------------- class BST
class BST{
    public:
        node *root;
        BST(){
            root=nullptr;
        }
        node *insertNum(node *currNode, int newNum);
        void showPostorder(node *currNode);
        void showPreorder(node *currNode);
        void showInorder(node *currNode);
        node *deleteNum(node *currNode, int targetNum);
        node *findMaxLeftNode(node *currNode);
        int findHeightNode(node *currNode);
        void isBalance(node *currNode);
};
node *BST::insertNum(node *currNode, int newNum){
    if(currNode==nullptr){
        return new node(newNum);
    }
    if(currNode->num<newNum){
        currNode->right=insertNum(currNode->right, newNum);
    }
    else if(currNode->num>newNum){
        currNode->left=insertNum(currNode->left, newNum);
    }
    return currNode;
}
void BST::showPostorder(node *currNode){
    // Left --> Right --> Root
    if(currNode!=nullptr){
        showPostorder(currNode->left);
        showPostorder(currNode->right);
        cout<<currNode->num<<" ";
    }
}
void BST::showPreorder(node *currNode){
    // Root --> Left --> Right
    if(currNode!=nullptr){
        cout<<currNode->num<<" ";
        showPreorder(currNode->left);
        showPreorder(currNode->right);
    }
}
void BST::showInorder(node *currNode){
    // Left --> Root --> Right
    if(currNode!=nullptr){
        showInorder(currNode->left);
        cout<<currNode->num<<" ";
        showInorder(currNode->right);
    }
}
node *BST::deleteNum(node *currNode, int targetNum){
    if(currNode==nullptr){
        return nullptr;
    }
    else if(currNode->num<targetNum){
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
            node *maxLeftNode=findMaxLeftNode(currNode);
            currNode->num=maxLeftNode->num;
            currNode->left=deleteNum(currNode->left, maxLeftNode->num);
        }
        else if(currNode->right==nullptr){
            currNode=currNode->left;
        }
        else if(currNode->left==nullptr){
            currNode=currNode->right;
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
int BST::findHeightNode(node *currNode){
    // Left --> Right --> Root
    if(currNode==nullptr){
        return 0;
    }
    int L_Height=findHeightNode(currNode->left);
    int R_Height=findHeightNode(currNode->right);
    return max(L_Height, R_Height)+1;
}
void BST::isBalance(node *currNode){
    
}
//--------------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->insertNum(bst->root, 50);
    bst->root=bst->insertNum(bst->root, 30);
    bst->root=bst->insertNum(bst->root, 20);
    bst->root=bst->insertNum(bst->root, 40);
    bst->root=bst->insertNum(bst->root, 60);
    bst->root=bst->insertNum(bst->root, 55);
    bst->root=bst->insertNum(bst->root, 75);
    bst->root=bst->insertNum(bst->root, 65);
    bst->root=bst->insertNum(bst->root, 80);
    bst->root=bst->insertNum(bst->root, 52);
    bst->root=bst->insertNum(bst->root, 51);
    bst->root=bst->insertNum(bst->root, 54);
    bst->showPostorder(bst->root);
    cout<<endl;
    cout<<bst->findHeightNode(bst->root);
}