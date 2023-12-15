// Close hash use array.
import java.util.Scanner;
public class DataStruct_CloseHash{
    public static void main(String[] args){
        Scanner input=new Scanner(System.in);
        System.out.printf("Enter size. ");
        int size=input.nextInt();
        int[] array=new int[size];
        int num, idx;
        int i=0;
        for(int a=0;a<size;a++){
            array[a]=-1;
        }
        do{
            System.out.printf("Enter number. ");
            num=input.nextInt();
            idx=num%size;
            System.out.printf("%d add in idx %d.\n", num, idx);
            if(num!=-1){
                if(array[idx]==-1){
                    array[idx]=num;
                }
                else if(array[idx]!=-1){
                    System.out.printf("Index %d is not empty.\n", idx);
                    idx=idx+1;
                    array[idx]=num;
                }
                i++;
            }
            else if(num==-1){
                break;
            }
        }
        while(i<size);
        for(int k=0;k<size;k++){
            System.out.printf("%d ", array[k]);
        }
    }
}
