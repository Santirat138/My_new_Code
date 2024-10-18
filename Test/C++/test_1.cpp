// Test array Binary search tree.
#include<iostream>
#include<vector>
#define MAXSIZE 15
#define NULLNUM -1
using namespace std;
//------------------------ functions
int findL_Child(int idxIn){
    return idxIn*2;
}
int findR_Child(int idxIn){
    return (idxIn*2)+1;
}
int findParent(int idxIn){
    return idxIn/2;
}
//------------------------ class arrayBST
class arrayBST{
    public:
        int root;
        int currIdx;
        vector<int> arrBST;
        arrayBST(vector<int> arrIn){
            root=1;
            currIdx=1;
            arrBST=arrIn;
        }
        void addNum(int currIdx, int newNum);
        void show_arrBST();
};
void arrayBST::addNum(int currIdx, int newNum){
    if(arrBST[currIdx]==NULLNUM){
        arrBST[currIdx]=newNum;
    }
    else{
        int L_Child=findL_Child(currIdx);
        int R_Child=findR_Child(currIdx);
        if(arrBST[currIdx]<newNum){
            if(arrBST[R_Child]!=NULLNUM){
                addNum(R_Child, newNum);
            }
            else{
                arrBST[R_Child]=newNum;
            }
        }
        else if(arrBST[currIdx]>newNum){
            if(arrBST[L_Child]!=NULLNUM){
                addNum(L_Child, newNum);
            }
            else{
                arrBST[L_Child]=newNum;
            }
        }
    }
}
void arrayBST::show_arrBST(){
    for(int i=1;i<MAXSIZE;i++){
        cout<<arrBST[i]<<" ";
    }
    cout<<endl;
}
//------------------------ main
int main(){
    vector<int> arrBST(MAXSIZE, NULLNUM);
    arrayBST aBST(arrBST);
    aBST.addNum(1, 10);
    aBST.addNum(1, 5);
    aBST.addNum(1, 20);
    aBST.addNum(1, 3);
    aBST.addNum(1, 7);
    aBST.addNum(1, 15);
    aBST.addNum(1, 25);
    aBST.addNum(1, 100);
    aBST.show_arrBST();
}