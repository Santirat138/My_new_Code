#include<iostream>
using namespace std;

//------------------------ functions ------------------------
//------------------------ main ------------------------
int main(){
    char chAry[]={'h', 'e', 'l', 'l', 'o'};
    int size=sizeof(chAry)/sizeof(chAry[0]);
    char *curr1=&chAry[0];
    char *curr2=&chAry[size-1];
    char temp;

    temp=*curr1;
    *curr1=*curr2;
    *curr2=temp;
    for(int i=0;i<size;i++){
        cout<<*(curr1+i)<<" ";
    }
}
//------------------------ functions ------------------------
