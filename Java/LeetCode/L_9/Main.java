package Leetcode.L_9;
public class Main{
    public static void main(String[] args){

    }
}
class numBox{
    int mainNum;
    int numSize;
}
class toolsBox extends numBox{
    int intPower(int base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*intPower(base, pow-1);
        }
    }
    void setMainNum(int numIn){
        mainNum=numIn;
    }
    void setNumSize(){
        int numRem=mainNum;
        int digi=0;
        while(numRem!=0){
            numRem=numRem/10;
            digi++;
        }
        numSize=digi;
    }
    int sentNum(int currDigi, int numIn){
        if((currDigi!=0)&&(currDigi<=numSize)){
            int temp=numIn/intPower(10, currDigi-1);
            return temp%10;
        }
        else{
            return -1;
        }
    }
}
