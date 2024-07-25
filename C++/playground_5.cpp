#include<iostream>
#include "doubleLL.h"
using namespace std;

int main(){
    linkList *list=new linkList();
    list->addSort(1000);
    list->addSort(20);
    list->addSort(30);
    list->addSort(14);
    

    cout<<list->findNodeAtPos(8)->num;
}