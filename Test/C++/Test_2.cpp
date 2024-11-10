// Change money use least money.
#include<iostream>
using namespace std;

int main(){
    int moneyIn=4321;
    int moneyRem=moneyIn;
    int amount1000=0;
    int amount500=0;
    int amount100=0;
    int amount50=0;
    int amount20=0;
    int amount10=0;
    int amount5=0;
    int amount1=0;
    while(moneyRem>=1000){
        moneyRem=moneyRem-1000;
        amount1000++;
    }
    while((moneyRem<1000)&&(moneyRem>=500)){
        moneyRem=moneyRem-500;
        amount500++;
    }
    while((moneyRem<500)&&(moneyRem>=100)){
        moneyRem=moneyRem-100;
        amount100++;
    }
    while((moneyRem<100)&&(moneyRem>=50)){
        moneyRem=moneyRem-50;
        amount50++;
    }
    while((moneyRem<50)&&(moneyRem>=20)){
        moneyRem=moneyRem-20;
        amount20++;
    }
    while((moneyRem<20)&&(moneyRem>=10)){
        moneyRem=moneyRem-10;
        amount10++;
    }
    while((moneyRem<10)&&(moneyRem>=5)){
        moneyRem=moneyRem-5;
        amount5++;
    }
    while((moneyRem<5)&&(moneyRem>=1)){
        moneyRem=moneyRem-1;
        amount1++;
    }
    if(amount1000!=0){
        cout<<"Cash 1000 : "<<amount1000<<endl;
    }
    if(amount500!=0){
        cout<<"Cash 500 : "<<amount500<<endl;
    }
    if(amount100!=0){
        cout<<"Cash 100 : "<<amount100<<endl;
    }
    if(amount50!=0){
        cout<<"Cash 50 : "<<amount50<<endl;
    }
    if(amount20!=0){
        cout<<"Cash 20 : "<<amount20<<endl;
    }
    if(amount10!=0){
        cout<<"Coin 10 : "<<amount10<<endl;
    }
    if(amount5!=0){
        cout<<"Coin 5 : "<<amount5<<endl;
    }
    if(amount1!=0){
        cout<<"Coin 1 : "<<amount1<<endl;
    }
}