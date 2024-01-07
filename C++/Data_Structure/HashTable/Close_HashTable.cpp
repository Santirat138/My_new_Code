#include<iostream>
using namespace std;
class table{
    public:
        int size;
        int array[1];
        int key;

        table(int sizeIn);
        int findKey(int numIn);
        void insertNum(int newNum);
        void show();
};
table::table(int sizeIn){
    size=sizeIn;
    array[size];
    for(int i=0;i<size;i++){
        array[i]=-1;
    }
}
int table::findKey(int numIn){
    return numIn%size;
}
void table::insertNum(int newNum){
    key=findKey(newNum);
    array[key]=newNum;
}
void table::show(){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    table table1(5);
    table1.insertNum(1);
    table1.insertNum(3);
    table1.insertNum(5);
    table1.show();
}