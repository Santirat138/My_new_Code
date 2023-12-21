package DataStruct.Test_Space.Way_2;

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
    node popNum(){
        node temp=head;
        head=head.next;
        temp.next=null;
        return temp;
    }
    node dequeueNum(){
        node temp=head;
        while(temp!=null){
            if(temp.next==tail){
                break;
            }
            else{
                temp=temp.next;
            }
        }
        tail=temp;
        temp=temp.next;
        tail.next=null;
        return temp;
    }
}
class arrayLLBox{
    int size;
    linkList[] arrayLL;

    arrayLLBox(int sizeIn){
        size=sizeIn;
        arrayLL=new linkList[size];
    }
    void insertInIdx(int idx, int newNum){
        arrayLL[idx].addFirst(newNum);
    }
}
class arrayStackBox{
    int size;
    linkList[] arrayStack;

    arrayStackBox(int sizeIn){
        size=sizeIn;
        arrayStack=new linkList[size];
        for(int i=0;i<size;i++){
            arrayStack[i]=new linkList();
        }
    }
    void pushInIdx(int idx, int newNum){
        arrayStack[idx].addFirst(newNum);
    }
    node popInIdx(int idx){
        return arrayStack[idx].popNum();
    }
}
class arrayQBox{
    int size;
    linkList[] arrayQueue;

    arrayQBox(int sizeIn){
        size=sizeIn;
        arrayQueue=new linkList[size];
        for(int i=0;i<size;i++){
            arrayQueue[i]=new linkList();
        }
    }
    void enqueueInIdx(int idx, int newNum){
        arrayQueue[idx].addLast(newNum);
    }
    node dequeueInIdx(int idx){
        return arrayQueue[idx].dequeueNum();
    }
}