// Test close hash table
#include<iostream>
using namespace std;
class hashTable{
	public:
		int size;
		int *array;

		hashTable(int sizeIn);
		int findKey(int numIn);
		void insertNum(int newNum);
		void show();
};
hashTable::hashTable(int sizeIn){
	size=sizeIn;
	array=new int[size];
	for(int i=0;i<size;i++){
		array[i]=-1;
	}
}
int hashTable::findKey(int numIn){
	return numIn%size;
}
void hashTable::insertNum(int newNum){
	int key=findKey(newNum);
	while(key<size){
		if(array[key]==-1){
			array[key]=newNum;
			break;
		}
		else{
			key++;
		}
	}
}
void hashTable::show(){
	for(int i=0;i<size;i++){
		cout<<"index "<<i<<" : ";
		cout<<array[i]<<endl;
	}
}
int main(){
	hashTable table1(5);
	table1.insertNum(5);
	table1.insertNum(15);
	table1.insertNum(10);
	table1.insertNum(1);

	table1.show();
}