#include<iostream>
#include "doubleLL.h"
using namespace std;

int main(){
    linkList *list1=new linkList();
    addFirst(list1, 1);
    addFirst(list1, 10);
    addFirst(list1, 100);
    cout<<findNodeAtPos(list1, 4)->num<<endl;
}