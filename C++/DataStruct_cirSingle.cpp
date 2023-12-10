#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;

        node(int newNum){
            num=newNum;
            next=NULL;
        }
};
class cirLinkList{
    public:
        node *nullNode=new node(-1);
        node *head;
        node *tail;

        cirLinkList(){
            head=NULL;
            tail=NULL;
        }
};
int main(){

}