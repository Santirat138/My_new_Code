package LeetCode.Done.L217_Contains_Duplicate;

public class L217_Contains_Duplicate {
    public static void main(String[] args){
        int[] array={1,1,1,3,3,4,3,2,4,2};
        arrayBox obj=new arrayBox(10, array);
        obj.checkDup();
    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){    
        size=sizeIn;
        array=arrayIn;
    }
    void checkDup(){
        int idx1;
        int idx2;
        boolean status=false;
        for(idx2=size-1;idx2>0;idx2--){
            for(idx1=0;idx1<size;idx1++){
                if(array[idx1]==array[idx2]){
                    status=true;
                    break;
                }
            }
        }
        if(!status){
            System.out.println("False.");
        }
        else if(status){
            System.out.println("True.");
        }
    }
}