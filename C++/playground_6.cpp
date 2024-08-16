#include<iostream>
#include"nodeLL2.h"
using namespace std;

int main(){
    node *head=NULL;
    node **headRef=&head;
    node *tail=NULL;
    node **tailRef=&tail;

    for(int i=1;i<=5;i++){
        addFirst(headRef, tailRef, i);
    }
    deleteNode(headRef, tailRef, 2);
    showLL(*headRef);
}