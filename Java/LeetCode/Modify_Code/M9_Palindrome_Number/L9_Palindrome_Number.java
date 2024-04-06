package LeetCode.Modify_Code.M9_Palindrome_Number;

public class L9_Palindrome_Number {
    public static void main(String[] args){
        palinBox palinObj=new palinBox();
        palinObj.check(12343721);
    }
}
class toolsBox{
    int power(int base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
    }
    int countDigi(int numRem, int digi){
        if(numRem==0){
            return digi;
        }
        else{
            return countDigi(numRem/10, digi+1);
        }
    }
}
class palinBox{
    toolsBox tool=new toolsBox();
    int makeRev(int numRem, int numRev, int currDigi){
        if(numRem==0){
            return numRev;
        }
        else{
            numRev=((numRem%10)*tool.power(10, currDigi))+numRev;
            return makeRev(numRem/10, numRev, currDigi-1);
        }
    }
    void check(int numIn){
        int numRev=makeRev(numIn, 0, tool.countDigi(numIn, 0)-1);
        if(numRev==numIn){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
    }
}