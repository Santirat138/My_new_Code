// Check match for any char(1 char) that is not number or operator.
//stackLL in linkList.
#include<iostream>
using namespace std;
//------------------ class
class node{
    public:
        char ch;
        node *next;
        node(char chIn){
            ch=chIn;
            next=NULL;
        }
};
node *nullNode=new node('_');
class stackLL{
    public:
        node *head;
        node *tail;
        int n_node;
        stackLL(){
            head=NULL;
            tail=NULL;
            n_node=0;
        }
        void show_LL(){
            for(node *curr=head;curr!=NULL;curr=curr->next){
                cout<<curr->ch<<" ";
            }
            cout<<endl;
        }
        bool isEmpty(){
            if((head==NULL&&tail==NULL)&&(n_node==0)){
                return true;
            }
            return false;
        }
        void push(char newChar){
            node *newNode=new node(newChar);
            if(tail!=NULL){
                tail->next=newNode;
            }
            else{
                head=newNode;
            }
            tail=newNode;
            n_node++;
        }
        void deleteLast(node *tempNode){
            if(isEmpty()){
                cout<<"Stack is empty."<<endl;
                tempNode=nullNode;
                return ;
            }
            if((head==tail)&&(n_node==1)){
                tempNode->ch=head->ch;
                head=NULL;
                tail=NULL;
                n_node=0;
                return ;
            }
            node *curr;
            for(curr=head;curr->next!=tail;curr=curr->next){}
            tempNode->ch=tail->ch;
            tail=curr;
            curr->next=NULL;
            n_node--;
        }
        void delete_pop(){
            node *temp=new node('_');
            deleteLast(temp);
        }

};
class linkList{
    public:
        node *head;
        node *tail;
        int n_LL;
        linkList(){
            head=NULL;
            tail=NULL;
            n_LL=0;
        }
        void addLast(){

        }
};
//------------------ main
int main(){
    stackLL stk;
    for(int i=0;i<=5;i++){
        stk.push('a'+i);
    }

}