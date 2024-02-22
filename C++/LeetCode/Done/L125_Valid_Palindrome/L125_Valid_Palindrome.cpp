#include<iostream>
using namespace std;
void check(string strIn);
int main(){
    string txtIn="PleummuelP";
    check(txtIn);
}
void check(string strIn){
    int amount=strIn.length();
    char array[amount];
    bool status=true;
    for(int i=amount-1, j=0;i>=0;i--, j++){
        array[j]=strIn[i];
    }
    for(int i=0;i<amount;i++){
        if(array[i]!=strIn[i]){
            status=false;
            break;
        }
    }
    if(status){
        cout<<"True."<<endl;
    }   
    else{
        cout<<"False."<<endl;
    }
}