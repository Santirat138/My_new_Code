package DataStruct.HashTable.Open_Hash;

public class Main{
    public static void main(String[] args){
        int size=5;
        hashTable table1=new hashTable(size);
        table1.insertNum(1);
        table1.insertNum(4);
        table1.insertNum(10);
        table1.insertNum(5);
        table1.insertNum(8);
        table1.showAll();
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
    node nullNode;

    linkList(){
        nullNode=new node(-1);
        head=null;
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
        System.out.println("");
    }
}
class hashTable{
    int size, key;
    linkList[] arrayLL;

    hashTable(int sizeIn){
        size=sizeIn;
        arrayLL=new linkList[size];
        for(int i=0;i<size;i++){
            arrayLL[i]=new linkList();
        }
    }
    int findKey(int numIn){
        return numIn%size;
    }
    void insertNum(int newNum){
        key=findKey(newNum);
        node newNode=new node(newNum);
        if(arrayLL[key].head==null){
            arrayLL[key].head=newNode;
        }
        else{
            node currNode=arrayLL[key].head;
            while(currNode!=null){
                if(currNode.next==null){
                    currNode.next=newNode;
                    break;
                }
                else{
                    currNode=currNode.next;
                }
            }
        }
    }
    void showAll(){
        for(int i=0;i<size;i++){
            System.out.printf("Index %d : ", i);
            arrayLL[i].show();
        }
    }
}