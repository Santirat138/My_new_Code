// Merge then sort.
#include<iostream>
using namespace std;
void mergeArray(int sizeIn1, int sizeIn2, int arrayIn1[], int arrayIn2[]);
// ------------- main -------------
int main(){
    int array1[]={1, 3, 5, 7, 9};
    int array2[]={0, 2, 4, 6, 8};

}
// ------------- main -------------
void mergeArray(int sizeIn1, int sizeIn2, int arrayIn1[], int arrayIn2[]){
    int size1=sizeIn1;
    int size2=sizeIn2;
    int size3=size1+size2;
    int array1[size1];
    int array2[size2];
    int array3[size3];
    for(int i=0;i<size1;i++){
        array1[i]=arrayIn1[i];
    }
    for(int i=0;i<size2;i++){
        array2[i]=arrayIn2[i];
    }
    for(int i=0;i<size3;i++){
        array3[i]
    }
}