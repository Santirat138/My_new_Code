#include<iostream>
using namespace std;
class arrNode{
    public:
        int num;
        int next;
        arrNode(int numIn);
};
class linkList{
    public:
        arrNode head;
        
};
arrNode::arrNode(int numIn){
    num=numIn;
    next=-1;
}
int main(){

}