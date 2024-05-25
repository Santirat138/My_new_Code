#include<iostream>
using namespace std;
//*********** functions ***********
int power(int base, int pow);
int toNum(int arrayIn[], int size, int currIdx, int num);
int plusNum(int num, int addNum);
int *toArray(int num);
int countDigi(int num, int currDigi);
void mainFunc(int arrayIn[], int size);
//*********** main ***********
int main(){
    int array[]={9, 9};
    int size=sizeof(array)/sizeof(array[0]);
    mainFunc(array, size);
}
//*********** functions ***********
int power(int base, int pow){
    if(pow==0){
        return 1;
    }
    else{
        return base*power(base, pow-1);
    }
}
int toNum(int arrayIn[], int size, int currIdx, int num){
    if(currIdx==size){
        return num;
    }
    else{
        num=(arrayIn[currIdx]*power(10, size-1-currIdx))+num;
        return toNum(arrayIn, size, currIdx+1, num);
    }
}
int plusNum(int num, int addNum){
    return num+addNum;
}
int *toArray(int num){
    int digi=countDigi(num, 0);
    int array[digi];
    for(int i=digi-1;i>=0;i--){
        array[i]=num%10;
        num=num/10;
    }
    int *ptrAry=array;
    return ptrAry;
}
int countDigi(int num, int currDigi){
    if(num==0){
        return currDigi;
    }
    else{
        return countDigi(num/10, currDigi+1);
    }
}
void mainFunc(int arrayIn[], int size){
    int num=toNum(arrayIn, size, 0, 0);
    int num2=plusNum(num, 1);
    int *pArray=toArray(num2);
    int newDigi=countDigi(num2, 0);
    cout<<pArray<<" ";

}