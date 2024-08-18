package OOP_old.p25_7;

public class Main {
    public static void main(String[] args) {
        int[] array={1, 2, 3, 4 , 5};
        toolsBox tool=new toolsBox(array);
        System.out.print(tool.findSum(2));
    }
}
class arrayBox{
    int[] array;
    int arrSize;
    arrayBox(int[] arrayIn){
        array=arrayIn;
        arrSize=array.length;
    }
}
class toolsBox extends arrayBox{
    toolsBox(int[] arrayIn){
        super(arrayIn);
    }
    int findSum(int idxIn){
        int sumAns=0;
        for(int i=0;i<=idxIn;i++){
            sumAns=sumAns+array[i];
        }
        return sumAns;
    }

}