#include<iostream>
#define defSize 1
using namespace std;
class arrayBox{
    public:
        int size;
        int array[defSize];

        arrayBox(int sizeIn, int arrayIn[]);
        void delNum(int numIn);
        void refacArray();
        void showArray(int currIdx);
};
arrayBox::arrayBox(int sizeIn, int arrayIn[]){
    size=sizeIn;
    for(int i=0;i<size;i++){
        array[i]=arrayIn[i];
    }
}
void arrayBox::delNum(int numIn){
    int currIdx;
    for(int i=0;i<size;i++){
        if(array[i]==numIn){
            array[i]=-1;
        }
    }
}
void arrayBox::refacArray(){
    int curr;
    int temp;
    for(curr=0;curr<size;curr++){
        for(temp=curr;temp<size;temp++){
            if(array[curr]==-1){
                
            }
        }
    }
}
void arrayBox::showArray(int currIdx){
    if(currIdx==size){
        cout<<"End."<<endl;
    }
    else{
        cout<<array[currIdx]<<" ";
        showArray(currIdx+1);
    }
}
int main(){
    int array[5]={1, 1, 2, 3, 4};
    arrayBox aBox(5, array);
    aBox.delNum(1);
    aBox.refacArray();
    aBox.showArray(0);
}