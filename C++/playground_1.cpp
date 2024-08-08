#include<iostream>
#include "nodeLL.h"
using namespace std;

//----------- main -----------
int main(){
	linkList *list1=new linkList;
    for(int i=0;i<5;i++){
        addFirst(list1, i);
    }
    deleteNode(list1, 2);
    showLL(list1);
}
