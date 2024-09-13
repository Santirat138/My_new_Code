#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn);
};
class tree{
    public:
        node *root;
        node *nullNode;
        
        tree();
        void insertNum(int newNum, node *nodeIn);
        void preorder(node *nodeIn);
        void inorder(node *nodeIn);
        void postorder(node *nodeIn);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
}
tree::tree(){
    root=NULL;
    nullNode=new node(-1);
}
void tree::insertNum(int newNum, node *nodeIn){
    if(nodeIn==NULL){
        root=new node(newNum);
    }
    else{
        if(newNum<nodeIn->num){
            if(nodeIn->left==NULL){
                nodeIn->left=new node(newNum);
            }
            else if(nodeIn->left!=NULL){
                insertNum(newNum, nodeIn->left);
            }
        }
        else if(newNum>nodeIn->num){
            if(nodeIn->right==NULL){
                nodeIn->right=new node(newNum);
            }
            else if(nodeIn->right!=NULL){
                insertNum(newNum, nodeIn->right);
            }
        }
    }
}
void tree::preorder(node *nodeIn){
    if(nodeIn!=NULL){
        cout<<nodeIn->num<<" ";
        preorder(nodeIn->left);
        preorder(nodeIn->right);
    }
    else{
        cout<<"NULL ";
    }
}
void tree::inorder(node *nodeIn){
    if(nodeIn!=NULL){
        inorder(nodeIn->left);
        cout<<nodeIn->num<<" ";
        inorder(nodeIn->right);
    }
    else{
        cout<<"NULL ";
    }
}
void tree::postorder(node *nodeIn){
    if(nodeIn!=NULL){
        postorder(nodeIn->left);
        postorder(nodeIn->right);
        cout<<nodeIn->num<<" ";
    }
    else{
        cout<<"NULL ";
    }
}
int main(){
    tree *t1=new tree();
    t1->insertNum(50, t1->root);
    t1->insertNum(500, t1->root);
    t1->insertNum(6, t1->root);
    t1->insertNum(2, t1->root);
    t1->insertNum(15, t1->root);
    t1->insertNum(25, t1->root);
    t1->insertNum(58, t1->root);
    t1->insertNum(13, t1->root);
    t1->insertNum(44, t1->root);
    t1->insertNum(79, t1->root);
    t1->insertNum(51, t1->root);
    t1->insertNum(4, t1->root);
    t1->insertNum(9, t1->root);
    t1->insertNum(80, t1->root);
    t1->preorder(t1->root);
}