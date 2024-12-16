#include<iostream>
using namespace std;

int main(){
	int monthArray[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int untilDay=31;
	int untilMonth=12-1;
	int currDay;
	int currMonth;
	int countDay=0;
	for(currMonth=0;currMonth<=untilMonth;currMonth++){
		for(currDay=1;currDay<=monthArray[currMonth];currDay++){
			countDay++;
			if((currMonth==untilMonth)&&(currDay==untilDay)){
				cout<<countDay<<endl;
				return 0;
			}
		}
	}
}