#include<iostream>
using namespace std;
//---------------- class
class node{
    public:
        int num;
        node *right;
        node(int numIn){
            num=numIn;
            right=NULL;
        }
};
class linkList{
    public:
        node *head=NULL;
        node *tail=NULL;
        void addFirst(int newNum){
            node *newNode=new node(newNum);
            if(head!=NULL){
                newNode->right=head;
            }
            else{
                tail=newNode;
            }
            head=newNode;
        }
        void addLast(int newNum){
            node *newNode=new node(newNum);
            if(tail!=nullptr){
                tail->right=newNode;
            }
            else{
                head=newNode;
            }
            tail=newNode;
        }
        void showLL(){
            for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
                cout<<currNode->num<<" ";
            }
            cout<<endl;
        }
        void insertBefore(int id, int newNum){
            bool canInsert=false;
            if(((head->num==id)&&(head==tail))||(head==NULL)){
                addLast(newNum);
            }
            else{
                for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
                    if(currNode->right->num==id){
                        node *newNode=new node(newNum);
                        canInsert=true;
                        newNode->right=currNode->right;
                        currNode->right=newNode;
                        break;
                    }
                }
                if(!canInsert){
                    addLast(newNum);
                }
            }
        }
        void insertAfter(int id, int newNum){
            bool canInsert=false;
            if(((head->num==id)&&(head==tail))||(head==NULL)){
                addLast(newNum);
            }
            else{
                for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
                    if(currNode->num==id){
                        node *newNode=new node(newNum);
                        canInsert=true;
                        newNode->right=currNode->right;
                        currNode->right=newNode;
                        break;
                    }
                }
                if(!canInsert){
                    addLast(newNum);
                }
            }
        }
        void deleteFirst(){
            node *currNode=head;
            head=head->right;
            currNode->right=NULL;
        }
        void deleteLast(){
            node *currNode=head;
            while(currNode->right!=tail){
                currNode=currNode->right;
            }
            tail=currNode;
            tail->right=NULL;
        }
        void deleteNode(int id){
            if(head->num==id){
                deleteFirst();
            }
            else if(tail->num==id){
                deleteLast();
            }
            else{
                for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
                    if(currNode->right->num==id){
                        node *delNode=currNode->right;
                        currNode->right=delNode->right;
                        delNode->right=NULL;
                        break;
                    }
                }
            }
        }
        void mainFunction();
};
//---------------- functions 
void linkList::mainFunction(){
    char chIn;
    int newNum;
    int targNum;
    do{
        cin>>chIn;
        if(chIn=='A'){
            cin>>newNum>>targNum;
            insertAfter(targNum, newNum);
        }
        else if(chIn=='I'){
            cin>>newNum>>targNum;
            insertBefore(targNum, newNum);
        }
        else if(chIn=='D'){
            cin>>targNum;
            deleteNode(targNum);
        }
        showLL();
    }
    while(chIn!='E');
}
//---------------- main 
int main(){
    linkList *list1=new linkList();
    list1->mainFunction();
}