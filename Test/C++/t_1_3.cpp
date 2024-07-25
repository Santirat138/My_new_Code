#include<iostream>
#include<vector>
using namespace std;
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
class linkList{
    public:
        node *head;
        linkList();
        void addFirst(int newNum);
        void showList(node *currNode);
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
void linkList::showList(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showList(currNode->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
class hashTable{
    public:
        linkList *list;
        vector<linkList> array;
        int size;
        hashTable();
        int findKey(int numIn);
};
hashTable::hashTable(){
    
}
//------------------- functions -------------------

//------------------- main -------------------
int main(){

}
//------------------- functions -------------------