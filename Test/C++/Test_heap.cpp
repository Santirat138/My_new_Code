// Max heap. Start at index 1.
#include<iostream>
#define MAXSIZE 20
using namespace std;
//------------------------ class
class maxHeap{
    public:
        int array[MAXSIZE];
        int root=0;
        int currIdx=0;
        int lastIdx=0;
        int findParentIdx(int idxIn);
        void insertNum(int newNum);
        void deleteRoot();
        void showArray();
};
int maxHeap::findParentIdx(int idxIn){
    return idxIn/2;
}
void maxHeap::insertNum(int newNum){
    if(root==0){
        root=1;
        currIdx=1;
        array[1]=newNum;
        lastIdx=2;
    }
    else{
        int parent;
        lastIdx++;
        currIdx=lastIdx-1;
        array[currIdx]=newNum;
        while(currIdx>root){
            parent=findParentIdx(currIdx);
            if(array[parent]<array[currIdx]){
                swap(array[parent], array[currIdx]);
                currIdx=parent;
            }
            else{
                break;
            }
        }
    }
}
void maxHeap::deleteRoot(){
    int delIdx=root;
    array[delIdx]=array[lastIdx-1];
    lastIdx--;
    int leftIdx;
    int rightIdx;
    int maxIdx=root;
    int maxChildIdx;
    while(true){
        leftIdx=maxIdx*2;
        rightIdx=(maxIdx*2)+1;
        if(array[leftIdx]>array[rightIdx]){
            maxChildIdx=leftIdx;
        }
        else if(array[leftIdx]<array[rightIdx]){
            maxChildIdx=rightIdx;
        }
        if(array[maxIdx]<array[maxChildIdx]){
            swap(array[maxIdx], array[maxChildIdx]);
            maxIdx=maxChildIdx;
        }
        else{
            maxIdx++;
        }
        if(maxIdx>=lastIdx){
            break;
        }
    }
}
void maxHeap::showArray(){
    for(int i=1;i<lastIdx;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
//------------------------ functions

//------------------------ main
int main(){
    maxHeap heap;
    heap.insertNum(20);
    heap.insertNum(30);
    heap.insertNum(40);
    heap.insertNum(50);
    heap.insertNum(60);
    heap.insertNum(70);
    heap.insertNum(80);
    heap.insertNum(90);
    heap.showArray();
    /* heap.deleteRoot();
    heap.showArray(); */
}
