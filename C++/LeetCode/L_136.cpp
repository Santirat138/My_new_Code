#include<iostream>
using namespace std;
//*********** functions ***********
void delDupNum(int array[], int size);
void createNewArray(int array[], int size);
//*********** main ***********
int main(){
    int array[]={1, 8, 1, 3, 5, 4, 3};
    int size=sizeof(array)/sizeof(array[0]);
    delDupNum(array, size);
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    createNewArray(array, size);
}
//*********** functions ***********
void delDupNum(int array[], int size){
    for(int curr=0;curr<size-1;curr++){
        for(int comp=curr+1; comp<size;comp++){
            if(array[curr]==array[comp]){
                array[curr]=-1;
                array[comp]=-1;
            }
        }
    }
}
void createNewArray(int array[], int size){
    int newSize;
    for(int i=0;i<size;i++){
        if(array[i]!=-1){
            newSize++;
        }
    }
    int newArray[newSize];
    int currIdx=0;
    for(int i=0;i<size;i++){
        if(array[i]!=-1){
            newArray[currIdx]=array[i];
            currIdx++;
        }
    }
    cout<<endl;
    for(int i=0;i<newSize;i++){
        cout<<newArray[i]<<" ";
    }
}