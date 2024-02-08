#include<iostream>
using namespace std;
class toolsBox{
    public:
        int power(int base, int pow);
        int countDigi(int numRem, int digi);
        int makeRev(int numIn);
};
class palinBox{
    public:
        toolsBox tool;
        int orgNum;
        int newNum;
        palinBox(int numIn);
        void checkNum();
};
int toolsBox::power(int base, int pow){
    if(pow==0){
        return 1;
    }
    else{
        return base*power(base, pow-1);
    }
}
int toolsBox::countDigi(int numRem, int digi){
    if(numRem==0){
        return digi;
    }
    else{
        return countDigi(numRem/10, digi+1);
    }
}
int toolsBox::makeRev(int numIn){
    int numRev=0;
    int numRem=numIn;
    int digi=countDigi(numRem, 0)-1;
    for(int i=digi;i>=0;i--){
        numRev=((numRem%10)*power(10, i))+numRev;
        numRem=numRem/10;
    }
    return numRev;
}
palinBox::palinBox(int numIn){
    orgNum=numIn;
    newNum=tool.makeRev(numIn);
}
void palinBox::checkNum(){
    if(orgNum==newNum){
        cout<<"True."<<endl;
    }
    else{
        cout<<"False."<<endl;
    }
}
int main(){
    palinBox paBox(123456);
    paBox.checkNum();
}