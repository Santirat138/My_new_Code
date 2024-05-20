#include<iostream>
using namespace std;
int array[7]={1, 4, 3, 3, 5, 2, 1};

int main(){
    int num=6;
    int size=7;
    for(int c1=0;c1<size-1;c1++){
        for(int c2=c1+1;c2<size;c2++){
            if(array[c1]+array[c2]==num){
                cout<<array[c1]<<" "<<array[c2]<<endl;
            }
        }
    }
}