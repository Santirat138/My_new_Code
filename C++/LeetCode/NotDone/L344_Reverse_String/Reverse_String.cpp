#include<iostream>
using namespace std;
//********* functions *********
string makeRev(string strIn);
//********* main *********
int main(){
    string mainStr="pleum";
    cout<<makeRev(mainStr);
}
//********* functions *********
string makeRev(string strIn){
    string str=strIn;
    string newStr;
    int size=str.size();
    char ch[size];
    char newCh[size];
    str.copy(ch, size);
    for(int i=0, j=size-1;i<size;i++, j--){
        newCh[j]=ch[i];
    }
    
    return 0;
}