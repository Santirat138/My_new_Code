// Double linkList
#include<iostream>
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
        int amount;

        linkList();
        void connectNode(node *n1, node *n2);
        void addSort(int newNum, node *compNode);
        void showH(node *currNode);
        void showT(node *currNode);
        void showLL();
        // Search number by use divide linklist left for min number, right for max number.
        void findMidNode(node *currNode, int currPos);
        node *findNum(int numIn);
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(-1);
}
void linkList::connectNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void linkList::addSort(int newNum, node *compNode){
    if((head==NULL)&&(tail==NULL)){
        node *newNode=new node(newNum);
        head=newNode;
        tail=newNode;
        amount=1;
    }
    else if(head==tail){
        node *newNode=new node(newNum);
        if(newNum<head->num){
            connectNode(newNode, head);
            head=newNode;
        }
        else if(newNum>head->num){
            connectNode(tail, newNode);
            tail=newNode;
        }
        amount=2;
    }
    else{
        if(compNode!=tail){
            if((newNum<compNode->num)&&(newNum<compNode->next->num)){
                node *newNode=new node(newNum);
                connectNode(newNode, head);
                head=newNode;
                amount++;
            }
            else if((newNum>compNode->num)&&(newNum<compNode->next->num)){
                node *newNode=new node(newNum);
                connectNode(newNode, compNode->next);
                connectNode(compNode, newNode);
                amount++;
            }
            else if((newNum>compNode->num)&&(newNum>compNode->next->num)){
                addSort(newNum, compNode->next);
            }
        }
        else if(compNode==tail){
            node *newNode=new node(newNum);
            if(newNum<tail->num){
                connectNode(tail->prev, newNode);
                connectNode(newNode, tail);
            }
            else if(newNum>tail->num){
                connectNode(tail, newNode);
                tail=newNode;
            }
            amount++;
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
void linkList::showLL(){
    showH(head);
    showT(tail);
}
void linkList::findMidNode(node *currNode, int currPos){
    int midPos;
    if(amount%2!=0){
        midPos=(1+amount)/2;
    }
    else if(amount%2==0){
        midPos=amount/2;
    }
    if(currPos==midPos){
        midNode=currNode;
    }
    else{
        findMidNode(currNode->next, currPos+1);
    }
}
node *linkList::findNum(int numIn){
    findMidNode(head, 1);
    node *currNode=midNode;
    while(currNode!=NULL){
        if(numIn!=currNode->num){
            if(numIn<midNode->num){
                currNode=currNode->prev;
            }
            else if(numIn>midNode->num){
                currNode=currNode->next;
            }
        }
        else if(numIn==currNode->num){
            return currNode;
        }
    }
    return nullNode;
}
int main(){
    linkList *list1=new linkList();
    list1->addSort(9, list1->head);
    list1->addSort(8, list1->head);
    list1->addSort(7, list1->head);
    list1->addSort(6, list1->head);
    list1->addSort(5, list1->head);
    list1->findMidNode(list1->head, 1);
    cout<<list1->findNum(6)->num;
}
