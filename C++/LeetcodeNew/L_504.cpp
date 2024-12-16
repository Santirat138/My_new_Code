#include<iostream>
#define SIZE 10
using namespace std;
//------------------ variable
int stackArr[10];
int top=0;
//------------------ functions
void push(int numIn){
    stackArr[top++]=numIn;
}
//------------------ main
int main(){
    int mainNum=1234;
    int num=mainNum;
    int scrapNum;
    int devideAns;
    do{
        devideAns=num/7;
        scrapNum=num-(7*devideAns);
        num=devideAns;
        push(scrapNum);
    }
    while(devideAns!=0);
    for(int i=top-1;i>=0;i--){
        cout<<stackArr[i];
    }
}