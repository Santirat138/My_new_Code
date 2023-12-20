package DataStruct.HashTable.Open_Hash;

public class Main {
    public static void main(String[] args){

    }
}
class node{
    int num;
    node next;

    node(int numIn){
        num=numIn;
        next=null;
    }
}
class linkList{
    node head;

    linkList(){
        head=null;
    }
    void insertNum(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
    }
}
class hashTable{
    int arraySize, key;
    linkList[] array;

    hashTable(int sizeIn){
        arraySize=sizeIn;
        array=new linkList[arraySize];
        for(int i=0;i<arraySize;i++){
            array[i]=new linkList();
        }
    }
}