package LeetCode.L_9;

public class Main{
    public static void main(String[] args){
        toolsBox tool=new toolsBox();
        int num=123456;
        int revNum=0;
        int digiSize=tool.countDigi(num, 0);
        tool.checkPalin(num, tool.makeRev(digiSize, num));
    }
}
class toolsBox{
    int countDigi(int numRem, int currDigi){
        if(numRem!=0){
            return countDigi(numRem/10, currDigi+1);
        }
        else{
            return currDigi;
        }
    }
    int popNum(int numIn, int digiNum){
        return (numIn/(int)Math.pow(10, digiNum))%10;
    }
    int makeRev(int digiNum, int numIn){
        int revNum=0;
        for(int i=0;i<digiNum;i++){
            revNum=revNum+(popNum(numIn, i)*(int)Math.pow(10, (digiNum-1)-i));
        }
        return revNum;
    }
    void checkPalin(int oldNum, int newNum){
        if(oldNum!=newNum){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
    }
}