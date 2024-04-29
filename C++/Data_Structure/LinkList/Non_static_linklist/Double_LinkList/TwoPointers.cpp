#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
node *nHead=NULL;
node **nHeadRef=&nHead;
node *nNull=new node(-1);
//******************** functions ********************
void linkNode(node *n1, node *n2);
void addFirst(node **nHeadRef, int newNum);
//******************** main ********************
int main(){

}
//******************** functions ********************
void linkNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void addFirst(node **nHeadRef, int newNum){
    node *nNew=new node(newNum);
    if(*nHeadRef!=NULL){
        linkNode(nNew, *nHeadRef);
    }
    *nHeadRef=nNew;
}