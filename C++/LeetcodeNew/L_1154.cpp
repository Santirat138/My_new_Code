#include<iostream>
using namespace std;
int monthArray[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//------------------ main
int main(){
    int endD=31;
    int endM=12;
    int sumDay=0;
    for(int currM=1;currM<endM;currM++){
        sumDay=monthArray[currM]+sumDay;
    }
    cout<<sumDay+endD;
}