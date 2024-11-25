#include<iostream>
using namespace std;

//---------------------- class itemBag
class itemBag{
	public:
		int amount_item=0;
		int amount_itemBag=0;
};
//---------------------- class surviBag
class surviBag{
	public:
		int ID_surviBag;
		itemBag waterBag;
		itemBag breadBag;
		itemBag eggBag;
		
		void input_item(int waterIn, int breadIn, int eggIn){
			waterBag.amount_item=waterIn;
			breadBag.amount_item=breadIn;
			eggBag.amount_item=eggIn;
		}
		void TEST_show_amount_item(){
			cout<<waterBag.amount_item<<endl;
			cout<<breadBag.amount_item<<endl;
			cout<<eggBag.amount_item<<endl;
		}
};
//---------------------- main
int main(){
	
}