#include<iostream>
using namespace std;

int main(){
    int array[]={9, 9, 9, 20};
    int size=sizeof(array)/sizeof(array[0]);
    int lastDigi=size-1;
    int plusNum=5;
    int baseNum=10;
    int temp=0;
    for(int curr=lastDigi;curr>0;curr--){
        if(array[curr]>9){
            array[curr]=array[curr]-baseNum;
            temp=1;
        }
        else{
            break;
        }
        array[curr-1]=array[curr-1]+temp;
    }
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}