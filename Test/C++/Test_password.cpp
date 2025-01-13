#include<iostream>
using namespace std;
//------------------ functions
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
			*(ptrArr+currI)=newNum%126;
		}
		*(ptrArr+(size-1))=(*(ptrArr+currI)+*(ptrArr+(size-1)))%126;
		nounce--;
	}
}
int getNumInChar(char chIn){
	return (int)chIn;
}
char getCharInNum(int numIn){
	return (char)numIn;
}
void showArray(int *ptrArr, int size, char choise){
	if(choise=='A'){
		for(int i=0;i<size;i++){
			cout<<*(ptrArr+i)<<" ";
		}
	}
	else if(choise=='E'){
		for(int i=0;i<size;i++){
			cout<<getCharInNum(*(ptrArr+i))<<" ";
		}
	}
	else{
		cout<<"Enter 'A' or 'E'.";
	}
	cout<<endl;
}
void mainFunc(string pswdIn, int nounce){
	int strSize=pswdIn.length();
	int pswdArr[strSize];
	int *ptrArr=pswdArr;
	for(int i=0;i<strSize;i++){
		pswdArr[i]=getNumInChar(pswdIn[i]);
	}
	spiralCal(ptrArr, strSize, nounce);
	showArray(ptrArr, strSize, 'E');
}
//------------------ main
int main(){
	string password="Pleum@1234";
	mainFunc(password, 3);
	
}