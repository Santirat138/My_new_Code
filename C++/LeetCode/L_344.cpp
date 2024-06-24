#include<iostream>
using namespace std;

//------------------------ functions ------------------------
char pop(char array[], int size, int top);
void makeRev(char array[], int size);
//------------------------ main ------------------------
int main(){
    char ch[]={'h', 'e', 'l', 'l', 'o'};    
    int size=sizeof(ch)/sizeof(ch[0]);
    makeRev(ch, size);
    for(int i=0;i<size;i++){
        cout<<ch[i]<<" ";
    }
}
//------------------------ functions ------------------------
char pop(char array[], int size, int top){
    if(top>=0){
        return array[top]; 
    }
    else{
        return '\0';
    }
}
void makeRev(char array[], int size){
    char newArray[size];
    int newCurr=0;
    int curr=size-1;
    while(curr>=0){
        newArray[newCurr]=pop(array, size, curr);
        curr--;
        newCurr++;
    }
    for(int i = 0; i < size; ++i) {
        array[i]=newArray[i];
    }
}