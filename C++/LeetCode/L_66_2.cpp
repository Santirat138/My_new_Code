#include<iostream>
#include<vector>
using namespace std;
//--------------- functions ---------------
void plusOne(vector<int> *pArray);
void show(vector<int> *pArray);
//--------------- main ---------------
int main(){
    vector<int> arrayNum={9, 9, 8, 9};
    plusOne(&arrayNum);
    show(&arrayNum);
}
//--------------- functions ---------------
void plusOne(vector<int> *pArray){
    int *curr=&(pArray->back());
    
}
void show(vector<int> *pArray){
    for(auto i=pArray->begin();i!=pArray->end();i++){
        cout<<*i<<" ";
    }
}