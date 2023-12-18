package DataStruct.Array_LinkList;

public class Main {
    public static void main(String[] args){
        int size=5;
        arrayLL array1=new arrayLL(size);
        for(int i=0;i<=5;i++){
            array1.insertAtIdx(1, i);
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
    node nullNode=new node(-1);
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
    void deleteFirst(){
        node delNode=head;
        head=delNode.next;
        delNode.next=null;
    }
    node findNode(node currNode, int currPos, int pos){
        if(currNode==null){
            return nullNode;
        }
        else{
            if(currPos==pos){
                return currNode;
            }
            else{
                return findNode(currNode.next, currPos+1, pos);
            }
        }
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
    void insertAtIdx(int idx, int newNum){
        array[idx].addFirst(newNum);
    }
    void show(int idx){
        node currNode=array[idx].head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
    void deleteFirstAtIdx(int idx){
        array[idx].deleteFirst();
    }
}