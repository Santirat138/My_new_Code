#include<iostream>
using namespace std;
int countDigi(int numRem, int currDigi);
//**************************************
int main(){
    cout<<countDigi(1203450, 0);
}
//**************************************
int countDigi(int numRem, int currDigi){
    if(numRem>0){
        return countDigi(numRem/10, currDigi+1);
    }
    else{
        return currDigi;
    }
}