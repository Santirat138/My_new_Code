package Test.Test_1;
// Test 27. Remove Element.
public class Test_1{
    public static void main(String[] args){
        int[] array={3, 5, 3, 3, 2, 3};
        mainBox box=new mainBox(array);
        box.removeNum(3);
        box.refacArray();
        box.showArray(0);
    }
}
class mainBox{
    int[] mainArray;
    int delNum;
    int arraySize;
    int newArraySize;
    mainBox(int[] arrayIn){
        mainArray=arrayIn;
        arraySize=mainArray.length;
    }
    void showArray(int currIdx){
        if(currIdx<arraySize){
            System.out.printf("%d ", mainArray[currIdx]);
            showArray(currIdx+1);
        }
        else{
            System.out.println("End.");
        }
    }
    void removeNum(int delNum){
        for(int i=0;i<arraySize;i++){
            if(mainArray[i]==delNum){
                mainArray[i]=-1;
            }
        }
    }
    void refacArray(){
        int temp;
        int idx1=0;
        int idx2=arraySize-1;
        while(idx2>0){
            if(mainArray[idx1]==-1){
                temp=mainArray[idx1];
                mainArray[idx1]=mainArray[idx2];
                mainArray[idx2]=temp;
            }
            idx1++;
            if(idx1==idx2){
                idx1=0;
                idx2--;
            }
        }
    }
}