#include<iostream>
using namespace std;
class palinBox{
    public:
        int oldNum;
        int newNum;
        int digi;
        int array[];

        void setNum(int numIn){
            oldNum=numIn;
        }
        void countDigi(int numRem){
            if(numRem!=0){
                digi++;
                countDigi(numRem/10);
            }
        }
		int power(int ans, int base, int pow){
			if(pow==0){
				return ans;
			}
			else{
				return power(ans*base, base, pow-1);
			}
		}
        void extNum(){
            array[digi];
            int numRem=oldNum;
            int i=0;
            while(numRem!=0){
                array[i]=numRem%10;
                numRem=numRem/10;
                i++;
            }
        }
        void arrayToNum(){
            newNum=0;
            for(int i=0;i<digi;i++){
                newNum=newNum+array[i]*(power(1, 10, digi-i-1));
            }
        }
        void tools(int numIn){
            if((numIn>0)&&(numIn%10!=0)){
                setNum(numIn);
                countDigi(numIn);
                extNum();
                arrayToNum();
                if(oldNum==newNum){
                    cout<<newNum<<" True";
                }
                else{
                    cout<<"False"<<endl;
                }
            }
            else{
                cout<<"False"<<endl;
            }
        }
};
int main(){
    palinBox pBox;
    pBox.tools(123321);
    
}