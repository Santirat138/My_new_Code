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
        linkList();
        void addFirst(int newNum);
};
class merge{
    public:
        
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    newNode->next=head;
    head=newNode;
}

int main(){

}