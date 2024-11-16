#include<iostream>
using namespace std;
//------------------------- class node
class node{
    public:
        int num;
        node *next;
        node(int numIn){
            num=numIn;
            next=nullptr;
        }
};
//------------------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList(){
            head=nullptr;
            tail=nullptr;
        }
        void addLast(int newNum);
        void deleteAllDuplicateNum();
};
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(head!=nullptr){
        tail->next=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::deleteAllDuplicateNum(){

}
//------------------------- functions
void showLL(linkList *listIn);
//------------------------- main
int main(){
    linkList *list=new linkList();
    for(int i=0;i<=3;i++){
        list->addLast(1);
    }
    for(int i=0;i<=3;i++){
        list->addLast(2);
        
    }
    list->deleteAllDuplicateNum();
    showLL(list); 
}
//------------------------- functions
void showLL(linkList *listIn){
    for(node *curr=listIn->head;curr!=nullptr;curr=curr->next){
        cout<<curr->num<<" ";
    }
}