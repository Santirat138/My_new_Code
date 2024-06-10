#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
};
struct infoNode{
    int max;
    int min;
    float avg;
    int sum;
};
int amount=0;
void addAtHead(node **headRef, node **tailRef, int newNum);
bool isNumTrue(node **headRef, int targetNum);
void showAll(node **headRef, node **tailRef);
void connectNode(node *node1, node *node2);
node *findNum(node **headRef, int num);
void deleteNum(node **headRef, node **tailRef, int target);
node *findPrevNum(node **headRef, int num);
node *findNextNum(node **headRef, int num);
void onlyNum(node **headRef, node **tailRef, int num);
void emptyNode(node **headRef, node **tailRef);
void swapNum(node **headRef, node **tailRef, int num1, int num2);
node *findPos(node **headRef, int pos);
void addAtPos(node **headRef, node **tailRef, int posBef, int posAft, int newNum);
void deletePos(node **headRef, node **tailRef, int pos);
void swapPos(node **headRef, node **tailRef, int pos1, int pos2);
struct infoNode findMaxNum(node **headRef);  // Show position
struct infoNode findMinNum(node **headRef);  // Show position
struct infoNode sumNode(node **headRef);
void bbSort(node **headRef);
struct infoNode avgNum(node **headRef);
// Stack
void push(node **topRef, int newNum);
node *pop(node **topRef);
// Queue
void enqueue(node **firstRef, node **lastRef, int newNum);
int main(){
    node *head=NULL;
    node **head_ref=&head;
    node *tail=NULL;
    node **tail_ref=&tail;
    node *top=NULL;
    node **top_ref=&top;
    node *first=NULL;
    node **first_ref=&first;
    node *last=NULL;
    node **last_ref=&last;
    int i;
    for(i=0;i<5;i++){
        addAtHead(head_ref, tail_ref, i);
    }
    showAll(head_ref, tail_ref);
    bbSort(head_ref);
    showAll(head_ref, tail_ref);
    cout<<endl<<endl<<"Stack"<<endl;
    for(i=6;i<11;i++){
        push(top_ref, i);
    }
    node *test;
    while(*top_ref!=NULL){
        test=pop(top_ref);
        cout<<test->num<<" ";
    }
}
void addAtHead(node **headRef, node **tailRef, int newNum){
    if(isNumTrue(headRef, newNum)){
        node *newNode=new node();
        newNode->num=newNum;
        if((*headRef==NULL)||(*tailRef==NULL)){
            *headRef=newNode;
            *tailRef=newNode;
        }
        else{
            connectNode(newNode, *headRef);
            *headRef=newNode;
        }
        amount++;
    }
    else{
        cout<<"Can't add number "<<newNum<<endl;
    }
}
bool isNumTrue(node **headRef, int targetNum){
    node *checkNode=*headRef;
    bool status=true;
    while(checkNode!=NULL){
        if(checkNode->num==targetNum){
            status=false;
            break;
        }
        else{
            status=true;
            checkNode=checkNode->next;
        }
    }
    return status;
}
void showAll(node **headRef, node **tailRef){
    node *startNode=*headRef;
    node *endNode=*tailRef;
    cout<<"Head --> Tail"<<endl;
    while(startNode!=NULL){
        cout<<startNode->num<<" ";
        startNode=startNode->next;
    }
    cout<<endl<<"Tail --> Head"<<endl;
    while(endNode!=NULL){
        cout<<endNode->num<<" ";
        endNode=endNode->prev;
    }
    cout<<endl<<endl;
}
void connectNode(node *node1, node *node2){
    if(node1==NULL){
        cout<<"Node1 is NULL";
    }
    else if(node2==NULL){
        cout<<"Node2 is NULL";
    }
    else{
        node1->next=node2;
        node2->prev=node1;
    }
}
node *findNum(node **headRef, int num){
    node *targetNum=*headRef;
    bool result;
    while(targetNum!=NULL){
        if(targetNum->num==num){
            result=true;
            break;
        }
        else{
            targetNum=targetNum->next;
            result=false;
        }
    }
    if(!result){
        targetNum=NULL;
        cout<<"Can't found "<<num<<endl;
    }
    return targetNum;
}
void deleteNum(node **headRef, node **tailRef, int target){
    node *deleteNode=findNum(headRef, target);
    node *prevNode;
    node *nextNode;
    if(deleteNode==NULL){
        cout<<"Can't delete number "<<target<<endl;
    }
    else{
        if(deleteNode==*headRef){
            *headRef=deleteNode->next;
            (*headRef)->prev=NULL;
            deleteNode->next=NULL;
        }
        else if(deleteNode==*tailRef){
            prevNode=findPrevNum(headRef, target);
            *tailRef=prevNode;
            (*tailRef)->next=NULL;
            deleteNode->prev=NULL;
        }
        else if((deleteNode!=*headRef)&&(deleteNode!=*tailRef)){
            nextNode=findNextNum(headRef, target);
            prevNode=findPrevNum(headRef, target);
            connectNode(prevNode, nextNode);
            deleteNode->prev=NULL;
            deleteNode->next=NULL;
        }
        amount--;
    }
}
node *findPrevNum(node **headRef, int num){
    node *prevNode=*headRef;
    node *targetNode=*headRef;
    bool result=true;
    if((*headRef)->next==NULL){
        result=false;
    }
    else{
        while(targetNode!=NULL){
            targetNode=targetNode->next;
            if(targetNode->num==num){
                result=true;
                break;
            }
            else{
                prevNode=targetNode;
                result=false;
            }
        }
    }
    if(!result){
        prevNode=NULL;
    }
    return prevNode;
}
node *findNextNum(node **headRef, int num){
    node *targetNode=*headRef;
    node *nextNode;
    bool result=true;
    if((*headRef)->next==NULL){
        result=false;
    }
    else{
        while(targetNode->next!=NULL){
            if(targetNode->num==num){
                nextNode=targetNode->next;
                result=true;
                break;
            }
            else{
                targetNode=targetNode->next;
                result=false;
            }
        }
    }
    if(!result){
        nextNode=NULL;
    }
    return nextNode;
}
void onlyNum(node **headRef, node **tailRef, int num){
    node *keepNode=findNum(headRef, num);
    if(keepNode==NULL){
        cout<<"Can't keep number "<<num<<endl;
    }
    else{
        *headRef=keepNode;
        *tailRef=keepNode;
        (*headRef)->next=NULL;
        (*tailRef)->prev=NULL;
    }
    amount=1;
}
void emptyNode(node **headRef, node **tailRef){
    *headRef=NULL;
    *tailRef=NULL;
    cout<<"Now node is empty."<<endl;
    showAll(headRef, tailRef);
    amount=0;
}
void swapNum(node **headRef, node **tailRef, int num1, int num2){
    node *node1=findNum(headRef, num1);
    node *node2=findNum(headRef, num2);
    if((node1->next==node2)&&(node2->prev==node1)){
        if(node1==*headRef){
            node *nextNode2=findNextNum(headRef, num2);
            connectNode(node1, nextNode2);
            connectNode(node2, node1);
            node2->prev=NULL;
            *headRef=node2;
        }
        else if(node2==*tailRef){
            node *prevNode1=findPrevNum(headRef, num1);
            connectNode(prevNode1, node2);
            connectNode(node2, node1);
            node1->next=NULL;
            *tailRef=node1;
        }
        else if((node1!=*headRef)&&(node2!=*tailRef)){
            node *prevNode1=findPrevNum(headRef, num1);
            node *nextNode2=findNextNum(headRef, num2);
            connectNode(prevNode1, node2);
            connectNode(node2, node1);
            connectNode(node1, nextNode2);
        }
    }
    else{
        cout<<"Can't swap number "<<num1<<" and "<<num2<<endl;
    }
}
node *findPos(node **headRef, int pos){
    node *targetNode=*headRef;
    int walk=0;
    if(pos>amount){
        pos=amount;
    }
    else if(pos<=0){
        pos=1;
    }
    while(true){
        if(walk==pos-1){
            cout<<"Found number "<<targetNode->num;
            cout<<" at position "<<pos<<" ,walk "<<walk<<" steps."<<endl;
            break;
        }
        else if(walk<pos-1){
            targetNode=targetNode->next;
            walk++;
        }
        else{
            cout<<"Can't find number at position "<<pos<<"."<<endl;
        }
    }
    return targetNode;
}
void addAtPos(node **headRef, node **tailRef, int posBef, int posAft, int newNum){
    if(isNumTrue(headRef, newNum)){
        node *newNode=new node();
        newNode->num=newNum;
        int walk=0;
        if((posBef<=0)&&(posAft==1)){
            posBef=0;
            connectNode(newNode, *headRef);
            *headRef=newNode;
        }
        else if((posBef==amount)&&(posAft>amount)){
            posAft=amount;
            connectNode(*tailRef, newNode);
            *tailRef=newNode;
        }
        else if((posBef>=1)&&(posAft<amount)){
            node *tempPrev=*headRef;
            node *tempNext;
            while(walk<=amount){
                if(walk==posBef-1){
                    tempNext=tempPrev->next;
                    connectNode(tempPrev, newNode);
                    connectNode(newNode, tempNext);
                    break;
                }
                else{
                    tempPrev=tempPrev->next;
                    walk++;
                }
            }
        }
        amount--;
    }
    else{
        cout<<"Can't add number "<<newNum<<"."<<endl;
    }
}
void deletePos(node **headRef, node **tailRef, int pos){
    node *prevTempNode;
    node *tempNode=*headRef;
    node *nextTempNode;
    int walk=0;
    if(pos<1){
        pos=1;
    }
    else if(pos>amount){
        pos=amount;
    }
    while(walk<pos){
        if(walk==pos-1){
            if(tempNode==*headRef){
                nextTempNode=tempNode->next;
                *headRef=nextTempNode;
                nextTempNode->prev=NULL;
                tempNode->next=NULL;
            }
            else if(tempNode==*tailRef){
                prevTempNode=tempNode->prev;
                *tailRef=prevTempNode;
                prevTempNode->next=NULL;
                tempNode->prev=NULL;
            }
            else if((tempNode!=*headRef)&&(tempNode!=*tailRef)){
                prevTempNode=tempNode->prev;
                nextTempNode=tempNode->next;
                connectNode(prevTempNode, nextTempNode);
                tempNode->prev=NULL;
                tempNode->next=NULL;
            }
            amount--;
            break;
        }
        else{
            tempNode=tempNode->next;
            walk++;
        }
    }
}
void swapPos(node **headRef, node **tailRef, int pos1, int pos2){
    int walk1=0;    // For pos1
    int walk2=0;    // For pos2
    bool statusPos1;
    bool statusPos2;
    node *temp1=*headRef;
    node *temp2=*headRef;
    node *checkNum1;
    node *checkNum2;
    if((pos1<1)||(pos2<2)){
        cout<<"Pos1 must > 0."<<endl;
        cout<<"Pos2 must > 2."<<endl;
    }
    else if((pos1>amount-1)||(pos2>amount)){
        cout<<"Pos1 must < amount."<<endl;
        cout<<"Pos2 must <= amount."<<endl;
    }
    else if((pos1>1)&&(pos1<amount)&&(pos2>1)&&(pos2<amount)){
        while(walk1<pos1){
            if(walk1==pos1-1){
                statusPos1=true;
                break;
            }
            else{
                statusPos1=false;
                temp1=temp1->next;
                walk1++;
            }
        }
        while(walk2<pos2){
            if(walk2==pos2-1){
                statusPos2=true;
                break;
            }
            else{
                statusPos2=false;
                temp2=temp2->next;
                walk2++;
            }
        }
        if((statusPos1)&&(statusPos2)){
            node *prevTemp1=temp1->prev;
            node *nextTemp2=temp2->next;
            checkNum1=findPos(headRef, pos1);
            checkNum2=findPos(headRef, pos2);
            cout<<"Swap number "<<checkNum1->num<<" and "<<checkNum2->num<<"."<<endl;
            if(temp1==*headRef){
                *headRef=temp2;
                connectNode(temp1, nextTemp2);
                connectNode(temp2, temp1);
                temp2->prev=NULL;
            }
            else if(temp2==*tailRef){
                *tailRef=temp1;
                connectNode(prevTemp1, temp2);
                connectNode(temp2, temp1);
                temp1->next=NULL;
            }
            else if((temp1!=*headRef)&&(temp2!=*tailRef)){
                connectNode(prevTemp1, temp2);
                connectNode(temp2, temp1);
                connectNode(temp1, nextTemp2);
            }
        }
        else{
            cout<<"Can't swap."<<endl;
        }
    }
    else if((pos1==1)&&(pos2==amount)){
        temp1=*headRef;
        temp2=*tailRef;
        node *nextTemp1=temp1->next;
        node *prevTemp2=temp2->prev;
        connectNode(temp2, nextTemp1);
        temp2->prev=NULL;
        connectNode(prevTemp2, temp1);
        temp1->next=NULL;
        *headRef=temp2;
        *tailRef=temp1;
    }
    else{
        cout<<"Can't swap."<<endl;
    }
}
struct infoNode findMaxNum(node **headRef){
    struct infoNode number;
    node *currNode=*headRef;
    node *maxNode=*headRef;
    while(currNode!=NULL){
        if(maxNode->num<(currNode->next)->num){
            maxNode->num=(currNode->next)->num;
        }
        currNode=currNode->next;
    }
    number.max=maxNode->num;
    return number;
}
struct infoNode findMinNum(node **headRef){
    struct infoNode number;
    node *minNode=*headRef;
    node *tempNode=*headRef;
    while(tempNode!=NULL){
        if((minNode->num)>(tempNode->num)){
            minNode=tempNode;
        }
        tempNode=tempNode->next;
    }
    number.min=minNode->num;
    return number;
}
struct infoNode sumNode(node **headRef){
    node *startNode=*headRef;
    struct infoNode number;
    while(startNode!=NULL){
        number.sum=startNode->num+number.sum;
        startNode=startNode->next;
    }
    return number;
}
void bbSort(node **headRef){
    bool status;
    int temp;
    node *currNode=NULL;
    node *sortedNode=NULL;
    cout<<" Bubble sort"<<endl;
    do{
        currNode=*headRef;
        status=false;
        while(currNode->next!=sortedNode){
            if(currNode->num>(currNode->next)->num){
                temp=currNode->num;
                currNode->num=(currNode->next)->num;
                (currNode->next)->num=temp;
                status=true;
            }
            currNode=currNode->next;
        }
        sortedNode=currNode;
    }
    while(status);
    status=false;
    currNode=NULL;
    sortedNode=NULL;
    do{
        currNode=*headRef;
        status=false;
        while(currNode->next!=sortedNode){
            if(currNode->num>(currNode->next)->num){
                temp=currNode->num;
                currNode->num=(currNode->next)->num;
                (currNode->next)->num=temp;
                status=true;
            }
            currNode=currNode->next;
        }
        sortedNode=currNode;
    }
    while(status);
}
struct infoNode avgNum(node **headRef){
    struct infoNode number;
    number=sumNode(headRef);
    number.avg=number.sum/amount;
    return number;
}
// Stack
void push(node **topRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if(*topRef!=NULL){
        newNode->next=*topRef;
    }
    *topRef=newNode;
}
node *pop(node **topRef){
    if(*topRef!=NULL){
        node *temp=*topRef;
        *topRef=(*topRef)->next;
        return temp;
    }
    else{
        return NULL;
    }
}
// queue
void enqueue(node **firstRef, node **lastRef, int newNum){
    node *newNode=new node();
    newNode->num=newNum;
    if((*firstRef!=NULL)&&(*lastRef!=NULL)){
        (*lastRef)->next=newNode;
    }
    else{
        *firstRef=newNode;
    }
    *lastRef=newNode;
}
node *dequeue(node **firstRef, node **lastRef){
    if((*firstRef!=NULL)&&(*lastRef!=NULL)){
        node *temp=*firstRef;
        *firstRef=(*firstRef)->next;
        temp->next=NULL;
        return temp;
    }
    else{
        return NULL;
    }
}