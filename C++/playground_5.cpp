#include<iostream>
#include "doubleLL.h"
using namespace std;

int main(){
    linkList *list=new linkList();
    list->addSort(2);
    list->addSort(4);
    list->addSort(6);
    list->addSort(1);
    list->addSort(3);
    list->showLL();
}