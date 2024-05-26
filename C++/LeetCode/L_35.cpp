#include<iostream>
using namespace std;
//********* functions *********
int findIdx(int arrayIn[], int size, int currIdx, int targNum);
//********* main *********
int main(){
    int array[]={1, 3, 5, 6, 9};
    cout<<findIdx(array, 5, 0, 3);
}
//********* functions *********
int findIdx(int arrayIn[], int size, int currIdx, int targNum){
    if(currIdx<size){
        if(arrayIn[currIdx]==targNum){
            return currIdx;
        }
        else{
            return findIdx(arrayIn, size, currIdx+1, targNum);
        }
    }
    else{
        return -1;
    }
}