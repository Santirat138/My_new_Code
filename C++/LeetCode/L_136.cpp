#include<iostream>
using namespace std;
//------------------ functions
int checkArray(int arrIn[], int sizeIn){
    int *ptrArr=arrIn;
    int currNum;
    for(int curr=0;curr<sizeIn;curr++){
        for(int j=0;j<sizeIn;j++){
            if(j==0){
                currNum=*(ptrArr+curr);
            }
            if((curr==j)||(*(ptrArr+j)==-1)){
                continue;
            }
            if(*(ptrArr+j)==currNum){
                *(ptrArr+curr)=-1;
                *(ptrArr+j)=-1;
            }
        }
    }
    for(int i=0;i<sizeIn;i++){
        if(arrIn[i]!=-1){
            return arrIn[i];
        }
    }
}
void showArray(int arrayIn[], int sizeIn){
    for(int i=0;i<sizeIn;i++){
        cout<<arrayIn[i]<<" ";
    }
}
//------------------ main
int main(){
    int array[]={5, 7, 3, 9, 7, 3, 7, 5, 5};
    int arrSize=sizeof(array)/sizeof(array[0]);
    cout<<checkArray(array, arrSize);
    //showArray(array, arrSize);
}