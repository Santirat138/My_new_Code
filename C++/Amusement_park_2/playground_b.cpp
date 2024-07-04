#include<iostream>
#include "manyClass.h"
using namespace std;

int main(){
    linkList *list1=new linkList();
    list1->addSort(5);
    list1->addSort(10);
    list1->addSort(15);
    list1->addSort(13);
    list1->showLL(list1->head, 1);
}