#include<iostream>
using namespace std;
//---------------- Node ----------------
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
}
node *nullNode=new node(-1);
//---------------- Link list ----------------
class linkList{
    public:
        node *head;
        node *tail;
        int amount;
        linkList();
        void connectNode(node *node1, node *node2);
        node *nodeGoLeft(node *nodeIn);
        node *nodeGoRight(node *nodeIn);
        void addFirst(int newNum);
        void addLast(int newNum);
        void showLL(node *currNode, int ticket);
        void addSort(int newNum);
        node *findNodeAtPos(int targPos);
        void addAtPos(int newNum);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
    amount=0;
}
void linkList::connectNode(node *node1, node *node2){
    node1->right=node2;
    node2->left=node1;
}
node *linkList::nodeGoLeft(node *nodeIn){
    if((nodeIn==head)||(nodeIn==nullNode)||(nodeIn==nullptr)){
        return nullNode;
    }
    else{
        return nodeIn->left;
    }
}
node *linkList::nodeGoRight(node *nodeIn){
    if((nodeIn==tail)||(nodeIn==nullNode)||(nodeIn==nullptr)){
        return nullNode;
    }
    else{
        return nodeIn->right;
    }
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=nullptr){
        connectNode(newNode, head);
    }
    else{
        tail=newNode;
    }
    head=newNode;
    amount++;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=nullptr){
        connectNode(tail, newNode);
    }
    else{
        head=newNode;
    }
    tail=newNode;
    amount++;
}
void linkList::showLL(node *currNode, int ticket){
    if(ticket==2){
        if(currNode!=tail){
            cout<<currNode->num<<" ";
            currNode=nodeGoRight(currNode);
            ticket=2;
        }
        else if(currNode==tail){
            cout<<tail->num<<endl;
            ticket=1;
        }
        showLL(currNode, ticket);
    }
    else if(ticket==1){
        if(currNode!=head){
            cout<<currNode->num<<" ";
            currNode=nodeGoLeft(currNode);
            ticket=1;
        }
        else if(currNode==head){
            cout<<head->num<<endl;
            ticket=0;
        }
        showLL(currNode, ticket);
    }
    else if(ticket==0){
        cout<<"End"<<endl;
    }
    else{
        cout<<endl<<"Error"<<endl;
    }
}
void linkList::addSort(int newNum){
    node *newNode=new node(newNum);
    if((head==nullptr)&&(tail==nullptr)){
        head=newNode;
        tail=newNode;
        amount=1;
    }
    else if(head==tail){
        if(newNum>head->num){
            addLast(newNum);
        }
        else if(newNum<head->num){
            addFirst(newNum);
        }
    }
    else{
        node *compNode=head;
        while(compNode!=tail){   
            if((newNum<compNode->num)&&(newNum<compNode->right->num)){
                addFirst(newNum);
                break;
            }
            else if((newNum>compNode->num)&&(newNum<compNode->right->num)){
                connectNode(newNode, compNode->right);
                connectNode(compNode, newNode);
                amount++;
                break;
            }
            else if((newNum>compNode->num)&&(newNum>compNode->right->num)){
                compNode=nodeGoRight(compNode);
            }
        }
        if(compNode==tail){
            if(newNum>compNode->num){
                addLast(newNum);
            }
            else{
                cout<<"Error."<<endl;
            }
        }
    }
}
node *linkList::findNodeAtPos(int targPos){
    int currPos=1;
    node *currNode=head;
    while(currPos!=targPos){
        currNode=nodeGoRight(currNode);
        currPos++;
    }
    return currNode;
}
void linkList::addAtPos(int newNum){

}