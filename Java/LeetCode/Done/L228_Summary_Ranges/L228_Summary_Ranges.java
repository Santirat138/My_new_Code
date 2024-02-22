package LeetCode.Done.L228_Summary_Ranges;

public class L228_Summary_Ranges {
    public static void main(String[] args){
        int[] array={1, 2, 3, 5, 7, 8, 9, 10, 20, 30, 31};
        arrayBox objArr=new arrayBox(11, array);
        objArr.range();
    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){
        size=sizeIn;
        array=arrayIn;
    }
    void range(){
        int curr=0;
        int check=1;
        int walk=1;
        while((curr<size)&&(check<size)){
            if(array[curr]+walk==array[check]){
                walk++;
            }
            else{
                System.out.printf("%d --> %d  ", array[curr], array[check-1]);
                curr=check;
                walk=1;
            }
            check++;
        }
        System.out.printf("%d --> %d  ", array[curr], array[check-1]);
    }
}