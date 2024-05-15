#include<iostream>
using namespace std;

//************ functions ************
bool IsPalindrome(string strIn);
//************ main ************
int main(){
    string str="racecar";
    cout<<IsPalindrome(str);
}
//************ functions ************
bool IsPalindrome(string strIn){
    string str=strIn;
    int size=str.size();
    char ch[size];
    str.copy(ch, size);
    int curr=0;
    int comp=size-1;
    bool status=true;
    if((size-1)%2==0){
        while(status){
            if(curr<comp){
                if(ch[curr]==ch[comp]){
                    curr++;
                    comp--;
                }
                else{
                    status=false;
                }
            }
            else if(curr==comp){
                break;
            }
        }
    }
    else if((size-1)%2==1){
        while(status){
            if(curr!=comp){
                if(ch[curr]==ch[comp]){
                    curr++;
                    comp--;
                }
                else{
                    status=false;
                }
            }
            else if(curr==comp){
                break;
            }
        }
    }
    return status;
}