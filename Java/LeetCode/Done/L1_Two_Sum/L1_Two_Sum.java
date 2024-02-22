package LeetCode.Done.L1_Two_Sum;

public class L1_Two_Sum {
    public static void main(String[] args){
        int[] array={0, 1, 2, 3, 5, 7, 8};
        arrayBox objArray=new arrayBox(7, array);
        objArray.findSum(8);
    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){
        size=sizeIn;
        array=arrayIn;
    }
    void findSum(int target){
        int i=size-1;
        int j;
        while(i>0){
            j=0;
            while(j<i){
                if(array[i]+array[j]==target){
                    System.out.printf("[%d, %d] ", array[j], array[i]);
                }
                j++;
            }
            i--;
        }
    }
}