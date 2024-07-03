#include<iostream>
#include<vector>
using namespace std;
//------------ functions ------------
void makeRevChar(string strIn, vector<char> *pAry);
void show(vector<char> *pAry);
void check(string strIn, vector<char> *pAry);
//------------ main ------------
int main(){
    string str={"pleum"};
    vector<char> chArray;
    makeRevChar(str, &chArray);
    check(str, &chArray);
}
//------------ functions ------------
void makeRevChar(string strIn, vector<char> *pAry){
    for(int i=0;i<strIn.size();i++){
        pAry->insert(pAry->begin(), strIn[i]);
    }
}
void show(vector<char> *pAry){
    for(auto i=pAry->begin();i!=pAry->end();i++){
        cout<<*i<<" ";
    }
}
void check(string strIn, vector<char> *pAry){
    int curr=0;
    bool status=true;
    for(auto i=pAry->begin();i!=pAry->end();i++){
        if(*i!=strIn[curr]){
            status=false;
            break;
        }
        curr++;
    }
    cout<<status<<endl;
}