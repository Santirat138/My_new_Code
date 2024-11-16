#include<iostream>
#define MAX 10
using namespace std;
//-------------------------- functions
int findParentIdx(int idxIn){
    return idxIn/2;
}
int findLeftIdx(int idxIn){
    return (idxIn*2)+1;
}
int findRightIdx(int idxIn){
    return (idxIn*2)+2;
}
//-------------------------- class heap
class heap{
    public:
        int root=0;
        int last=0;
        int array[MAX];
        void addNum(int newNum){
        	if(last>=MAX){
                return ;
            }
            int curr=last;
            array[curr]=newNum;
            last++;
            while(curr!=root){
                int parentIdx=findParentIdx(curr);
                if(array[parentIdx]<array[curr]){
                    swap(array[parentIdx], array[curr]);
                    curr=parentIdx;
                }
                else if(array[parentIdx]>array[curr]){
                    break;
                }
            }
        }
        void deleteRoot(){
            array[root]=array[last-1];
            last--;
            int curr=root;
            int L_Idx;
            int R_Idx;
            int maxIdx;
			do{
            	L_Idx=findLeftIdx(curr);
            	R_Idx=findRightIdx(curr);
            	if(R_Idx>=last){
            		maxIdx=L_Idx;
				}
				else{
					if(array[L_Idx]>array[R_Idx]){
						maxIdx=L_Idx;
					}
					else if(array[L_Idx]<array[R_Idx]){
						maxIdx=R_Idx;
					}
				}
				if(array[curr]<array[maxIdx]){
					swap(array[curr], array[maxIdx]);
					curr=maxIdx;
				}
				else{
					break;
				}
			}
			while(L_Idx<last);
        }
        void showArray(){
            for(int curr=root;curr<last;curr++){
                cout<<array[curr]<<" ";
            }
            cout<<endl;
        }
};
//-------------------------- main
int main(){
    heap maxHeap;
    maxHeap.addNum(50);
    maxHeap.addNum(40);
    maxHeap.addNum(80);
    maxHeap.addNum(65);
    maxHeap.addNum(70);
    maxHeap.addNum(30);
    maxHeap.addNum(35);
    maxHeap.addNum(10);
    maxHeap.addNum(15);
    maxHeap.addNum(55);
    maxHeap.addNum(45);
    maxHeap.addNum(60);
    maxHeap.showArray();
    cout<<endl;
    maxHeap.deleteRoot();
    maxHeap.showArray();
}