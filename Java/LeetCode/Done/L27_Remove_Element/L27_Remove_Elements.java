package LeetCode.Done.L27_Remove_Element;

public class L27_Remove_Elements {
    public static void main(String[] args) {
        int[] array={1, 8, 5, 4, 3, 1};
        mainBox box=new mainBox(array, 1);
        box.setTarget(0);
        box.restructArray(0);
        box.showArray(0);
    }
}
class mainBox{
    int[] array;
    int size;
    int target;
    mainBox(int[] arrayIn, int targetIn){
        array=arrayIn;
        size=array.length;
        target=targetIn;
    }
    void setTarget(int currIdx){
        if(currIdx<size){
            if(array[currIdx]==target){
                array[currIdx]=-1;        
            }
            setTarget(currIdx+1);
        }
        else{
            System.out.println("Done.");
        }
    }
    void showArray(int currIdx){
        if(currIdx<size){
            System.out.printf("%d ", array[currIdx]);
            showArray(currIdx+1);
        }
        else{
            System.out.println("End.");
        }
    }
    void swapNum(int idx1, int idx2){
        int temp=array[idx1];
        array[idx1]=array[idx2];
        array[idx2]=temp;
    }
    void restructArray(int currIdx){
        if(currIdx+1<size){
            if(array[currIdx]==-1){
                swapNum(currIdx, currIdx+1);
            }
            restructArray(currIdx+1);
        }
        else{
            System.out.println("End.");
        }
    }
}