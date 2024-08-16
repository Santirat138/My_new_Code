#include<iostream>
#include"openHashTable.h"
using namespace std;

int main(){
    hashTable *table=new hashTable();
    table->insertNum(1);
    table->insertNum(10);
    table->insertNum(6);
    table->insertNum(21);
    table->insertNum(500);
    table->showTable();
}