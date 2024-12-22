#include<iostream>
using namespace std;

//------------------ main
int main(){
    int array[5]={1, 2, 3, 4, 5};
    int *ptrArr=&array[6];
    if(ptrArr==NULL){
        cout<<"NULL";
    }
    else{
        cout<<"Not NULL";
    }
}