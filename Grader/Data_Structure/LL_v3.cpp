#include<iostream>
using namespace std;
//-------------- class --------------
class node{
    public:
        int num;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    right=NULL;
}
node *nullNode=new node(-1);
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void showList();
        void addLast(int newNum);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::showList(){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        cout<<currNode->num<<" ";
    }
    cout<<endl;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        tail->right=newNode;
    }
    else{
        head=newNode;
    }
    head=newNode;
}
//-------------- main --------------
int main(){
    
}