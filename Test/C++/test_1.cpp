// Test struct data, hash table(link list).
#include<iostream>
#define MAXSIZE 10
#define nullNum -1
#define nullStr "-"
using namespace std;
//-------------------------------------- struct
typedef struct{
    int id;
    string fName;
    string lName;
    int age;
}info;
//-------------------------------------- class node
class node{
    public:
        info data;
        node *right;
        node(int idIn, string fNameIn, string lNameIn, int ageIn);
};
node::node(int idIn, string fNameIn, string lNameIn, int ageIn){
    data.id=idIn;
    data.fName=fNameIn;
    data.lName=lNameIn;
    data.age=ageIn;
}
node *nullNode=new node(nullNum, nullStr, nullStr, nullNum);
//-------------------------------------- class linkList
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addFirst(int idIn, string fNameIn, string lNameIn, int ageIn);
        void showLL();
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
void linkList::showLL(){
    for(node *currNode=head;currNode!=tail->right;currNode=currNode->right){
        cout<<currNode->data.id<<" : "<<currNode->data.fName<<" "<<currNode->data.lName<<" "<<currNode->data.age<<endl;
    }
}
//-------------------------------------- class hashTable
class hashTable{
    public:
        linkList *arrayLL[MAXSIZE];
        hashTable();
        int giveKey(int idIn);
        void insertData(int idIn, string fNameIn, string lNameIn, int ageIn);
        void showData();
};
hashTable::hashTable(){
    for(int i=0;i<MAXSIZE;i++){
        arrayLL[i]=new linkList();
    }
}
int hashTable::giveKey(int idIn){
    return idIn%MAXSIZE;
}
void hashTable::insertData(int idIn, string fNameIn, string lNameIn, int ageIn){
    int key=giveKey(idIn);
    arrayLL[key]->addFirst(idIn, fNameIn, lNameIn, ageIn);
}
void hashTable::showData(){
    for(int i=0;i<MAXSIZE;i++){
        if(arrayLL[i]->head!=NULL){
            arrayLL[i]->showLL();
        }
        else{
            cout<<"null"<<endl;
        }
        cout<<"----------------------------------------------------"<<endl;
    }
}
//-------------------------------------- functions

//-------------------------------------- main
int main(){
    hashTable *table=new hashTable();
    table->insertData(1001, "AAA", "aaa", 25);
    table->insertData(1021, "BBB", "bbb", 28);
    table->insertData(1003, "CCC", "ccc", 15);
    table->insertData(1004, "DDD", "ddd", 29);
    table->insertData(1005, "EEE", "eee", 27);
    table->insertData(1011, "AAAAAA", "aaaaaa", 25);
    table->insertData(1016, "FFF", "fff", 57);
    table->showData();
}