#include<iostream>
#define maxSize 15
#define nullVar -1
using namespace std;
int array[maxSize];
//-------------- functions --------------
void createTable();
int findKey(int numIn);
void insertNum(int keyIn, int newNum);
//-------------- main --------------
int main(){

}
//-------------- functions --------------
void createTable(){
    for(int i=0;i<maxSize;i++){
        array[i]=nullVar;
    }
}
int findKey(int numIn){
    return numIn%maxSize;
}
void insertNum(int keyIn, int newNum){
    int key=findKey(newNum);
    if(keyIn<maxSize){
        if(array[key]==-1){
            array[key]=newNum;
        }
        else{
            insertNum(keyIn+1, newNum);
        }
    }
    else{
        cout<<"Full."<<endl;
    }
}