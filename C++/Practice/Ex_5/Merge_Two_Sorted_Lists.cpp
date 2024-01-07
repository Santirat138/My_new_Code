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
    node *newHead;
    node *newTail;

    linkList(int headNum);
    void addFirst(int newNum);
    void show();
    void mergeList(node *head1, node *head2);
    node *findPrevNode(node *nodeIn);
    void sortMinMax();
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(int headNum){
    head=new node(headNum);
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    newNode->next=head;
    head=newNode;
}
void linkList::show(){
    node *currNode=head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->next;
    }
    cout<<endl;
}
void linkList::mergeList(node *head1, node *head2){
    node *connectNode=head1;
    while(connectNode!=NULL){
        if(connectNode->next==NULL){
            connectNode->next=head2;
            newHead=head1;
            break;
        }
        else{
            connectNode=connectNode->next;
        }
    }
    newTail=newHead;
    while(newTail!=NULL){
        if(newTail->next==NULL){
            break;
        }
        else{
            newTail=newTail->next;
        }
    }
}
node *linkList::findPrevNode(node *nodeIn){
    node *prevNode=newHead;
    while(prevNode!=NULL){
        if(prevNode->next==nodeIn){
            return prevNode;
        }
        else{
            prevNode=prevNode->next;
        }
    }
}
void linkList::sortMinMax(){
    node *currNode=newHead;
    node *lastNode=newTail;
    int temp;
    while(lastNode!=NULL){
        while(currNode!=lastNode){
            if(currNode->num>currNode->next->num){
                temp=currNode->num;
                currNode->num=currNode->next->num;
                currNode->next->num=temp;
            }
            currNode=currNode->next;
        }
        lastNode=findPrevNode(lastNode);
        currNode=newHead;
    }
}
int main(){
    linkList *list1=new linkList(6);
    list1->addFirst(1);
    list1->addFirst(2);
    list1->addFirst(4);
    linkList *list2=new linkList(5);
    list2->addFirst(1);
    list2->addFirst(3);
    list2->addFirst(4);
    list1->show();
    list1->mergeList(list1->head, list2->head);
    list1->sortMinMax();
    list1->show();
}