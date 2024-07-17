package LeetCode.L_35;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        int size=5;
        int[] array=new int[size];
        int targNum;
        Scanner input=new Scanner(System.in);
        for(int i=0;i<size;i++){
            array[i]=input.nextInt();
        }
        System.out.println("Enter targNum.");
        targNum=input.nextInt();
        for(int currIdx=0;currIdx<size;currIdx++){
            if(array[currIdx]==targNum){
                System.out.printf("%d", currIdx);
                break;
            }
        }
    }
}
