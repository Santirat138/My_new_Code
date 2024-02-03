public class Plus_One {
    public static void main(String[] args){
        int[] array={9, 9, 9, 9};
        arrayBox box=new arrayBox(array, 1);
        System.out.printf("%d\n", box.num2);
        box.makeArray();
        
    }
}
class toolBox{
    int countDigi(int numIn, int digi){
        if(numIn==0){
            return digi;
        }
        else{
            return countDigi(numIn/10, digi+1);
        }
    }
    int power(int base, int pow){
        if(pow==0){
            return 1;
        }
        else{
            return base*power(base, pow-1);
        }
    }
    int makeInt(int[] arrayIn, int powNum, int currIdx, int newNum){
        if(currIdx==arrayIn.length){
            return newNum;
        }
        else{
            newNum=newNum+(arrayIn[currIdx]*power(10, powNum));
            return makeInt(arrayIn, powNum-1, currIdx+1, newNum);
        }
    }
    
}
class arrayBox{
    toolBox tools=new toolBox();;
    int plusNum;
    int[] array1;
    int[] array2;
    int num1, num2;
    arrayBox(int[] arrayIn1, int plusNumIn){
        array1=arrayIn1;
        plusNum=plusNumIn;
        for(int i=0;i<array1.length;i++){
            System.out.printf("%d ", array1[i]);
        }
        num2=tools.makeInt(arrayIn1, array1.length-1, 0, 0)+plusNum;
    }
    void makeArray(){
        int size2=tools.countDigi(num2, 0);
        array2=new int[size2];
        for(int i=size2-1;i>=0;i--){
            array2[i]=num2%10;
            num2=num2/10;
        }
        for(int i=0;i<size2;i++){
            System.out.printf("%d ", array2[i]);
        }
    }
}