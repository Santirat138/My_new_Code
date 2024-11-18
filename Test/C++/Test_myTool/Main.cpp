#include "HeapTool.hpp"
//-------------------------- functions
heap removeTop_itemValue(heap heapIn){
    cout<<"ID: "<<heapIn.array[0].itemId<<"\titemValue: "<<heapIn.array[0].itemValue<<endl;
    heapIn.deleteRoot();
    return heapIn;
}
heap modifyValue(heap heapIn, int target_id, int new_wishValue, int new_importantValue){
    for(int i=0;i<heapIn.last;i++){
        int id=heapIn.array[i].itemId;
        if(id==target_id){
            heapIn.array[i].wishValue=new_wishValue;
            heapIn.array[i].importantValue=new_importantValue;
            heapIn.array[i].itemValue=getItemVal(new_wishValue, new_importantValue);
            break;
        }
    }
    return heapIn;
}
//-------------------------- main
int main(){
    heap myHeap;
    myHeap.addItem(1001, "item_1", 20, 30);
    myHeap.addItem(1002, "item_2", 60, 20);
    myHeap.addItem(1003, "item_3", 80, 20);
    myHeap.addItem(1004, "item_4", 20, 80);
    myHeap.showArray();
    myHeap=modifyValue(myHeap, 1004, 1, 2);
    cout<<endl;
    myHeap.showArray();
}