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
        int minArray[maxSize];
        minHeap(){
            root=0;
            currIdx=0;
            lastIdx=0;
        }
        void insertNum(int newNum);
        void show_minArray();
        void deleteRoot();
};
void minHeap::insertNum(int newNum){
    if(root==0){
        root=1;
        currIdx=1;
        lastIdx=2;
        minArray[1]=newNum;
    }
    else{
        lastIdx++;
        currIdx=lastIdx-1;
        minArray[currIdx]=newNum;
        while(currIdx>root){
            int parentIdx=findParent(currIdx);
            if(minArray[parentIdx]>minArray[currIdx]){
                swap(minArray[parentIdx], minArray[currIdx]);
                currIdx=parentIdx;
            }
            else{
                currIdx--;
            }
        }
    }
}
void minHeap::show_minArray(){
    for(int i=1;i<lastIdx;i++){
        cout<<minArray[i]<<" ";
    }
    cout<<endl;
}
void minHeap::deleteRoot(){
    lastIdx--;
    minArray[root]=minArray[lastIdx];
    currIdx=root;
    int leftIdx=findLeftChild(currIdx);
    int rightIdx=findRightChild(currIdx);
    int minIdx;
    do{
        leftIdx=findLeftChild(currIdx);
        rightIdx=findRightChild(currIdx);
        if(rightIdx>=lastIdx){
            minIdx=leftIdx;
        }
        else{
            if(minArray[leftIdx]<minArray[rightIdx]){
                minIdx=leftIdx;
            }
            else{
                minIdx=rightIdx;
            }
        }
        if(minArray[currIdx]>minArray[minIdx]){
            swap(minArray[currIdx], minArray[minIdx]);
            currIdx=minIdx;
        }
        else{
            currIdx++;
        }
    }
    while(leftIdx<lastIdx);
}
//-------------------- class maxHeap
class maxHeap{
    public:
        int root;
        int currIdx;
        int lastIdx;
        int maxArray[maxSize];
        maxHeap(){
            root=0;
            currIdx=0;
            lastIdx=0;
        }
        void insertNum(int newNum);
        void show_maxArray();
        void deleteRoot();
};
void maxHeap::insertNum(int newNum){
    if(root==0){
        root=1;
        currIdx=1;
        lastIdx=2;
        maxArray[1]=newNum;
    }
    else{
        lastIdx++;
        currIdx=lastIdx-1;
        maxArray[currIdx]=newNum;
        while(currIdx>root){
            int parentIdx=findParent(currIdx);
            if(maxArray[parentIdx]<maxArray[currIdx]){
                swap(maxArray[parentIdx], maxArray[currIdx]);
                currIdx=parentIdx;
            }
            else{
                currIdx--;
            }
        }
    }
}
void maxHeap::show_maxArray(){
    for(int i=1;i<lastIdx;i++){
        cout<<maxArray[i]<<" ";
    }
    cout<<endl;
}
void maxHeap::deleteRoot(){
    lastIdx--;
    maxArray[root]=maxArray[lastIdx];
    int currIdx=root;
    int leftIdx;
    int rightIdx;
    int maxIdx;
    do{
        leftIdx=findLeftChild(currIdx);
        rightIdx=findRightChild(currIdx);
        if(rightIdx>=lastIdx){
            maxIdx=leftIdx;
        }
        if(maxArray[leftIdx]<maxArray[rightIdx]){
            maxIdx=rightIdx;
        }
        else{
            maxIdx=leftIdx;
        }
        if(maxArray[currIdx]>maxArray[maxIdx]){
            swap(maxArray[currIdx], maxArray[maxIdx]);
            currIdx=maxIdx;
        }
        else{
            currIdx++;
        }
    }
    while(leftIdx<lastIdx);
}
//-------------------- main
int main(){
    maxHeap maxArray;
    maxArray.insertNum(50);
    maxArray.insertNum(40);
    maxArray.insertNum(80);
    maxArray.insertNum(60);
    maxArray.insertNum(70);
    maxArray.insertNum(30);
    maxArray.show_maxArray();
    maxArray.deleteRoot();
    maxArray.show_maxArray();
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