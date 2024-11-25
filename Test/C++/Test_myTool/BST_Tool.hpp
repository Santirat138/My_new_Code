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
        int countHeight(node *currNode){
            if(currNode==NULL){
                return 0;
            }
            int L_Height=countHeight(currNode->left);
            int R_Height=countHeight(currNode->right);
            return max(L_Height, R_Height)+1;
        }    
        node *findShortestNode(node *nodeIn){
            if((nodeIn->left!=NULL)&&(nodeIn->right!=NULL)){
                int L_Height=countHeight(nodeIn->left);
                int R_Height=countHeight(nodeIn->right);
                if(L_Height>R_Height){
                    return nodeIn->right;
                }
                else{
                    return nodeIn->left;
                }
            }
            else if(nodeIn->left!=NULL){
                return nodeIn->left;
            }
            else if(nodeIn->right!=NULL){
                return nodeIn->right;
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
        node *addNumBy_itemValue(node *currNode, int idIn, string nameIn, int wishValueIn, int importantValueIn){
            if(currNode==NULL){
                return new node(idIn, nameIn, wishValueIn, importantValueIn);
            }
            else{
                if(currNode->itemData.itemValue<getItemVal(wishValueIn, importantValueIn)){
                    currNode->right=addNumBy_itemValue(currNode->right, idIn, nameIn, wishValueIn, importantValueIn);
                }
                else if(currNode->itemData.itemValue>=getItemVal(wishValueIn, importantValueIn)){
                    currNode->left=addNumBy_itemValue(currNode->left, idIn, nameIn, wishValueIn, importantValueIn);
                }
            }
            return currNode;
        }
        node *addNumBy_itemId(node *currNode, int idIn, string nameIn, int wishValueIn, int importantValueIn){
            if(currNode==NULL){
                return new node(idIn, nameIn, wishValueIn, importantValueIn);
            }
            else{
                if(currNode->itemData.itemId<idIn){
                    currNode->right=addNumBy_itemId(currNode->right, idIn, nameIn, wishValueIn, importantValueIn);
                }
                else if(currNode->itemData.itemId>=idIn){
                    currNode->left=addNumBy_itemId(currNode->left, idIn, nameIn, wishValueIn, importantValueIn);
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
                    if(currNode->left==tool.findShortestNode(currNode)){
                        node *maxValueNode=tool.findMaxLeftNode(currNode);
                        currNode->itemData=maxValueNode->itemData;
                        currNode->left=deleteItemId(currNode->left, maxValueNode->itemData.itemId);
                    }
                    else{
                        node *minRightNode=tool.findMinRightNode(currNode);
                        currNode->itemData=minRightNode->itemData;
                        currNode->right=deleteItemId(currNode->right, minRightNode->itemData.itemId);
                    }
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
            int treeHeight=tool.countHeight(root);
            for(int i=0;i<treeHeight;i++){
                showCurrLevel(root, i);
                cout<<endl;
            }
        }
        node *findItem(node *currNode, int targetId){
            if(currNode==NULL){
                return new node(-1, "-", -1, -1);
            }
            if(currNode->itemData.itemId<targetId){
                cout<<"Go right"<<endl;
                return findItem(currNode->right, targetId);
            }
            else if(currNode->itemData.itemId>targetId){
                cout<<"Go left"<<endl;
                return findItem(currNode->left, targetId);
            }
            else if(currNode->itemData.itemId==targetId){
                /* currNode->itemData.showItemInfo(); */
                return currNode;
            }
            
        }
};
