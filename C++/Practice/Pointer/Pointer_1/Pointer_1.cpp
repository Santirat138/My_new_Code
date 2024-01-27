#include<iostream>
using namespace std;
void setNum(int *ptrIn, int **pptrIn);
int main(){
    int num=1;
    int *ptrNum=&num;
    int **pptrNum=&ptrNum;
    setNum(ptrNum, pptrNum);
    cout<<num<<endl;
    cout<<*ptrNum<<endl;
    cout<<**pptrNum<<endl;
}
void setNum(int *ptrIn, int **pptrIn){
    *ptrIn=2;
    **pptrIn=20;
}