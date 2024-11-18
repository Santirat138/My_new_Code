#include "Info.hpp"
//-------------------------- class node
class node{
    public:
        itemInfo itemData;
        node *left;
        node *right;
        node(int idIn, string nameIn,int wishValueIn, int importantValueIn){
            itemData.setItemInfo(idIn, nameIn, wishValueIn, importantValueIn);
            left=NULL;
            right=NULL;
        }
};
//-------------------------- class BST
class BST{
    public:
        node *root;
        BST(){
            root=NULL;
        }
        node *addNum(node *currNode, int idIn, string nameIn, int wishValueIn, int importantValueIn){
            if(currNode==NULL){
                return new node(idIn, nameIn, wishValueIn, importantValueIn);
            }
            else{
                if(currNode->itemData.itemValue<getItemVal(wishValueIn, importantValueIn)){
                    currNode->right=addNum(currNode->right, idIn, nameIn, wishValueIn, importantValueIn);
                }
                else if(currNode->itemData.itemValue>getItemVal(wishValueIn, importantValueIn)){
                    currNode->left=addNum(currNode->left, idIn, nameIn, wishValueIn, importantValueIn);
                }
                else if(currNode->itemData.itemValue==getItemVal(wishValueIn, importantValueIn)){
                    cout<<"Has same itemValue."<<endl;
                }
            }
            return currNode;
        }
        void showPostorder(node *currNode){
            // left, right, root
            if(currNode!=NULL){
                showPostorder(currNode->left);
                showPostorder(currNode->right);
                cout<<currNode->itemData.itemId<<" : "<<currNode->itemData.itemValue<<endl;
            }
        }
};
