#include<iostream>
using namespace std;
void plusNum(int *ptrIn);
int main(){
    int array[]={1, 2, 3, 4, 5};
    int *ptr=array;
    plusNum(ptr);
    for(int i=0;i<5;i++){
        cout<<array[i]<<" ";
    }
}
void plusNum(int *ptrIn){
    *(ptrIn + 1) = *(ptrIn + 1) + 1;
}