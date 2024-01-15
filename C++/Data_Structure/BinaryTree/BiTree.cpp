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
        cout<<"End. ";
    }
}
void tree::inorder(node *nodeIn){
    if(nodeIn!=NULL){
        inorder(nodeIn->left);
        cout<<nodeIn->num<<" ";
        inorder(nodeIn->right);
    }
    else{
        cout<<"End. ";
    }
}
void tree::postorder(node *nodeIn){
    if(nodeIn!=NULL){
        postorder(nodeIn->left);
        postorder(nodeIn->right);
        cout<<nodeIn->num<<" ";
    }
    else{
        cout<<"End. ";
    }
}
int main(){
    tree *t1=new tree();
    t1->insertNum(5, t1->root);
    t1->insertNum(3, t1->root);
    t1->insertNum(7, t1->root);
    t1->insertNum(2, t1->root);
    t1->insertNum(4, t1->root);
    t1->insertNum(8, t1->root);
    t1->postorder(t1->root);
}