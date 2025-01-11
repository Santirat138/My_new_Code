#include<iostream>
using namespace std;
//------------------ functions
bool checkPalin(char *ptr, int size){
    int start=0;
    int end=size-1;
    int currIdx;
	while(start<end){
		currIdx=start;
		char ch1=*(ptr+currIdx);
		start++;
		currIdx=end;
		char ch2=*(ptr+currIdx);
		end--;
		if(ch1!=ch2){
			cout<<"False"<<endl;
			return false;
		}
	}
}
//------------------ main
int main(){
    string str="A man, a plan, a canal: Panama";
    int strSize=str.length();
    char *ptr=&str[0];

}