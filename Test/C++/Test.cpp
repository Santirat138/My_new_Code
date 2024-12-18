#include<iostream>
using namespace std;// 1   2   3   4   5   6   7   8   9   10   11  12
int monthArray[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//------------------ functions
int getLimDayOfMonth(int mIn){
    if((mIn==1)||(mIn==3)||(mIn==5)||(mIn==7)||(mIn==8)||(mIn==10)||(mIn==12)){
        return 31;
    }
    else if((mIn==4)||(mIn==6)||(mIn==9)||(mIn==11)){
        return 30;
    }
    else if(mIn==2){
        return 28;
    }
    return 0;
}
//------------------ class dateBox
class dateBox{
	public:
		int day;
		int month;
		int year;
		dateBox(int dayIn, int monthIn, int yearIn){
			day=dayIn;
			month=monthIn;
			year=yearIn;
		}
};
//------------------ class node

//------------------ main
int main(){

}