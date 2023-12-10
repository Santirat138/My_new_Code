#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;

        node(int numIn){
            num=numIn;
            prev=NULL;
            next=NULL;
        }
};
class linkList{
    public:
        int amount;
        node *nullNode=new node(-1);
        node *head;
        node *tail;

        linkList(){
            amount=0;
            head=NULL;
            tail=NULL;
        }
        void connectNode(node *node1, node *node2);
        void addFirst(int newNum);
        void addLast(int newNum);
};
void linkList::connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        connectNode(newNode, head);
    }
    head=newNode;
    amount++;
}
int main(){

}