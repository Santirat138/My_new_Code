package DataStruct.Test_Space.Way_3.Way_3_1;

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
    node tail;

    linkList(){
        head=null;
        tail=null;
    }
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            tail=newNode;
        }
        else{
            newNode.next=head;
        }
        head=newNode;
    }
    void addLast(int newNum){
        node newNode=new node(newNum);
        if((head==null)&&(tail==null)){
            head=newNode;
        }
        else{
            tail.next=newNode;
        }
        tail=newNode;
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
    node pop(){
        node top=head;
        head=head.next;
        top.next=null;
        return top;
    }
}
class arrayBox{
    int size;
    linkList[] arrayLL;
    linkList[] arrayStack;
    linkList[] arrayQueue;

    arrayBox(int sizeIn){
        size=sizeIn;
        arrayLL=new linkList[size];
        arrayStack=new linkList[size];
        arrayQueue=new linkList[size];
    }
    void insertLinkList(int idx, int newNum){
        arrayLL[idx].addFirst(newNum);
    }
    void pushInIdx(int idx, int newNum){
        arrayStack[idx].addFirst(newNum);
    }
    node popInIdx(int idx){
        return arrayStack[idx].pop();
    }
    void enqueueInIdx(int idx, int newNum){
        arrayQueue[idx].addLast(newNum);
    }
}