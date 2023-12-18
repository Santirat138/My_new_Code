package DataStruct.HashTable.Close_Hash;

public class Main {
    public static void main(String[] args){
        table table1=new table(5);
        table1.insert(1);
        table1.insert(3);
        table1.insert(5);
        table1.insert(55);
        table1.deleteNum(55);
        table1.show();
    }
}
class table{
    int size, key;
    int[] array;

    table(int sizeIn){
        size=sizeIn;
        array=new int[size];
        for(int i=0;i<size;i++){
            array[i]=-1;
        }
    }
    int findKey(int numIn){
        return numIn%size;
    }
    void insert(int newNum){
        key=findKey(newNum);
        while(key<size){
            if(array[key]==-1){
                array[key]=newNum;
                break;
            }
            else{
                System.out.printf("Index(key) %d is already has number %d.\n", key, array[key]);
                key++;
                System.out.printf("Then insert at Index(key) %d.\n", key);
            }
        }
    }
    void show(){
        for(int i=0;i<size;i++){
            System.out.printf("%d ", array[i]);
        }
    }
    int findNum(int numIn){
        key=findKey(numIn);
        while(key<size){
            if(array[key]==numIn){
                return key;
            }
            else{
                key++;
            }
        }
        return -1;
    }
    void deleteNum(int numIn){
        int delKey=findNum(numIn);
        array[delKey]=-1;
    }
}