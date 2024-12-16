#include<iostream>
using namespace std;
//------------------ class node
class node{
    public:
        int num;
        node *next;
        node(int numIn){
            num=numIn;
            next=NULL;
        }
};
//------------------ class linkList
class linkList{
    public:
        node *head=NULL;
        void addFirst(int newNum){
            node *newNode=new node(newNum);
            if(head!=NULL){
                newNode->next=head;
            }
            head=newNode;
        }
        void showLL(){
            for(node *curr=head;curr!=NULL;curr=curr->next){
                cout<<curr->num<<" ";
            }
            cout<<endl;
        }
        void deleteDupliNum(){
            node *curr=head;
            node *temp=curr->next;
            while(curr->next!=NULL){
                if(curr->num==curr->next->num){
                    curr->next=temp->next;
                    temp->next=NULL;
                    temp=curr->next;
                }
                else{
                    curr=temp;
                    temp=temp->next;
                }
            }
        }
};
//------------------ main
int main(){
    linkList ll;
    ll.addFirst(8);
    ll.addFirst(7);
    ll.addFirst(6);
    ll.addFirst(6);
    ll.addFirst(6);
    ll.addFirst(5);
    ll.addFirst(4);
    ll.addFirst(4);
    ll.addFirst(3);
    ll.addFirst(2);
    ll.addFirst(2);
    ll.addFirst(1);
    ll.addFirst(1);
    ll.addFirst(1);
    ll.deleteDupliNum();
    ll.showLL();
}