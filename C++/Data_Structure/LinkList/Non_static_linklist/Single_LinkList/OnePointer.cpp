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
node *nHead=NULL;
node *nNull=new node(-1);
//**************** functions ****************
node *addFirst(int newNum);
void showLL(node *nCurr);
//**************** main ****************
int main(){
    nHead=addFirst(1);
    nHead=addFirst(2);
    nHead=addFirst(3);
    showLL(nHead);
}
//**************** functions ****************
node *addFirst(int newNum){
    node *nNew=new node(newNum);
    nNew->next=nHead;
    nHead=nNew;
    return nHead;
}
void showLL(node *nCurr){
    if(nCurr!=NULL){
        cout<<nCurr->num<<" ";
        showLL(nCurr->next);
    }
    else{
        cout<<"End."<<endl;
    }
}