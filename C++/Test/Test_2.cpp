// Test makeRev function.
#include<iostream>
using namespace std;
int power(int base, int pow);
int countDigi(int numRem, int digi);
int makeRev(int numRem);
int main(){
    cout<<makeRev(1234);
}
int power(int base, int pow){
    if(pow==0){
        return 1;
    }
    else{
        return base*power(base, pow-1);
    }
}
int countDigi(int numRem, int digi){
    if(numRem==0){
        return digi;
    }
    else{
        return countDigi(numRem/10, digi+1);
    }
}
int makeRev(int numRem){
    int numRev=0;
    int digi=countDigi(numRem, 0)-1;
    for(int i=digi;i>=0;i--){
        numRev=((numRem%10)*power(10, i))+numRev;
        numRem=numRem/10;
    }
    return numRev;
}