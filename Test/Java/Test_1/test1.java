// Test L_169
package Test_1;
public class test1{
    public static void main(String[] args){
        int[] array={1, 1, 1, 1, 2, 2, 3, 3};
        arrayBox box=new arrayBox(array);

    }
}
class arrayBox{
    int[] array;
    arrayBox(int[] arrayIn){
        array=arrayIn;
    }
    int setEndIdx(int start){
        int end=1;
        while(true){
            if(array[start]==array[end]){
                end++;
            }
            else{
                return end;
            }
        }
    }
    int countNum(int start){
        int end=setEndIdx(start);
        return (end-start)+1;
    }
    
}