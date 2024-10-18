#include<iostream>
#define MAXSIZE 20
#define NULLNUM -1
using namespace std;
//---------------------- class class toolsBox
class toolsBox{
    public:
        int findL_ChildIdx(int idxIn);
        int findR_ChildIdx(int idxIn);
        int findParent(int idxIn);
};
int toolsBox::findL_ChildIdx(int idxIn){
    return (idxIn*2)+1;
}
int toolsBox::findR_ChildIdx(int idxIn){
    return (idxIn*2)+2;
}
int toolsBox::findParent(int idxIn){
    return idxIn/2;
}
//---------------------- class arrayBST
class arrayBST{
    public:
        toolsBox *tool;
        int array[MAXSIZE];
        int *ptrArray;
        int root;
        arrayBST(){
            tool=new toolsBox();
            ptrArray=array;
            root=0;
            for(int i=0;i<MAXSIZE;i++){
                *(ptrArray+i)=NULLNUM;
            }
        }
        void insertNum(int currIdx, int newNum);
        void showArray();
};
void arrayBST::insertNum(int currIdx, int newNum){
    if(ptrArray[currIdx]==NULLNUM){
        ptrArray[currIdx]=newNum;
    }
    else{
        if(ptrArray[currIdx]<newNum){
            int R_Child=tool->findR_ChildIdx(currIdx);
            if(ptrArray[R_Child]!=NULLNUM){
                insertNum(R_Child, newNum);
            }
            else{
                ptrArray[R_Child]=newNum;
            }
        }
        else if(ptrArray[currIdx]>newNum){
            int L_Child=tool->findL_ChildIdx(currIdx);
            if(ptrArray[L_Child]!=NULLNUM){
                insertNum(L_Child, newNum);
            }
            else{
                ptrArray[L_Child]=newNum;
            }
        }
    }
}
void arrayBST::showArray(){
    for(int i=1;i<MAXSIZE;i++){
        cout<<ptrArray[i]<<" ";
    }
    cout<<endl;
}
//---------------------- main
int main(){

}