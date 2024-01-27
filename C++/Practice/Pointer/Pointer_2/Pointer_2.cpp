// Pointer with array.
#include<iostream>
using namespace std;
void buildArray(int *newArray, int *newSize, int startNum);
void showArray(int *arrayIn, int *sizeIn);
void changeNum(int *arrayIn, int idxIn, int newNum);
// --------------- main ---------------
int main(){
    int size=4;
    int array[size];
    buildArray(array, &size, 0);
    changeNum(array, 0, 50);
    showArray(array, &size);
}
// --------------- main ---------------
void buildArray(int *newArray, int *newSize, int startNum){
    for(int i=0;i<*newSize;i++){
        newArray[i]=startNum+i+1;
    }
}
void showArray(int *arrayIn, int *sizeIn){
    for(int i=0;i<*sizeIn;i++){
        cout<<arrayIn[i]<<" ";
    }
    cout<<endl;
}
void changeNum(int *arrayIn, int idxIn, int newNum){
    arrayIn[idxIn]=newNum;
}