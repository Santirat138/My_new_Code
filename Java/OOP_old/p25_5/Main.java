package OOP_old.p25_5;
public class Main{
    public static void main(String[] args){
        int[] array={1, 2, 3, 4};
        arrayBox box=new arrayBox(array);
        box.method2();
    }
}
class toolsBox{
    int errVal=-1;
    int pop(int top, int[] arrayIn){
        if(top!=0){
            int temp=arrayIn[top-1];
            top--;
            return temp;
        }
        else{
            return errVal;
        }
    }
    void swapNum(int[] arrayIn, int idx1, int idx2){
        int temp=arrayIn[idx1];
        arrayIn[idx1]=arrayIn[idx2];
        arrayIn[idx2]=temp;
    }
}
class arrayBox{
    int[] array;
    int[] newArray;
    int arrSize;
    toolsBox tool;
    arrayBox(int[] arrayIn){
        array=arrayIn;
        arrSize=array.length;
        newArray=new int[arrSize];
        tool=new toolsBox();
    }
    void method1(){
        for(int curr=0;curr<arrSize;curr++){
            newArray[curr]=tool.pop(arrSize-curr, array);
        }
        for(int i=0;i<arrSize;i++){
            System.out.printf("%d ", newArray[i]);
        }
    }
    void method2(){
        if(arrSize%2==0){
            for(int curr1=0, curr2=arrSize-1;curr1<curr2;curr1++, curr2--){
                tool.swapNum(array, curr1, curr2);
            }
        }
        else{
            for(int curr1=0, curr2=arrSize-1;curr1!=curr2;curr1++, curr2--){
                tool.swapNum(array, curr1, curr2);
            }
        }
        for(int i=0;i<arrSize;i++){
            System.out.printf("%d ", array[i]);
        }
    }
}
