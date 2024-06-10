#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
}
//**************** functions ****************
void addFirst(node **headRef, node **tailRef, int newNum);
//**************** main ****************
int main(){
    node *head=NULL;
    node *tail=NULL;
    node **headRef=&head;
    node **tailRef=&tail;

}
//**************** functions ****************
void addFirst(node **headRef, node **tailRef, int newNum){
    
}