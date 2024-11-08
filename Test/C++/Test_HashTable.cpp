#include<iostream>
#define MAX 10
using namespace std;
//--------------------------- class node
class node{
    public:
        char ch;
        node *next;
        node(char chIn){
             ch=chIn;
             next=nullptr;
        }
};
//--------------------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList(){
            head=nullptr;
            tail=nullptr;
        }
        bool isEmpty();
        void push(char chIn);
        char pop();
};
bool linkList::isEmpty(){
    if((head!=nullptr)&&(tail!=nullptr)){
        return false;
    }
    else{
        return true;
    }
}
void linkList::push(char chIn){
    node *newNode=new node(chIn);
    if(tail==nullptr){
        tail->next=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
char linkList::pop(){
    node *temp;
    for(temp=head;temp->next!=tail;temp=temp->next){}
    tail=temp;
    temp=temp->next;
    tail->next=nullptr;
    return temp->ch;
}
//--------------------------- class hashTable
class hashTable{
    public:
        linkList *hashArray[MAX];
        hashTable(){
            for(int i=0;i<MAX;i++){
                hashArray[i]=new linkList();
            }
        }
        
};
//--------------------------- main
int main(){

}