// Test Binary tree.
#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}

class tree{
    public:
        node *root;
        tree();
        void insert(int newNum);
};
tree::tree(){
    root=NULL;
}
void tree::insert(int newNum){
    
}
//************ main ************
int main(){

}
