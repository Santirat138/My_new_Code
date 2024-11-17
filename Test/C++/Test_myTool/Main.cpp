#include "HeapTool.hpp"

int main(){
    heap myHeap;
    myHeap.addItem(1, "aaaaa", 20, 30);
    myHeap.addItem(2, "bbbbb", 60, 20);
    myHeap.addItem(3, "ccccc", 80, 20);
    myHeap.addItem(4, "ddddd", 20, 80);
    myHeap.showArray();
}