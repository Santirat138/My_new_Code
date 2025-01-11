#include<iostream>
using namespace std;
//------------------ functions
int getMajNum(int *ptrArr, int arrSize){
    int amount=0;
    int currNum;
    for(int currI=0;currI<arrSize;currI++){
        if(amount==0){
            currNum=*(ptrArr+currI);
            amount++;
        }
        if(currNum!=*(ptrArr+currI)){
            amount--;
        }
    }
    return currNum;
}
//------------------ main
int main(){
    int array[]={2, 1, 3, 1, 1, 3, 2, 1, 2, 2, 2, 3, 3, 1, 3, 3, 1};
    int *ptrArr=array;
    int arrSize=sizeof(array)/sizeof(array[0]);
    cout<<getMajNum(ptrArr, arrSize);
}