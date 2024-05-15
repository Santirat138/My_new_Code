#include<iostream>
using namespace std;
class hTable{
	public:
		int size=5;
		int array[5];

		hTable();
		int findKey(int numIn);
		void insertNum(int newNum);
		void show(int currIdx);
};
hTable::hTable(){
	for(int i=0;i<size;i++){
		array[i]=-1;
	}
}
int hTable::findKey(int numIn){
	return numIn%size;
}
void hTable::insertNum(int newNum){
	int key=findKey(newNum);
	while(1){
		if(array[key]==-1){
			array[key]=newNum;
			break;
		}
		else{
			key++;
		}
	}
}
void hTable::show(int currIdx){
	if(currIdx<size){
		cout<<array[currIdx]<<" ";
		show(currIdx+1);
	}
	else{
		cout<<"End."<<endl;
	}
}
int main(){
	hTable table;
	table.insertNum(2);
	table.insertNum(20);
	table.insertNum(1);
	table.show(0);
}