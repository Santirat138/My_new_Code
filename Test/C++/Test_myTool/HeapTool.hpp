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
        void addItem(int idIn, string nameIn, int wishValueIn, int importantValueIn){
        	if(last>=MAX){
                return ;
            }
            int curr=last;
            array[curr].setItemInfo(idIn, nameIn, wishValueIn, importantValueIn);
            last++;
            while(curr!=root){
                int parentIdx=findParentIdx(curr);
                if(array[parentIdx].itemValue<array[curr].itemValue){
                    swap(array[parentIdx], array[curr]);
                    curr=parentIdx;
                }
                else if(array[parentIdx].itemValue>=array[curr].itemValue){
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
					if(array[L_Idx].itemValue>array[R_Idx].itemValue){
						maxIdx=L_Idx;
					}
					else if(array[L_Idx].itemValue<array[R_Idx].itemValue){
						maxIdx=R_Idx;
					}
				}
				if(array[curr].itemValue<array[maxIdx].itemValue){
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
            cout<<"Item ID :"<<" Item name\t"<<"Item Value"<<endl;
            for(int curr=root;curr<last;curr++){
                cout<<"   "<<array[curr].itemId<<"\t   "<<array[curr].itemName<<"\t  "<<array[curr].itemValue<<endl;
            }
            cout<<endl;
        }
};
