#include<iostream>
using namespace std;
//************ node ************
class node{
    public:
        int num;
        node *next;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
//************ linkList ************
class linkList{
    public:
        node *head;
        node *nullNode;
        linkList();
        void addFirst(int newNum);
        void showLL(node *currNode);
        //void addSort();
};
linkList::linkList(){
    head=NULL;
    nullNode=new node(-1);
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        newNode->next=head;
    }
    head=newNode;
}
void showLL(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showLL(currNode->next);
    }
    else{
        cout<<"End."<<endl;
    }
}
//************ hashTable ************
class hashTable{
    public:
        int size=5;
        int array[5];
        hashTable();
};
hashTable::hashTable(){
    
}
//************ main ************
int main(){

}