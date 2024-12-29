// Test time calculator.
#include<iostream>

using namespace std;
//------------------ class timeBox
class timeBox{
    public:
        int hour;
        int minute;
};
//------------------ class dateBox{
class dateBox{
    public:
        int day;
        int month;
        int year;
};
//------------------ functions
void calTime(timeBox startTime, timeBox endTime){
    timeBox diffTime;
    if(startTime.minute<=endTime.minute){
        diffTime.minute=endTime.minute-startTime.minute;
        diffTime.hour=endTime.hour-startTime.hour;
    }
    else if(startTime.minute>endTime.minute){
        int minTemp=60-startTime.minute;
        diffTime.minute=minTemp+endTime.minute;
        diffTime.hour=(endTime.hour-startTime.hour)-1;
    }
    cout<<diffTime.hour<<" : "<<diffTime.minute<<endl;
}

//------------------ main
int main(){
    timeBox startT;
    timeBox endT;
    startT.hour=13;
    startT.minute=30;
    
    endT.hour=19;
    endT.minute=30;
    calTime(startT, endT);
}