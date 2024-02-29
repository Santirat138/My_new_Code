// Merge array, array with pointer.
#include<iostream>
using namespace std;
int countArray(int arrayIn[]);
void mergeArray(int array1[], int array2[]);
int main(){
    int array[]={1, 2, 3, 4, 5, 6, 7};
    cout<<countArray(array);
}
int countArray(int arrayIn[]){
    int *curr=&arrayIn[0];
    int amount=0;
    int i=0;
    while(curr!=NULL){
        *curr=(*curr+1);
        amount++;
    }
    return amount;
}
void mergeArray(int array1[], int array2[]){

}