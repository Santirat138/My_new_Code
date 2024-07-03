// Vector array hash table.
#include<iostream>
#include<vector>
using namespace std;
int size=10;
//-------------- functions --------------
int findKey(int numIn);
void insertNum(vector<int> &arrayIn, int newNum);
//-------------- main --------------
int main(){
    vector<int> array;
    insertNum(array, 1);
    insertNum(array, 2);
    for(auto i=array.begin();i!=array.end();i++){
        cout<<*i<<" ";
    }
}
//-------------- functions --------------
int findKey(int numIn){
    return numIn%size;
}
void insertNum(vector<int> &arrayIn, int newNum){
    arrayIn.push_back(newNum);
}