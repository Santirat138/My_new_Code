// Use methods recursive.
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
        linkList();
        void linkNode(node *node1, node *node2);
        void addFirst(int newNum);
        void addLast(int newNum);
        void showH(node *currNode);
        void showT(node *currNode);
        void showList();
        node *findNum(int target, node *currNode);
        void deleteNum(int target);
        void removeNum(int numIn);
        node *findPos(int posIn, int currPos, node *currNode);
        void addSort(int newNum);
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
void linkList::linkNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        linkNode(newNode, head);
    }
    else if(head==NULL){
        tail=newNode;
    }
    head=newNode;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        linkNode(tail, newNode);
    }
    else if(tail==NULL){
        head=newNode;
    }
    tail=newNode;
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
}
node *linkList::findNum(int target, node *currNode){
    if(currNode==NULL){
        return nullNode;
    }
    else{
        if(currNode->num==target){
            return currNode;
        }
        else if(currNode->num!=target){
            return findNum(target, currNode->next);
        }
    }
    return nullNode;
}
void linkList::deleteNum(int target){
    node *delNode=findNum(target, head);
    if((delNode==head)&&(delNode==tail)){
        head=NULL;
        tail=NULL;
    }
    else if((delNode==head)&&(delNode!=tail)){
        head=head->next;
        head->prev=NULL;
        delNode->next=NULL;
    }
    else if((delNode!=head)&&(delNode==tail)){
        tail=tail->prev;
        tail->next=NULL;
        delNode->prev=NULL;
    }
    else if((delNode!=head)&&(delNode!=tail)){
        linkNode(delNode->prev, delNode->next);
        delNode->prev=NULL;
        delNode->next=NULL;
    }
}
void linkList::removeNum(int numIn){
    node *currNode=head;
    while(currNode!=NULL){
        if(currNode->num==numIn){
            deleteNum(currNode->num);
            currNode=head;
        }
        else{
            currNode=currNode->next;
        }
    }
}
node *linkList::findPos(int posIn, int currPos, node *currNode){
    if(currPos==posIn){
        return currNode;
    }
    else{
        return findPos(posIn, currPos+1, currNode->next);
    }
}
void linkList::addSort(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
        tail=newNode;
    }
    else if(head==tail){
        if(newNum<head->num){
            addFirst(newNum);
        }
        else if(newNum>head->num){
            addLast(newNum);
        }
    }
    else{
        node *compare=head;
        while(compare!=NULL){
            if(compare!=tail){
                if(newNum<compare->num){
                    addFirst(newNum);
                    break;
                }
                else if((newNum>compare->num)&&(newNum<compare->next->num)){
                    linkNode(newNode, compare->next);
                    linkNode(compare, newNode);
                    break;
                }
                else if((newNum>compare->num)&&(newNum>compare->next->num)){
                    compare=compare->next;
                }
            }
            else if(compare==tail){
                if(newNum>compare->num){
                    linkNode(tail, newNode);
                    tail=newNode;
                }
                else if(newNum<compare->num){
                    linkNode(tail->prev, newNode);
                    linkNode(newNode, tail);
                }
                break;
            }
        }
    }
}
// -------------------- main --------------------
int main(){
    linkList *list=new linkList();
    list->addSort(10);
    list->addSort(5);
    list->addSort(25);
    list->addSort(20);
    list->showList();
}