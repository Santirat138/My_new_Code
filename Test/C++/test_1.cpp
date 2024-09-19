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

}
void maxHeap::showArray(){
    for(int i=1;i<lastIdx;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
//------------------ functions

//------------------ main
int main(){
    maxHeap heap;
    heap.insertNum(60);
    heap.insertNum(88);
    heap.insertNum(76);
    heap.insertNum(44);
    heap.insertNum(92);
    heap.insertNum(53);
    heap.insertNum(99);
    heap.showArray();
    heap.deleteRoot();
    heap.showArray();
}
//------------------ functions
