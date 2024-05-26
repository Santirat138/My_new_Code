#include<iostream>
using namespace std;

//************ function ************
bool check(string strIn, int curr, int comp, bool status);
//************ main ************
int main(){
    string str="ppapp";
    int size=str.length();
    cout<<check(str, 0, size-1, true);
}
//************ function ************
bool check(string strIn, int curr, int comp, bool status){
    if(strIn[curr]==strIn[comp]){
        check(strIn, curr+1, comp-1, true);
    }
    else{
        status=false;
    }
    return status;
}