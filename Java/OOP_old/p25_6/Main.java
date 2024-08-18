package OOP_old.p25_6;

public class Main {
    public static void main(String[] args){
        int[] array={1, 5, 0, 2, 8};
        toolsBox tool=new toolsBox(array);
        tool.findMaxNum();
        tool.setNewArray();

    }
}
class arrayBox{
    int[] array;
    int arrSize;
    void setArray(int[] arrayIn){
        array=arrayIn;
        arrSize=array.length;
    }   
}
class toolsBox extends arrayBox{
    toolsBox(int[] arrayIn){
        setArray(arrayIn);
    }
    int findMaxNum(){
        int maxNum=array[0];
        for(int curr=0;curr<arrSize;curr++){
            if(maxNum<array[curr]){
                maxNum=array[curr];
            }
        }
        return maxNum;
    }
    void setNewArray(){
        int mainNum=findMaxNum();
        for(int i=0;i<arrSize;i++){
            array[i]=mainNum;
        }
        for(int i=0;i<arrSize;i++){
            System.out.printf("%d ", array[i]);
        }
    }
}