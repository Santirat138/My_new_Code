#include<iostream>
#define nullNum 0
using namespace std;
class node{
    public:
        int num;
        node *next;
        node(int numIn);
};
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        linkList();
        void addLast(int numIn);
        void showList(node *currNode);
};
class mainBox{
    public:
        linkList *list1;
        linkList *list2;
        
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(nullNum);
}
void linkList::addLast(int numIn){
    node *newNode=new node(numIn);
    if(tail==NULL){
        head=newNode;
    }
    else{
        tail->next=newNode;
    }
    tail=newNode;
}
void linkList::showList(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showList(currNode->next);
    }
    else{
        cout<<"End."<<endl;
    }
}
int main(){

}