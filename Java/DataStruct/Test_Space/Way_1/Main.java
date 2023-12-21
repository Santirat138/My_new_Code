package DataStruct.Test_Space.Way_1;

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
    void addFirst(int newNum){
        node newNode=new node(newNum);
        if(head!=null){
            newNode.next=head;
        }
        head=newNode;
    }
    void show(){
        node currNode=head;
        while(currNode!=null){
            System.out.printf("%d ", currNode.num);
            currNode=currNode.next;
        }
    }
}
class stack{
    node top;

    stack(){
        top=null;
    }
    void push(int newNum){
        node newNode=new node(newNum);
        if(top!=null){
            newNode.next=top;
        }
        top=newNode;
    }
    node pop(){
        node temp=top;
        top=top.next;
        temp.next=null;
        return temp;
    }
}
class queue{
    node firstNode;
    node lastNode;

    queue(){
        firstNode=null;
        lastNode=null;
    }
    void  enqueue(int newNum){
        node newNode=new node(newNum);
        if((firstNode==null)&&(lastNode==null)){
            firstNode=newNode;
        }
        else{
            lastNode.next=newNode;
        }
        lastNode=newNode;
    }
    node dequeue(){
        node temp=firstNode;
        while(temp!=null){
            if(temp.next==lastNode){
                break;
            }
            else{
                temp=temp.next;
            }
        }
        lastNode=temp;
        temp=lastNode.next;
        lastNode.next=null;
        return temp;
    }
}
class arrayLLBox{
    int size;
    linkList[] arrayLL;

    arrayLLBox(int sizeIn){
        size=sizeIn;
        arrayLL=new linkList[size];
        for(int i=0;i<size;i++){
            arrayLL[i]=new linkList();
        }
    }
    void insertNum(int idx, int newNum){
        arrayLL[idx].addFirst(newNum);
    }
    void showIdx(int idx){
        arrayLL[idx].show();
    }
    void showAll(){
        for(int i=0;i<size;i++){
            arrayLL[i].show();
        }
    }
}
class arrayStackBox{
    int size;
    stack[] arrayStack;

    arrayStackBox(int sizeIn){
        size=sizeIn;
        arrayStack=new stack[size];
        for(int i=0;i<size;i++){
            arrayStack[i]=new stack();
        }
    }
    void pushInIdx(int idx, int newNum){
        arrayStack[idx].push(newNum);
    }
    node popInIdx(int idx){
        return arrayStack[idx].pop();
    }
}
class arrayQueueBox{
    int size;
    queue[] arrayQueue;

    arrayQueueBox(int sizeIn){
        size=sizeIn;
        arrayQueue=new queue[size];
        for(int i=0;i<size;i++){
            arrayQueue[i]=new queue();
        }
    }
    void enqueueInIdx(int idx, int newNum){
        arrayQueue[idx].enqueue(newNum);
    }
    node dequeueInIdx(int idx){
        return arrayQueue[idx].dequeue();
    }
}