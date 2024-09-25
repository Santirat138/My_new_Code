#include<iostream>
#define maxSize 20
#define nullNum -1
using namespace std;
//----------------------- functions
int findParent(int idxIn){
    return idxIn/2;
}
int findLeftChild(int idxIn){
    return idxIn*2;
}
int findRightChild(int idxIn){
    return (idxIn*2)+1;
}
//----------------------- class arrayTree
class arrayTree{
    public:
        int array[maxSize];
        int root;
        int currIdx;
        arrayTree(){
            root=0;
            for(int i=0;i<maxSize;i++){
                array[i]=nullNum;
            }
        }
        void insertNum(int newNum);
        void showArray();
        void deleteNum(int targetNum);
};
void arrayTree::insertNum(int newNum){
    if(root==0){
        root=1;
        currIdx=1;
        array[1]=newNum;
    }
    else{
        while(currIdx<maxSize){
            int leftChild=findLeftChild(currIdx);
            int rightChild=findRightChild(currIdx);
            if(array[currIdx]>newNum){
                if(array[leftChild]!=nullNum){
                    currIdx=leftChild;
                }
                else{
                    array[leftChild]=newNum;
                    break;
                }
            }
            else if(array[currIdx]<newNum){
                if(array[rightChild]!=nullNum){
                    currIdx=rightChild;
                }
                else{
                    array[rightChild]=newNum;
                    break;
                }
            }
        }
    }
}
void arrayTree::showArray(){
    for(int i=1;i<maxSize;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void arrayTree::deleteNum(int targetNum){
    
}
//----------------------- main
int main(){
    arrayTree aTree;
    aTree.insertNum(72);
    aTree.insertNum(65);
    aTree.insertNum(62);
    aTree.insertNum(70);
    aTree.insertNum(60);
    aTree.insertNum(51);
    aTree.insertNum(61);
    aTree.insertNum(53);
    aTree.showArray();
}