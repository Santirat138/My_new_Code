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
        int amount;
        node *nullNode=new node(-1);
        node *head;
        node *tail;

        linkList(){
            amount=0;
            head=NULL;
            tail=NULL;
        }
        void connectNode(node *node1, node *node2);
        void addFirst(int newNum);
        void addLast(int newNum);
        void showHT(node *currNode);
        void showTH(node *currNode);
        void showList();
        node *findNode(node *currNode, int walk, int pos);
        node *findNum(node *currNode, int target);
        void deleteAt(int pos);
        void insertAt(int pos, int newNum);
        void swapNum(int num1, int num2);
        void swapNode(int pos1, int pos2);
        void sortMinMax();
            // New methods
        void addSortMinMax(int newNum);
        void addSortMaxMin(int newNum);
};
class stack{
    public:
        node *top;

        stack(int topNum);
        void push(int newNum);
        int pop();
};
class queue{
    public:
        node *firstNode;
        node *lastNode;

        queue(int firstNum);
        void enqueue(int newNum);
        int dequeue();
};
void linkList::connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        connectNode(newNode, head);
    }
    head=newNode;
    amount++;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
    }
    else{
        connectNode(tail, newNode);
    }
    tail=newNode;
    amount++;
}
void linkList::showHT(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showHT(currNode->next);
    }
}
void linkList::showTH(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showTH(currNode->prev);
    }
}
void linkList::showList(){
    cout<<endl<<endl<<"Head --> Tail.  ";
    showHT(head);
    cout<<endl;
    cout<<"Tail --> Head.  ";
    showTH(tail);
}
node *linkList::findNode(node *currNode, int walk, int pos){
    if(pos<1){
        pos=1;
    }
    else if(pos>amount){
        pos=amount;
    }
    if(currNode==NULL){
            return nullNode;
        }
    else{
        if(walk==pos-1){
            return currNode;
        }
        else{
            return findNode(currNode->next, walk+1, pos);
        }
    }
}
node *linkList::findNum(node *currNode, int target){
    if(currNode==NULL){
        return nullNode;
    }
    else{
        if(currNode->num==target){
            return currNode;
        }
        else{
            return findNum(currNode->next, target);
        }
    }
}
void linkList::deleteAt(int pos){
    node *delNode=findNode(head, 0, pos);
    if(delNode!=nullNode){
        if(delNode==head){
            head=delNode->next;
            head->prev=NULL;
            delNode->next=NULL;
        }
        else if(delNode==tail){
            tail=delNode->prev;
            tail->next=NULL;
            delNode->prev=NULL;
        }
        else if((delNode!=head)&&(delNode!=tail)){
            connectNode(delNode->prev, delNode->next);
            delNode->prev=NULL;
            delNode->next=NULL;
        }
        amount--;
    }
    else if(delNode==nullNode){
        cout<<"Can't delete."<<endl;
    }
}
void linkList::insertAt(int pos, int newNum){
    if(pos<=1){
        addFirst(newNum);
    }
    else if(pos>amount){
        addLast(newNum);
    }
    else{
        node *newNode=new node(newNum);
        node *currNode=findNode(head, 0, pos);
        node *prevNode=currNode->prev;
        connectNode(newNode, currNode);
        connectNode(prevNode, newNode);
    }
    amount++;
}
void linkList::swapNum(int num1, int num2){
    node *node1=findNum(head, num1);
    node *node2=findNum(head, num2);
    node *temp=new node(-1);
    temp->num=node1->num;
    node1->num=node2->num;
    node2->num=temp->num;
}
void linkList::swapNode(int pos1, int pos2){
    node *node1=findNode(head, 0, pos1);
    node *node2=findNode(head, 0, pos2);
    if((node1!=NULL)&&(node2!=NULL)&&(node1!=node2)){
        node *temp=new node(-1);
        temp->num=node1->num;
        node1->num=node2->num;
        node2->num=temp->num;
    }
    else{
        cout<<"Can't swap."<<endl;
    }
}
void linkList::sortMinMax(){
    node *currNode=head;
    node *lastNode=tail;
    while(lastNode!=head){
        while(currNode!=lastNode){
            if(currNode->num>currNode->next->num){
                swapNum(currNode->num, currNode->next->num);
            }
            currNode=currNode->next;
        }
        currNode=head;
        lastNode=lastNode->prev;
    }
}
void linkList::addSortMinMax(int newNum){
    node *newNode=new node(newNum);
    node *compNode=head;
    if(compNode==NULL){
        head=new node(newNum);
        tail=head;
    }
    else{
        while(compNode!=NULL){
            if((compNode==head)&&(compNode==tail)){
                if(newNum<compNode->num){
                    addFirst(newNum);
                }
                else if(newNum>compNode->num){
                    addLast(newNum);
                }
                break;
            }
            else{
                if((newNum<compNode->num)&&(newNum<compNode->next->num)){
                    addFirst(newNum);
                    break;
                }
                else if(newNum>compNode->num){
                    if(compNode!=tail){
                        if(newNum<compNode->next->num){
                            connectNode(newNode, compNode->next);
                            connectNode(compNode, newNode);
                            amount++;
                            break;
                        }
                        else{
                            compNode=compNode->next;
                        }
                    }
                    else if(compNode==tail){
                        addLast(newNum);
                        break;
                    }
                }
            }
        }
    }
}
void linkList::addSortMaxMin(int newNum){
    node *newNode=new node(newNum);
    node *compNode=head;
    if(compNode==NULL){
        head=new node(newNum);
        tail=head;
    }
    else{
        while(compNode!=NULL){
            if((compNode==head)&&(compNode==tail)){
                if(newNum<compNode->num){
                    addLast(newNum);
                }
                else if(newNum>compNode->num){
                    addFirst(newNum);
                }
                break;
            }
            else{
                if((newNum>compNode->num)&&(newNum>compNode->next->num)){
                    addFirst(newNum);
                    break;
                }
                else if(newNum<compNode->num){
                    if(compNode!=tail){
                        if(newNum>compNode->next->num){
                            connectNode(newNode, compNode->next);
                            connectNode(compNode, newNode);
                            amount++;
                            break;
                        }
                        else{
                            compNode=compNode->next;
                        }
                    }
                    else if(compNode==tail){
                        addLast(newNum);
                        break;
                    }
                }
            }
        }
    }
}
stack::stack(int topNum){
    top=new node(topNum);
}
void stack::push(int newNum){
    node *newNode=new node(newNum);
    newNode->next=top;
    top=newNode;
}
int stack::pop(){
    node *temp=top;
    if(top->next!=NULL){
        top=top->next;
        temp->next=NULL;
    }
    return temp->num;
}
queue::queue(int firstNum){
    firstNode=new node(firstNum);
    lastNode=firstNode;
}
void queue::enqueue(int newNum){
    node *newNode=new node(newNum);
    lastNode->next=newNode;
    lastNode=newNode;
}
int queue::dequeue(){
    node *temp=firstNode;
    firstNode=firstNode->next;
    temp->next=NULL;
    return temp->num;
}
int main(){
    
}
