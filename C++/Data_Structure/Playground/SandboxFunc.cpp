#include<iostream>
using namespace std;
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
class mainNode{
    public:
        node *head=NULL;
        node *tail=NULL;
};
//**************** functions ****************
void addFirst(mainNode *nodes, int newNum);
void show(mainNode *nodes);
void addLast(mainNode *nodes, int newNum);
void deleteNode(mainNode *nodes, node *delNode);
node *findPrevNode(node *currNode, node *targNode);
node *findNum(node *currNode, int targNum);
void deleteNum(mainNode *nodes, int delNum);
void makeRef(mainNode *nodes);
void addSort(mainNode *nodes, int newNum);
void deleteAllNum(mainNode *nodes, int targNum);
//**************** main ****************
int main(){
    mainNode *mNode=new mainNode();
    addSort(mNode, 1);
    addSort(mNode, 3);
    addSort(mNode, 2);
    addSort(mNode, 2);
    addSort(mNode, 2);
    deleteAllNum(mNode, 2);
    show(mNode);
}
//**************** functions ****************
void addFirst(mainNode *nodes, int newNum){
    node *newNode=new node(newNum);
    if(nodes->head==NULL){
        nodes->tail=newNode;
    }
    else{
        newNode->right=nodes->head;
    }
    nodes->head=newNode;
}
void show(mainNode *nodes){
    node *currNode=nodes->head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<"End."<<endl;
}
void addLast(mainNode *nodes, int newNum){
    node *newNode=new node(newNum);
    if(nodes->tail==NULL){
        nodes->head=newNode;
    }
    else{
        nodes->tail->right=newNode;
    }
    nodes->tail=newNode;
}
void deleteNode(mainNode *nodes, node *delNode){
    if((delNode==nodes->head)&&(delNode==nodes->tail)){
        delNode==NULL;
    }
    else if(delNode==nodes->head){
        nodes->head=delNode->right;
        delNode->right=NULL;
    }
    else if(delNode==nodes->tail){
        node *newTail=findPrevNode(nodes->head, delNode);
        nodes->tail=newTail;
        newTail->right=NULL;
    }
    else{
        node *leftNode=findPrevNode(nodes->head, delNode);
        leftNode->right=delNode->right;
        delNode->right=NULL;
    }
}
node *findPrevNode(node *currNode, node *targNode){
    if((currNode!=NULL)&&(targNode!=NULL)){
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
node *findNum(node *currNode, int targNum){
    if(currNode!=NULL){
        if(currNode->num==targNum){
            return currNode;
        }
        else{
            return findNum(currNode->right, targNum);
        }
    }
    else{
        return nullNode;
    }
}
void deleteNum(mainNode *nodes, int delNum){
    deleteNode(nodes, findNum(nodes->head, delNum));
}
void makeRef(mainNode *nodes){
    node *leftNode=NULL;
    node *currNode=nodes->head;
    node *rightNode=nodes->head->right;
    while(currNode!=NULL){
        currNode->right=leftNode;
        leftNode=currNode;
        currNode=rightNode;
        if(rightNode->right!=NULL){
            rightNode=rightNode->right;
        }
        else{
            currNode->right=leftNode;
            break;
        }
    }
    nodes->tail=nodes->head;
    nodes->head=currNode;
}
void addSort(mainNode *nodes, int newNum){
    node *newNode=new node(newNum);
    node *leftNode;
    node *rightNode;
    if((nodes->head!=NULL)&&(nodes->tail!=NULL)){
        leftNode=nodes->head;
        rightNode=nodes->head->right;
        if(nodes->head==nodes->tail){
            if(newNum>nodes->head->num){
                addLast(nodes, newNum);
            }
            else{
                addFirst(nodes, newNum);
            }
        }
        else{
            while(leftNode!=NULL){
                if((newNum<=leftNode->num)&&(newNum<rightNode->num)){
                    addFirst(nodes, newNum);
                    break;
                }
                else if((newNum>leftNode->num)&&(newNum<=rightNode->num)){
                    newNode->right=rightNode;
                    leftNode->right=newNode;
                    break;
                }
                else if((newNum>leftNode->num)&&(newNum>rightNode->num)){
                    leftNode=leftNode->right;
                    if(rightNode->right!=NULL){
                        rightNode=rightNode->right;
                    }
                    else{
                        addLast(nodes, newNum);
                        break;
                    }
                }
                
            }
        }
    }
    else if((nodes->head==NULL)&&(nodes->tail==NULL)){
        nodes->head=newNode;
        nodes->tail=newNode;
    }
}
void deleteAllNum(mainNode *nodes, int targNum){

}