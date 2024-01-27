#include<iostream>
#define defSize 1
using namespace std;
class arrayBox{
    private:
        int plusNum;
    public:
        int size;
        int oldNum;
        int newNum;
        int oldArray[defSize];
        int newArray[defSize];

        arrayBox(int sizeIn, int arrayIn[]);
        int power(int base, int pow);
        void makeNum();
        void makeNewArray();
        void show();
};
arrayBox::arrayBox(int sizeIn, int arrayIn[]){
    plusNum=1;
    size=sizeIn;
    for(int i=0;i<size;i++){
        oldArray[i]=arrayIn[i];
    }
}
int arrayBox::power(int base, int pow){
    if(pow==0){
        return 1;
    }
    else{
        return base*power(base, pow-1);
    }
}
void arrayBox::makeNum(){
    oldNum=0;
    for(int i=size-1, j=0;i>=0;i--, j++){
        oldNum=(oldArray[j]*power(10, i))+oldNum;
    }
    newNum=oldNum+plusNum;
}
void arrayBox::makeNewArray(){
    int digi=0;
    int numRem=newNum;
    while(numRem>0){
        numRem=numRem/10;
        digi++;
    }
    size=digi;
    for(int k=size-1;k>=0;k--){
        newArray[k]=newNum%10;
        newNum=newNum/10;
    }
}
void arrayBox::show(){
    makeNum();
    makeNewArray();
    for(int i=0;i<size;i++){
        cout<<newArray[i]<<" ";
    }
}
int main(){
    int array[4]={4, 8, 9, 9};
    arrayBox box1(4, array);
    box1.show();
}