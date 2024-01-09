#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *left;
        node *right;

        node(int numIn);
};
class tree{
    public:
        node *root;

        void insertNum(int newNum);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
}
int main(){

}