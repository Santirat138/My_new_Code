package LeetCode.Modify_Code.M35_Search_Insert_Position;

public class M35_Search_Insert_Position {
    public static void main(String[] args){
        int[] array={1, 2, 3, 4, 5, 6};
        arrayBox arrayObj=new arrayBox(6, array);
        System.out.printf("%d ", arrayObj.findIndex(0, 3));
    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){
        size=sizeIn;
        array=arrayIn;
    }
    int findIndex(int currIdx, int numIn){
        if(currIdx<size){
            if(array[currIdx]==numIn){
                return currIdx;
            }
            else{
                return findIndex(currIdx+1, numIn);
            }
        }
        else{
            return -1;
        }
    }
}