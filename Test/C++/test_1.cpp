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
        node *deleteNum(node *currNode, int targetNum);
        node *findMaxLeftNode(node *currNode);
        int findHeightNode(node *currNode);
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
    bst->showPostorder(bst->root);
    bst->root=bst->deleteNum(bst->root, 60);
    cout<<endl;
    bst->showPostorder(bst->root);
}