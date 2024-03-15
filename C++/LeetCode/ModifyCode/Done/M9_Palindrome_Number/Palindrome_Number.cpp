#include<iostream>
using namespace std;
class arrayBox{
    public:
        int num;
        int arrSize;
        int *array;
        arrayBox(int numIn){
            num=numIn;
            arrSize=countDigi(0, num);
            array=new int[arrSize];
        }
		int countDigi(int currDigi, int numRem){
			if(numRem==0){
				return currDigi;
			}
			else{
				return countDigi(currDigi+1, numRem/10);
			}
		}
		void makeArray(){
			int numRem=num;
			int currIdx=arrSize-1;
            for(int i=currIdx;i>=0;i--){
                array[i]=numRem%10;
                numRem=numRem/10;
            }
		}
        void checkPalin(int curr, int check, bool status){
            if((curr==check)|(check+1==curr)){
                if(status){
                    cout<<"True";
                }
                else if(!status){
                    cout<<"False";
                }
            }
            else{
                if(array[curr]==array[check]){
                    checkPalin(curr+1, check-1, true);
                }
                else{
                    cout<<"False."<<endl;
                }
            }
        }
};
int main(){
    int num=11811;
    arrayBox arrayObj(num);
    arrayObj.makeArray();
    arrayObj.checkPalin(0, 4, true);
}