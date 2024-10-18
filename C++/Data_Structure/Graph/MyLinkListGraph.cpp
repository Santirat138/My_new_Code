#include<iostream>
#define maxSize 10
using namespace std;
//----------------------- class node
class node{
    public:
        int num;
        node *next;
        node(int numIn){
            num=numIn;
            next=nullptr;
        }
};
//----------------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList(){
            head=nullptr;
            tail=nullptr;
        }
        void addLast(int newNum);
        void showLL();
};
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=nullptr){
        tail->next=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::showLL(){
    for(node *currNode=head;currNode!=nullptr;currNode=currNode->next){
        cout<<currNode->num<<" ";
    }
    cout<<endl;
}
//----------------------- class arrayList
class arrayList{
    public:
        linkList *arrayLL[maxSize];
        arrayList(){
            for(int i=0;i<maxSize;i++){
                arrayLL[i]=new linkList();
            }
        }
        void addNum(int idxIn, int newNum);
        void show_arrayLL();
};
void arrayList::addNum(int idxIn, int newNum){
    arrayLL[idxIn]->addLast(newNum);
}
void arrayList::show_arrayLL(){
    for(int i=0;i<maxSize;i++){
        cout<<i<<": ";
        arrayLL[i]->showLL();
    }
}
//----------------------- class graph
class graph{
    public:
        arrayList *arrLL;
        graph(){
            arrLL=new arrayList();
        }
        void addEdge(int i, int j);
        void showGraph();
};
void graph::addEdge(int i, int j){
    arrLL->addNum(i, j);
    arrLL->addNum(j, i);
}
void graph::showGraph(){
    arrLL->show_arrayLL();
}
//----------------------- main
int main(){
    graph *g=new graph();
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(2, 1);
    g->addEdge(2, 3);
    g->showGraph();
}