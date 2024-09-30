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
node *nullNode=new node(nullNum);
//-------------------- class BST
class BST{
    public:
        node *root;
        BST(){
            root=nullptr;
        }
        node *insertNum(node *currNode, int newNum);
        void showPreorder(node *currNode); // root -> left -> right
        void showPostorder(node *currNode); // left -> right -> root
        void showInorder(node *currNode); // left -> root -> right
        node *deleteNum(node *currNode, int targetNum);
        node *findMaxLeftNum(node *currNode);
        node *findMinRightNum(node *currNode);
        
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
void BST::showInorder(node *currNode){
    if(currNode==nullptr){
        return ;
    }
    showInorder(currNode->left);
    cout<<currNode->num<<" ";
    showInorder(currNode->right);
}
node *BST::deleteNum(node *currNode, int targetNum){
    if(currNode==nullptr){
        return nullptr;
    }
    if(currNode->num<targetNum){
        currNode->right=deleteNum(currNode->right, targetNum);
    }
    else if(currNode->num>targetNum){
        currNode->left=deleteNum(currNode->left, targetNum);
    }
    else if(currNode->num==targetNum){
        if((currNode->left==nullptr)&&(currNode->right==nullptr)){
            return nullptr;
        }
        else if((currNode->left!=nullptr)&&(currNode->right!=nullptr)){
            node *maxLeftNode=findMaxLeftNum(currNode);
            currNode->num=maxLeftNode->num;
            currNode->left=deleteNum(currNode->left, maxLeftNode->num);
        }
        else if(currNode->left==nullptr){
            currNode=currNode->right;
        }
        else if(currNode->right==nullptr){
            currNode=currNode->left;
        }
    }
    return currNode;
}
node *BST::findMaxLeftNum(node *currNode){
    if(currNode==nullptr){
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
    return nullptr;
}
//-------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->insertNum(bst->root, 10);
    bst->root=bst->insertNum(bst->root, 7);
    bst->root=bst->insertNum(bst->root, 2);
    bst->root=bst->insertNum(bst->root, 9);
    bst->root=bst->insertNum(bst->root, 13);
    bst->root=bst->insertNum(bst->root, 11);
    bst->root=bst->insertNum(bst->root, 20);
    bst->root=bst->deleteNum(bst->root, 10);
    bst->showInorder(bst->root);
}