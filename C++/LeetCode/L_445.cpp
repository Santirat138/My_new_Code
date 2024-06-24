#include<iostream>
using namespace std;
//------------------- node -------------------
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
//------------------- Link_list -------------------
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addLast(int newNum);
        void show(node *currNode);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)||(tail==NULL)){
        head=newNode;
    }
    else{
        tail->right=newNode;
    }
    tail=newNode;
}
void linkList::show(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        show(currNode->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
//------------------- functions -------------------

//------------------- main -------------------
int main(){

}
//------------------- functions -------------------