package Leetcode.L_66;

public class Main {
    public static void main(String[] args) {
        int[] array={1, 2, 3, 4};
        method1 box=new method1();
        box.setArrayBox(array);
        box.changeToArray();
    }
}
class mathIntTools{
    int power(int base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
    }
    int countDigi(int numIn){
        int digi=0;
        while(numIn!=0){
            numIn=numIn/10;
            digi++;
        }
        return digi;
    }
}
class arrayBox{
    int[] mainArray;
    int arrSize;
}
class method1 extends arrayBox{
    int[] newArray;
    mathIntTools mTool=new mathIntTools();
    void setArrayBox(int[] arrayIn){
        mainArray=arrayIn;
        arrSize=mainArray.length;
    }
    int changeToNumPlusOne(){
        int num=0;
        for(int curr=arrSize-1;curr>=0;curr--){
            num=num+(mainArray[curr]*mTool.power(10, arrSize-1-curr));
        }
        return num+1;
    }
    void changeToArray(){
        int newNum=changeToNumPlusOne();
        int newArrSize=mTool.countDigi(newNum);
        newArray=new int[newArrSize];
        for(int i=newArrSize-1;i>=0;i--){
            newArray[i]=newNum%10;
            newNum=newNum/10;
        }
        for(int i=0;i<newArrSize;i++){
            System.out.printf("%d ", newArray[i]);
        }
    }
}
class method2 extends arrayBox{
    
}