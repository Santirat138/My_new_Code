#include<iostream>
using namespace std;
//-------------- functions --------------
void sortMinToMax(int array[], int size);
//-------------- main --------------
int main(){
    int array[]={1, 9, 1, 8, 2};
    int dupNum;
    int size=sizeof(array)/sizeof(array[0]);
    int curr1=0;
    sortMinToMax(array, size);
    while(curr1<size){
        if(array[curr1]!=array[curr1+1]){
            cout<<array[curr1]<<" ";
            curr1++;
        }
        else{
            dupNum=array[curr1];
            while(array[curr1]==dupNum){
                curr1++;
            }
        }
    }

}
//-------------- functions --------------
void sortMinToMax(int array[], int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]>array[j]){
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}