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

int main(){

}