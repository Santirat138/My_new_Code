import java.util.Scanner;

public class DataStruct_CloseHash {
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        int size=input.nextInt();
        int[] array=new int[size];
        int num, idx;
        int i=0;
        do{
            System.out.printf("Enter number. ");
            num=input.nextInt();
            idx=num%size;
            if(array[idx]==0){
                array[idx]=num;
            }
            else{
                System.out.println("Error");
            }
            i++;
        }
        while(i<size);
        for(i=0;i<size;i++){
            System.out.printf("idx %d, number %d\n", i, array[i]);
        }
    }
}
