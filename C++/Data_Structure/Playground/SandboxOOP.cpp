#include<iostream>
using namespace std;
//**************** node ****************
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int num);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
};
node *nullNode=new node(-1);
//**************** link list ****************
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addFirst(int newNum);
        void addLast(int newNum);
        void showLL(node *currNode);
        node *findPrevNode(node *currNode, node *targNode);
        node *findNodeByNum(node *currNode, int targNum);
        void deleteNode(node *targNode);
        void deleteNodeByNum(int targNum);
        void deleteAllNodeByNum(int targNum);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        newNode->right=head;
    }
    head=newNode;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
    }
    else{
        tail->right=newNode;
    }
    tail=newNode;
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
node *linkList::findPrevNode(node *currNode, node *targNode){
    if((targNode!=NULL)&&(targNode!=head)){
        if(currNode->right==targNode){
            return currNode;
        }
        else{
            return findPrevNode(currNode->right, targNode);
        }
    }
    else{
        return nullNode;
    }
}
node *linkList::findNodeByNum(node *currNode, int targNum){
    if(currNode!=NULL){
        if(currNode->num==targNum){
            return currNode;
        }
        else{
            return findNodeByNum(currNode->right, targNum);
        }
    }
    else{
        return nullNode;
    }
}
void linkList::deleteNode(node *targNode){
    if((targNode==head)&&(targNode==tail)){
        head=NULL;
        tail=NULL;
    }
    else if((targNode==head)&&(targNode!=tail)){
        head=head->right;
        targNode->right=NULL;
    }
    else if((targNode!=head)&&(targNode!=tail)){
        node *temp=findPrevNode(head, targNode);
        temp->right=targNode->right;
        targNode->right=NULL;
    }
    else if((targNode!=head)&&(targNode==tail)){
        node *temp=findPrevNode(head, targNode);
        tail=temp;
        tail->right=NULL;
    }
}
void linkList::deleteNodeByNum(int targNum){
    deleteNode(findNodeByNum(head, targNum));
}
void linkList::deleteAllNodeByNum(int targNum){

}
//**************** tree ****************
//**************** main ****************
int main(){
    linkList *list=new linkList();
    list->addLast(1);
    list->addLast(2);
    list->addLast(3);
    list->addLast(4);
    list->deleteNodeByNum(1);

    list->showLL(list->head);
}
