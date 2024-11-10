#include<iostream>
#define MAX 10
#define NULLNUM -1
using namespace std;
//------------------------ class numInfo
class numInfo{
    public:
        int num;
        int amount;
        numInfo(){
            num=NULLNUM;
            amount=0;
        }
};
//------------------------ class arrayBox
class arrayBox{
    public:
        int array[MAX]={1, 4, 1, 1, 4, 1, 7, 1, 7, 1};
        numInfo currNum;
        numInfo mostNum;
        int check();
};
int arrayBox::check(){
    for(int curr=0;curr<MAX;curr++){
        currNum.num=array[curr];
        currNum.amount=0;
        for(int check=0;check<MAX;check++){
            if(array[check]==currNum.num){
                currNum.amount++;
            }
        }
        if(currNum.amount>=mostNum.amount){
            mostNum.num=currNum.num;
            mostNum.amount=currNum.amount;
        }
    }
    return mostNum.num;
}
//------------------------ main
int main(){
    arrayBox box;
    cout<<box.check();
}