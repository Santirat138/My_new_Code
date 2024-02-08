#include<iostream>
using namespace std;
class arrayBox{
    private:
        int target;
    public:
        int size;
        int ans1, ans2;
        int array[];
    
        arrayBox(int sizeIn, int arrayIn[], int targetIn);
        void findAns();
};
arrayBox::arrayBox(int sizeIn, int arrayIn[], int targetIn){
    size=sizeIn;
    for(int i=0;i<size;i++){
        array[i]=arrayIn[i];
    }
    target=targetIn;
}
void arrayBox::findAns(){
    for(ans1=0;ans1<size-1;ans1++){
        for(ans2=ans1+1;ans2<size;ans2++){
            if(array[ans1]+array[ans2]==target){
                cout<<"Index "<<ans1<<" and index "<<ans2<<endl;
                cout<<"Number "<<array[ans1]<<" and number "<<array[ans2]<<endl<<endl;
            }
            
        }
    }
}
int main(){
    int size=5;
    int array[5]={1, 2, 3, 4, 5};
    arrayBox aBox(size, array, 4);
    aBox.findAns();
}