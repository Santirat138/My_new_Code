#include<iostream>
#include<vector>
using namespace std;
//--------------- link list ---------------
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
//--------------- link list ---------------
class linkList{
    public:
        node *head;
        node **headRef;
        node *nullNode;
        linkList();
        void addFirst(int newNum);
        void showLL(node *currNode);
        node *findPrevNode(node *nodeIn);
        void addSort(int newNum);
        node *findNode(int targNum);
        void deleteNode(node *targNode);
        void deleteNum(int numIn);
};
linkList::linkList(){
    head=NULL;
    headRef=&head;
    nullNode=new node(-1);
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->right=*headRef;
    }
    *headRef=newNode;
}
void linkList::showLL(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showLL(currNode->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
node *linkList::findPrevNode(node *nodeIn){
    if(nodeIn!=nullNode){
        if(nodeIn==*headRef){
            return nullNode;
        }
        else{
            node *prevNode=head;
            while(prevNode!=NULL){
                if(prevNode->right=nodeIn){
                    return prevNode;
                }
                else{
                    prevNode=prevNode->right;
                }
            }
        }
    }
    else{
        cout<<"Can't find prevNode."<<endl;
    }
    return nullNode;
}
void linkList::addSort(int newNum){
    node *newNode=new node(newNum);
    node *compNode=head;
    if(head==NULL){
        head=newNode;
    }
    else if((head!=NULL)&&(head->right==NULL)){
        if(newNum<head->num){
            addFirst(newNum);
        }
        else if(newNum>head->num){
            head->right=newNode;
        }
    }
    else{
        while((compNode!=NULL)&&(compNode->right!=NULL)){
            if((newNum>compNode->num)&&(newNum<compNode->right->num)){
                newNode->right=compNode->right;
                compNode->right=newNode;
                break;
            }
            else if((newNum<compNode->num)&&(newNum<compNode->right->num)){
                node *prevNode=findPrevNode(compNode);
                newNode->right=compNode;
                prevNode->right=newNode;
                break;
            }
            else if((newNum>compNode->num)&&(newNum>compNode->right->num)){
                compNode=compNode->right;
            }
        }
        if(compNode->right==NULL){
            compNode->right=newNode;
        }
    }
}
node *linkList::findNode(int targNum){
    node *currNode=head;
    while(currNode!=NULL){
        if(currNode->num==targNum){
            break;
        }
        else{
            currNode=currNode->right;
        }
    }
    return currNode;
}
void linkList::deleteNode(node *targNode){
    if((targNode!=nullNode)&&(targNode!=NULL)){
        if((targNode==head)&&(targNode->right==NULL)){
            head=NULL;
        }
        else if((targNode==head)&&(targNode->right!=NULL)){
            *headRef=targNode->right;
            targNode->right=NULL;
        }
        else if((targNode!=head)&&(targNode->right==NULL)){
            node *prevNode=findPrevNode(targNode);
            prevNode->right=NULL;
        }
        else if((targNode!=head)&&(targNode->right!=NULL)){
            node *prevNode=findPrevNode(targNode);
            prevNode->right=targNode->right;
            targNode->right=NULL;
        }
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
void linkList::deleteNum(int numIn){
    node *delNode=findNode(numIn);
    deleteNode(delNode);
}
//--------------- array ---------------
int size;
vector<linkList*> array;
void createArray(){
    for(int i=0;i<size;i++){
        array.push_back(new linkList());
    }
}
int findKey(int numIn){
    return numIn%size;
}
void insertArray(int newNum){
    int key=findKey(newNum);
    array[key]->addSort(newNum);
}
void showArray(){
    for(int i=0;i<size;i++){
        array[i]->showLL(array[i]->head);
    }
}
void deleteNumInArray(int numIn){
    int key=findKey(numIn);
    array[key]->deleteNum(numIn);
}
int findLLSum(int idx){
    node *currNode=array[idx]->head;
    int sum=0;
    while(currNode!=NULL){
        sum=sum+currNode->num;
        currNode=currNode->right;
    }
    return sum;
}
void showAllSum(){
    for(int i=0;i<size;i++){
        cout<<findLLSum(i)<<endl;
    }
}
