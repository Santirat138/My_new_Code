// Last in first out.
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
//************** functions **************
void push(node *top, int newNum);
node *pop(node *top);
//************** main **************
int main(){

}
//************** functions **************
void push(node *top, int newNum){
    node *newNode=new node(newNum);
    if(top!=NULL){
        newNode->next=top;
    }
    top=newNode;
}