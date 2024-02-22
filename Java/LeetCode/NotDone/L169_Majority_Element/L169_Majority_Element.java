package LeetCode.NotDone.L169_Majority_Element;

public class L169_Majority_Element {
    public static void main(String[] args){
        int[] array={1, 8, 8, 1, 2, 8, 2};
        arrayBox arrayObj=new arrayBox(7, array);

    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){
        size=sizeIn;
        array=arrayIn;
    }

}