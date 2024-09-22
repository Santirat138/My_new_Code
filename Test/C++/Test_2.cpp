// Test Bubble sort link list.
#include<iostream>
using namespace std;
//------------------- class info
class info{
    public:
        int id;
        string name;
        int age;
};
//------------------- class node
class node{
    public:
        info data;
        node *next;
        node(int idIn, string nameIn, int ageIn){
            data.id=idIn;
            data.name=nameIn;
            data.age=ageIn;
            next=nullptr;
        }
};
//------------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList(){
            head=nullptr;
            tail=nullptr;
        }
        void addFirst(int idIn, string nameIn, int ageIn);
        void showLL();
        void bbSortId();
};
void linkList::addFirst(int idIn, string nameIn, int ageIn){
    node *newNode=new node(idIn, nameIn, ageIn);
    if(head!=nullptr){
        newNode->next=head;
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::showLL(){
    for(node *curr=head;curr!=nullptr;curr=curr->next){
        cout<<curr->data.id<<" : "<<curr->data.name<<" "<<curr->data.age<<endl;
    }
    cout<<endl;
}
void linkList::bbSortId(){
    node *currNode;
    node *sortedNode=nullptr;
    bool swapped;
    do{
        currNode=head;
        swapped=false;
        while(currNode->next!=sortedNode){
            if(currNode->data.id>currNode->next->data.id){
                swap(currNode->data, currNode->next->data);
                swapped=true;
            }
            currNode=currNode->next;
        }
        sortedNode=currNode;
    }
    while(swapped);
}
//------------------- main
int main(){
    linkList *ll=new linkList();
    ll->addFirst(1001, "aaa", 15);
    ll->addFirst(1002, "bbb", 14);
    ll->addFirst(1003, "ccc", 13);
    ll->addFirst(1004, "ddd", 12);
    ll->showLL();
    ll->bbSortId();
    ll->showLL();
}