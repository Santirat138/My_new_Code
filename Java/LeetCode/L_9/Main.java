package Leetcode.L_9;
public class Main{
    public static void main(String[] args){
        toolsBox2 box=new toolsBox2();
        box.checkPalin(1258521);
    }
}
class numBox{
    int mainNum;
    int numSize;
    int[] newNum;
}
class toolsBox1 extends numBox{
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
    void setNewNum(int numIn){
        setMainNum(numIn);
        setNumSize();
        newNum=new int[numSize];
        for(int i=0;i<numSize;i++){
            newNum[i]=sentNum(i+1, numIn);
        }
        for(int i=0;i<numSize;i++){
            System.out.printf("%d ", newNum[i]);
        }
    }
}
class toolsBox2 extends numBox{
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
    int findNumAtPos(int numIn, int posIn){
        int numRem=numIn;
        int currPos=1;
        while(currPos!=posIn){
            numRem=numRem/10;
            currPos++;
        }
        return numRem%10;
    }
    void checkPalin(int numIn){
        int num1, num2;
        boolean isPalin=true;
        setMainNum(numIn);
        setNumSize();
        if(numSize%2==0){
            for(int front=numSize, back=1;back<=numSize/2;front--, back++){
                num1=findNumAtPos(numIn, front);
                num2=findNumAtPos(numIn, back);
                if(num1!=num2){
                    isPalin=false;
                    break;
                }
            }
        }
        else{
            for(int front=numSize, back=1;front!=back;front--, back++){
                num1=findNumAtPos(numIn, front);
                num2=findNumAtPos(numIn, back);
                if(num1!=num2){
                    isPalin=false;
                    break;
                }
            }
        }
        if(isPalin){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
    }
}