#include<iostream>
#define MAXSIZE 15
using namespace std;
//------------------ variables

//------------------ class
class maxHeap{
    public:
        int array[MAXSIZE];
        int root;
        int currIdx;
        int lastIdx;
        maxHeap(){
            root=0;
            currIdx=0;
            lastIdx=0;
        }
        int findParent(int idxIn);
        int findLeftChild(int idxIn);
        int findRightChild(int idxIn);
        void insertNum(int newNum);
        void deleteRoot();
        int compareMaxIdx(int leftIdx, int rightIdx);
        void showArray();
};
int maxHeap::findParent(int idxIn){
    return idxIn/2;
}
int maxHeap::findLeftChild(int idxIn){
    return idxIn*2;
}
int maxHeap::findRightChild(int idxIn){
    return (idxIn*2)+1;
}
void maxHeap::insertNum(int newNum){
    if(root==0){
        root=1;
        currIdx=1;
        array[1]=newNum;
        lastIdx=2;
    }
    else{
        lastIdx++;
        currIdx=lastIdx-1;
        array[currIdx]=newNum;
        int parentIdx=findParent(currIdx);
        while(currIdx>root){
            parentIdx=findParent(currIdx);
            if(array[parentIdx]<array[currIdx]){
                swap(array[parentIdx], array[currIdx]);
                currIdx=parentIdx;
            }
            else{
                break;
            }
        }
    }
}
void maxHeap::deleteRoot(){
    int delIdx=root;
    int leftIdx=findLeftChild(delIdx);
    int rightIdx=findRightChild(delIdx);
    int maxIdx;
    array[delIdx]=array[lastIdx-1];
    lastIdx--;
    while(rightIdx<lastIdx){
        leftIdx=findLeftChild(delIdx);
        rightIdx=findRightChild(delIdx);
        maxIdx=compareMaxIdx(leftIdx, rightIdx);
        if(array[delIdx]<array[maxIdx]){
            swap(array[delIdx], array[maxIdx]);
            delIdx=maxIdx;
        }
        else{
            delIdx++;
        }
    }
}
int maxHeap::compareMaxIdx(int leftIdx, int rightIdx){
    if(array[leftIdx]>array[rightIdx]){
        return leftIdx;
    }
    else if(array[leftIdx]<array[rightIdx]){
        return rightIdx;
    }
}
void maxHeap::showArray(){
    for(int i=1;i<lastIdx;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
//------------------ functions
void mainFunc();
//------------------ main
int main(){
    mainFunc();

}
//------------------ functions
void mainFunc(){
    maxHeap myMaxHeap;
    char chIn;
    int numIn;
    while(true){
        cin>>chIn;
        if(chIn=='a'){
            cin>>numIn;
            myMaxHeap.insertNum(numIn);
        }
        else if(chIn=='p'){
            myMaxHeap.showArray();
        }
        else if(chIn=='d'){
            myMaxHeap.deleteRoot();
        }
        else if(chIn=='e'){
            break;
        }
    }
}