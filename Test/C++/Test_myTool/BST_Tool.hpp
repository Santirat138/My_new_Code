#include "Info.hpp"
//-------------------------- class node
class node{
    public:
        itemInfo itemData;
        node *left;
        node *right;
        node(int idIn, string nameIn, int wishValueIn, int importantValueIn){
            itemData.setItemInfo(idIn, nameIn, wishValueIn, importantValueIn);
            left=NULL;
            right=NULL;
        }
};
//-------------------------- class toolsBox
class toolsBox{
    public:
        node *findMaxLeftNode(node *currNode){
            if(currNode->left!=NULL){
                currNode=currNode->left;
                while(currNode->right!=NULL){
                    currNode=currNode->right;
                }
                return currNode;
            }
            return NULL;
        }
        node *findMinRightNode(node *currNode){
            if(currNode->right!=NULL){
                currNode=currNode->right;
                while(currNode->left!=NULL){
                    currNode=currNode->left;
                }
                return currNode;
            }
            return NULL;           
        }
};
//-------------------------- class BST
class BST{
    public:
        node *root;
        toolsBox tool;
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
                else if(currNode->itemData.itemValue>=getItemVal(wishValueIn, importantValueIn)){
                    currNode->left=addNum(currNode->left, idIn, nameIn, wishValueIn, importantValueIn);
                }
            }
            return currNode;
        }       
        node *deleteItemId(node *currNode, int idIn){
            if(currNode->itemData.itemId<idIn){
                currNode->right=deleteItemId(currNode->right, idIn);
            }
            else if(currNode->itemData.itemId>idIn){
                currNode->left=deleteItemId(currNode->left, idIn);
            }
            else if(currNode->itemData.itemId==idIn){
                if((currNode->left==NULL)&&(currNode->right==NULL)){
                    currNode=NULL;
                }
                else if((currNode->left!=NULL)&&(currNode->right!=NULL)){
                    if()
                    node *maxValueNode=tool.findMaxLeftNode(currNode);
                    currNode->itemData=maxValueNode->itemData;
                    currNode->left=deleteItemId(currNode->left, maxValueNode->itemData.itemId);
                }
                else if(currNode->left==NULL){
                    currNode=currNode->right;
                }
                else if(currNode->right==NULL){
                    currNode=currNode->left;
                }
            }
            return currNode;
        }
        int countHeight(node *currNode){
            if(currNode==NULL){
                return 0;
            }
            int L_Height=countHeight(currNode->left);
            int R_Height=countHeight(currNode->right);
            return max(L_Height, R_Height)+1;
        }
        void showCurrLevel(node *currNode, int currLevel){
            if(currNode==NULL){
                return ;
            }
            if(currLevel==0){
                /* currNode->itemData.showItemInfo(); */
                cout<<currNode->itemData.itemId<<": "<<currNode->itemData.itemValue<<"\t";
            }
            else if(currLevel>0){
                showCurrLevel(currNode->left, currLevel-1);
                showCurrLevel(currNode->right, currLevel-1);
            }
        }
        void showLevelorder(){
            int treeHeight=countHeight(root);
            for(int i=0;i<treeHeight;i++){
                showCurrLevel(root, i);
                cout<<endl;
            }
        }
};
