#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> array;
    for(int i=0;i<=10;i++){
        array.push_back(i);
    }
    for(int i=0;i<array.size()-1;i++){
        cout<<array[i]<<" ";
    }
}