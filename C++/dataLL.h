#include<iostream>
#define nullNum -1
#define nullStr "-"
using namespace std;

//---------------- struct
typedef struct{
    string fName;
    string lName;
}name;
typedef struct{
    int id;
    name rName;
    int age;
}data;
//---------------- class node
class node{
    public:
        data info;
        node *right;
        node(int idIn, string fNameIn, string lNameIn, int ageIn);
};
node::node(int idIn, string fNameIn, string lNameIn, int ageIn){
    info.id=idIn;
    info.rName.fName=fNameIn;
    info.rName.lName=lNameIn;
    info.age=ageIn;
    right=NULL;
}
node *nullNode=new node(nullNum, nullStr, nullStr, nullNum);
//---------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addFirst(int idIn, string fNameIn, string lNameIn, int ageIn);
        void addLast(int idIn, string fNameIn, string lNameIn, int ageIn);
        void showLL();
        void deleteId(int idIn);
        void sortId();
        // Add more methods.
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addFirst(int idIn, string fNameIn, string lNameIn, int ageIn){
    node *newNode=new node(idIn, fNameIn, lNameIn, ageIn);
    if(head!=NULL){
        newNode->right=head;
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::addLast(int idIn, string fNameIn, string lNameIn, int ageIn){
    node *newNode=new node(idIn, fNameIn, lNameIn, ageIn);
    if(tail!=NULL){
        tail->right=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::showLL(){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        cout<<currNode->info.id<<" : "<<currNode->info.rName.fName<<" "<<currNode->info.rName.lName<<" "<<currNode->info.age<<endl;
    }
}
void linkList::deleteId(int idIn){
    node *targNode=head;
    while(targNode!=NULL){
        if(targNode->right->info.id==idIn){
            node *delNode=targNode->right;
            targNode->right=delNode->right;
            delNode->right=NULL;
            break;
        }
        else{
            targNode=targNode->right;
        }
    }
}
void linkList::sortId(){

}
//---------------- functions