// Test int getLevel().
#include<iostream>
using namespace std;
//------------------------ class node
class node{
    public:
        int num;
        int height;
        node *left;
        node *right;
        node(int numIn){
            num=numIn;
            height=1;
            left=NULL;
            right=NULL;
        }
};
//------------------------ class toolsBox
class toolsBox{
    public:
        int getNodeHeight(node *nodeIn){
            if(nodeIn==NULL){
                return 0;
            }
            return nodeIn->height;
        }
        int countHeight(node *nodeIn){
            if(nodeIn==NULL){
                return 0;
            }
            int L_Height=countHeight(nodeIn->left);
            int R_Height=countHeight(nodeIn->right);
            return max(L_Height, R_Height)+1;
        }
};
//------------------------ class BST
class BST{
    public:
        node *root;
        BST(){
            root=NULL;
        }
        node *addNum(node *currNode, int newNum){
            if(currNode==nullptr){
                return new node(newNum);
            }
            if(currNode->num<newNum){
                currNode->right=addNum(currNode->right, newNum);
            }
            else if(currNode->num>newNum){
                currNode->left=addNum(currNode->left, newNum);
            }
            return currNode;
        }
        void BST::showPostorder(node *currNode){
            if(currNode==nullptr){
                return ;
            }
            showPostorder(currNode->left);
            showPostorder(currNode->right);
        }
        
};
//------------------------ main
int main(){

}