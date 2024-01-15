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
        int numList;
        int digis;

        linkList(int numIn);
        void extractNum();
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(int numIn){
    head=NULL;
    numList=numIn;
}
void linkList::extractNum(){
    // Count digits.
    // Extract number.
    
}
int main(){

}