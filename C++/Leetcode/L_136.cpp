// Test hash table.
#include<iostream>
#define SIZE 15
using namespace std;
//------------------ functions
int getKey(int numIn){
    return numIn%SIZE;
}
void showSingleNum(int arr[SIZE][2]){
    for(int i=0;i<SIZE;i++){
        if((arr[i][0]!=-1)&&(arr[i][1]==-1)){
            cout<<arr[i][0]<<endl;
        }
    }
}
//------------------ class hashTable
class hashTable{
    public:
        int array[SIZE][2];
        hashTable(){
            for(int i=0;i<SIZE;i++){
                array[i][0]=-1;
                array[i][1]=-1;
            }
        }
        void addNum(int newNum){
            int key=getKey(newNum);
            if(array[key][0]==-1){
                array[key][0]=newNum;
                return ;
            }
            if(array[key][1]==-1){
                array[key][1]=newNum;
                return ;
            }
            else if(array[key][1]!=-1){
                cout<<"Full"<<"("<<newNum<<")"<<endl;
            }
        }
        void showHashTable(){
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<2;j++){
                    cout<<array[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};
//------------------ main
int main(){
    hashTable ht;
    int arrayNum[]={3, 3, 21, 3, 21, 21, 1, 2, 4, 4, 3, 3, 3, 80, 2};
    for(int i=0;i<sizeof(arrayNum)/sizeof(arrayNum[0]);i++){
        ht.addNum(arrayNum[i]);
    }
    showSingleNum(ht.array);
}