#include<iostream>
using namespace std;
//************ node ************
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
}
//************ tree ************
class tree{
    public:
        node *root;
        tree();
        void insertNum(int newNum);
        void preorder(node *currNode);
};
tree::tree(){
    root=NULL;
}
void tree::insertNum(int newNum){
    if(root==NULL){
        root=new node(newNum);
    }
    else{
        node *currNode=root;
        node *newNode=new node(newNum);
        while(1){
            if(currNode!=NULL){
                if(newNum<currNode->num){
                    if(currNode->left!=NULL){
                        currNode=currNode->left;
                    }
                    else{
                        currNode->left=newNode;
                        break;
                    }
                }
                else if(newNum>currNode->num){
                    if(currNode->right!=NULL){
                        currNode=currNode->right;
                    }
                    else{
                        currNode->right=newNode;
                        break;
                    }
                }
                else if(newNum==currNode->num){
                    cout<<"Can't insert "<<newNum<<" ."<<endl;
                    break;
                }
            }
            else{
                root=new node(newNum);
                break;
            }
        }
    }
}
void tree::preorder(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        preorder(currNode->left);
        preorder(currNode->right);
    }
    else{
        cout<<"End. ";
    }
}
//************ main ************
int main(){
    tree *t1=new tree();
    t1->insertNum(50);
    t1->insertNum(20);
    t1->insertNum(60);
    t1->insertNum(10);
    t1->insertNum(30);
    t1->insertNum(3);
    t1->insertNum(2);
    t1->insertNum(5);
    t1->preorder(t1->root);
}
//************ function ************
