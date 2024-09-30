#include<iostream>
using namespace std;
//----------------- class node
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
node *nullNode=new node(-1);
//----------------- class BST
class BST{
    public:
        node *root;
        BST(){
            root=nullptr;
        }
        node *addNum(node *currNode, int newNum);
        node *findNode(node *currNode, int targetNum);
        int findHeightOfNum(int targetNum);
        int findHeightOfNode(node *currNode);
        void checkNonBalance(node *currNode);
        int getHeight(node *currNode);
        void showCurrLevel(node *currNode ,int levelIn);
        void showLevelorder();
};
node *BST::addNum(node *currNode, int newNum){
    if(currNode==nullptr){
        return new node(newNum);
    }
    else{
        if(currNode->num>newNum){
            currNode->left=addNum(currNode->left, newNum);
        }
        else if(currNode->num<newNum){
            currNode->right=addNum(currNode->right, newNum);
        }
    }
    currNode->height=findHeightOfNode(currNode);
    checkNonBalance(currNode);
    return currNode;
}
node *BST::findNode(node *currNode, int targetNum){
    if(currNode==nullptr){
        return nullptr;
    }
    if(currNode->num<targetNum){
        return findNode(currNode->right, targetNum);
    }
    else if(currNode->num>targetNum){
        return findNode(currNode->left, targetNum);
    }
    else{
        return currNode;
    }
}
int BST::findHeightOfNum(int targetNum){
    node *targetNode=findNode(root, targetNum);
    return findHeightOfNode(targetNode);
}
int BST::findHeightOfNode(node *currNode){
    // Postorder (left --> right --> root)
    if(currNode==nullptr){
        return 0;
    }
    int L_Height=findHeightOfNode(currNode->left);
    int R_Height=findHeightOfNode(currNode->right);
    return max(L_Height, R_Height)+1;
}
void BST::checkNonBalance(node *currNode){
    int L_Height=getHeight(currNode->left);
    int R_Height=getHeight(currNode->right);
    if((abs(L_Height-R_Height)>1)){
        cout<<currNode->num<<" is not balance."<<endl<<"Left height = "<<L_Height<<"    Right height = "<<R_Height<<endl;
        if(R_Height>L_Height){
            if(getHeight(currNode->right->left)>getHeight(currNode->right->right)){
                cout<<"Do Right-Left rotation."<<endl;
            }
            else{
                cout<<"Do Left rotation."<<endl;
            }
        }
        else if(L_Height>R_Height){
            if(getHeight(currNode->left->right)>getHeight(currNode->left->left)){
                cout<<"Do Left-Right rotation."<<endl;
            }
            else{
                cout<<"Do Right rotation."<<endl;
            }
        }
    }
    cout<<endl;
}
int BST::getHeight(node *currNode){
    if(currNode==nullptr){
        return 0;
    }
    else{
        return currNode->height;
    }
}
void BST::showCurrLevel(node *currNode ,int levelIn){
    if(currNode==nullptr){
        return ;
    }
    if(levelIn==0){
        cout<<currNode->num<<" ";
    }
    else{
        showCurrLevel(currNode->left, levelIn-1);
        showCurrLevel(currNode->right, levelIn-1);
    }
}
void BST::showLevelorder(){
    int treeHeight=findHeightOfNode(root);
    for(int i=0;i<=treeHeight;i++){
        showCurrLevel(root, i);
        cout<<endl;
    }
}
//----------------- main
int main(){
    BST *bst=new BST();
    bst->root=bst->addNum(bst->root, 50);
    bst->root=bst->addNum(bst->root, 25);
    bst->root=bst->addNum(bst->root, 75);
    bst->root=bst->addNum(bst->root, 80);
    bst->root=bst->addNum(bst->root, 78);
    bst->showLevelorder();
}