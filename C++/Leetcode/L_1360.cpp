#include<iostream>
#define MAXYEAR 2100
#define MAXMONTH 12
#define MAXDAY 365
using namespace std;
//------------------------- class dateBox
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
//------------------------- functions
int isFirst(bool status, int numIn){
	if(status){
		return numIn;
	}
	return 0;
}
//------------------------- main
int main(){
	int monthArray[MAXMONTH]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	dateBox startDate(29, 5, 2019);
	dateBox endDate(30, 5, 2019);
	int countDate=0;
	bool firstMonth=true;
	bool firstDay=true;
	
	for(int currYear=startDate.year;currYear<MAXYEAR;currYear++){
		int tempM=isFirst(firstMonth, startDate.month);
		for(int currMonth=tempM;currMonth<MAXMONTH;currMonth++){
			firstMonth=false;
			int tempD=isFirst(firstDay, startDate.day);
			for(int currDay=tempD;currDay<=monthArray[currMonth];currDay++){
				firstDay=false;
				if((currDay==endDate.day)&&(currMonth==endDate.month)&&(currYear==endDate.year)){
					cout<<countDate<<endl;
					return 0;
				}
				countDate++;
			}
		}
	}
}