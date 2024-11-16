#include<iostream>
#define MAX 10
using namespace std;
//------------------------ functions
string makeRev(string strIn, int untilIdx){
	int frontIdx=0;
	int lastIdx=untilIdx-1;
	while(frontIdx<lastIdx){
		swap(strIn[frontIdx], strIn[lastIdx]);
		frontIdx++;
		lastIdx--;
	}
	return strIn;
}
//------------------------ main
int main(){
	string str="pleum";
	str=makeRev(str, 3);
	cout<<str;
}