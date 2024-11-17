#include<iostream>
using namespace std;

//-------------------------- functions

//-------------------------- class itemInfo
class itemInfo{
	public:
		int itemId;
		string itemName;
		int wishValue;
		int importantValue;
		int itemValue;
		void setItemInfo(int itemIdIn, string nameIn, int wishValueIn, int importantValueIn){
			itemId=itemIdIn;
            itemName=nameIn;
			wishValue=wishValueIn;
			importantValue=importantValueIn;
			itemValue=(wishValue/2)+(importantValue);
		}
		
};