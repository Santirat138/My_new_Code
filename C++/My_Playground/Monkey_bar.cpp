// Array
#include<iostream>
using namespace std;
class aNode{
    public:
        int num;
        int next;
};
class arrayLinkList{
    public:
        int size;
        aNode array[];

        arrayLinkList(int sizeIn);
        void insertNum(int currIdx, int newNum, int nextIdx);
        void show(int currIdx);
};
arrayLinkList::arrayLinkList(int sizeIn){
    size=sizeIn;
    for(int i=0;i<size;i++){
        array[i].num=-1;
        array[i].next=-1;
    }
}
void arrayLinkList::insertNum(int currIdx, int newNum, int nextIdx){
    array[currIdx].num=newNum;
    array[currIdx].next=nextIdx;
}
void arrayLinkList::show(int currIdx){
    if(currIdx==-1){
        cout<<"End."<<endl;
    }
    else{
        cout<<array[currIdx].num<<" ";
        show(array[currIdx].next);
    }
}
int main(){
    arrayLinkList arrayLL(5);
    arrayLL.insertNum(0, 1, 4);
    arrayLL.insertNum(4, 11, 1);
    arrayLL.insertNum(1, 111, 3);
    arrayLL.insertNum(3, 1111, -1);
    arrayLL.show(0);
}