#include<iostream>
using namespace std;

int main(){
    int size=5;
    int array[]={1, 2, 3, 4, 5};
    int target=5;

    for(int i=size-1;i>=0;i--){
        for(int j=0;j<size-1;j++){
            if(array[i]+array[j]==target){
                cout<<"Number "<<array[i]<<" "<<array[j]<<endl;
                cout<<"Index "<<i<<" "<<j<<endl<<endl;
            }
        }
    }
}