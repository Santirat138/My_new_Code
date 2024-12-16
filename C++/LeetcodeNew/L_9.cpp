#include<iostream>
#include<cmath>
using namespace std;
//------------------ functions
int countDigi(int numIn){
    int currDigi=0;
    while(numIn!=0){
        numIn=numIn/10;
        currDigi++;
    }
    return currDigi;
}

//------------------ main
int main(){
    int temp=0;
    int mainNum=12021;
    int num=mainNum;
    int digiSize=countDigi(num);
    for(int i=digiSize-1;i>=0;i--){
        temp=((num%10)*pow(10, i))+temp;
        num=num/10;
    }
    if(temp==mainNum){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}