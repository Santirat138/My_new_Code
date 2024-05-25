#include<iostream>
using namespace std;
//*********** functions ***********
void show1(int &pAry);
void show2(int *pAry);
//*********** main ***********
int main(){
    int array[]={2, 4, 6};
    int *pAry=array;
    show1(*pAry);
    show2(pAry);
}
//*********** functions ***********
void show1(int &pAry){
    cout<<pAry<<endl;
}
void show2(int *pAry){
    cout<<*pAry<<endl;
}