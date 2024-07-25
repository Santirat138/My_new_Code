// Pop array.
#include<iostream>
using namespace std;
//-------------- functions --------------
int pop(int *pArray, int *pCurr);
//-------------- main --------------
int main(){
    int array[5]={1, 2, 3, 4, 5};
    int size=sizeof(array)/sizeof(array[0]);
    int curr=size-1;
    int *pCurr=&curr;
    int *pArray=array;
    cout<<pop(array, pCurr)<<" ";
}
//-------------- functions --------------
int pop(int *pArray, int *pCurr){
    int sentNum=*(pArray+(*pCurr));
    *pCurr=(*pCurr)-1;
    return sentNum;
}