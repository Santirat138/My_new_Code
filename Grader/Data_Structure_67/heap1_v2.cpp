#include<iostream>
#define maxSize 20
using namespace std;
//--------------------- class
class maxHeap{
	public:
		int heapArray[maxSize];
		int root;
		int currIdx;
		int lastIdx;
		maxHeap(){
			root=0;
			currIdx=0;
			lastIdx=0;
		}
		int findMaxNumIdx(int idx1, int idx2);
		int findParentIdx(int idxIn);
		int findLeftIdx(int idxIn);
		int findRightIdx(int idxIn);
		void insertNewNum(int newNum);
		void showHeapArray();
		void deleteRoot();
};
int maxHeap::findMaxNumIdx(int idx1, int idx2){
	if(heapArray[idx1]>heapArray[idx2]){
		return idx1;
	}
	else if(heapArray[idx1]<heapArray[idx2]){
		return idx2;
	}
	else{
		return idx1;
	}
}
int maxHeap::findParentIdx(int idxIn){
	return idxIn/2;
}
int maxHeap::findLeftIdx(int idxIn){
	return idxIn*2;
}
int maxHeap::findRightIdx(int idxIn){
	return (idxIn*2)+1;
}
void maxHeap::insertNewNum(int newNum){
	if(root==0){
		root=1;
		currIdx=1;
		lastIdx=2;
		heapArray[1]=newNum;
	}
	else{
		lastIdx++;
		currIdx=lastIdx-1;
		heapArray[currIdx]=newNum;
		while(true){
			if(currIdx==root){
				break;
			}
			int parentIdx=findParentIdx(currIdx);
			if(heapArray[parentIdx]<heapArray[currIdx]){
				swap(heapArray[parentIdx], heapArray[currIdx]);
			}
			currIdx--;
		}
	}
}
void maxHeap::showHeapArray(){
	for(int i=1;i<lastIdx;i++){
		cout<<heapArray[i]<<" ";
	}
	cout<<endl;
}
void maxHeap::deleteRoot(){
	int delIdx=root;
	cout<<heapArray[delIdx]<<endl;
	heapArray[delIdx]=heapArray[lastIdx-1];
	lastIdx--;
	int leftIdx;
	int rightIdx;
	int maxNumIdx;
	while(true){
		leftIdx=findLeftIdx(delIdx);
		rightIdx=findRightIdx(delIdx);
		if(leftIdx>=lastIdx){
			break;
		}
		if(rightIdx>=lastIdx){
			maxNumIdx=leftIdx;
		}
		else{
			maxNumIdx=findMaxNumIdx(leftIdx, rightIdx);
		}
		if(heapArray[maxNumIdx]>heapArray[delIdx]){
			swap(heapArray[delIdx], heapArray[maxNumIdx]);
			delIdx=maxNumIdx;
		}
		else{
			break;
		}
	}
}
//--------------------- functions
void mainFunc();
//--------------------- main
int main(){
    mainFunc();
}
//--------------------- functions
void mainFunc(){
    maxHeap myHeap;
    char chIn;
    int numIn;
    do{
        cin>>chIn;
        if(chIn=='a'){
            cin>>numIn;
            myHeap.insertNewNum(numIn);
        }
        else if(chIn=='p'){
            myHeap.showHeapArray();
        }
        else if(chIn=='d'){
            myHeap.deleteRoot();
        }
    }
    while(chIn!='e');
}