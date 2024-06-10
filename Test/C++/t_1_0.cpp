#include<iostream>
using namespace std;
//*********** functions ***********

//*********** main ***********
int main(){
    int array[]={9, 9, 9, 9, 9};
    int size=sizeof(array)/sizeof(array[0]);
    int *ptr;
    int *newArray=array;
    *(newArray+(size-1))=*(newArray+(size-1))+1;
    for(int i=0;i<size;i++){
        cout<<*(newArray+i)<<" ";
    }
}
//*********** functions ***********
