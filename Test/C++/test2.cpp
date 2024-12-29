#include<iostream>
#define MAXMONTH 13
using namespace std;
int monthArray[MAXMONTH]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//------------------ functions
int calcuM(int mIn){
    if(mIn>12){
        return 1;
    }
    else if(mIn<1){
        return 12;
    }
    return mIn;
}
int calcuHeadTail_nDay(int mIn, char startType){
    // startType(s) = start from startDate
    // startType(e) = start from endDate
    int sumDay=0;
    if(startType=='s'){
        for(int currM=mIn;currM<=12;currM++){
            sumDay=sumDay+monthArray[currM];
        }
    }
    else if(startType=='e'){
        for(int currM=mIn;currM>=1;currM--){
            sumDay=sumDay+monthArray[currM];
        }
    }
    return sumDay;
}
//------------------ class dateBox
class dateBox{
	public:
		int day;
		int month;
		int year;
        
};
//------------------ class toolsBox
class toolsBox{
    public:
    	dateBox sDate;
	    dateBox eDate;
        int calcuDay(){
            int n_D=0;
            /* int n_M=0;*/
            int n_Y=0;
            if(eDate.year-sDate.year>=3){
                int new_sY=sDate.year+1;
                int new_eY=eDate.year-1;
                // Get n year of leap year.
                n_Y=(new_eY-new_sY)+1;
                int n_Leap_Y=n_Y%4;
                // Get n day of full year.
                n_D=(365*n_Y)+(4*n_Leap_Y);
                
                int new_sM=calcuM(sDate.month+1);
                int new_eM=calcuM(eDate.month-1);

                // Get n day of head tail full month to start end of year.
                n_D=n_D+calcuHeadTail_nDay(new_sM, 's')+calcuHeadTail_nDay(new_eM, 'e');

                n_D=n_D+(monthArray[sDate.month]-sDate.day)+eDate.day;
            }
            else if(eDate.year-sDate.year<3){

            }
            return n_D;
        }
};
//------------------ main
int main(){
    toolsBox tool;
    tool.sDate.day=2;
    tool.sDate.month=10;
    tool.sDate.year=2001;
    tool.eDate.day=15;
    tool.eDate.month=6;
    tool.eDate.year=2030;
    cout<<tool.calcuDay();
}