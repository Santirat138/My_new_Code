#include<iostream>
using namespace std;
//---------------- class
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
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        linkList();  
        void linkNode(node *node1, node *node2);
        void addFirst(int newNum);
        void addLast(int newNum);
        node *findNode(int targNum);
        void addBefore(int targId, int newNum);
        void addAfter(int targId, int newNum);
        void deleteNode(int targId);
        void showLL();
        bool isSameNum(int numIn);
        void mainFunc();
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(-1);
}
void linkList::linkNode(node *node1, node *node2){
    node1->right=node2;
    node2->left=node1;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        linkNode(newNode, head);
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        linkNode(tail, newNode);
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
node *linkList::findNode(int targNum){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        if(currNode->num==targNum){
            return currNode;
        }
    }
    return nullNode;
}
void linkList::addBefore(int targId, int newNum){
    node *targNode=findNode(targId);
    if(targNode!=nullNode){
        if(targNode==head){
            addFirst(newNum);
        }
        else{
            node *leftNode=targNode->left;
            node *newNode=new node(newNum);
            linkNode(newNode, targNode);
            linkNode(leftNode, newNode);
        }
    }
    else{
        addLast(newNum);
    }
    showLL();
}
void linkList::addAfter(int targId, int newNum){
    node *targNode=findNode(targId);
    if(targNode!=nullNode){
        if(targNode==tail){
            addLast(newNum);
        }
        else{
            node *rightNode=targNode->right;
            node *newNode=new node(newNum);
            linkNode(newNode, rightNode);
            linkNode(targNode, newNode);
        }
    }
    else{
        addLast(newNum);
    }
    showLL();
}
void linkList::deleteNode(int targId){
    node *targNode=findNode(targId);
    if((head!=tail)&&(head!=NULL)&&(tail!=NULL)){
        if(targNode!=nullNode){
            if((targNode==head)&&(targNode!=tail)){
                head=head->right;
                head->left=NULL;
                targNode->right=NULL;
            }
            else if((targNode!=head)&&(targNode==tail)){
                tail=tail->left;
                tail->right=NULL;
                targNode->left=NULL;
            }
            else{
                node *leftNode=targNode->left;
                node *rightNode=targNode->right;
                linkNode(leftNode, rightNode);
                targNode->left=NULL;
                targNode->right=NULL;
            }
            showLL();
        }
    }
    else{

    }
}
void linkList::showLL(){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        cout<<currNode->num<<" ";
    }
    cout<<endl;
}
bool linkList::isSameNum(int numIn){
    node *currNode=findNode(numIn);
    if(currNode==nullNode){
        return false;
    }
    else{
        return true;
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
            if(!isSameNum(newNum)){
                addAfter(targNum, newNum);
            }
        }
        else if(chIn=='I'){
            cin>>newNum>>targNum;
            if(!isSameNum(newNum)){
                addBefore(targNum, newNum);
            }
        }
        else if(chIn=='D'){
            cin>>targNum;
            deleteNode(targNum);
        }
        
    }
    while(chIn!='E');
}
//---------------- functions

//---------------- main
int main(){
    linkList *ll=new linkList();
    ll->mainFunc();
}