// Sort array data.
#include<iostream>
using namespace std;
//--------------- class
class data{
    public:
        int id;
        int num;
};
//--------------- functions
void showData(data *pBox, int size);
void swapData(data *pBox, int idx1, int idx2);
void sortId(data *pBox, int size);
//--------------- main
int main(){
    int size=5;
    data box[size];
    for(int i=0;i<size;i++){
        box[i].id=i+101;
    }
    showData(box, size);
    sortId(box, size);
    showData(box, size);
}
//--------------- functions
void showData(data *pBox, int size){
    for(int i=0;i<size;i++){
        cout<<(pBox+i)->id<<" ";
    }
    cout<<endl;
}
void swapData(data *pBox, int idx1, int idx2){
    data temp=*(pBox+idx1);
    *(pBox+idx1)=*(pBox+idx2);
    *(pBox+idx2)=temp;
}
void sortId(data *pBox, int size){
    data maxIdBox;
    for(int i=0;i<size;i++){
        maxIdBox=*(pBox+i);
        for(int j=i+1;j<size;j++){
            if((pBox+j)->id>maxIdBox.id){
                maxIdBox=*(pBox+j);
                swapData(pBox, i, j);
            }
        }
    }
}