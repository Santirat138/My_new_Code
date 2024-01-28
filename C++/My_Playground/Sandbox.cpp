#include<iostream>
#define nullNum -1
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
        node(int numIn);
};
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        node *midNode;
        int nodeAmount;
        linkList();
        void connectNode(node *n1, node *n2);
        void addMinMax(int newNum, node *compNode);
        void showH(node *currNode);
        void showT(node *currNode);
        void showList();
        void countNode(node *currNode, int amount);
        void findMid();
        node *findNum(int numIn);
        void deleteNum(int numIn);
        node *findPos(node *currNode, int currPos, int posIn);
};
class stack{
    public:
        node *top;
        stack();
        void push(int newNum);
        int pop();
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(nullNum);
}
void linkList::connectNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void linkList::addMinMax(int newNum, node *compNode){
    if((head==NULL)||(tail==NULL)){
        head=new node(newNum);
        tail=head;
    }
    else if((compNode==head)&&(compNode==tail)){
        node *newNode=new node(newNum);
        if(newNum<compNode->num){
            connectNode(newNode, head);
            head=newNode;
        }
        else if(newNum>compNode->num){
            connectNode(tail, newNode);
            tail=newNode;
        }
    }
    else if(compNode!=tail){
        if((newNum<compNode->num)&&(newNum<compNode->next->num)){
            node *newNode=new node(newNum);
            connectNode(newNode, head);
            head=newNode;
        }
        else if((newNum>compNode->num)&&(newNum<compNode->next->num)){
            node *newNode=new node(newNum);
            connectNode(newNode, compNode->next);
            connectNode(compNode, newNode);
        }
        else if((newNum>compNode->num)&&(newNum>compNode->next->num)){
            addMinMax(newNum, compNode->next);
        }
    }
    else if(compNode==tail){
        node *newNode=new node(newNum);
        if(newNum<compNode->num){
            connectNode(compNode->prev, newNode);
            connectNode(newNode, compNode);
        }
        else if(newNum>compNode->num){
            connectNode(tail, newNode);
            tail=newNode;
        }
    }
}
void linkList::showH(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showH(currNode->next);
    }
}
void linkList::showT(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showT(currNode->prev);
    }
}
void linkList::showList(){
    showH(head);
    showT(tail);
    cout<<endl;
}
void linkList::countNode(node *currNode, int amount){
    if(currNode==NULL){
        nodeAmount=amount;
    }
    else{
        countNode(currNode->next, amount+1);
    }
}
// Can make it to recursive?
void linkList::findMid(){
    node *n1=head;
    node *n2=head;
    int step1=0;
    int step2=0;
    while(n1!=NULL){
        n2=n1;
        step2=0;
        while(n2!=NULL){
            n2=n2->next;
            step2++;
        }
        if(step2-step1<=1){
            midNode=n1;
            break;
        }
        else{
            n1=n1->next;
            step1++;
        }
    }
}
node *linkList::findNum(int numIn){
    findMid();
    node *currNode=midNode;
    if(numIn<midNode->num){
        while(currNode!=NULL){
            if(currNode->num==numIn){
                return currNode;
            }
            else{
                currNode=currNode->prev;
            }
        }
    }
    else if(numIn>midNode->num){
        while(currNode!=NULL){
            if(currNode->num==numIn){
                return currNode;
            }
            else{
                currNode=currNode->next;
            }
        }
    }
    else if(numIn==midNode->num){
        return currNode;
    }
    return nullNode;
}
void linkList::deleteNum(int numIn){
    node *delNode=findNum(numIn);
    if(delNode!=nullNode){
        if(head==tail){
            head=NULL;
            tail=NULL;
        }
        else{
            if(delNode==head){
                head=head->next;
                head->prev=NULL;
                delNode->next=NULL;
            }
            else if(delNode==tail){
                tail=tail->prev;
                tail->next=NULL;
                delNode->prev=NULL;
            }
            else{
                connectNode(delNode->prev, delNode->next);
                delNode->prev=NULL;
                delNode->next=NULL;
            }
        }
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
node *linkList::findPos(node *currNode, int currPos, int posIn){
    if(currNode==NULL){
        return nullNode;
    }
    else{
        if(currPos==posIn){
            return currNode;
        }
        else{
            findPos(currNode->next, currPos+1, posIn);
        }
    }
}
stack::stack(){
    top=NULL;
}
void stack::push(int newNum){
    node *newNode=new node(newNum);
    if(top!=NULL){
        newNode->next=top;
    }
    top=newNode;
}
int stack::pop(){
    node *temp=top;
    top=top->next;
    temp->next=NULL;
    return temp->num;
}
int main(){
    linkList *list1=new linkList();
    list1->addMinMax(5, list1->head);
    list1->addMinMax(50, list1->head);
    list1->addMinMax(2, list1->head);
    list1->addMinMax(45, list1->head);
    list1->addMinMax(4, list1->head);
    list1->showList();
    list1->deleteNum(2);
    list1->showList();
}