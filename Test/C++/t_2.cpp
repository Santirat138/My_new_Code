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
int main(){

}