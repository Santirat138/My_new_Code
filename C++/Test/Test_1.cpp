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
void addFirst(node *nHeadRef, int newNum);
void show(node **nHeadRef);
//***************** main *****************
int main(){
    node *nHead=NULL;
    node **nHeadRef=&nHead;
    addFirst(nHead, 1);
    addFirst(nHead, 2);
    show(nHeadRef);
}
//***************** functions *****************
void addFirst(node *nHead, int newNum){
    node *nNew=new node(newNum);
    if(nHead!=NULL){
        nNew->next=nHead;
    }
    nHead=nNew;
}
void show(node **nHeadRef){
    node *nCurr=*nHeadRef;
    while(nCurr!=NULL){
        cout<<nCurr->num<<" ";
        nCurr=nCurr->next;
    }
}
