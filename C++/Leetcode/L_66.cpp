#include<iostream>
using namespace std;
//------------------ functions
int getCarryNum(int numIn){
	int carryNum=0;
	while(numIn>=10){
		numIn=numIn-10;
		carryNum++;
	}
	return carryNum;
}
void plusNumMore(int *ptrArr, int arrSize, int plusNum){
    *(ptrArr+(arrSize-1))=*(ptrArr+(arrSize-1))+plusNum;
    for(int currI=arrSize-1;currI>0;currI--){
        int carryNum=getCarryNum(*(ptrArr+currI));
        if(carryNum>0){
            *(ptrArr+currI)=*(ptrArr+currI)%10;
        }
        *(ptrArr+(currI-1))=*(ptrArr+(currI-1))+carryNum;
    }

}
void showArray(int *ptrArr, int arrSize){
    for(int currI=0;currI<arrSize;currI++){
        cout<<*(ptrArr+currI)<<" ";
    }
}
//------------------ main
int main(){
    int array[]={0, 0, 9, 9, 8};
    int *ptrArr=array;
    int arrSize=sizeof(array)/sizeof(array[0]);
    plusNumMore(ptrArr, arrSize, 25);
    showArray(ptrArr, arrSize);
}