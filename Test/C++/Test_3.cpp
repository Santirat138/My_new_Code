#include<iostream>
#define MAXSIZE 10
using namespace std;
//--------------------- class ptrArray
class ptrArray{
    public:
        int *pArray;
        int array[MAXSIZE];
        ptrArray(){
            pArray=&array[0];
        }
        void addNum(int idxIn, int newNum);
        void showArray();
};
void ptrArray::addNum(int idxIn, int newNum){
    *(pArray+idxIn)=newNum;
}
void ptrArray::showArray(){
    for(int i=0;i<MAXSIZE;i++){
        cout<<*(pArray+i)<<" ";
    }
    cout<<endl;
}
//--------------------- main
int main(){
    ptrArray *pArr=new ptrArray();
    pArr->addNum(1, 50);
    pArr->addNum(3, 80);
    pArr->showArray();
}