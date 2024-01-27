#include<iostream>
using namespace std;
class arrayBox{
    public:
        int size;
        int array[];

        arrayBox(int sizeIn);
        void showArray();
        void changeNum(int idxIn, int newNum);
};
arrayBox::arrayBox(int sizeIn){
    size=sizeIn;
}
void arrayBox::showArray(){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}
void arrayBox::changeNum(int idxIn, int newNum){
    array[idxIn]=newNum;
}
int main(){
    arrayBox *arr1=new arrayBox(5);
    for(int i=0;i<5;i++){
        arr1->array[i]=i*2;
    }
    arr1->changeNum(1, 50);
    arr1->showArray();
}
