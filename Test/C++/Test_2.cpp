// Test delete BST.
#include<iostream>
using namespace std;
//---------------------- class node
class node{
    public:
        int num;
        node *left;
        node *right;
        int height;
        node(int numIn){
            num=numIn;
            left=nullptr;
            right=nullptr;
            height=1;
        }
};
//---------------------- class toolsBox
class toolsBox{
    public:
        int getNodeHeight(node *nodeIn){
            if(nodeIn==nullptr){
                return 0;
            }
            return nodeIn->height;
        }
};
//---------------------- class BST
class BST{
    public:
        node *root;
        toolsBox *tool;
        BST(){
            root=nullptr;
            tool=new toolsBox();
        }
        node *insertNum(node *currNode, int newNum){
            if(currNode==nullptr){
                currNode=new node(newNum);
            }
            if(currNode->num<newNum){
                currNode->right=insertNum(currNode->right, newNum);
            }
            else if(currNode->num>newNum){
                currNode->right=insertNum(currNode->right, newNum);
            }
            return currNode;
        }
        void showPostorder(node *currNode){
            if(currNode!=nullptr){
                showPostorder(currNode->left);
                showPostorder(currNode->right);
                cout<<currNode->num<<" ";
            }
            else{
                cout<<"NULL ";
            }
        }
        node *deleteNum(node *currNode, int targetNum){
            if(currNode==nullptr){
                return nullptr;
            }
            if(currNode->num<targetNum){
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
                    // Find the shortest height side of currNode.
                    int leftHeight=tool->getNodeHeight(currNode->left);
                    int rightHeight=tool->getNodeHeight(currNode->right);
                    node *temp;
                    if(leftHeight<rightHeight){
                        temp=getMaxLeftNode(currNode);
                        currNode->num=temp->num;
                        currNode->left=deleteNum(currNode->left, temp->num);
                    }
                    else{
                        temp=getMinRightNode(currNode);
                        currNode->num=temp->num;
                        currNode->right=deleteNum(currNode->right, temp->num);
                    }
                    
                }
                else if(currNode->left==nullptr){
                    return currNode->right;
                }
                else if(currNode->right==nullptr){
                    return currNode->left;
                }
            }
        }
        node *getMaxLeftNode(node *currNode){
            if(currNode->left!=nullptr){
                currNode=currNode->left;
                while(currNode->right!=nullptr){
                    currNode=currNode->right;
                }
            }
            return currNode;
        }
        node *getMinRightNode(node *currNode){
            if(currNode->right!=nullptr){
                currNode=currNode->right;
                while(currNode->left!=nullptr){
                    currNode=currNode->left;
                }
            }
            return currNode;
        }
};
//---------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->insertNum(bst->root, 50);
    bst->root=bst->insertNum(bst->root, 40);
    bst->root=bst->insertNum(bst->root, 30);
    bst->root=bst->insertNum(bst->root, 45);
    bst->root=bst->insertNum(bst->root, 70);
    bst->root=bst->deleteNum(bst->root, 50);
    bst->showPostorder(bst->root);
}