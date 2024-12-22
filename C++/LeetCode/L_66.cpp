#include<iostream>
#include<vector>
#define MAX 10
using namespace std;
//---------------------- functions
vector<int> plusOne(vector<int> arrayIn);
//---------------------- main
int main(){
    vector<int> array({9, 9, 9, 9, 9});
    array=plusOne(array);
    for(int curr=0;curr<array.size();curr++){
        cout<<array.at(curr)<<" ";
    }
}
//---------------------- functions
vector<int> plusOne(vector<int> arrayIn){
    arrayIn.back()=arrayIn.back()+1;
    if(arrayIn.back()==10){
        for(int curr=arrayIn.size()-1;curr>0;curr--){
            if(arrayIn.at(curr)==10){
                arrayIn.at(curr)=0;
                arrayIn.at(curr-1)=arrayIn.at(curr-1)+1;
            }
        }
    }
    return arrayIn;
}