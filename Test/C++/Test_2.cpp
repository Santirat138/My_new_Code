// Array Binary search tree.
#include<iostream>
#define MAX 20
#define NULLNUM -1
using namespace std;
//-------------------------- class arrayBST
class arrayBST{
    public:
        int array[MAX];
        int root;
        arrayBST(){
            for(int i=0;i<MAX;i++){
                array[i]=NULLNUM;
            }
        }
        int findLeftIdx(int idxIn);
        int findRightIdx(int idxIn);
        int findParentIdx(int idxIn);
        void insertNum(int currIdx, int newNum);
        void showArray();
        int findMaxLeftIdx(int currIdx);
        void deleteNum(int currIdx, int targetNum);
};
int arrayBST::findLeftIdx(int idxIn){
    return (idxIn*2)+1;
}
int arrayBST::findRightIdx(int idxIn){
    return (idxIn*2)+2;
}
int arrayBST::findParentIdx(int idxIn){
    return idxIn/2;
}
void arrayBST::insertNum(int currIdx, int newNum){
    if(currIdx>MAX){
        cout<<"Out of index."<<endl<<"Can't add "<<newNum<<"."<<endl;
        return ;
    }
    if(array[currIdx]==NULLNUM){
        array[currIdx]=newNum;
    }
    else{
        if(array[currIdx]<newNum){
            if(array[findRightIdx(currIdx)]!=NULLNUM){
                insertNum(findRightIdx(currIdx), newNum);
            }
            else{
                array[findRightIdx(currIdx)]=newNum;
            }
        }
        else if(array[currIdx]>newNum){
            if(array[findLeftIdx(currIdx)]!=NULLNUM){
                insertNum(findLeftIdx(currIdx), newNum);
            }
            else{
                array[findLeftIdx(currIdx)]=newNum;
            }
        }
    }
}
void arrayBST::showArray(){
    for(int i=0;i<MAX;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int arrayBST::findMaxLeftIdx(int currIdx){
    if(array[findLeftIdx(currIdx)]!=NULLNUM){
        int maxLeftIdx=findLeftIdx(currIdx);
        while(maxLeftIdx<MAX){
            if(array[findRightIdx(maxLeftIdx)]!=NULLNUM){
                return findRightIdx(maxLeftIdx);
            }
            else{
                maxLeftIdx=findRightIdx(maxLeftIdx);
            }
        }
    }
    return NULLNUM;
}
void arrayBST::deleteNum(int currIdx, int targetNum){
    if((targetNum<array[currIdx])&&(array[currIdx]!=NULLNUM)){
        deleteNum(findLeftIdx(currIdx), targetNum);
    }
    else if((targetNum>array[currIdx])&&(array[currIdx]!=NULLNUM)){
        deleteNum(findRightIdx(currIdx), targetNum);
    }
    else{
        if((array[findLeftIdx(currIdx)]==NULLNUM)&&(array[findRightIdx(currIdx)]==NULLNUM)){
            array[currIdx]=NULLNUM;
        }
        else if((array[findLeftIdx(currIdx)]!=NULLNUM)&&(array[findRightIdx(currIdx)]!=NULLNUM)){
            int maxLeftNum=array[findMaxLeftIdx(currIdx)];
            array[currIdx]=maxLeftNum;
            deleteNum(findLeftIdx(currIdx), maxLeftNum);
        }
        else if(array[findLeftIdx(currIdx)]!=NULLNUM){
            int temp=array[findLeftIdx(currIdx)];
            array[currIdx]=temp;
            array[findLeftIdx(currIdx)]=NULLNUM;
        }
        else if(array[findRightIdx(currIdx)]!=NULLNUM){
            int temp=array[findRightIdx(currIdx)];
            array[currIdx]=temp;
            array[findRightIdx(currIdx)]=NULLNUM;
        }
    }
}
//-------------------------- main
int main(){
    arrayBST arrBST;
    arrBST.insertNum(0, 5);
    arrBST.insertNum(0, 3);
    arrBST.insertNum(0, 10);
    arrBST.insertNum(0, 8);
    arrBST.insertNum(0, 20);
    arrBST.insertNum(0, 1);
    arrBST.insertNum(0, 9);
    arrBST.deleteNum(0, 5);
    arrBST.showArray();

}