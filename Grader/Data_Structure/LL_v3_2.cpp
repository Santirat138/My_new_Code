#include<iostream>
using namespace std;
//---------------- class
class node{
    public:
        int num;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    right=NULL;
}
//---------------- functions
void addLast(node **headRef, node **tailRef, int newNum);
void showLL(node *head);
void insertBefore(node **headRef, node **tailRef, int targId, int newNum);
void insertAfter(node **headRef, node **tailRef, int targId, int newNum);
void deleteNode(node **headRef, node **tailRef, int targId);
void mainFunc(node **headRef, node **tailRef);
//---------------- main
int main(){
    node *head=NULL;
    node *tail=NULL;
    node **headRef=&head;
    node **tailRef=&tail;
    mainFunc(headRef, tailRef);
}
//---------------- functions
void addLast(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if(*tailRef!=NULL){
        (*tailRef)->right=newNode;
    }
    else{
        *headRef=newNode;
    }
    *tailRef=newNode;
}
void showLL(node *head){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        cout<<currNode->num<<" ";
    }
    cout<<endl;
}
void insertBefore(node **headRef, node **tailRef, int targId, int newNum){
    node *newNode=new node(newNum);
    if(*headRef==NULL){
        *headRef=newNode;
        *tailRef=newNode;
    }
    else if(targId==(*headRef)->num){
        newNode->right=*headRef;
        *headRef=newNode;
    }
    else{
        bool found=false;
        node *currNode;
        for(currNode=*headRef;currNode->right!=NULL;currNode=currNode->right){
            if(currNode->right->num==targId){
                found=true;
                break;
            }
        }
        if(found){
            newNode->right=currNode->right;
            currNode->right=newNode;
        }
        else if(!found){
            addLast(headRef, tailRef, newNum);
        }
    }
}
void insertAfter(node **headRef, node **tailRef, int targId, int newNum){
    node *newNode=new node(newNum);
    if(*headRef==NULL){
        *headRef=newNode;
        *tailRef=newNode;
    }
    else if(targId==(*tailRef)->num){
        addLast(headRef, tailRef, newNum);
    }
    else{
        bool found=false;
        node *currNode;
        for(currNode=*headRef;currNode->right!=NULL;currNode=currNode->right){
            if(currNode->num==targId){
                found=true;
                break;
            }
        }
        if(found){
            newNode->right=currNode->right;
            currNode->right=newNode;
        }
        else if(!found){
            addLast(headRef, tailRef, newNum);
        }
    }
}
void deleteNode(node **headRef, node **tailRef, int targId){
    node *targNode;
    node *currNode;
    if(((*headRef)->num==targId)&&((*tailRef)->num!=targId)){
        targNode=*headRef;
        *headRef=(*headRef)->right;
        targNode->right=NULL;
    }
    else if(((*headRef)->num!=targId)&&((*tailRef)->num==targId)){
        for(currNode=*headRef;currNode->right!=*tailRef;currNode=currNode->right){}
        *tailRef=currNode;
        currNode->right=NULL;
    }
    else if(((*headRef)->num!=targId)&&((*tailRef)->num!=targId)){
        bool found=false;
        for(currNode=*headRef;currNode->right!=*tailRef;currNode=currNode->right){
            if(currNode->right->num==targId){
                found=true;
                break;
            }
        }
        if(found){
            currNode->right=targNode->right;
            targNode->right=NULL;
        }
        else{

        }
    }
}
void mainFunc(node **headRef, node **tailRef){
    char chIn;
    int newNum;
    int targNum;
    do{
        cin>>chIn;
        if(chIn=='A'){
            cin>>targNum>>newNum;
            insertAfter(headRef, tailRef, targNum, newNum);
        }
        else if(chIn=='I'){
            cin>>targNum>>newNum;
            insertBefore(headRef, tailRef, targNum, newNum);
        }
        else if(chIn=='D'){
            cin>>targNum;
            deleteNode(headRef, tailRef, targNum);
        }
        showLL(*headRef);
    }
    while(chIn!='E');
}