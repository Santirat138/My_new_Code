// Test link list
#include<iostream>
using namespace std;

//------------------- class -------------------
class node{
    public:
        int num;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    right=NULL;
}
node *nullNode=new node(-1);
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addFirst(int newNum);
        void addLast(int newNum);
        void showLL();
        node *findNode(int targNum);
        node *findPrevNode(int targNum);
        void deleteNode(int targNum);
        void insertAft(int newNum, int targNum);
        void insertBef(int newNum, int targNum);
        void mainFunc();
};
linkList::linkList(){
    head=nullptr;
    tail=nullptr;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=nullptr){
        newNode->right=head;
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=nullptr){
        tail->right=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::showLL(){
    node *currNode=head;
    while(currNode!=nullptr){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<endl;
}
node *linkList::findNode(int targNum){
    node *currNode=head;
    while(currNode!=nullptr){
        if(currNode->num==targNum){
            return currNode;
        }
        else{
            currNode=currNode->right;
        }
    }
    return nullNode;
}
node *linkList::findPrevNode(int targNum){
    node *targNode=findNode(targNum);
    if(targNode!=nullNode){
        node *currNode=head;
        while(currNode!=nullptr){
            if(currNode->right=targNode){
                return currNode;
            }
            else{
                currNode=currNode->right;
            }
        }
    }
    else{
        return nullNode;
    }
}
void linkList::deleteNode(int targNum){
    node *delNode=findNode(targNum);
    if(delNode!=nullNode){
        if((delNode==head)&&(delNode==tail)){
            head=nullptr;
            tail=nullptr;
        }
        else if((delNode==head)&&(delNode!=tail)){
            head=head->right;
            delNode->right=nullptr;
        }
        else if((delNode!=head)&&(delNode!=tail)){
            node *leftNode=findPrevNode(targNum);
            leftNode->right=delNode->right;
            delNode->right=nullptr;
        }
        else if((delNode!=head)&&(delNode==tail)){
            tail=findPrevNode(tail->num);
            tail->right=nullptr;
        }
        
    }
    else{

    }
}
void linkList::insertAft(int newNum, int targNum){
    node *newNode=new node(newNum);
    node *targNode=findNode(targNum);
    if(targNode!=nullNode){
        if(targNode!=tail){
            node *rightNode=targNode->right;
            newNode->right=rightNode;
            targNode->right=newNode;
        }
        else{
            addLast(newNum);
        }
    }
    else{
        addLast(newNum);
    }
    showLL();
}
void linkList::insertBef(int newNum, int targNum){
    node *newNode=new node(newNum);
    node *targNode=findNode(targNum);
    if(targNode!=nullNode){
        if(targNode!=head){
            node *leftNode=findPrevNode(targNum);
            newNode->right=targNode;
            leftNode->right=newNode;
        }
        else{
            addFirst(newNum);
        }
    }
    else{
        addLast(newNum);
    }
    
}
void linkList::mainFunc(){
    char chIn;
    int newNum;
    int targNum;
    do{
        cin>>chIn;
        if(chIn=='A'){
            cin>>newNum>>targNum;
            insertAft(newNum, targNum);
        }
        else if(chIn=='I'){
            cin>>newNum>>targNum;
            insertBef(newNum, targNum);
        }
        else if(chIn=='D'){
            cin>>targNum;
            deleteNode(targNum);
        }
        showLL();
    }
    while(chIn!='E');
}
//------------------- main -------------------
int main(){
    linkList *list=new linkList();
    list->mainFunc();
}