#include "Info.hpp"

int main(){
    itemInfo item1;
    item1.info.setValueInfo(10, 10);
    item1.setItemInfo(1, "aaa", item1.info);
    cout<<item1.itemValue<<" "<<item1.info.importantValue;
}