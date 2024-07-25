#include<iostream>
#include "FuncNode.h"
using namespace std;

int main(){
    linkList *list=new linkList();
    list->addSort(5);
    list->addSort(50);
    list->addSort(1);
    list->addSort(10);
    list->showLL(list->head, 2);
}