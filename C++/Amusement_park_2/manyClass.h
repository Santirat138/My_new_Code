// Double link list in hash table.
#include<iostream>
#include<vector>
using namespace std;

//---------------- node ----------------
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
//---------------- functions ----------------
void connectNode(node *node1, node *node2){
    node1->right=node2;
    node2->left=node1;
}
//---------------- link list ----------------
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        linkList();
        void addFirst(int newNum);
        void addLast(int newNum);
        void showLL(node *currNode, int haveTicket);
        void addSort(int newNum);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(-1);
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
}
void linkList::showLL(node *currNode, int haveTicket){
    if(haveTicket==1){
        cout<<currNode->num<<" ";
        if(currNode==tail){
            cout<<"End."<<endl;
            showLL(currNode, 0);
        }
        else{
            showLL(currNode->right, 1);
        }
    }
    else if(haveTicket==0){
        cout<<currNode->num<<" ";
        if(currNode==head){
            cout<<"End."<<endl;
            cout<<"End of list."<<endl;
        }
        else{
            showLL(currNode->left, 0);
        }
    }
}
void linkList::addSort(int newNum){
    node *newNode=new node(newNum);
    node *compNode=head;
    if(compNode==NULL){
        head=newNode;
        tail=newNode;
    }
    else if(compNode!=NULL){
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
            else if((compNode!=head)&&(compNode!=tail)){
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
            else if((compNode==head)&&(compNode!=tail)){
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
            else if((compNode!=head)&&(compNode==tail)){
                if(newNum<compNode->num){
                    connectNode(newNode, compNode);
                    connectNode(compNode->left, newNode);
                }
                else if(newNum>compNode->num){
                    addLast(newNum);
                }
                break;
            }
        }
    }
}
//---------------- hash table ----------------
class hashTable{
    public:
        int size;
        
};