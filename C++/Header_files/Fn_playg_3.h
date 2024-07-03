// Header file.
#include<iostream>
#include<vector>
using namespace std;
vector<int> *mainArray;
int size;
void createTable(int sizeIn){
    size=sizeIn;
    mainArray->assign(size, -1);
}
int findKey(int numIn){
    return numIn%size;
}
void insertNum(int newNum){
    int idx=findKey(newNum);
    if(mainArray->front()+idx==-1){
        mainArray->insert(mainArray->begin()+idx, newNum);
    }
    else{
        cout<<idx<<" not empty."<<endl;
        while(true){
            if(mainArray->front()+idx!=-1){
                mainArray->insert(mainArray->begin()+idx, newNum);
                break;
            }
            else{
                idx++;
            }
        }
        
    }
}
void show(){
    for(auto curr=mainArray->begin();curr!=mainArray->end();curr++){
        cout<<*curr<<" ";
    }
}
