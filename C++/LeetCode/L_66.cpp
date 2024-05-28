#include<iostream>
using namespace std;
//*********** functions ***********

//*********** main ***********
int main(){
    int array[]={9, 9, 9, 9};
    int size=sizeof(array)/sizeof(array[0]);
    int curr=size-1;
    array[curr]=array[curr]+1;
    while(curr>0){
        if(array[curr]>=10){
            array[curr]=0;
            curr--;
            array[curr]++;
        }
        else{
            break;
        }
    }
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}
//*********** functions ***********
