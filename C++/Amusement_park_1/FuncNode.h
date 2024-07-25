#include<iostream>
#include<vector>
using namespace std;
//----------------- node -----------------
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn){
            num=numIn;
            left=nullptr;
            right=nullptr;
        }
};
node *nullNode=new node(-1);
//----------------- link list -----------------
class linkList{
    public:
        node *head;
        node *mid;
        node *tail;
        int amount;
        linkList(){
            head=nullptr;
            mid=nullptr;
            tail=nullptr;
            amount=0;
        }
        void linkNode(node *node1, node *node2){
            node1->right=node2;
            node2->left=node1;
        }
        void addFirst(int newNum){
            node *newNode=new node(newNum);
            if(head!=nullptr){
                linkNode(newNode, head);
            }
            else{
                tail=newNode;
            }
            head=newNode;
            amount++;
        }
        void addLast(int newNum){
            node *newNode=new node(newNum);
            if(tail!=nullptr){
                linkNode(tail, newNode);
            }
            else{
                head=newNode;
            }
            tail=newNode;
            amount--;
        }
        void showLL(node *currNode, int ticket){
            if((ticket==2)&&(currNode!=nullptr)){
                cout<<currNode->num<<" ";
                if(currNode!=tail){
                    currNode=currNode->right;
                }
                else{
                    ticket=1;
                    currNode=tail;
                    cout<<endl;
                }
                showLL(currNode, ticket);
            }
            else if((ticket==1)&&(currNode!=nullptr)){
                cout<<currNode->num<<" ";
                if(currNode!=head){
                    currNode=currNode->left;
                }
                else{
                    ticket=0;
                    currNode=head;
                }
                showLL(currNode, ticket);
            }
            else if(ticket==0){
                cout<<endl<<"End."<<endl;
            }
        }
        void addSort(int newNum){
            node *newNode=new node(newNum);
            if((head==nullptr)&&(tail==nullptr)){
                head=newNode;
                tail=newNode;
                amount=1;
            }
            else if(head==tail){
                if(newNum>head->num){
                    addLast(newNum);
                }
                else if(newNum<head->num){
                    addFirst(newNum);
                }
            }
            else{
                node *compNode=head;
                while(compNode!=tail){   
                    if((newNum<compNode->num)&&(newNum<compNode->right->num)){
                        addFirst(newNum);
                        break;
                    }
                    else if((newNum>compNode->num)&&(newNum<compNode->right->num)){
                        linkNode(newNode, compNode->right);
                        linkNode(compNode, newNode);
                        amount++;
                        break;
                    }
                    else if((newNum>compNode->num)&&(newNum>compNode->right->num)){
                        compNode=compNode->right;
                    }
                }
                if(compNode==tail){
                    if(newNum>compNode->num){
                        addLast(newNum);
                    }
                    else{
                        cout<<"Error."<<endl;
                    }
                }
            }
        }
        
};