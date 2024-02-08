#include<iostream>
using namespace std;
class toolsBox{
    public:
        int power(int base, int pow);
        int makeInt(int arrIn[], int sizeIn);
};
class oneBox{
    public:
       int size;
       int array[];
       oneBox(int arrayIn[], int sizeIn);
       void show();
};
int toolsBox::power(int base, int pow){
    if(pow==0){
        return 1;
    }
    else{
        return base*power(base, pow-1);
    }
}
int toolsBox::makeInt(int arrayIn[], int sizeIn){
    int digiNum=sizeIn-1;
    int newNum=0;
    for(int curr=0;curr<sizeIn;curr++){
        newNum=(arrayIn[curr]*power(10, digiNum))+newNum;
        digiNum--;
    }
    return newNum;
}
oneBox::oneBox(int arrayIn[], int sizeIn){
    size=sizeIn;
    for(int i=0;i<size;i++){
        array[i]=arrayIn[i];
    }
}
void oneBox::show(){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    int array[]={1, 2, 3, 4};
    toolsBox t;
    cout<<t.makeInt(array, 4);
    
}