#include<iostream>
#define D_IN_Y 356
using namespace std;
int monthArray[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
        void setDate(int dIn, int mIn, int yIn){
            day=dIn;
            month=mIn;
            year=yIn;
        }
};

//------------------ functions
bool isFull_Y(dateBox sDate, dateBox eDate){
    if(eDate.year-sDate.year==1){
        if((eDate.month==sDate.month)&&(eDate.day>=sDate.day)){
            return true;
        }
        else if(eDate.month>sDate.month){
            return true;
        }
    }
    else if(eDate.year-sDate.year>1){
        return true;
    }
    return false;
}
int get_nDay(dateBox sDate, dateBox eDate){

}
//------------------ main
int main(){
    dateBox startDate;
    dateBox endDate;
    startDate.setDate(15, 12, 2001);
    endDate.setDate(15, 1, 2002);
    
}