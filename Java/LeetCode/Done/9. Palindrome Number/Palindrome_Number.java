public class Palindrome_Number{
    public static void main(String[] args){
        palinBox pBox=new palinBox(12521);
        pBox.checkPalin();
    }
}
class toolsBox{
    int num;
    toolsBox(int numIn){
        num=numIn;
    }
    int power(int base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
    }
    int countDigi(int digi, int numRem){
        if(numRem==0){
            return digi;
        }
        else{
            return countDigi(digi+1, numRem/10);
        }
    }
    int makeRev(int numRem, int numRev, int currDigi){
        if(currDigi<0){
            return numRev;
        }
        else{
            numRev=numRev+(((numRem%10)*power(10, currDigi)));
            return makeRev(numRem/10, numRev, currDigi-1);
        }
    }
}
class palinBox{
    int orgNum;
    int newNum;
    int digi;
    toolsBox tool=new toolsBox(orgNum);
    palinBox(int numIn){
        orgNum=numIn;
        digi=tool.countDigi(0, orgNum)-1;
        newNum=tool.makeRev(orgNum, 0, digi);
    }
    void checkPalin(){
        if(orgNum==newNum){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
    }
}