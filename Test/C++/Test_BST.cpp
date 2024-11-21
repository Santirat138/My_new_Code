// Test BST.
#include<iostream>
using namespace std;
//------------------------- class node
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
//------------------------- class toolsBox
class toolsBox{
    public:
        int getNodeHeight(node *nodeIn){
            if(nodeIn==NULL){
                return 0;
            }
            else{
                return nodeIn->height;
            }
        }
        int countHeight(node *currNode){
			if(currNode==NULL){
				return 0;
			}
			int L_Height=countHeight(currNode->left);
			int R_Height=countHeight(currNode->right);
			return max(L_Height, R_Height)+1;
        }
        node *findMaxLeftNum(node *nodeIn){
            if(nodeIn->left!=NULL){
                nodeIn=nodeIn->left;
                while(nodeIn->right!=NULL){
                    nodeIn=nodeIn->right;
                }
            }
            return nodeIn;
        }
        node *findMinRightNum(node *nodeIn){
            if(nodeIn->right!=NULL){
                nodeIn=nodeIn->right;
                while(nodeIn->left!=NULL){
                    nodeIn=nodeIn->left;
                }
            }
            return nodeIn;
        }
};
//------------------------- class BST
class BST{
    public:
        node *root;
        toolsBox tool;
        BST(){
            root=NULL;
        }
        node *insertNum(node *currNode, int newNum){
            if(currNode==NULL){
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
        node *deleteNum(node *currNode, int targetNum){
            if(currNode->num<targetNum){
                currNode->right=deleteNum(currNode->right, targetNum);
            }
            else if(currNode->num>targetNum){
                currNode->left=deleteNum(currNode->left, targetNum);
            }
            else{
                if((currNode->left==NULL)&&(currNode->right==NULL)){
                    return NULL;
                }
                else if((currNode->left!=NULL)&&(currNode->right!=NULL)){
                    int L_Height=tool.countHeight(currNode->left);
                    int R_Height=tool.countHeight(currNode->right);
                    int tempNum;
                    if(L_Height<R_Height){
                        tempNum=tool.findMaxLeftNum(currNode)->num;
                        currNode->left=deleteNum(currNode->left, targetNum);
                    }
                    else{
                        tempNum=tool.findMinRightNum(currNode)->num;
                        currNode->right=deleteNum(currNode->right, targetNum);
                    }
                }
                else if(currNode->left!=NULL){
                    return currNode->left;
                }
                else if(currNode->right!=NULL){
                    return currNode->right;
                }
            }
            return currNode;
        }
        void showPostorder(node *currNode){
            if(currNode!=NULL){
                showPostorder(currNode->left);
                showPostorder(currNode->right);
                cout<<currNode->num<<" ";
            }
        }
};
//------------------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->insertNum(bst->root, 50);
    bst->root=bst->insertNum(bst->root, 30);
    bst->root=bst->insertNum(bst->root, 70);
    bst->root=bst->insertNum(bst->root, 20);
    bst->root=bst->insertNum(bst->root, 40);
    bst->root=bst->insertNum(bst->root, 90);
    bst->root=bst->insertNum(bst->root, 80);
    bst->root=bst->insertNum(bst->root, 95);
    bst->showPostorder(bst->root);
    cout<<endl;
    bst->root=bst->deleteNum(bst->root, 20);
    bst->showPostorder(bst->root);
}