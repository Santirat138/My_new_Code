#include<iostream>
#include<vector>
#define SIZE 15
using namespace std;
//------------------ functions
vector<int> checkArray(vector<int> arrV){
    for(int i=0;i<arrV.size();i++){
        for(int j=0;j<arrV.size();j++){
            if((i==j)||(arrV.at(j)==-1)){
                continue;
            }
            if(arrV.at(i)==arrV.at(j)){
                arrV.at(i)=-1;
                arrV.at(j)=-1;
            }
        }
    }
    return arrV;
}
void showArray(vector<int> arrV){
    for(int i=0;i<arrV.size();i++){
        cout<<arrV[i]<<" ";
    }
}
//------------------ main
int main(){
    int mainArray[SIZE]={1, 1, 5, 5, 8, 7, 7, 9, 6, 9, 6};
    int size=sizeof(mainArray)/sizeof(mainArray[0]);
    vector<int> arrayV(mainArray, mainArray+size);
    arrayV=checkArray(arrayV);
    showArray(arrayV);
}