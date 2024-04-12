#include<iostream>
using namespace std;
void changeArray(int *ptrIdx, int newNum);
int main(){
    int arrayMain[]={1, 2, 3, 4, 5};
    int *ptrIdx;
    ptrIdx=&arrayMain[1];
    changeArray(ptrIdx, 50);
    for(int i=0;i<5;i++){
        cout<<arrayMain[i]<<" ";
    }
}
void changeArray(int *ptrIdx, int newNum){
    *ptrIdx=newNum;
}