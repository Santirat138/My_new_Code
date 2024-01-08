#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;

        node(int numIn);
};
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;

        linkList();
        void connectNode(node *n1, node *n2);
        void addFirst(int numIn);
        void addLast(int numIn);
        void addSortMinMax(int numIn);
        void showHT(node *currNode);
        void showTH(node *currNode);
        void showList();
};
class hashTable{
    public:
        int num;
        int key;
        int size;
        linkList *arrayLL[];

        hashTable(int sizeIn);
        void setKey(int numIn);
        void insertNum(int newNum);
        void showAll();
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=head;
    nullNode=new node(-1);
}
void linkList::connectNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void linkList::addFirst(int numIn){
    node *newNode=new node(numIn);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        connectNode(newNode, head);
    }
    head=newNode;
}
void linkList::addLast(int numIn){
    node *newNode=new node(numIn);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
    }
    else{
        connectNode(tail, newNode);
    }
    tail=newNode;
}
void linkList::addSortMinMax(int numIn){
    node *compNode=head;
    node *newNode=new node(numIn);
    if(compNode==NULL){
        head=newNode;
        tail=head;
    }
    else if(head==tail){
        if(numIn<head->num){
            addFirst(numIn);
        }
        else if(numIn>head->num){
            addLast(numIn);
        }
    }
    else{
        while(compNode!=NULL){
            if(compNode->next!=NULL){
                if((numIn<compNode->num)&&(numIn<compNode->next->num)){
                    addFirst(numIn);
                    break;
                }
                else if((numIn>compNode->num)&&(numIn<compNode->next->num)){
                    connectNode(newNode, compNode->next);
                    connectNode(compNode, newNode);
                    break;
                }
                else if((numIn>compNode->num)&&(numIn>compNode->next->num)){
                    compNode=compNode->next;
                }
            }
            else if(compNode->next==NULL){
                if(numIn>compNode->num){
                    addLast(numIn);
                }
                else if(numIn<compNode->num){
                    connectNode(compNode->prev, newNode);
                    connectNode(newNode, compNode);
                }
                break;
            }
        }
    }
}
void linkList::showHT(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showHT(currNode->next);
    }
}
void linkList::showTH(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showTH(currNode->prev);
    }
}
void linkList::showList(){
    cout<<"Head --> Tail. ";
    showHT(head);
    cout<<"Tail --> Head. ";
    showTH(tail);
    cout<<endl<<endl;
}
hashTable::hashTable(int sizeIn){
    size=sizeIn;
    arrayLL[size]=new linkList();
    for(int i=0;i<size;i++){
        arrayLL[i]=new linkList();
    }
}
void hashTable::setKey(int numIn){
    num=numIn;
    key=numIn%size;
}
void hashTable::insertNum(int newNum){
    setKey(newNum);
    arrayLL[key]->addSortMinMax(newNum);
}
void hashTable::showAll(){
    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<endl;
        arrayLL[i]->showList();
    }
}
int main(){
    hashTable *table1=new hashTable(5);
    table1->insertNum(5);
    table1->insertNum(50);
    table1->insertNum(7);
    table1->insertNum(3);
    table1->showAll();
}