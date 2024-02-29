#include<iostream>
using namespace std;
void countRange(int sizeIn, int arrayIn[]);
int main(){
    int size=9;
    int array[]={1, 2, 3, 4, 5, 7, 19, 20, 21};
    countRange(size, array);
}
void countRange(int sizeIn, int arrayIn[]){
    int size=sizeIn;
    int array[size];
    for(int i=0;i<size;i++){
        array[i]=arrayIn[i];
    }
    int stand=0;
    int curr=1;
    int walk=1;
    while(stand<size){
        if(curr<size){
            if(array[stand]+walk==array[curr]){
                curr++;
                walk++;
            }
            else if(array[stand]+walk!=array[curr]){
                cout<<array[stand]<<" "<<array[curr-1]<<endl;
                stand=curr;
                curr++;
                walk=1;
            }
        }
        else if(curr==size){
            cout<<array[stand]<<" "<<array[curr-1]<<endl;
            break;
        }
    }
}