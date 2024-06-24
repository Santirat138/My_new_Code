#include<iostream>
using namespace std;
//*************** functions ***************

//*************** main ***************
int main(){
    int array[]={1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4};
    int size=sizeof(array)/sizeof(array[0]);

    int maxAmount=0;
    int currAmount=0;
    int mostNum;
    int curr=0;
    int comp=1;
    while(comp<size){
        if(array[curr]==array[comp]){
            currAmount++;
        }
        else{
            currAmount=0;
            curr=comp;
        }
        if(currAmount>maxAmount){
            mostNum=array[curr];
            maxAmount=currAmount;
        }
        comp++;
    }
    cout<<mostNum;
}
//*************** functions ***************
