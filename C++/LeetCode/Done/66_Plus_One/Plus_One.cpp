#include<iostream>
using namespace std;
class toolsBox{
    public:
        int power(int base, int pow);
        int makeInt(int arrIn[], int sizeIn);
        int countNum(int numIn, int digi);
};
class oneBox{
    public:
        int newNum;
        toolsBox tool1;
        int size;
        int array[];
        oneBox(int arrayIn[], int sizeIn);
        void show();
        int plus1();
        void setArray();
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
int toolsBox::countNum(int numIn, int digi){
    if(numIn==0){
        return digi;
    }
    else{
        return countNum(numIn/10, digi+1);
    }
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
int oneBox::plus1(){
    int newNum=tool1.makeInt(array, size);
    newNum=newNum+1;
    return newNum;
}
void oneBox::setArray(){
    newNum=plus1();
    int numRem=newNum;
    int newSize=tool1.countNum(newNum, 0);
    for(int curr=newSize-1;curr>=0;curr--){
        array[curr]=numRem%10;
        numRem=numRem/10;
    }
    newNum=tool1.makeInt(array, newSize);
}
int main(){
    int array[]={1, 2, 3, 4};
    oneBox b(array, 4);
    b.setArray();
    cout<<b.newNum;
}