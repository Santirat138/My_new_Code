package LeetCode.Done.L35_Search_Insert_Position;

public class L35_Search_Insert_Position {
    public static void main(String[] args){
        int[] array={2, 4, 6, 8, 10};
        arrayBox arrayObj=new arrayBox(5, array);
        System.out.printf("%d", arrayObj.searchNum(9));
    }
}
class arrayBox{
    int size;
    int[] array;
    arrayBox(int sizeIn, int[] arrayIn){
        size=sizeIn;
        array=arrayIn;
    }
    // If not found return -1;
    int findNum(int numIn){
        for(int i=0;i<size;i++){
            if(array[i]==numIn){
                return i;
            }
        }
        return -1;
    }
    int searchNum(int numIn){
        int result=findNum(numIn);
        int curr=0;
        if(result!=-1){
            return result;
        }
        else{
            while(curr+1<size){
                if((numIn>array[curr])&&(numIn<array[curr+1])){
                    break;
                }
                else{
                    curr++;
                }
            }
        }
        return curr+1;
    }
}