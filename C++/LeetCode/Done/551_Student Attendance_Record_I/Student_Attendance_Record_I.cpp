#include<iostream>
using namespace std;
class checkBox{
    private:
        int size;
        string record;
        float status;
    public:
        int nA, nL, nP;
        checkBox(int sizeIn, string recordIn);
        void countRec(float status, int currIdx);
        void showStatus();
};
checkBox::checkBox(int sizeIn, string recordIn){
    size=sizeIn;
    record=recordIn;
}
void checkBox::countRec(float statusIn, int currIdx){
    if(currIdx==size-1){
        status=statusIn;
    }
    else{
        if(record[currIdx]=='A'){
            statusIn=statusIn-0.5;
        }
        else if(record[currIdx]=='L'){
            statusIn=statusIn-0.25;
        }
        else if(record[currIdx]=='P'){
            statusIn=statusIn;
        }
        countRec(statusIn, currIdx+1);
    }
}
void checkBox::showStatus(){
    countRec(0, 0);
    if(status<=-1){
        cout<<"Not pass."<<endl;
    }
    else{
        cout<<"Pass."<<endl;
    }
}
int main(){
    string status="PPPP";
    int size=4;
    checkBox cBox(size, status);
    cBox.showStatus();
}