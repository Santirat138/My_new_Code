#include<iostream>
#define MAX 10
using namespace std;
//------------------------ functions
string makeRev(string strIn){
	int frontIdx=0;
	int lastIdx=strIn.length()-1;
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
	str=makeRev(str);
	cout<<str;
}