#include<iostream>
using namespace std;
//------------------ class node
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn){
            num=numIn;
            left=NULL;
            right=NULL;
        }
};
//------------------ class BST
class BST{
    public:
        node *root=NULL;
        node *insertNum(node *curr, int newNum){
            if(curr==NULL){
                return new node(newNum);
            }
            if(curr->num<newNum){
                curr->right=insertNum(curr->right, newNum);
            }
            else if(curr->num>newNum){
                curr->left
            }
        }
};
//------------------ main
int main(){

}