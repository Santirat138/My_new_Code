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
        return nullNode;
    }
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
    array[key]->addFirst(newNum);
}
void showArray(){
    for(int i=0;i<size;i++){
        array[i]->showLL(array[i]->head);
    }
}