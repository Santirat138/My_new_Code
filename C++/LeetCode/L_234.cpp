#include<iostream>
using namespace std;
//************ class node ************
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
//************ class link-List ************
class linkList{
    public:
        node *head;
        linkList();
        void addFirst(int newNum);
        void show(node *currNode);
};
linkList::linkList(){
    head=NULL;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        newNode->right=head;
    }
    head=newNode;
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
//************ functions ************
node *makeRev(node *head);
//************ main ************
int main(){
    linkList *list1=new linkList();
    list1->addFirst(4);
    list1->addFirst(3);
    list1->addFirst(2);
    list1->addFirst(1);
    list1->show(list1->head);
    list1->head=makeRev(list1->head);
    list1->show(list1->head);
}
//************ functions ************
node *makeRev(node *head){
    node *leftNode=NULL;
    node *currNode=head;
    node *rightNode=head->right;
    while(currNode!=NULL){
        currNode->right=leftNode;
        leftNode=currNode;
        currNode=rightNode;
        if(currNode->right!=NULL){
            rightNode=currNode->right;
        }
        else{
            currNode->right=leftNode;
            break;
        }
    }
    return currNode;
}