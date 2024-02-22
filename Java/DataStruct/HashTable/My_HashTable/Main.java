package DataStruct.HashTable.My_HashTable;
public class Main{
    public static void main(String[] args){

    }
}
class node{
    int num;
    node prev;
    node next;
    node(int numIn){
        num=numIn;
        prev=null;
        next=null;
    }
}
class linkList{
    node head;
    node tail;
    node nullNode;
    linkList(){
        head=null;
        tail=null;
        nullNode=new node(-1);
    }
    void linkNode(node n1, node n2){
        n1.next=n2;
        n2.prev=n1;
    }
    void addSort(int newNum){
        node newNode=new node(newNum);
        
    }
}