#include<iostream>
using namespace std;

//-------------------------- functions
int getItemVal(int wishValueIn, int importantValueIn){
	return (wishValueIn/2)+(importantValueIn);
}
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
			itemValue=getItemVal(wishValue, importantValue);
		}
		void showItemInfo(){
			cout<<endl<<"------------------------------------------------"<<endl;
			cout<<"ID: "<<itemId<<"\tName: "<<itemName<<endl;
			cout<<"\twishValue "<<wishValue<<"\timportaneValue "<<importantValue<<endl;
			cout<<"\titemValue "<<itemValue<<endl<<"------------------------------------------------";
			cout<<endl;
		}
};