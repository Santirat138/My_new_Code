package LeetCode.L_1;

public class Main{
    public static void main(String[] args){
        int[] array={1, 2, 3, 4, 5, 6};
        int size=array.length;
        int targNum=6;
        for(int curr1=0;curr1<size;curr1++){
            for(int curr2=0;curr2<size;curr2++){
                if(curr1==curr2){
                    continue;
                }
                if(array[curr1]+array[curr2]==targNum){
                    System.out.printf("%d + %d\n", array[curr1], array[curr2]);
                }
            }
        }
    }
}