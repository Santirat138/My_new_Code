#include<iostream>
using namespace std;

int main(){
    int array[]={9, 9, 9, 9};
    int size=sizeof(array)/sizeof(array[0]);
    int curr=size-1;
    int temp=0;
    array[curr]=array[curr]+1;
    while(curr>0){
        while(array[curr]>9){
            array[curr]=array[curr]-10;
            temp++;
            if(array[curr]<=9){
                array[curr]=0;
                break;
            }
        }
        array[curr-1]=array[curr-1]+temp;
        curr--;
    }
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}