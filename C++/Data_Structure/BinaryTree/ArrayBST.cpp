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
        int findMaxLeft(int *pArrIn);
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
int toolsBox::findMaxLeft(int *pArrIn){
    
}
//---------------------- class arrayBST
class arrayBST{
    public:
        toolsBox *tool;
        int lastIdx;
        int array[MAXSIZE];
        int *ptrArray;
        int root;
        arrayBST(){
            tool=new toolsBox();
            lastIdx=0;
            ptrArray=array;
            root=0;
            for(int i=0;i<MAXSIZE;i++){
                *(ptrArray+i)=NULLNUM;
            }
        }
        void insertNum(int currIdx, int newNum);
        int searchNum(int targetNum);
        void showArray();
        void deleteNum(int currIdx, int targetNum);
};
void arrayBST::insertNum(int currIdx, int newNum){
    if(ptrArray[currIdx]==NULLNUM){
        ptrArray[currIdx]=newNum;
        return ;
    }
    else{
        if(ptrArray[currIdx]<newNum){
            insertNum(tool->findR_ChildIdx(currIdx), newNum);
        }
        else if(ptrArray[currIdx]>newNum){
            insertNum(tool->findL_ChildIdx(currIdx), newNum);
        }
    }
}
int arrayBST::searchNum(int targetNum){
    int currIdx=0;
    while(currIdx<=lastIdx){
        if(ptrArray[currIdx]<targetNum){
            currIdx=tool->findR_ChildIdx(currIdx);
        }
        else if(ptrArray[currIdx]>targetNum){
            currIdx=tool->findL_ChildIdx(currIdx);
        }
        else{
            return ptrArray[currIdx];
        }
    }
    return NULLNUM;
}
void arrayBST::showArray(){
    for(int i=0;i<=MAXSIZE;i++){
        cout<<ptrArray[i]<<" ";
    }
    cout<<endl<<"-------------------------------------------------"<<endl;
    for(int i=0;i<MAXSIZE;i++){
        cout<<" "<<i<<" ";
    }
    cout<<endl;
}
void arrayBST::deleteNum(int currIdx, int targetNum){
    if(ptrArray[currIdx]<targetNum){
        deleteNum(tool->findR_ChildIdx(currIdx), targetNum);
    }
    else if(ptrArray[currIdx]<targetNum){
        deleteNum(tool->findL_ChildIdx(currIdx), targetNum);
    }
    else{
        if((ptrArray[tool->findL_ChildIdx(currIdx)]==NULLNUM)&&(ptrArray[tool->findR_ChildIdx(currIdx)]==NULLNUM)){
            ptrArray[currIdx]=NULLNUM;
        }
        else if((ptrArray[tool->findL_ChildIdx(currIdx)]!=NULLNUM)&&(ptrArray[tool->findR_ChildIdx(currIdx)]!=NULLNUM)){
            
        }
        else if(ptrArray[tool->findL_ChildIdx(currIdx)]!=NULLNUM){
            ptrArray[currIdx]=ptrArray[tool->findL_ChildIdx(currIdx)];
        }
        else if(ptrArray[tool->findR_ChildIdx(currIdx)]!=NULLNUM){
            ptrArray[currIdx]=ptrArray[tool->findR_ChildIdx(currIdx)];
        }
    }
}
//---------------------- main
int main(){
    arrayBST *aBST=new arrayBST();
    aBST->insertNum(0, 10);
    aBST->insertNum(0, 20);
    aBST->insertNum(0, 5);
    aBST->insertNum(0, 3);
    aBST->insertNum(0, 7);
    aBST->insertNum(0, 15);
    aBST->insertNum(0, 25);
    aBST->insertNum(0, 100);
    aBST->insertNum(0, 1);
    aBST->insertNum(0, 0);
    aBST->insertNum(0, 18);
    aBST->showArray();
}