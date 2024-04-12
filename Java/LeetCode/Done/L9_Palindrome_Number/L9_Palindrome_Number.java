package LeetCode.Done.L9_Palindrome_Number;
public class L9_Palindrome_Number {
    public static void main(String[] args) {

    }
}
class palinBox{
    int[] array;
    int size;
    int num;
    palinBox(int numIn){
        num=numIn;
    }
    void checkPalin(int curr1, int curr2){
        if(curr1<curr2){
            if(array[curr1]==array[curr2]){
                checkPalin(curr1+1, curr2-1);
            }
            else{
                System.out.println("False.");
            }
        }
        else{
            System.out.println("True.");
        }
    }
    void numToAry(){
        
    }
}