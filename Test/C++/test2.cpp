// Test password.
#include<iostream>
using namespace std;
//------------------ variable

//------------------ functions
void spiralCal(int array[], int size, int nounce){
	while(nounce>0){
		int startI=size-1;
		int endI=0;
		int currI=startI;
		int newNum=0;
		while(startI>endI){
			newNum=array[endI]+array[startI];
			if(currI>=size/2){
				currI=endI;
				startI--;
			}
			else if(currI<size/2){
				currI=startI;
				endI++;
			}
			array[currI]=newNum;
		}
		array[size-1]=array[currI]+array[size-1];
		nounce--;
	}
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
}
//------------------ main
int main(){
	int size=4;
	int array[]={1, 2, 3, 4};
	spiralCal(array, size, 2);
}