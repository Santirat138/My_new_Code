#include<iostream>
using namespace std;
//*************** functions ***************
int setStartEnd(int arrayIn[], int start, int end);
int countNum(int arrayIn[], int start, int end);
//*************** main ***************
int main(){
    int array[]={1, 1, 1, 1, 2, 2, 3, 3};
    int size=sizeof(array)/sizeof(array[0]);
    int start=0;
    int end=setStartEnd(array, start, end);
    int nA=countNum(array, start, end);
    
}
//*************** functions ***************
int setStartEnd(int arrayIn[], int start, int end){
    while(1){
        if(arrayIn[start]==arrayIn[end]){
            end++;
        }
        else{
            break;
        }
    }
    return end;
}
int countNum(int arrayIn[], int start, int end){
    return (end-start)+1;
}