#include<iostream>
#include "nodeLL.h"
using namespace std;
//----------- functions -----------

//----------- main -----------
int main(){
	linkList *list1=new linkList();
	list1->addFirst(2);
	list1->addFirst(5);
	list1->showList();
}
//----------- functions -----------
