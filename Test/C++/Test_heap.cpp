// Max heap. Start at index 1.
#include<iostream>
#define MAXSIZE 19
using namespace std;
//------------------------ class
class maxHeap{
    public:
        int array[MAXSIZE];
        int root=0;
        int lastIdx=0;
        int findParentIdx(int idxIn);
        void insertNum(int newNum);
};
int maxHeap::findParentIdx(int idxIn){
    return idxIn/2;
}
void maxHeap::insertNum(int newNum){
    if(root==0){
        root=1;
        array[1]=newNum;
        lastIdx=2;
    }
    else{
        
    }
}
//------------------------ functions

//------------------------ main
int main(){

}
