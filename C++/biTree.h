#include<iostream>
using namespace std;
//---------------- node ----------------
class node{
    public:
        int num;
        node *right;
        node *left;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    right=NULL;
    left=NULL;
}
//---------------- Binary tree ----------------
class biTree{
    public:
        node *root;
        biTree();
        void insert(int newNum, node *rootNode);
        void showPreorder(node *node);
        void showInorder(node *root);
        void showPostorder(node *root);
};
biTree::biTree(){
    root=NULL;
}
void biTree::insert(int newNum, node *rootNode){
    if(root==NULL){
        root=new node(newNum);
    }
    else{
        if(newNum>rootNode->num){
            if(rootNode->right==NULL){
                rootNode->right=new node(newNum);
            }
            else{
                insert(newNum, rootNode->right);
            }
        }
        else if(newNum<rootNode->num){
            if(rootNode->left==NULL){
                rootNode->left=new node(newNum);
            }
            else{
                insert(newNum, rootNode->left);
            }
        }
    }
}
void biTree::showPreorder(node *node)
{
    if(node!=NULL){
        cout << node->num << " ";
        showPreorder(node->left);
        showPreorder(node->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
void biTree::showInorder(node *node){
    if(node!=NULL){
        showInorder(node->left);
        cout<<node->num<<" ";
        showInorder(node->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
void biTree::showPostorder(node *root){
    if(root!=NULL){
        showPostorder(root->left);
        showPostorder(root->right);
        cout<<root->num<<" ";
    }
    else{
        cout<<"End."<<endl;
    }
}