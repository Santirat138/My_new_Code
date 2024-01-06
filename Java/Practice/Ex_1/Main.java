package Practice.Ex_1;

public class Main {
    public static void main(String[] args){
        int[] array={1, 2, 3, 4, 5};
        int target=6;
        for(int i=4;i>=0;i--){
            for(int j=0;j<i;j++){
                if(array[i]+array[j]==target){
                    System.out.printf("Number %d %d\n", array[i], array[j]);
                    System.out.printf("Index %d %d\n\n", i, j);
                }
            }
        }
    }
}