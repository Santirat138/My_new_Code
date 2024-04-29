#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
node *nNull=new node(-1);
void addFirst(node **nHeadRef, int newNum);
void show(node **nHeadRef);
void deleteFirst(node **nHeadRef);
node *findNum(node **nHeadRef, int target);
void deleteNum(node **nHeadRef, int target);
node *findPrevNum(node **nHeadRef, int target);
//***************** main *****************
int main(){
    node *nHead=NULL;
    node **nHeadRef=&nHead;
    for(int i=0;i<=5;i++){
        addFirst(nHeadRef, i);
    }
    show(nHeadRef);
    deleteNum(nHeadRef, 2);
}
//***************** functions *****************
void addFirst(node **nHeadRef, int newNum){
    node *nNew=new node(newNum);
    if(*nHeadRef!=NULL){
        nNew->next=*nHeadRef;
    }
    *nHeadRef=nNew;
}
void show(node **nHeadRef){
    node *nCurr=*nHeadRef;
    while(nCurr!=NULL){
        cout<<nCurr->num<<" ";
        nCurr=nCurr->next;
    }
}
void deleteFirst(node **nHeadRef){
    if((*nHeadRef!=NULL)&&((*nHeadRef)->next!=NULL)){
        node *nDel=*nHeadRef;
        *nHeadRef=nDel->next;
        nDel->next=NULL;
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
node *findNum(node **nHeadRef, int target){
    if(*nHeadRef!=NULL){
        node *nCurr=*nHeadRef;
        while(nCurr!=NULL){
            if(nCurr->num==target){
                return nCurr;
            }
            else{
                nCurr=nCurr->next;
            }
        }
    }
    else{
        return nNull;
    }
}
void deleteNum(node **nHeadRef, int target){
    node *nDel=findNum(&(*nHeadRef), target);
    if(nDel!=NULL){
        if(nDel==*nHeadRef){
            deleteFirst(&(*nHeadRef));
        }
        else if((nDel!=*nHeadRef)&&(nDel->next!=NULL)){
            // FindPrevNum
        }
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
node *findPrevNum(node **nHeadRef, int target){
    node *nPrev=*nHeadRef;
    
}