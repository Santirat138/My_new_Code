// Start at index 1.
#include<iostream>
#define size 10
#define nullNum -1
using namespace std;
//---------------- variable

//---------------- class minHeap
class minHeap{
    public:
        int array[size];
        int currIdx=0;
        int lastIdx=0;
        int findParent(int idxIn){
            return idxIn/2;
        }
        int findLeftChild(int idxIn){
            return idxIn*2;
        }
        int findRightChild(int idxIn){
            return (idxIn*2)+1;
        }
        void insertNewNum(int newNum);
        void swapNum(int idx1, int idx2);
        void showHeap(){
            for(int i=1;i<lastIdx;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
        void removeRoot();
};
void minHeap::insertNewNum(int newNum){
    if(currIdx==0&&lastIdx==0){
        array[1]=newNum;
        currIdx=1;
        lastIdx=2;
    }
    else{
        currIdx=lastIdx;
        lastIdx++;
        array[currIdx]=newNum;
        while(currIdx>1&&(array[findParent(currIdx)]>array[currIdx])){
            swapNum(findParent(currIdx), currIdx);
            currIdx=findParent(currIdx);
        }
    }
}

void minHeap::swapNum(int idx1, int idx2){
    int temp=array[idx1];
    array[idx1]=array[idx2];
    array[idx2]=temp;
}
void minHeap::removeRoot() {
    int delIdx = 1; // Assuming 1-based indexing
    array[delIdx] = array[lastIdx - 1];
    array[lastIdx - 1] = nullNum;
    lastIdx--;
    int smallestIdx;
    int leftIdx;
    int rightIdx;
    while (true) {
        leftIdx = findLeftChild(delIdx);
        rightIdx = findRightChild(delIdx);
        if (leftIdx >= lastIdx){
            break; // No children
        }
        if (rightIdx >= lastIdx) {
            smallestIdx = leftIdx; // Only left child exists
        } else {
            smallestIdx = (array[leftIdx] < array[rightIdx]) ? leftIdx : rightIdx;
        }
        if (array[delIdx] <= array[smallestIdx]){
            break; // Heap property satisfied
        }
        swapNum(delIdx, smallestIdx);
        delIdx = smallestIdx;
    }
}

/* void minHeap::heapify(int currIdx){
    int leftIdx=findLeftIdx(currIdx);
    int rightIdx=findRightIdx(currIdx);
    int minIdx=currIdx;
    if((leftIdx<lastIdx)||(rightIdx<lastIdx)){
        if((array[leftIdx]<array[rightIdx])&&(array[currIdx]>array[leftIdx])){
            minIdx=leftIdx;
        }
        else if((array[leftIdx]>array[rightIdx])&&(array[currIdx]>array[rightIdx])){
            minIdx=rightIdx;
        }
        if(minIdx!=currIdx){
            swap(array[currIdx], array[minIdx]);
            heapify(minIdx);
        }
    }
    else{
        return ;
    }
} */
//---------------- functions

//---------------- main
int main(){
    minHeap mHeap;
    mHeap.insertNewNum(50);
    mHeap.insertNewNum(70);
    mHeap.insertNewNum(60);
    mHeap.insertNewNum(30);
    mHeap.insertNewNum(20);
    mHeap.insertNewNum(55);
    mHeap.insertNewNum(25);
    mHeap.insertNewNum(5);
    mHeap.showHeap();
    mHeap.removeRoot();
    mHeap.showHeap();
}
//---------------- functions
