#include<iostream>
using namespace std;
//--------- class
class node{
    public:
        string str;
        node *right;
        node(string strIn);
};
node::node(string strIn){
    str=strIn;
    right=NULL;
}
class linkList{
    public:
        node *head;
        linkList();
        
};
linkList::linkList(){
    head=NULL;
}
//--------- functions

//--------- main
int main(){

}