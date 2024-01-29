#include<iostream>
using namespace std;
void moveZero(int arrayIn[], int size);
void swapNum(int idx1, int idx2, int arrayIn[]);
int main(){
    int array[8]={7, 0, 1, 0, 2, 5, 0, 0};
    moveZero(array, 8);
    for(int i=0;i<8;i++){
        cout<<array[i]<<" ";
    }
}
void moveZero(int arrayIn[], int size){
    int currIdx;
    int checkedIdx;
    for(checkedIdx=size-1;checkedIdx>=0;checkedIdx--){
        for(currIdx=0;currIdx+1<checkedIdx;currIdx++){
            if(arrayIn[currIdx]==0){
                swapNum(currIdx, currIdx+1, arrayIn);
            }
        }
    }
}
void swapNum(int idx1, int idx2, int arrayIn[]){
    int temp=arrayIn[idx1];
    arrayIn[idx1]=arrayIn[idx2];
    arrayIn[idx2]=temp;
}