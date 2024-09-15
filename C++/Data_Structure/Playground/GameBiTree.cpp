#include<iostream>
#include<vector>
#define nullNum -1
using namespace std;
//------------------- variable

//------------------- class node
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
node *nullNode=new node(nullNum);
//------------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList(){
            head=NULL;
            tail=NULL;
        }
        void addLast(int newNum);
        void showLL();
};

void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        tail->right=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::showLL(){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        cout<<currNode->num<<" ";
    }
}
//------------------- class biTree
class biTree{
    public:
        node *root;
        linkList *ll;
        linkList *ansLL;
        biTree(){
            root=NULL;
            ll=new linkList();
            ansLL=new linkList();
        }
        void insertNum(node *currNode, int newNum);
        void preorder(node *currNode);
        void inorder(node *currNode);
        void postorder(node *currNode);
        void setAnsPreorder(node *currNode);
        void setAnsInorder(node *currNode);
        void setAnsPostorder(node *currNode);
        void showAnsArray();
        void insertAns(int ansIn);
        void checkAns(int arrSize);
};
void biTree::insertNum(node *currNode, int newNum){
    if(currNode==NULL){
        root=new node(newNum);
    }
    else{
        if(newNum<currNode->num){
            if(currNode->left==NULL){
                currNode->left=new node(newNum);
            }
            else if(currNode->left!=NULL){
                insertNum(currNode->left, newNum);
            }
        }
        else if(newNum>currNode->num){
            if(currNode->right==NULL){
                currNode->right=new node(newNum);
            }
            else if(currNode->right!=NULL){
                insertNum(currNode->right, newNum);
            }
        }
    }
}
void biTree::preorder(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        preorder(currNode->left);
        preorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::inorder(node *currNode){
    if(currNode!=NULL){
        inorder(currNode->left);
        cout<<currNode->num<<" ";
        inorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::postorder(node *currNode){
    if(currNode!=NULL){
        postorder(currNode->left);
        postorder(currNode->right);
        cout<<currNode->num<<" ";
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::setAnsPreorder(node *currNode){
    if(currNode!=NULL){
        ll->addLast(currNode->num);
        setAnsPreorder(currNode->left);
        setAnsPreorder(currNode->right);
    }
    else{
        ll->addLast(nullNum);
    }
}
void biTree::setAnsInorder(node *currNode){
    if(currNode!=NULL){
        setAnsInorder(currNode->left);
        ll->addLast(currNode->num);
        setAnsInorder(currNode->right);
    }
    else{
        ll->addLast(nullNum);
    }
}
void biTree::setAnsPostorder(node *currNode){
    if(currNode!=NULL){
        setAnsPostorder(currNode->left);
        setAnsPostorder(currNode->right);
        ll->addLast(currNode->num);
    }
    else{
        ll->addLast(nullNum);
    }
}
void biTree::showAnsArray(){
    ll->showLL();
}
void biTree::insertAns(int ansIn){
    ansLL->addLast(ansIn);
}
void biTree::checkAns(int arrSize){
    bool pass=true;
    int currIdx=0;
    for(node *curr1=ll->head, *curr2=ansLL->head;currIdx<arrSize;curr1=curr1->right, curr2=curr2->right, currIdx++){
        if(curr1->num!=curr2->num){
            pass=false;
            cout<<"Error "<<curr1->num<<" != "<<curr2->num<<endl;
        }
    }
    if(!pass){
        cout<<"Not pass."<<endl;
    }
    else if(pass){
        cout<<"Pass."<<endl;
    }

}
//------------------- functions

//------------------- main
int main(){
    biTree *tree=new biTree();
    vector<int> arrayTree({50, 6, 500, 2, 15, 58, 4, 13, 25, 51, 79, 9, 44, 80});
    for(int i=0;i<arrayTree.size();i++){
        tree->insertNum(tree->root, arrayTree.at(i));
    }
    tree->setAnsPreorder(tree->root);
    
    vector<int> arrayAns({50, 6, 2, -1, 4, -1, -1, 15, 13, 9, -1, -1, -1, 25, -1, 44, -1, -1, 500, 58, 51, -1, -1, 79, -1, 80, -1, -1, -1});
    int arrSize=arrayAns.size();
    for(int i=0;i<arrSize;i++){
        tree->insertAns(arrayAns.at(i));
    }
    tree->checkAns(arrSize);
}
//------------------- functions
