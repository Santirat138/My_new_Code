// Binary Search Tree in array.
#include<iostream>
#include<vector>
#define maxSize 20
#define nullNum -1
using namespace std;
//------------------------ class BST_Array
class BST_Array{
    public:
        int root;
        int *ptrArray;
        int array[maxSize];
        BST_Array(){
            root=1;
            for(int i=0;i<maxSize;i++){
                array[i]=nullNum;
            }
            ptrArray=&array[0];
        }
        void showArray();
        int getLeftChildIdx(int parentIdx);
        int getRightChildIdx(int parentIdx);
        int *insertNum(int currIdx, int newNum);
        int *deleteNum(int currIdx, int targetNum);
        int getMaxLeftIdx(int currIdx);
};
void BST_Array::showArray(){
    for(int i=1;i<maxSize;i++){
        cout<<ptrArray[i]<<" ";
    }
}
int BST_Array::getLeftChildIdx(int parentIdx){
    return parentIdx*2;
}
int BST_Array::getRightChildIdx(int parentIdx){
    return (parentIdx*2)+1;
}
int *BST_Array::insertNum(int currIdx, int newNum){
    if(*(ptrArray+currIdx)==nullNum){
        ptrArray[currIdx]=newNum;
    }
    else{
        if(*(ptrArray+currIdx)<newNum){
            ptrArray=insertNum(getRightChildIdx(currIdx), newNum);
        }
        else if(*(ptrArray+currIdx)>newNum){
            ptrArray=insertNum(getLeftChildIdx(currIdx), newNum);
        }
    }
    return ptrArray;
}
int *BST_Array::deleteNum(int currIdx, int targetNum){
    if((currIdx>maxSize)||(currIdx==nullNum)){
        return nullptr;
    }
    if(ptrArray[currIdx]<targetNum){
        return deleteNum(getRightChildIdx(currIdx), targetNum);
    }
    else if(ptrArray[currIdx]>targetNum){
        return deleteNum(getLeftChildIdx(currIdx), targetNum);
    }
    else{
        if((ptrArray[getLeftChildIdx(currIdx)]==nullNum)&&(ptrArray[getRightChildIdx(currIdx)]==nullNum)){
            return nullptr;
        }
        else if((ptrArray[getLeftChildIdx(currIdx)]!=nullNum)&&(ptrArray[getRightChildIdx(currIdx)]!=nullNum)){
            int maxLeftIdx=getMaxLeftIdx(currIdx);
            ptrArray[currIdx]=ptrArray[maxLeftIdx];
            return deleteNum(currIdx, maxLeftIdx);
        }
        else if(ptrArray[getLeftChildIdx(currIdx)]==nullNum){
            return &ptrArray[getRightChildIdx(currIdx)];
        }
        else if(ptrArray[getRightChildIdx(currIdx)]==nullNum){
            return &ptrArray[getLeftChildIdx(currIdx)];
        }
    }
    return ptrArray;
}
int BST_Array::getMaxLeftIdx(int currIdx){
    if(ptrArray[getLeftChildIdx(currIdx)]!=nullNum){
        currIdx=getLeftChildIdx(currIdx);
        while((ptrArray[getRightChildIdx(currIdx)]!=nullNum)&&(getRightChildIdx(currIdx)<maxSize)){
            currIdx=getRightChildIdx(currIdx);
        }
        return currIdx;
    }
    return nullNum;
}
//------------------------ main
int main(){
    BST_Array *arr=new BST_Array();
    arr->ptrArray=arr->insertNum(1, 40);
    arr->ptrArray=arr->insertNum(1, 15);
    arr->ptrArray=arr->insertNum(1, 45);
    arr->ptrArray=arr->insertNum(1, 5);
    arr->ptrArray=arr->insertNum(1, 25);
    arr->ptrArray=arr->insertNum(1, 20);
    arr->ptrArray=arr->insertNum(1, 26);
    arr->showArray();
    arr->ptrArray=arr->deleteNum(1, 5);
    arr->showArray();
}