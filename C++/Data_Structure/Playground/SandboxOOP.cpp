#include<iostream>
using namespace std;
//**************** node ****************
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int num);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
};
//**************** link list ****************
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        linkList();
        void addFirst(int newNum);
        void addLast(int newNum);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(-1);
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        newNode->right=head;
    }
    head=newNode;
}
//**************** tree ****************
//**************** main ****************
int main(){
    node *head=NULL;
    node **headRef=&head;
    node *tail=NULL;
    node **tailRef=&tail;

}
