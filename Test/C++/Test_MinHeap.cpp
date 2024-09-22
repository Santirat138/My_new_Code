#include<iostream>
#include<vector>
#define MAXSIZE 10
using namespace std;
//-------------------- class
class minHeap{
    public:
        int heapArray[MAXSIZE];
        int root;
        int currIdx;
        int lastIdx;
        minHeap(){
            root=0;
            currIdx=0;
            lastIdx=0;
        }
        int findParent(int idxIn);
        int findLeftChild(int idxIn);
        int findRightChild(int idxIn);
        void insertNum(int newNum);
        void deleteRoot();
        void showHeapArray();
};
int minHeap::findParent(int idxIn){
    return idxIn/2;
}
int minHeap::findLeftChild(int idxIn){
    return idxIn*2;
}
int minHeap::findRightChild(int idxIn){
    return (idxIn*2)+1;
}
void minHeap::insertNum(int newNum){
    if(root==0){
        root=1;
        currIdx=1;
        lastIdx=2;
        heapArray[currIdx]=newNum;
    }
    else{
        lastIdx++;
        currIdx=lastIdx-1;
        heapArray[currIdx]=newNum;
        do{
            int parent=findParent(currIdx);
            if(heapArray[parent]>heapArray[currIdx]){
                swap(heapArray[parent], heapArray[currIdx]);
                currIdx=parent;
            }
            else{
                currIdx--;
            }
        }
        while(currIdx>root);
    }
}

void minHeap::showHeapArray(){
    for(int i=1;i<lastIdx;i++){
        cout<<heapArray[i]<<" ";
    }
    cout<<endl;
}
//-------------------- main
int main(){
    minHeap myHeap;
    vector<int> array({4, 8, 70, 46, 12, 88, 93, 15, 1, 85});
    for(int i=0;i<array.size();i++){
        myHeap.insertNum(array.at(i));
    }
    myHeap.showHeapArray();
    myHeap.deleteRoot();
    myHeap.deleteRoot();
    myHeap.showHeapArray();
}