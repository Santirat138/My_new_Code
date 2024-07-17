#include<iostream>
#include "manyClass.h"
using namespace std;

int main(){
    int size=5;
    hashTable *table=new hashTable(size);
    table->insertNum(1);
    table->insertNum(5);
    table->insertNum(50);
    table->insertNum(25);
    table->insertNum(2);
    table->insertNum(31);
    table->deleteNum(25);
    table->showTable();
}