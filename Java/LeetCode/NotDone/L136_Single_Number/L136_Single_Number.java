package LeetCode.NotDone.L136_Single_Number;

public class L136_Single_Number {
    public static void main(String[] args){
        int[] array={1, 3, 2, 1, 2, 8};
        arrayBox arrayObj=new arrayBox(6, array);
        arrayObj.showSingle();
    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){
        size=sizeIn;
        array=arrayIn;
    }
    void showSingle(){
        int currIdx=0;
        
    }
}