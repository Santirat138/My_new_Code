package DataStruct.Array_LinkList;

public class Main {
    public static void main(String[] args){
        int size=5;
        arrayLL array1=new arrayLL(size);
        for(int i=0;i<=5;i++){
            array1.insertAt(1, i);
        }
        array1.show(1);
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
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
    }

}
class arrayLL{
    linkList[] array;
    int size;
    arrayLL(int sizeIn){
        size=sizeIn;
        array=new linkList[size];
        for(int i=0;i<size;i++){
            array[i]=new linkList();
        }
    }
    void insertAt(int idx, int newNum){
        array[idx].addFirst(newNum);
    }
    void show(int idx){
        node currNode=array[idx].head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
}