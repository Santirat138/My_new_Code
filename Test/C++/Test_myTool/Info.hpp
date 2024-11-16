#include<iostream>
using namespace std;

//-------------------------- functions
//-------------------------- class valueInfo
class valueInfo{
	public:
		int wishValue;
		int importantValue;
		void setValueInfo(int wishValIn, int importantValIn){
			wishValue=wishValIn;
			importantValue=importantValIn;
		}
};
//-------------------------- class itemInfo
class itemInfo{
	public:
		valueInfo info;
		int itemId;
		string itemName;
		int itemValue;
		void setItemInfo(int itemIdIn, string nameIn, valueInfo infoIn){
			itemId=itemIdIn;
            itemName=nameIn;
			info.wishValue=infoIn.wishValue;
			info.importantValue=infoIn.importantValue;
			itemValue=(info.wishValue/2)+(info.importantValue);
		}
		
};