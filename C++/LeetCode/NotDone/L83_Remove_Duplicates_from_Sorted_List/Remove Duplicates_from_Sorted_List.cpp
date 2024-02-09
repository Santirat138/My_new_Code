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
        linkList();
        void addLast(int newNum);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addLast(int newNum){
    
}
int main(){

}