// Close hash use array.
import java.util.Scanner;
public class Test_1{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        System.out.printf("Enter size.");
        int size=input.nextInt();
        int[] array=new int[size];
        int num, idx;
        for(int i=0;i<size;i++){
            System.out.printf("Enter number. ");
            num=input.nextInt();
            idx=num%size;
            if(array[idx]==0){
                array[idx]=num;
            }
            else{
                System.out.printf("idx %d is not empty.\n", i);
                idx=idx+1;
            }
        }
        for(int i=0;i<size;i++){
            System.out.printf("%d ", array[i]);
        }
    }
}
