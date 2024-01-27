#include<iostream>
using namespace std;
class palinBox{
    public:
        int num;
        int digi;
        int newNum;

        palinBox(int numIn);
        void countDigi(int numRem, int currDigi);
        int power(int base, int pow, int ans);
        void check();
};
palinBox::palinBox(int numIn){
    num=numIn;
    newNum=0;
    digi=0;
}
void palinBox::countDigi(int numRem, int currDigi){
    if(numRem==0){
        digi=currDigi;
    }
    else{
        countDigi(numRem/10, currDigi+1);
    }
}
int palinBox::power(int base, int pow, int ans){
    if(pow==0){
        return ans;
    }
    else{
        return power(base, pow-1, ans*base);
    }
}
void palinBox::check(){
    int numRem=num;
    countDigi(numRem, 0);
    for(int i=digi-1;i>=0;i--){
        newNum=((numRem%10)*power(10, i, 1)+newNum);
        numRem=numRem/10;
    }
    if(newNum==num){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}
int main(){
    palinBox palin(1234);
    palin.check();
}