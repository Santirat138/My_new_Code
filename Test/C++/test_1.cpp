// Test heap.
#include<iostream>
#define maxSize 20
using namespace std;
//--------------- class minHeap
class minHeap{
	public:
		int heapArray[maxSize];
		int root;
		int currIdx;
		int lastIdx;
		minHeap(){
			root=0;
			currIdx=0;
			lastIdx=0;
		}
		int findParentIdx(int idxIn);
		int findLeftIdx(int idxIn);
		int findRightIdx(int idxIn);
        void insertNewNum(int newNum);
};
int minHeap::findParentIdx(int idxIn){
    return idxIn/2;
}
int minHeap::findLeftIdx(int idxIn){
    return idxIn*2;
}
int minHeap::findRightIdx(int idxIn){
    return (idxIn*2)+1;
}
void minHeap::insertNewNum(int newNum){
    if(root==0){
		root=1;
		currIdx=1;
		lastIdx=2;
		heapArray[1]=newNum;
	}
	else{
		lastIdx++;
		currIdx++;
		heapArray[currIdx]=newNum;
		
	}
}
//--------------- class maxHeap

//--------------- main
int main(){
	
}