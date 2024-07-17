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
    void addFirst(int newNum);
    void addLast(int newNum);
    void showLL();
    void addSort(int newNum);
    node *findNode(int targNum);
    node *findMidNode();
    void countNode(node *currNode, int currAmount);
    node *findNodeAtPos(int posIn);
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
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        connectNode(newNode, head);
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        connectNode(tail, newNode);
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::showLL(){
    node *currNode=head;
    int ticket=2;
    if(currNode!=NULL){
        while(currNode!=tail){
            cout<<currNode->num<<" ";
            currNode=currNode->right;
        }
        cout<<tail->num<<" || ";
        while(currNode!=head){
            cout<<currNode->num<<" ";
            currNode=currNode->left;
        }
        cout<<head->num<<" End."<<endl;
    }
    else{
        cout<<"NULL"<<endl;
    }
}
void linkList::addSort(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
        tail=newNode;
    }
    else{
        node *compNode=head;
        while(compNode!=NULL){
            if(compNode==tail){
                if(newNum>tail->num){
                    addLast(newNum);
                    break;
                }
                else{
                    cout<<"Error."<<endl;
                    break;
                }
            }
            else{
                if((newNum<compNode->num)&&(newNum<compNode->right->num)){
                    addFirst(newNum);
                    break;
                }
                else if((newNum>compNode->num)&&(newNum<compNode->right->num)){
                    connectNode(newNode, compNode->right);
                    connectNode(compNode, newNode);
                    break;
                }
                else if((newNum>compNode->num)&&(newNum>compNode->right->num)){
                    compNode=compNode->right;
                }
            }
        }
    }
}
node *linkList::findNode(int targNum){
    node *currNode;

}
node *linkList::findMidNode(){
    node *currNode;
    int midPos;
    countNode(head, 0);
    midPos=amount/2;
    currNode=findNodeAtPos(midPos);
    
}
void linkList::countNode(node *currNode, int currAmount){
    if(currNode!=NULL){
        countNode(currNode->right, amount+1);
    }
    else{
        amount=currAmount;
    }
}
node *linkList::findNodeAtPos(int posIn){
    node *currNode=head;
    int currPos=1;
    countNode(head, 0);
    if(currNode!=NULL){
        while(currPos<=amount){
            currNode=currNode->right;
            currPos++;
        }
    }
    else{
        currNode=nullNode;
    }
    return currNode;
}
