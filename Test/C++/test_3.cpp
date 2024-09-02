// Sort link list data.
#include<iostream>
#define nullNum -1
using namespace std;
//--------------- class node
class node{
    public:
        int idNum;
        int age;
        node *right;
        node(int idIn, int ageIn);
};
node::node(int idIn, int ageIn){
    idNum=idIn;
    age=ageIn;
    right=NULL;
}
node *nullNode=new node(nullNum, nullNum);
//--------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addFirst(int newId, int newAge);
        void showLL();
        void swapId(node *node1, node *node2);
        void sortId();
        void copyNode(node *node1, node *node2);
        void clearNode(node *nodeIn);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addFirst(int newId, int newAge){
    node *newNode=new node(newId, newAge);
    if(head!=NULL){
        newNode->right=head;
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::showLL(){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        cout<<currNode->idNum<<" : "<<currNode->age<<endl;
    }
    cout<<endl;
}
void linkList::swapId(node *node1, node *node2){
    node *temp=nullNode;
    copyNode(temp, node1);
    copyNode(node1, node2);
    copyNode(node2, temp);
    clearNode(nullNode);
}
void linkList::sortId(){
    node *maxId=nullNode;
    for(node *curr1=head;curr1!=NULL;curr1=curr1->right){
        maxId=curr1;
        for(node *curr2=curr1->right;curr2!=NULL;curr2=curr2->right){
            if(curr2->idNum>maxId->idNum){
                maxId=curr2;
                swapId(curr2, curr1);
            }
        }
    }
    clearNode(nullNode);
}
void linkList::copyNode(node *node1, node *node2){
    node1->idNum=node2->idNum;
    node1->age=node2->age;
}
void linkList::clearNode(node *nodeIn){
    nodeIn->idNum=-1;
    nodeIn->age=-1;
    nodeIn->right=NULL;
}
//--------------- functions

//--------------- main
int main(){
    linkList *list=new linkList();
    for(int i=5;i>0;i--){
        list->addFirst(i, 10+i);
    }
    list->showLL();
    list->sortId();
    list->showLL();
}
//--------------- functions
