// Close hash use array.
public class DataStruct_CloseHash{
    public static void main(String[] args){
        int size=5;
        table hash1=new table(size);
        hash1.insert(7);
        hash1.insert(22);
        hash1.insert(5);
        hash1.insert(25);
        hash1.show();
        hash1.deleteNum(25);
        hash1.show();
    }
}
class table{
    int size;
    int[] array;
    int idx;
    int num;
    
    table(int sizeIn){
        num=-1;
        size=sizeIn;
        array=new int[size];
        for(int i=0;i<size;i++){
            array[i]=num;
        }
    }
    int findIdx(int numIn){
        return numIn%size;
    }
    void insert(int newNum){
        num=newNum;
        idx=findIdx(num);
        if((idx<size)&&(idx>=0)){
            while(idx<size){
                if(array[idx]==-1){
                    array[idx]=newNum;
                    break;
                }
                else{
                    idx++;
                }
            }
        }
        else{
            System.out.println("Error");
        }
    }
    void show(){
        System.out.printf("\n");
        for(int i=0;i<size;i++){
            System.out.printf("%d ", array[i]);
        }
        System.out.printf("\n");
    }
    void deleteNum(int target){
        int currIdx=findIdx(target);
        while(currIdx<size){
            if(array[currIdx]==target){
                array[currIdx]=-1;
            }
            else{
                currIdx++;
            }
        }
    }
}