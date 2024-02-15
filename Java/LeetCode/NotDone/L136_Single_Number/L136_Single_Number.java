package LeetCode.NotDone.L136_Single_Number;

public class L136_Single_Number {
    public static void main(String[] args){
        int[] array={5, 7, 3, 6, 5, 9};
        arrayBox arrayObj=new arrayBox(6, array);

    }
}
class eleBox{
    int num;
    int amount;
    eleBox(int numIn){
        num=numIn;
        amount=0;
    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){
        size=sizeIn;
        array=arrayIn;
    }
    void findSingle(){
        int curr=0;
        int check;
        int singleNum;
        
    }
}