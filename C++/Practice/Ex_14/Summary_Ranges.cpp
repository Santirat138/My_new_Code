#include<iostream>
using namespace std;
void checkRange(int arrayIn[], int size);
int main(){
    int array[6]={0, 1, 2, 4, 5, 7};

}
void checkRange(int arrayIn[], int size){
    int currIdx=0;
    int endIdx;
    while(currIdx<size){
        if(arrayIn[currIdx]==arrayIn[currIdx]+1){
            currIdx++;
            endIdx=currIdx;
        }
    }
}