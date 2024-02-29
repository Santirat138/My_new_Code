// Test Merge_Two_Sorted_Lists. Double link-list
#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
        node(int numIn){
            num=numIn;
            prev=NULL;
            next=NULL;
        }
};
class linkList{
    public:
        node *head;
        node *tail;
        linkList(){
            head=NULL;
            tail=NULL;
        }
        void linkNode(node *n1, node *n2){
            n1->next=n2;
            n2->prev=n1;
        }
        void addLast(int newNum){
            node *newNode=new node(newNum);
            if(tail!=NULL){
                linkNode(tail, newNode);
            }
            else{
                head=newNode;
            }
            tail=newNode;
        }
        void showH(node *currNode){
            if(currNode!=NULL){
                cout<<currNode->num<<" ";
                showH(currNode->next);
            }
            else{
                cout<<"End."<<endl;
            }
        }
        void showT(node *currNode){
            if(currNode!=NULL){
                cout<<currNode->num<<" ";
                showT(currNode->prev);
            }
            else{
                cout<<"End."<<endl;
            }
        }
        void showList(){
            showH(head);
            showT(tail);
        }
        void mergeList(){
            
        }
};
int main(){
    linkList *list=new linkList();
    for(int i=0;i<5;i++){
        list->addLast(i);
    }
    list->showList();
}