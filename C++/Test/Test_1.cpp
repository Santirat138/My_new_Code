// Test Palindrome number.
#include<iostream>
using namespace std;
class mainBox{
    public:
        int num;
        int digiAll;
        mainBox(int numIn){
            num=numIn;
            countDigi(0, num);
        }
        void countDigi(int currDigi, int numRem){
            if(numRem==0){
                digiAll=currDigi;
            }
            else{
                countDigi(currDigi+1, numRem/10);
            }
        }
};
int main(){

}
