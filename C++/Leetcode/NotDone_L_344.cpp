#include<iostream>
using namespace std;
//------------------ functions

//------------------ main
int main(){
    char arrCh[]={'h', 'e', 'l', 'l', 'o'};
    char *ptrCh=&arrCh[0];
    int arrSize=sizeof(arrCh)/sizeof(arrCh[0]);
    
    for(int curr=0;curr!=arrSize;curr++){
        cout<<arrCh[curr]<<" ";
    }
}