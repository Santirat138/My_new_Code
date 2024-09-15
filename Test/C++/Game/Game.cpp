#include<iostream>
#include<vector>
#include "Main.hpp"
using namespace std;

int main(){
    Main *m=new Main();
    vector<int> array({50, 30, 80, 25, 45, 75, 85, 20, 26, 34, 46, 72, 99, 19, 21, 29, 33, 35, 71, 73, 97, 69, 74});
    /* vector<int> ansArray({}); */
    for(int i=0;i<array.size();i++){
        m->addTree(array.at(i));
    }
    m->buildSolveLLPreorder(m->tree->root);
    
    /* for(int i=0;i<ansArray.size();i++){
        m->insertAns(ansArray.at(i));
    }
    m->checkAns(); */
    m->showSolveLL();
}