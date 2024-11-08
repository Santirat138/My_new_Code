// Change Test_2 to use array link list.
#include<iostream>
#define MAX 10
#define NULLCH '_'
using namespace std;
//------------------------- class node
class node{
    public:
        char ch;
        node *next;
        node(char chIn){
             ch=chIn;
             next=nullptr;
        }
};
//------------------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList(){
            head=nullptr;
            tail=nullptr;
        }
        bool isEmpty();
        void push(char chIn);
        char pop();
};
bool linkList::isEmpty(){
    if((head!=nullptr)&&(tail!=nullptr)){
        return false;
    }
    else{
        return true;
    }
}
void linkList::push(char chIn){
    node *newNode=new node(chIn);
    if(tail!=nullptr){
        tail->next=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
char linkList::pop(){
    if(!isEmpty()){
        node *temp;
        for(temp=head;temp->next!=tail;temp=temp->next){}
        tail=temp;
        temp=temp->next;
        tail->next=nullptr;
        return temp->ch;
    }
    return NULLCH;
}
//------------------------- class arrayLL
class arrayLL{
    public:
        linkList *arrLL[MAX];
        arrayLL(){
            for(int i=0;i<MAX;i++){
                arrLL[i]=new linkList();
            }
            arrLL[0]->push('(');
            arrLL[1]->push('[');
        }
        void checkSyntax(string strIn);
};
void arrayLL::checkSyntax(string strIn){
    int strSize=strIn.length();
    for(int i=0;i<strSize;i++){
        if(strIn[i]=='('){
            arrLL[0]->push('(');
        }
        else if(strIn[i]=='['){
            arrLL[1]->push('[');
        }
        if(strIn[i]==')'){
            if(!arrLL[0]->isEmpty()){
                arrLL[2]->push(arrLL[0]->pop());
            }
            else{
                cout<<"False."<<endl;
                return ;
            }
        }
        else if(strIn[i]==']'){
            if(!arrLL[1]->isEmpty()){
                arrLL[3]->push(arrLL[1]->pop());
            }
            else{
                cout<<"False."<<endl;
                return ;
            }
        } 
    }
}
//------------------------- main
int main(){
    arrayLL *myArrLL=new arrayLL();
    myArrLL->checkSyntax("(5+5))");
}