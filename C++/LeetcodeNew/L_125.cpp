#include<iostream>
using namespace std;
//------------------------ functions
bool isPalindrome(string strIn);
//------------------------ main
int main(){
	string str="ark ra";
	cout<<isPalindrome(str);
}
//------------------------ functions
bool isPalindrome(string strIn){
	int size=strIn.length();
	for(int curr1=0, curr2=size-1;curr1!=curr2;curr1++, curr2--){
		if(strIn[curr1]!=strIn[curr2]){
			return false;
		}
	}
	return true;
}