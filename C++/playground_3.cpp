// Vector array hash table.
#include<iostream>
#include<vector>
#include "Fn_playg_3.h"
using namespace std;

//-------------- functions --------------

//-------------- main --------------
int main(){
    size=10;
    vector<int> array;
    mainArray=&array;
    createTable(size);
    insertNum(150);
    insertNum(170);
    show();
}
//-------------- functions --------------
