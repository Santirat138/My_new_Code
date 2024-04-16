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
        void deleteNum(int numTarget);
        void deleteHead();
        void deleteTail();
        node *findPrevNode(node *prevNode, node *currNode);
        void deleteAllNum(int numTarget);
        void sortMinMax();
        void swap(node *node1, node *node2);
        // void addSort();
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
void linkList::deleteNum(int numTarget){
    node *currNode=findNum(numTarget, head);
    if(currNode!=NULL){
        if(currNode==head){
            deleteHead();
        }
        else if(currNode==tail){
            deleteTail();
        }
        else{
            node *temp=findPrevNode(head, currNode);
            temp->next=currNode->next;
            currNode->next=NULL;
        }
    }
    else{
        cout<<"Can't delete.";
    }
}
void linkList::deleteHead(){
    if(head!=NULL){
        node *temp=head;
        head=head->next;
        temp->next=NULL;
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
void linkList::deleteTail(){
    if(tail!=NULL){
        node *temp=findPrevNode(head, tail);
        tail=temp;
        tail->next=NULL;
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
node *linkList::findPrevNode(node *prevNode ,node *currNode){
    if((currNode!=head)||(currNode!=NULL)){
        if(prevNode->next==currNode){
            return prevNode;
        }
        else{
            return findPrevNode(prevNode->next, currNode);
        }
    }
    else{
        cout<<"Can't find previous node."<<endl;
        return nullNode;
    }
}
void linkList::deleteAllNum(int numTarget){
    node *currNode;
    node *temp=head;
    do{
        if(currNode->num==numTarget){
            temp=currNode->next;
            deleteNum(numTarget);
        }
        currNode=findNum(numTarget, temp);
    }
    while(currNode!=nullNode);
    if(currNode==nullNode){
        cout<<"Clear "<<numTarget<<"."<<endl;
    }
}
void linkList::sortMinMax(){

}
void linkList::swap(node *node1, node *node2){
    int temp=node1->num;
    node1->num=node2->num;
    node2->num=temp;
}
int main(){
    linkList *list=new linkList();
    list->addLast(0);
    list->addLast(1);
    list->addLast(2);
    list->addLast(1);
    list->addLast(1);
    list->addLast(3);
    list->addLast(2);
    list->showList(list->head);
}