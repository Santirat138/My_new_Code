#include<iostream>
using namespace std;
//************** functions **************
int power(int base, int pow);
int makeRev(int numIn);
int countDigi(int numIn, int currDigi);
bool compareNum(int numIn);
//************** main **************
int main(){
    cout<<compareNum(123321);
}
//************** functions **************
int power(int base, int pow){
    if(pow==0){
        return 1;
    }
    else{
        return base*power(base, pow-1);
    }
}
int makeRev(int numIn){
    int numNew=0;
    int numRem=numIn;
    int numCurr;
    int numSize=countDigi(numIn, 0);
    for(int dVal=numSize-1;dVal>=0;dVal--){
        numCurr=numRem%10;
        numRem=numRem/10;
        numNew=(numCurr*power(10, dVal))+numNew;
    }
    return numNew;
}
int countDigi(int numIn, int currDigi){
    if(numIn!=0){
        return countDigi(numIn/10, currDigi+1);
    }
    else{
        return currDigi;
    }
}
bool compareNum(int numIn){
    if(numIn==makeRev(numIn)){
        return true;
    }
    else{
        return false;
    }
}