#include<iostream>
#include<vector>
#include "Main.hpp"
using namespace std;

int main(){
    Main *m=new Main();
    vector<int> array({50, 42, 88, 20, 44, 73, 89, 15, 21});
    // Your answer.
    vector<int> ansArray({/*-----------*/});
    for(int i=0;i<ansArray.size();i++){
        m->insertAns(ansArray.at(i));
    }

    for(int i=0;i<array.size();i++){
        m->addTree(array.at(i));
    }
    m->buildSolveLLInorder(m->tree->root);
    m->checkAns();
    m->showSolveLL();
}