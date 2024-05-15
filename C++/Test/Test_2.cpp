#include<iostream>
using namespace std;
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
//******** functions ********
void addFirst(node **headRef, int newNum);

//******** main ********
int main(){
    node *head=NULL;
    node **headRef=&head;
    addFirst(&head, 1);
    addFirst(&head, 2);
    cout<<(*headRef)->next->num;
}
//******** functions ********
void addFirst(node **headRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->next=*headRef;
    }
    *headRef=newNode;
}
