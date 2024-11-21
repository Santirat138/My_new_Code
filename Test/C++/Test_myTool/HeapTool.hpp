#include "Info.hpp"
#define MAX 10
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
        itemInfo array[MAX];
        void heapify(int currIdx){
            int L_Idx=findLeftIdx(currIdx);
            int R_Idx=findRightIdx(currIdx);
            int maxNumIdx=currIdx;
            if((R_Idx<last)&&(array[R_Idx].itemValue>array[maxNumIdx].itemValue)){
                maxNumIdx=R_Idx;
            }
            if((L_Idx<last)&&(array[L_Idx].itemValue>array[maxNumIdx].itemValue)){
                maxNumIdx=L_Idx;
            }
            if(maxNumIdx!=currIdx){
                swap(array[maxNumIdx], array[currIdx]);
                heapify(currIdx+1);
            }
        }
        void checkHeap(){
            for(int i=last-1;i>=0;i--){
                heapify(i);
            }
        }
        void addItem(int idIn, string nameIn, int wishValueIn, int importantValueIn){
        	if(last>=MAX){
                return ;
            }
            array[last].setItemInfo(idIn, nameIn, wishValueIn, importantValueIn);
            last++;
            checkHeap();
        }
        void deleteRoot(){
            array[root]=array[last-1];
            last--;
            checkHeap();
        }
        void showArray(){
            cout<<"Item ID :"<<" Item name\t"<<"Item Value"<<endl;
            for(int curr=root;curr<last;curr++){
                cout<<"   "<<array[curr].itemId<<"\t   "<<array[curr].itemName<<"\t  "<<array[curr].itemValue<<endl;
            }
            cout<<endl;
        }
};
