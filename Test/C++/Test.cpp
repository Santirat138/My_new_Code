#include<iostream>
using namespace std;
//------------------ variable

//------------------ functions
void showArray(int *ptrArr, int size){
	for(int i=0;i<size;i++){
		cout<<*(ptrArr+i)<<" ";
	}
}
void spiralCal(int *ptrArr, int size, int nounce){
	while(nounce>0){
		int startI=size-1;
		int endI=0;
		int currI=startI;
		int newNum=0;
		while(startI>endI){
			newNum=*(ptrArr+startI)+*(ptrArr+endI);
			if(currI>=size/2){
				currI=endI;
				startI--;
			}
			else if(currI<size/2){
				currI=startI;
				endI++;
			}
			*(ptrArr+currI)=newNum;
		}
		*(ptrArr+(size-1))=*(ptrArr+currI)+*(ptrArr+(size-1));
		nounce--;
	}
}
int getNumInChar(char chIn){
	return (int)chIn;
}
void mainFunc(string pswdIn, int nounce){
	int strSize=pswdIn.length();
	int pswdArr[strSize];
	int *ptrArr=pswdArr;
	for(int i=0;i<strSize;i++){
		pswdArr[i]=getNumInChar(pswdIn[i]);
	}
	spiralCal(ptrArr, strSize, nounce);
	showArray(ptrArr, strSize);
}
//------------------ main
int main(){
	string password="Pleum@123";
	mainFunc(password, 1);
}