package Practice.Ex_2;

public class Main {
    public static void main(String[] args){
        palinBox box1=new palinBox(1210);
        box1.tools();
    }
}
class palinBox{
    int oldNum;
    int newNum;
    int digi;
    int[] array;

    palinBox(int numIn){
        oldNum=numIn;
    }
    void countDigi(){
        int numRem=oldNum;
        while(numRem!=0){
            numRem=numRem/10;
            digi++;
        }
        array=new int[digi];
    }
    void extNum(){
        int numRem=oldNum;
        for(int i=0;i<digi;i++){
            array[i]=numRem%10;
            numRem=numRem/10;
        }
    }
    int power(int base, int pow){
        int ans=1;
    	for(int i=0;i<pow;i++) {
    		ans=ans*base;
    	}
    	return ans;
    }
    void arrayToNum(){
        for(int i=0;i<digi;i++){
            newNum=newNum+array[i]*(power(10, digi-1-i));
        }
    }
    void compareNum(){
        if(newNum==oldNum){
            System.out.println("\nTrue");
        }
        else if((oldNum<0)||(oldNum%10==0)){
            System.out.println("\nFalse");
        }
    }
    void tools(){
        countDigi();
        extNum();
        arrayToNum();
        compareNum();
    }
}