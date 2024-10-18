// Test array Binary search tree.
#include<iostream>
#define MAXSIZE 25
#define NULLNUM -1
using namespace std;
//-------------------------- class arrayBST
class arrayBST{
    public:
        int arrBST[MAXSIZE];
        int *pArray;
        arrayBST(){
            pArray=arrBST;
            for(int i=0;i<MAXSIZE;i++){
                *(pArray+i)=NULLNUM;
            }
        }
        int findL_Child(int currIdx);
        int findR_Child(int currIdx);
        void addNum(int currIdx, int newNum);
        void show_arrBST();
};
int arrayBST::findL_Child(int currIdx){
    return currIdx*2;
}
int arrayBST::findR_Child(int currIdx){
    return (currIdx*2)+1;
}
void arrayBST::addNum(int currIdx, int newNum){
    if(pArray[currIdx]==NULLNUM){
        pArray[currIdx]=newNum;
    }
    else{
        int L_Child=findL_Child(currIdx);
        int R_Child=findR_Child(currIdx);
        if(pArray[currIdx]<newNum){
            if(pArray[R_Child]!=NULLNUM){
                addNum(R_Child, newNum);
            }
            else{
                pArray[R_Child]=newNum;
            }
        }
        else if(pArray[currIdx]>newNum){
            if(pArray[L_Child]!=NULLNUM){
                addNum(L_Child, newNum);
            }
            else{
                pArray[L_Child]=newNum;
            }
        }
    }
}
void arrayBST::show_arrBST(){
    for(int i=0;i<MAXSIZE;i++){
        cout<<*(pArray+i)<<" ";
    }
}
//-------------------------- main
int main(){
    arrayBST *aBST=new arrayBST();
    aBST->addNum(1, 10);
    aBST->addNum(1, 5);
    aBST->addNum(1, 20);
    aBST->addNum(1, 3);
    aBST->addNum(1, 70);
    aBST->addNum(1, 15);
    aBST->addNum(1, 25);
    aBST->addNum(1, 100);
    aBST->show_arrBST();
}