// class minHeap, class maxHeap (array)
#include<iostream>
#define maxSize 20
using namespace std;
//-------------------- functions
int findParent(int idxIn);
int findLeftChild(int idxIn);
int findRightChild(int idxIn);
//-------------------- class minHeap
class minHeap{
    public:
        int root;
        int currIdx;
        int lastIdx;
        int minHeapArray[maxSize];
        minHeap(){
            root=0;
            currIdx=0;
            lastIdx=0;
        }
        void insertNum(int newNum);
};
void minHeap::insertNum(int newNum){
    if(root==0){
        root=1;
        currIdx=1;
        lastIdx=2;
        minHeapArray[1]=newNum;
    }
    else{
        lastIdx++;
        currIdx=lastIdx-1;
        minHeapArray[currIdx]=newNum;
        
    }
}
//-------------------- class maxHeap
class maxHeap{
    public:

};

//-------------------- main
int main(){

}
//-------------------- functions
int findParent(int idxIn){
    return idxIn/2;
}
int findLeftChild(int idxIn){
    return idxIn*2;
}
int findRightChild(int idxIn){
    return (idxIn*2)+1;
}