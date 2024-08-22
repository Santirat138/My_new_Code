#include<iostream>
#define maxSize 17
#define nullCh "-"
#define nullNum -1
using namespace std;
//--------- class
class node{
    public:
        int key;
        string str;
        node *right;
        node(int keyIn, string strIn);
};
node::node(int keyIn, string strIn){
    key=keyIn;
    str=strIn;
    right=NULL;
}
node *nullNode=new node(nullNum, nullCh);
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        /* void addFirst(int keyIn, string strIn); */
        void addLast(int keyIn, string strIn);
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
/* void linkList::addFirst(int keyIn, string strIn){
    node *newNode=new node(keyIn, strIn);
    if(head!=NULL){
        newNode->right=head;
    }
    head=newNode;
} */
void linkList::addLast(int keyIn, string strIn){
    node *newNode=new node(keyIn, strIn);
    if(tail!=NULL){
        tail->right=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
class hashTable{
    public:
        linkList *arrayCh[maxSize];
        hashTable();
        void setData(int keyIn, string chIn);
        void showTable();
        void findData(int keyIn);
};
hashTable::hashTable(){
    for(int i=0;i<maxSize;i++){
        arrayCh[i]=new linkList();
    }
}
void hashTable::setData(int keyIn, string chIn){
    int key=keyIn%maxSize;
    arrayCh[key]->addLast(keyIn, chIn);
}
void hashTable::showTable(){
   /*cout<<"("<<currKey<<", "<<currNode->str<<")"<<" "; */
    for(int currKey=0;currKey<maxSize;currKey++){
        if(arrayCh[currKey]->head==NULL){
            cout<<"(-1, -)"<<endl;
            
        }
        else{
            for(node *currNode=arrayCh[currKey]->head;currNode!=NULL;currNode=currNode->right){
                cout<<"("<<currNode->key<<", "<<currNode->str<<")"<<" "; 
            }
            cout<<endl;
        }
    }
}
void hashTable::findData(int keyIn){
    int key=keyIn%maxSize;
    if(arrayCh[key]->head==NULL){
        cout<<"(-1, -)"<<endl;
    }
    else{
        for(node *currNode=arrayCh[key]->head;currNode!=NULL;currNode=currNode->right){
            cout<<"("<<currNode->key<<", "<<currNode->str<<")"<<" "; 
        }
        cout<<endl;
    }
}
//--------- functions
void mainFunction();
//--------- main
int main(){
    mainFunction();
}
//--------- functions
void mainFunction(){
    hashTable *table=new hashTable();
    char cmdCh;
    string strIn;
    int key;
    do{
        cin>>cmdCh;
        if(cmdCh=='a'){
            cin>>key;
            getline(cin, strIn);
            table->setData(key, strIn);
        }
        else if(cmdCh=='p'){
            table->showTable();
        }
        else if(cmdCh=='s'){
            cin>>key;
            table->findData(key);
        }
    }
    while(cmdCh!='e');
}