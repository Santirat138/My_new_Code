#include<iostream>
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
        void addFirst(int newNum);
        void addLast(int newNum);
        void showList(node *currNode);
        node *findNum(int numTarget, node *currNode);
        void deleteNum(int numTarget, node *currNode);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=NULL;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        newNode->next=head;
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        tail->next=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::showList(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showList(currNode->next);
    }
    else{
        cout<<"End.";
    }
}
node *linkList::findNum(int numTarget, node *currNode){
    if(currNode!=NULL){
        if(currNode->num!=numTarget){
            return findNum(numTarget, currNode->next);
        }
        else if(currNode->num==numTarget){
            return currNode;
        }
    }
    else{
        return nullNode;
    }
}
void deleteNum(int numTarget, node *currNode){
    
}
int main(){

}