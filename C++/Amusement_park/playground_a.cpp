#include<iostream>
#include "FuncNode.h"
using namespace std;

int main(){
    linkList *list1=new linkList();
    list1->addSort(5);
    list1->addSort(10);
    list1->addSort(15);
    list1->addSort(2);
    list1->addSort(4);
    list1->addSort(6);
    list1->addSort(8);
    list1->addSort(12);
    list1->addSort(14);
    list1->addSort(20);

    list1->showLL(list1->head);
}