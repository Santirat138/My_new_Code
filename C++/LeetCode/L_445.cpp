#include<iostream>
using namespace std;
//------------------ class node
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
//------------------ functions
void connectNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
//------------------ class linkList
class linkList{
    public:
        node *head=NULL;
        node *tail=NULL;
        void addFirst(int newNum){
            node *newNode=new node(newNum);
            if(head!=NULL){
                connectNode(newNode, head);
            }
            else{
                tail=newNode;
            }
            head=newNode;
        }
        void addLast(int newNum){
            node *newNode=new node(newNum);
            if(tail!=NULL){
                connectNode(tail, newNode);
            }
            else{
                head=newNode;
            }
            tail=newNode;
        }
        void showLL(){
            for(node *curr=head;curr!=NULL;curr=curr->next){
                cout<<curr->num<<" ";
            }
            cout<<endl;
        }
};
//------------------ functions
linkList *plusLL(linkList *LL_1, linkList *LL_2){
    node *curr1=LL_1->tail;
    node *curr2=LL_2->tail;
    linkList *ansLL=new linkList();
    int temp=0;
    int currAns;
    while(true){
        if((curr1!=NULL)&&(curr2!=NULL)){
            currAns=curr1->num+curr2->num+temp;
            if(currAns>=10){
                currAns=currAns-10;
                temp=1;
            }
            ansLL->addFirst(currAns);
            curr1=curr1->prev;
            curr2=curr2->prev;
        }
        else if((curr1==NULL)&&(curr2!=NULL)){
            currAns=curr2->num+temp;
            if(currAns>=10){
                currAns=currAns-10;
                temp=1;
            }
            ansLL->addFirst(currAns);
            curr2=curr2->prev;
        }
        else if((curr1!=NULL)&&(curr2==NULL)){
            currAns=curr1->num+temp;
            if(currAns>=10){
                currAns=currAns-10;
                temp=1;
            }
            ansLL->addFirst(currAns);
            curr1=curr1->prev;
        }
        else{
            if(temp!=0){
                ansLL->addFirst(temp);
            }
            break;
        }
    }
    return ansLL;
}
//------------------ main
int main(){
    linkList *list1=new linkList();
    linkList *list2=new linkList();
    linkList *listAns=new linkList();
    list1->addLast(2);
    list1->addLast(3);
    list1->addLast(9);
    list1->addLast(9);

    list2->addLast(1);
    list2->addLast(9);
    list2->addLast(5);
    listAns=plusLL(list1, list2);
    listAns->showLL();
}