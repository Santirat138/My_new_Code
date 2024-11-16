#include<iostream>
#define MAX 12
using namespace std;

int main(){
	int monthArray[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int untilDay=31;
	int untilMonth=11;
	int currDay;
	int currMonth;
	int countDay=0;
	bool status=false;
	for(currMonth=0;currMonth<MAX;currMonth++){
		for(currDay=1;currDay<=monthArray[currMonth];currDay++){
			countDay++;
			if((currMonth==untilMonth)&&(currDay==untilDay)){
				cout<<countDay<<endl;
				status=true;
				break;
			}
		}
		if(status){
			break;
		}
	}
}